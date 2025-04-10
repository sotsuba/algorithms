/*
Link to problem: https://cses.fi/problemset/task/1668
*/

#include <iostream>
#include <vector>
#include <queue>

using std::cin, std::cout, std::vector, std::queue;

void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited, int &count) {
    if (visited[s]) return;
    visited[s] = true;
    count++;
    for (auto v : adj[s]) 
        dfs(v, adj, visited, count);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_1(n), adj_2(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj_1[--u].push_back(--v);
        adj_2[v].push_back(u);
    }

    vector<bool> visited_1(n), visited_2(n);
    int count_1 = 0, count_2 = 0;
    dfs(0, adj_1, visited_1, count_1);
    dfs(0, adj_2, visited_2, count_2);
    // for (int i = 0; i < n; i++) cout << visited_1[i] << " \n"[i==n-1];
    // for (int i = 0; i < n; i++) cout << visited_2[i] << " \n"[i==n-1];
    for (int i = 0; i < n; i++) {
        if (visited_1[i] == false) {
            cout << "NO\n";
            cout << 1 << ' ' << i + 1 << '\n';
            return 0;
        }
        if (visited_2[i] == false) {
            cout << "NO\n";
            cout << i + 1 << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES\n";
}