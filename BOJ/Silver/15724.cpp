// 주지수 - S1 - 2023/08/20
// endl이랑 fastio 껴야 풀리넹.. 안하면 시간초과났었음
// 그냥 그동안 했던 누적합 개념 써먹으면 풀림
#include<iostream>
#include<algorithm>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define endl "\n"
using namespace std;
int n,m,k;
ll arr[1025][1025];
ll sum[1025][1025];
int main(){
    fastio;
    cin>>n>>m;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m;j++)
            cin>>arr[i][j];
    cin>>k;
    sum[1][1]=arr[1][1];
    for(int i=2; i<=n;i++)
        sum[i][1]=sum[i-1][1]+arr[i][1];
    for(int i=2; i<=m;i++)
        sum[1][i]=sum[1][i-1]+arr[1][i];
    for(int i=2; i<=n ; i++){
        for(int j=2; j<=m; j++){
            sum[i][j]=arr[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    while(k--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<endl;
    }
}