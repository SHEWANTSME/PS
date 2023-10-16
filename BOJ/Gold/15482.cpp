//한글 LCS - G5 - 2023/10/16
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string a,b;
int dp[1002][1002];
// 한글을 위한 LCS는 3글자씩 비교해야한다.
// vs는 2바이트, g++은 3바이트
// 
int main(){
    cin>>a>>b;
    for(int i=3; i<=a.size();i+=3){
        for(int j=3;j<=b.size();j+=3){
            if(a.substr(i-3,3) == b.substr(j-3,3)){
                // 알파벳이랑 한글이랑 달라서 
                // 기존엔 if(a[i-1]==b[j-1]) 이렇게 했는데 지금은 substr써서 byte수 만큼 비교해야함
                //cout<<a.substr(i-1,3)<<" "<<b.substr(j-1,3)<<endl;
                dp[i][j]=dp[i-3][j-3]+1;// 이전값에서 1을 더해줌
            }
            // if(a[i-1]==b[j-1]){
            //     cout<<a.substr(i-1,3)<<" "<<b.substr(j-1,3)<<endl;
            //     //cout<<a[i-1]<<" "<<b[j-1]<<endl;    
            //     dp[i][j]=dp[i-1][j-1]+1;
            // }
            else dp[i][j]=max(dp[i-3][j],dp[i][j-3]);// 이전값중 큰값을 저장
        }
    }
    for(int i=0;i<a.size();i+=3){
        for(int j=0;j<b.size();j+=3){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[a.size()][b.size()]<<endl;// 마지막값 출력
}