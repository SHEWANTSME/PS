//ABCDE - G5 - 2024/12/31
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int>v[2001];
int vis[2001];
bool flag=0;
void Recur(int st , int cnt){
    int now = st;
    if(flag)return;
    if(cnt==6){
        flag=1;
        return;
    }
    if(vis[now]){
        return;
    }
    vis[now]=1;
    for(auto &e : v[now]){
        Recur(e,cnt+1);
    }
    vis[now]=0;
    cnt-=1;
}
int main(){
    cin>>n>>m;
    while(m--){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=2000;j++)vis[j]=0;
        Recur(i,1);
        if(flag==1){cout<<1<<endl;exit(0);}
    }
    cout<<0<<endl;
}