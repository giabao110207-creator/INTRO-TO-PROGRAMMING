// ĐỒ THỊ TRỌNG SỐ.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
-Họ và tên: Nguyễn Hoàng Gia Bảo 
-MSSV: 25AD11003
-Ngày cập nhật: 26/03/2026
-Công dụng: Biểu diễn đồ thị trọng số bằng Krusal hoặc Prim's
*/

#include <iostream>     // cin, cout
#include <vector>       // vector
#include <algorithm>    // sort
#include <queue>        // priority_queue
#include <functional>   // greater<>
using namespace std;

struct Edge {
    int u, v, w;
};

int n, m;
vector<Edge> edges;       //Danh sách cạnh (Dùng cho krusal)
vector<pair<int, int>> adj[1005]; //Danh sách kề {weight, vertex}

// ======================= DSU cho Kruskal =======================
int parent[1005];

//Mỗi đỉnh là 1 tập 
void make_set() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

//Gốp hai tập lại với nhau 
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

// ======================= KRUSKAL =======================
void kruskal() {
    make_set();
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
        });

    int mst_weight = 0;     //Tổng trọng số MST 
    vector<Edge> mst;

    for (auto e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            union_set(e.u, e.v);       //Gộp lại 
            mst.push_back(e);          //Thêm vào MST 
            mst_weight += e.w;         //Cộng trọng số 
        }
    }

    cout << "\n=== KRUSKAL ===\n";
    cout << "Trong so MST: " << mst_weight << endl;
    cout << "Cac canh:\n";
    for (auto e : mst) {
        cout << e.u << " - " << e.v << " : " << e.w << endl;
    }
}

// ======================= PRIM =======================
void prim() {
    vector<bool> visited(n + 1, false);        //Đánh dấu đỉnh đã chọn 
    //Luôn lấy cạnh có trọng số nhỏ nhất 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, 1 }); // bắt đầu từ đỉnh 1
    int mst_weight = 0;

    cout << "\n=== PRIM ===\n";

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int w = top.first;
        int u = top.second;

        if (visited[u]) continue;

        visited[u] = true;
        mst_weight += w;

        cout << "Chon dinh " << u << " voi trong so " << w << endl;

        //Duyệt các đỉnh kề 
        for (auto x : adj[u]) {
            int weight = x.first;
            int v = x.second;
            if (!visited[v]) {
                pq.push({ weight, v });
            }
        }
    }

    cout << "Trong so MST: " << mst_weight << endl;
}

// ======================= MAIN =======================
int main() {
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    edges.resize(m);

    cout << "Nhap cac canh (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

        // cho Prim
        adj[edges[i].u].push_back({ edges[i].w, edges[i].v });
        adj[edges[i].v].push_back({ edges[i].w, edges[i].u });
    }

    int choice;
    cout << "\nChon thuat toan:\n";
    cout << "1. Kruskal\n";
    cout << "2. Prim\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    if (choice == 1) {
        kruskal();
    }
    else if (choice == 2) {
        prim();
    }
    else {
        cout << "Lua chon khong hop le!\n";
    }

    return 0;
}