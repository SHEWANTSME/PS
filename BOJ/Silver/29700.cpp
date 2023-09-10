//우당탕탕 영화예매 - S4 - 2023/09/09
#include<iostream>
#include<vector>
using namespace std;
char arr[1001][5001];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int emp_cnt = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '0') {
                emp_cnt++;
                if (emp_cnt >= k) ans++;
            } 
            else emp_cnt = 0;
        }
    }
    cout << ans << endl;
}