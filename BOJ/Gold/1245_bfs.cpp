#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int cnt = 0;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int arr[101][71];
int vis[101][71];

void check(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    int now = arr[x][y];
    bool flag = true; // 봉우리 확인
    while (not q.empty()) {
        auto e = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = e.first + dx[i];
            int ny = e.second + dy[i];
            if(nx<1 or ny<1 or nx>n or ny>m)continue;
            if (arr[nx][ny] > now) {
                flag=0;  // 더 높은 곳이 있으면 봉우리가 아님
            } 
            else if (arr[nx][ny] == now and not vis[nx][ny]) {
                vis[nx][ny] = 1;  // 같은 높이의 지역을 방문 처리
                q.push({nx, ny});  // 큐에 추가하여 BFS 탐색
            }
        }
    }
    if(flag) cnt++;  // 봉우리인 경우에만 카운트 증가
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> arr[i][j];
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if (not vis[i][j]) 
                check(i, j);

    cout << cnt << endl;
}
