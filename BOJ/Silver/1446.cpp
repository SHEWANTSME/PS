// 지름길- S1 - 2023/06/26
#include<iostream>
#include<algorithm>
#include<vector>
#define ff first
#define sc second
int dp[10001];
using namespace std;
vector<pair<pair<int, int>, int>>v;
int n,d;
int main(){
    cin>>n>>d;
    for(int i=0;i<=10000;i++)dp[i]=1e9;//최소값이니까
    dp[0]=0;// 거리 차이가 없을땐 0
    for(int i=0 ; i<n ; i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({{a,b},c});// 싹다 v에 넣고
    }    
    for(int i=0; i<d;i++){
        dp[i+1]=min(dp[i+1],dp[i]+1);// dp[0]=0으로 해뒀으니까
        for(auto &[x,y] : v){
            // 이게 구조적 바인딩이란 기법인데 c++17부터쓸 수 있음
            int a= x.ff;
            int b=x.sc;
            int c=y;// 기존에 사용하던것과 크게 다르진 않은데, [a,b] 이상으로
            //auto &[a,b,c,d] : v 이런식으로는 쓸 수 없음..
            if(a==i and b<=d)dp[b]=min(dp[b],dp[i]+c);// b<=d도 되네 보니까
        }
    }
    
    cout<<dp[d]<<endl;
}