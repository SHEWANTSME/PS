// 쿠키런 - S3 - 2025.05.27
// 그냥 그리디로 하면 되는데 굳이 DP로 했네..?
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define endl "\n"
using namespace std;
int n, j, s, h, k;
char arr[3][101];
int dp[101][101][101];

int main() {
    fastio;
    cin>>n>>j>>s>>h>>k;
    
    for (int i=0; i<3; i++) {
        string ss; cin >> ss;
        for (int jj=0; jj<n; jj++) {
            arr[i][jj] = ss[jj];
        }
    }

    for (int i=0; i<=n; i++) 
        for (int jj=0; jj<=j; jj++) 
            for (int ss=0; ss<=s; ss++) 
                dp[i][jj][ss] = -1;

    dp[0][0][0] = h;
    for (int i=0; i<n; i++) {
        char now_1 = arr[0][i];
        char now_2 = arr[1][i];
        char now_3 = arr[2][i];

        for (int jj=0; jj<=j; jj++) {
            for (int ss=0; ss<=s; ss++) {
                int tmp = dp[i][jj][ss]; // 현재 체력
                if (tmp<0) continue;   // 불가능 상태
                if ((now_1 == '.' and now_2 == '.') and now_3 == '.') {
                    dp[i+1][jj][ss] = max(dp[i+1][jj][ss], tmp);continue;
                }
                if ((now_1 == '.' and now_2 == '^') and now_3 == '^') {
                    if (jj+2<=j) dp[i+1][jj+2][ss] = max(dp[i+1][jj+2][ss], tmp);
                    if (tmp > k) dp[i+1][jj][ss] = max(dp[i+1][jj][ss], tmp-k);
                    continue;
                }

                if ((now_1 == '.' && now_2 == '.') && now_3 == '^') {
                    if (jj+1<=j) dp[i+1][jj+1][ss] = max(dp[i+1][jj+1][ss], tmp);
                    if (tmp > k) dp[i+1][jj][ss] = max(dp[i+1][jj][ss], tmp-k);
                    continue;
                }

                if ((now_1 == 'v' && now_2 == 'v') && now_3 == '.') {
                    if (ss+1<= s) dp[i+1][jj][ss+1] = max(dp[i+1][jj][ss+1], tmp);
                    if (tmp > k) dp[i+1][jj][ss] = max(dp[i+1][jj][ss], tmp-k);
                    continue;
                }
            }
        }
    }

    bool flag = 1;
    int max_health = -1;
    for (int jj = 0; jj <= j; jj++) {
        for (int ss = 0; ss <= s; ss++) {
            if (dp[n][jj][ss] >= 0) {
                flag = 0;
                max_health = max(max_health, dp[n][jj][ss]);
            }
        }
    }

    if(flag) cout<<-1<<endl;
    else cout<<max_health<<endl;
}