// Four Squares - S3 - 2023/04/12
// 처음 풀이는 시간초과라서 딱봐도 안될것 같았음.
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int dp[50001];
int main(){
    cin >> n;
    dp[1]=1;dp[2]=2;dp[3]=3;dp[4]=1;
    for (int i = 5; i <= n; i++){
        dp[i] = dp[i-1]+1; // 일단 이걸 디폴트로 깔아두고
        for (int j = 2; j * j <= i; j++){ //i보다 작은 제곱값을 
            // n=12면 -> 11 + 1, 10+2 , 9+3, 8+4 ..
            dp[i] = min(dp[i], 1 + dp[i - j * j]);// 비교해봐라~
        }
    }
    cout << dp[n]<<endl;
}
