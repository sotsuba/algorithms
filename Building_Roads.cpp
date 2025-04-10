#include <iostream>
#include <vector>
#include <queue>

using std::vector, std::cin, std::cout, std::queue;


void readInput(int &n, int &m, vector<vector<int>> &adj) {
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int s, const vector<vector<int>> &adj, vector<bool> &visited) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto v : adj[s]) 
        dfs(v, adj, visited); 
}

void bfs(int s, const vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

int main() {
    int n, m;
    vector<vector<int>> adj;
    readInput(n, m, adj);
    vector<bool> visited(n, false);

    vector<int> parentList;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, adj, visited);
            parentList.push_back(i + 1);
        } 
    }
    cout << parentList.size() - 1<< '\n';
    for (int i = 1; i < parentList.size(); i++) {
        cout << parentList[i - 1] << ' ' << parentList[i] << '\n'; 
    }
}