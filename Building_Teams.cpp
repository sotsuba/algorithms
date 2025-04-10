/*
Link to problem: https://cses.fi/problemset/task/1668
*/

#include <iostream>
#include <vector>
#include <queue>

#define BLANK   -1

using std::cin, std::cout, std::vector, std::queue;

bool dfs(int s, vector<vector<int>> &adj, vector<int> &colors, int color) {
    if (colors[s] != BLANK) {
        return colors[s] == color;
    }
    colors[s] = color % 2;
    bool ans = true;
    for (auto v : adj[s]) 
        ans &= dfs(v, adj, colors, 1 - color);
    return ans;
}

bool bfs(int s, vector<vector<int>> &adj, vector<int> &colors) {
    colors[s] = 0;
    queue<std::pair<int,int>> q;
    q.push({s, 0});
    bool isBipartitie = true;
    while (q.empty() == false) {
        int u = q.front().first; 
        int color = q.front().second;
        q.pop();
        
        colors[u] = color;
        color = 1 - color;
        for (auto v : adj[u]) {
            if (colors[v] != BLANK) {
                isBipartitie &= colors[v] == color;
                continue;
            }
            q.push({v, color});
        }
    }
    return isBipartitie;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> colors(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isDivideable = true;
    for (int i = 0; i < n; i++) {
        // if (colors[i] == -1) isDivideable &= dfs(i, adj, colors, 0);
        if (colors[i] == -1) isDivideable &= bfs(i, adj, colors);
    }
    
    if (isDivideable == false) {
        cout << "IMPOSSIBLE\n";
    } 
    else {
        for (auto color : colors) cout << color + 1 << ' ';
    }
}