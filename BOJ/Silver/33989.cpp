// 벚꽃과 단풍 - S3 - 2025/05/30

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
string s;
int main(){
    cin>>n>>s;
    vector<int>DP_B(n), DP_D(n);
    //DP_B : 왼쪽에서 모두 B가 되게 하기 위한 누적 변경 수
    //DP_D : 오른쪽에서 모두 D가 되게 하기 위한 누적 변경 수
    
    if(s[0]=='D') DP_B[0]=1;
    else DP_B[0]=0;
    for(int i=1; i<n ;i++){
        if(s[i]=='D') DP_B[i] = DP_B[i-1]+1;
        else DP_B[i] = DP_B[i-1];
    }
    
    if(s[n-1]=='B') DP_D[n-1]=1;
    else DP_D[n-1]=0;
    for(int i=n-2; i>=0;i--){
        if(s[i]=='B') DP_D[i] = DP_D[i+1]+1;
        else DP_D[i] = DP_D[i+1];
    }
    
    int ans = n;
    for(int i=0; i<=n-2; i++)
        ans = min(ans, DP_B[i] + DP_D[i+1]);
    
    ans = min(ans,min(DP_B[n-1],DP_D[0]));
    // 전체가 B로 바꾸거나 D로 바꾸는 경우도 고려
    cout<<ans<<endl;
}