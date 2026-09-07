#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>
#include <fstream>
#include <tuple>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// ═══ ANSI ═══
#define RST   "\033[0m"
#define BLD   "\033[1m"
#define DM    "\033[2m"
#define RD    "\033[31m"
#define GR    "\033[32m"
#define YL    "\033[33m"
#define BL    "\033[34m"
#define MG    "\033[35m"
#define CY    "\033[36m"
#define WH    "\033[37m"
#define BGG   "\033[42m"
#define BGR   "\033[41m"
#define BGB   "\033[44m"

// ═══ Global State ═══
int V = 0;
vector<vector<int>> cap, fl;
vector<int> par;
struct Edge { int u, v; };
vector<Edge> edges;
int src = 0, snk = 0;
bool netOk = false, algDone = false;
int maxFlowRes = 0;
ofstream htmlFile;

// ═══ Presets ═══
struct Preset { string name; int n; vector<tuple<int, int, int>> e; int s, t; };
vector<Preset> presets = {
    {"Mang don gian (4 tram, 5 tuyen)", 4,
     {{0,1,10},{0,2,8},{1,2,5},{1,3,7},{2,3,10}}, 0, 3},
    {"Mang trung binh (6 tram, 10 tuyen)", 6,
     {{0,1,16},{0,2,13},{1,2,10},{1,3,12},{2,1,4},{2,4,14},{3,2,9},{3,5,20},{4,3,7},{4,5,4}}, 0, 5},
    {"Mang phuc tap (8 tram, 14 tuyen)", 8,
     {{0,1,10},{0,2,5},{0,3,15},{1,2,4},{1,4,9},{1,5,15},{2,3,4},{2,5,8},{3,6,16},{4,5,15},{4,7,10},{5,6,15},{5,7,10},{6,7,10}}, 0, 7}
};

// ═══ Utilities ═══
void cls() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void enableANSI() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE) return;
    DWORD m = 0;
    GetConsoleMode(h, &m);
    SetConsoleMode(h, m | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

void pause(const string& msg = "Nhan Enter de tiep tuc...") {
    cout << YL << "\n  [" << msg << "]" << RST;
    cin.get();
}

void initNet(int n) {
    V = n;
    cap.assign(V, vector<int>(V, 0));
    fl.assign(V, vector<int>(V, 0));
    par.resize(V);
    edges.clear();
    algDone = false;
    maxFlowRes = 0;
}

// ═══ Progress Bar ═══
void printBar(int val, int mx, int len = 20) {
    double r = mx > 0 ? (double)val / mx : 0;
    int f = (int)(r * len);
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i < f) {
            if (r >= 1.0) cout << RD << "#" << RST;
            else if (r > 0.5) cout << YL << "#" << RST;
            else cout << GR << "#" << RST;
        }
        else cout << DM << "-" << RST;
    }
    cout << "]";
}

// ═══ MENU ═══
void showMenu() {
    cls();
    cout << CY << BLD << "\n";
    cout << "  ┌─────────────────────────────────────────────────┐\n";
    cout << "  │       HE THONG DIEU PHOI LOGISTICS              │\n";
    cout << "  │       Thuat toan Edmonds-Karp (Max Flow)         │\n";
    cout << "  └─────────────────────────────────────────────────┘\n" << RST;

    if (netOk) {
        cout << "\n  " << BGG << WH << BLD << " NETWORK " << RST << GR
            << " " << V << " tram | " << edges.size() << " tuyen | T"
            << src << " -> T" << snk << RST;
        if (algDone) cout << MG << " | Max Flow = " << maxFlowRes << " tan" << RST;
        cout << "\n";
    }
    else {
        cout << "\n  " << DM << "! Chua co mang luoi" << RST << "\n";
    }

    cout << "\n";
    cout << "  " << GR << BLD << " [1] " << RST << "Tao mang luoi moi (nhap tay)\n";
    cout << "  " << GR << BLD << " [2] " << RST << "Chon mang luoi mau\n";
    cout << "  " << CY << BLD << " [3] " << RST << "Xem chi tiet mang luoi\n";
    cout << "  " << YL << BLD << " [4] " << RST << "Chay Edmonds-Karp (tung buoc)\n";
    cout << "  " << YL << BLD << " [5] " << RST << "Chay Edmonds-Karp (tu dong)\n";
    cout << "  " << MG << BLD << " [6] " << RST << "Xuat bao cao HTML\n";
    cout << "  " << RD << BLD << " [0] " << RST << "Thoat\n";
    cout << "\n  " << BLD << ">> Lua chon: " << RST;
}

