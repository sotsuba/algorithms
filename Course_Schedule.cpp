/*
Link to problem: https://cses.fi/problemset/task/1679
*/
#include <iostream>
#include <vector>
#include <queue>

using std::vector, std::cin, std::cout, std::queue;

#define BLANK       0
#define IN_PROGRESS 1
#define COMPLETED   2

void dfs(int s, vector<int> &status, vector<vector<int>> &adj, vector<int> &ans, bool &hasCycle) {
    if (status[s] == IN_PROGRESS) {
        hasCycle = true;
        return;
    }
    if (hasCycle || status[s] == COMPLETED) return;
    status[s] = IN_PROGRESS;
    for (auto v : adj[s]) 
        dfs(v, status, adj, ans, hasCycle);
    ans.push_back(s);
    status[s] = COMPLETED;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vector<int> status(n, BLANK), ans;
    bool hasCycle = false;
    for (int i = 0; i < n && hasCycle == false; i++) {
        if (status[i] == BLANK) dfs(i, status, adj, ans, hasCycle);
    }

    if (hasCycle) puts("IMPOSSIBLE");
    else {
        for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1  << ' ';
    }
}
