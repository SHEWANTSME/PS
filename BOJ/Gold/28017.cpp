// 게임을 클리어하자 - G5 - 2023/08/24
// dp인가 greedy인가 좀 헷갈렸음.. 
// greedy였으면 각 행에서 최소값만을 뽑았을때 전체 합도 최소가 무조건 된다는
// 증명을 하면 되는데, 그럴 기미가 보이지가 않아서 dp로 풀었음
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int arr[501][501];
int visited[501][501];
int dp[501][501];
int ans =1e9;

int main(){
    for(int i=1; i<=500; i++){
        for(int j=1; j<=500 ; j++){
            dp[i][j]=1e9;
        }
    }
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m ; j++)
            cin>>arr[i][j];  
    for(int i=1; i<=m; i++)
        dp[1][i]=arr[1][i];

    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1;k<=m;k++){
                if(k==j)continue;
                else dp[i][j]=min(dp[i][j],dp[i-1][k]+arr[i][j]);
            }
            //cout<<"i : "<<i<<" j : "<<j<<" dp[i][j] : "<<dp[i][j]<<endl;
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    //dp[2][1] =  dp[1][2]...dp[1][n] 중에 최소값 + arr[2][1];
    for(int i=1; i<=m;i++){
        ans = (ans<dp[n][i])? ans : dp[n][i];
        //cout<<dp[n][i]<<" ";
    }
    cout<<ans<<endl;
}