// ═══ Option 1: Create ═══
void createNetwork() {
    cls();
    cout << CY << BLD << "\n  == TAO MANG LUOI MOI ==\n\n" << RST;
    int n, e;
    cout << "  So luong tram: "; cin >> n;
    cout << "  So luong tuyen: "; cin >> e;
    cout << "  Tram nguon (0-" << n - 1 << "): "; cin >> src;
    cout << "  Tram dich  (0-" << n - 1 << "): "; cin >> snk;

    if (src < 0 || src >= n || snk < 0 || snk >= n || src == snk) {
        cout << RD << "\n  Loi: Nguon/dich khong hop le!" << RST;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        pause();
        return;
    }

    initNet(n);
    cout << "\n  Nhap cac tuyen (tram_di tram_den tai_trong):\n";
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cout << "  Tuyen " << (i + 1) << ": ";
        cin >> u >> v >> c;
        if (u >= 0 && u < V && v >= 0 && v < V && c > 0) {
            cap[u][v] = c;
            edges.push_back({ u, v });
        }
        else {
            cout << RD << "    Tuyen khong hop le, bo qua." << RST << "\n";
        }
    }
    netOk = true;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cout << GR << "\n  Da tao mang luoi thanh cong!" << RST;
    pause();
}

// ═══ Option 2: Preset ═══
void loadPreset() {
    cls();
    cout << CY << BLD << "\n  == CHON MANG LUOI MAU ==\n\n" << RST;
    for (size_t i = 0; i < presets.size(); i++)
        cout << "  " << GR << "[" << (i + 1) << "]" << RST << " " << presets[i].name << "\n";
    cout << "\n  Chon: ";
    int c; cin >> c;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    if (c < 1 || c >(int)presets.size()) {
        cout << RD << "  Lua chon khong hop le!" << RST;
        pause(); return;
    }
    auto& p = presets[c - 1];
    initNet(p.n);
    src = p.s; snk = p.t;
    for (auto& [u, v, w] : p.e) {
        cap[u][v] = w;
        edges.push_back({ u, v });
    }
    netOk = true;
    cout << GR << "\n  Da nap: " << p.name << RST;
    pause();
}

// ═══ Option 3: View ═══
void viewNetwork() {
    cls();
    cout << CY << BLD << "\n  == CHI TIET MANG LUOI ==\n\n" << RST;
    if (!netOk) {
        cout << RD << "  Chua co mang luoi!" << RST;
        pause(); return;
    }
    cout << "  So tram: " << BLD << V << RST
        << " | So tuyen: " << BLD << edges.size() << RST << "\n";
    cout << "  Nguon: " << BGB << WH << BLD << " T" << src << " " << RST
        << " --> Dich: " << BGR << WH << BLD << " T" << snk << " " << RST << "\n\n";

    cout << "  " << BLD << "Tuyen          Tai trong   Luong       Muc dung               Trang thai" << RST << "\n";
    cout << "  " << string(75, '-') << "\n";

    for (auto& e : edges) {
        int u = e.u, v = e.v;
        printf("  T%d -> T%d       %-10d  %-10d  ", u, v, cap[u][v], fl[u][v]);
        printBar(fl[u][v], cap[u][v]);
        if (fl[u][v] == cap[u][v] && cap[u][v] > 0)
            cout << RD << BLD << " DAY TAI" << RST;
        else if (fl[u][v] > 0)
            cout << YL << " Dang dung" << RST;
        else
            cout << DM << " Trong" << RST;
        cout << "\n";
    }

    if (algDone)
        cout << "\n  " << GR << BLD << ">> Luong cuc dai: " << maxFlowRes << " tan" << RST << "\n";
    pause();
}

