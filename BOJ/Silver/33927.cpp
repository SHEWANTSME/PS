//나이트 오브 나이츠 - S2 - 2025.05.21
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[5][5];
int ans = 0;
bool visited[5][5];

// 나이트의 이동 방향 (8가지)
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 현재 위치에서 나이트가 이동할 수 있는 위치들을 체크
bool canPlace(int x, int y) {
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && visited[nx][ny]) {
            return false;
        }
    }
    return true;
}

void backtrack(int x, int y, int sum) {
    if(x > n) {
        ans = max(ans, sum);
        return;
    }
    
    int nextX = x;
    int nextY = y + 1;
    if(nextY > n) {
        nextX = x + 1;
        nextY = 1;
    }
    
    // 현재 위치에 나이트를 놓을 수 있는 경우
    if(canPlace(x, y)) {
        visited[x][y] = true;
        backtrack(nextX, nextY, sum + arr[x][y]);
        visited[x][y] = false;
    }
    
    // 현재 위치에 나이트를 놓지 않는 경우
    backtrack(nextX, nextY, sum);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    
    backtrack(1, 1, 0);
    cout << ans << endl;
    
    return 0;
}