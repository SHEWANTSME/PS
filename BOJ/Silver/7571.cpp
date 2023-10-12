//점모으기 - S1- 2023/10/12
//임의의 (x,y)까지의 최솟값을 구하기 위해 x,y를 정렬한 후 중간값을 구하면 되는데,
// x,y는 각각 independent하고 절댓값 그래프를 그려보고 최솟값을 찾아보면
// 중간값과 관련이 있구나를 알 수 있음
#include<iostream>
#include<algorithm>
#include<vector>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,m;
vector<int>x;
vector<int>y;
int main(){
    fastio;
    cin>>n>>m;
    int nm = m;
    while(m--){
        int a,b;cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int nx = x[nm/2];//중간값
    int ny= y[nm/2];//중간값
    int len=0;
    for(int i=0;i<x.size();i++){
        len+=(abs(x[i]-nx) + abs(y[i]-ny));//중간값과의 거리의 합
    }
    cout<<len<<"\n";
}
//틀린풀이 - bruteforce로 풀면 시간초과남 
#include<iostream>
#include<algorithm>
#include<vector>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,m;
int minn = 1e9;
vector<pair<int,int>>v;
int main(){
    fastio;
    cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n; j++){
            int len =0;
            for(int k=0;k<v.size();k++){
                int x= v[k].first;
                int y= v[k].second;
                len +=(abs(x-i) + abs(y-i));
            }
            minn =min(len, minn);
        }
    }
    cout<<minn<<"\n";
}