// ═══ BFS ═══
bool bfs() {
    fill(par.begin(), par.end(), -1);
    par[src] = src;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < V; v++) {
            if (par[v] == -1 && cap[u][v] - fl[u][v] > 0) {
                par[v] = u;
                if (v == snk) return true;
                q.push(v);
            }
        }
    }
    return false;
}

// ═══ Dashboard ═══
void dashboard(const vector<int>& path = {}) {
    cls();
    cout << CY << BLD << "\n  == DANG CHAY EDMONDS-KARP ==\n\n" << RST;

    auto onPath = [&](int u, int v) {
        for (size_t i = 0; i + 1 < path.size(); i++)
            if (path[i] == u && path[i + 1] == v) return true;
        return false;
        };

    for (auto& e : edges) {
        int u = e.u, v = e.v;
        bool hl = onPath(u, v);
        if (hl) cout << GR << BLD << "  >> ";
        else cout << "     ";

        printf("T%d -> T%d  ", u, v);
        printBar(fl[u][v], cap[u][v]);
        printf(" %d/%d tan", fl[u][v], cap[u][v]);

        if (hl) cout << GR << " << DANG PHAN BO" << RST;
        else if (fl[u][v] == cap[u][v] && cap[u][v] > 0) cout << RD << " [DAY TAI]" << RST;
        cout << "\n";
    }
}

// ═══ HTML Functions ═══
void startHTML() {
    htmlFile.open("Bao_cao_Logistics.html");
    htmlFile << "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Bao Cao Edmonds-Karp</title>\n";
    htmlFile << "<style>body{font-family:'Segoe UI',sans-serif;background:#0f172a;color:#e2e8f0;padding:20px;max-width:900px;margin:auto}"
        << "h1{text-align:center;color:#22d3ee;font-size:1.8em}h2{color:#94a3b8;text-align:center}"
        << ".step{background:#1e293b;border-left:4px solid #22c55e;padding:15px;margin:15px 0;border-radius:0 8px 8px 0}"
        << ".path{color:#f59e0b;font-weight:bold}.hl{color:#22c55e;font-weight:bold}"
        << "table{width:100%;border-collapse:collapse;margin:10px 0}"
        << "th,td{border:1px solid #334155;padding:8px;text-align:center}"
        << "th{background:#1e40af;color:white}"
        << ".res{text-align:center;padding:30px;background:linear-gradient(135deg,#1e3a5f,#064e3b);border-radius:12px;margin:20px 0}"
        << ".num{font-size:3em;color:#22c55e;font-weight:bold}"
        << "</style></head><body>\n";
    htmlFile << "<h1>HE THONG DIEU PHOI LOGISTICS</h1>\n";
    htmlFile << "<h2>Bao cao thuat toan Edmonds-Karp</h2>\n";
}

void logHTML(int step, const vector<int>& p, int bn, int mf) {
    htmlFile << "<div class='step'><h3>Buoc " << step << "</h3><p>Tuyen: <span class='path'>";
    for (size_t i = 0; i < p.size(); i++)
        htmlFile << "T" << p[i] << (i + 1 < p.size() ? " &rarr; " : "");
    htmlFile << "</span></p><p>Bottleneck: <span class='hl'>" << bn << " tan</span></p>"
        << "<p><b>Tong luong: " << mf << " tan</b></p>\n";
    htmlFile << "<table><tr><th>Tuyen</th><th>Luong / Tai trong</th><th>Trang thai</th></tr>\n";
    for (auto& e : edges) {
        htmlFile << "<tr><td>T" << e.u << " &rarr; T" << e.v << "</td>"
            << "<td>" << fl[e.u][e.v] << " / " << cap[e.u][e.v] << "</td><td>";
        if (fl[e.u][e.v] == cap[e.u][e.v] && cap[e.u][e.v] > 0)
            htmlFile << "<span style='color:#ef4444;font-weight:bold'>Day tai</span>";
        else htmlFile << "Binh thuong";
        htmlFile << "</td></tr>\n";
    }
    htmlFile << "</table></div>\n";
}

