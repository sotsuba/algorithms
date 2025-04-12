/*
Link to problem: https://cses.fi/problemset/task/1192
*/
#include <iostream>
#include <vector>
#include <queue>

using std::cin, std::cout, std::vector, std::queue, std::pair;

vector<int> dx = {1, 0, -1,  0};
vector<int> dy = {0, 1,  0, -1};

bool inRange(int x, int y, vector<vector<int>> &matrix) {
    return (0 <= x && x < matrix.size() && 0 <= y && y < matrix[0].size());
}

void dfs(int x, int y, vector<vector<int>> &matrix) {
    if (inRange(x, y, matrix) == false || matrix[x][y] == 0) return;
    matrix[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], matrix);
    }
}

void bfs(int x, int y, vector<vector<int>> &matrix) {
    queue<pair<int,int>> q;
    matrix[x][y] = 0;
    q.push({x, y});
    while(q.empty() == false) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (inRange(n_x, n_y, matrix) == false || matrix[n_x][n_y] == 0) continue;
            matrix[n_x][n_y] = 0;    
            q.push({n_x, n_y});
        }
    } 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') matrix[i][j] = 1;
        }
    }

    int countingRoom = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                countingRoom++;
                // dfs(i, j, matrix);
                bfs(i, j, matrix);
            }
        }
    }
    cout << countingRoom << '\n';
}
