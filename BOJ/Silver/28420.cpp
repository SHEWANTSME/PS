// 카더가든 -S1 - 2023/07/31
// 미루다보니 8/3일에 풀게 되었는데 이미지랑 꼭 같이봐야 이해가 감
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
int n,m,a,b,c,ans=1e9;
int arr[301][301];
int main(){
    cin>>n>>m>>a>>b>>c;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            cin>>arr[i][j];
    // 누적합 계산
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            arr[i][j] = arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]+arr[i][j];
    // 1번 경우
    for(int i=a ; i<=n ; i++)
        for(int j=b+c;j<=m ; j++)
            ans=min(ans,arr[i][j]-arr[i-a][j]-arr[i][j-b-c]+arr[i-a][j-b-c]);
    // 2번 경우
    for(int i=a+c;i<=n ; i++)
        for(int j=a+b ; j<=m ; j++)// 뺄때 문자 잘못써서 시간 엄청 오래 걸렸음.. ㅠㅠ
            ans = min(ans,arr[i][j]-arr[i-c][j]-arr[i][j-a]+arr[i-c][j-a]+arr[i-c][j-a]-arr[i-c][j-a-b]-arr[i-a-c][j-a]+arr[i-c-a][j-a-b]);
    // 3번 경우
    for(int i=a+b ; i<=n ; i++)
        for(int j=a+c ; j<=m ; j++)
            ans = min(ans,arr[i][j]-arr[i][j-a]-arr[i-b][j]+arr[i-b][j-a]+arr[i-b][j-a]-arr[i-b][j-a-c]-arr[i-b-a][j-a]+arr[i-b-a][j-a-c]);
    cout<<ans<<endl;
}