void endHTML(int mf) {
    htmlFile << "<div class='res'><p style='color:#94a3b8'>Luong cuc dai tu T"
        << src << " den T" << snk << "</p><p class='num'>" << mf
        << "</p><p style='color:#94a3b8'>tan</p></div>\n";
    htmlFile << "</body></html>";
    htmlFile.close();
}

// ═══ Run Algorithm ═══
void runAlgo(bool stepByStep) {
    if (!netOk) {
        cls();
        cout << RD << "\n  Chua co mang luoi! Hay tao truoc." << RST;
        pause(); return;
    }

    // Reset flow
    fl.assign(V, vector<int>(V, 0));
    algDone = false;
    maxFlowRes = 0;
    int step = 0;

    startHTML();
    dashboard();
    if (stepByStep) pause("Nhan Enter de bat dau...");

    while (bfs()) {
        int bn = (int)1e9;
        vector<int> path;
        int cur = snk;
        while (cur != src) {
            path.push_back(cur);
            int p = par[cur];
            bn = min(bn, cap[p][cur] - fl[p][cur]);
            cur = p;
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        cur = snk;
        while (cur != src) {
            int p = par[cur];
            fl[p][cur] += bn;
            fl[cur][p] -= bn;
            cur = p;
        }
        maxFlowRes += bn;
        step++;

        dashboard(path);
        cout << "\n  " << GR << BLD << ">> Duong tang luong #" << step << ": ";
        for (size_t i = 0; i < path.size(); i++)
            cout << "T" << path[i] << (i + 1 < path.size() ? " -> " : "");
        cout << RST << "\n";
        cout << "  " << GR << ">> Bottleneck = " << bn << " tan" << RST << "\n";
        cout << "  " << BLD << ">> TONG LUONG: " << maxFlowRes << " tan" << RST << "\n";

        logHTML(step, path, bn, maxFlowRes);

        if (stepByStep) pause("Nhan Enter cho buoc tiep...");
    }

    dashboard();
    endHTML(maxFlowRes);
    algDone = true;

    cout << "\n  " << string(50, '=') << "\n";
    cout << "  " << GR << BLD << "HOAN TAT! Luong cuc dai = " << maxFlowRes << " tan" << RST << "\n";
    cout << "  " << CY << "File HTML: Bao_cao_Logistics.html" << RST << "\n";
    cout << "  " << string(50, '=') << "\n";
    pause();
}

// ═══ Option 6: Export ═══
void exportHTML() {
    if (!algDone) {
        cls();
        cout << RD << "\n  Chua chay thuat toan! Hay chay truoc." << RST;
        pause(); return;
    }
    cls();
    cout << GR << BLD << "\n  File da duoc tao: Bao_cao_Logistics.html" << RST << "\n";
    cout << "  Mo file bang trinh duyet de xem bao cao.\n";
    pause();
}

// ═══ MAIN ═══
int main() {
    enableANSI();
    int choice = -1;
    do {
        showMenu();
        cin >> choice;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        switch (choice) {
        case 1: createNetwork(); break;
        case 2: loadPreset(); break;
        case 3: viewNetwork(); break;
        case 4: runAlgo(true); break;
        case 5: runAlgo(false); break;
        case 6: exportHTML(); break;
        case 0:
            cls();
            cout << CY << BLD << "\n  Cam on da su dung he thong!\n\n" << RST;
            break;
        default:
            cout << RD << "  Lua chon khong hop le!" << RST;
            pause();
        }
    } while (choice != 0);
    return 0;
}