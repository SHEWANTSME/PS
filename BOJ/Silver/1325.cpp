// 효율적인해킹 - S1 - 2023/02/22
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pp pair<int,int>
using namespace std;
int n,m;
vector<int>v[10000];// 이거를 10001로 했어야 bad_alloc이 안걸리겠지?
// 괜히 이것때문에 30분 버림
int vis[10001];
priority_queue<pp,vector<pp>, greater<pp>>pq;
// 뭔가 pq쓰면 될거같은데 -> 마지막에 sort를 하든가 애초에 pq로 넣던가 하면 풀릴듯
int cnt =0;
int mx= -1;
void DFS(int num){
    vis[num]=1;
    for(auto &x : v[num]){
        if(vis[x])continue;
        cnt++;
        // cout<<x<<" "; -> DFS가 어떻게 돌아가는지 보고싶으면 이렇게 찍어보면 좋다.
        DFS(x);
        
    }
    //cout<<num << " " <<cnt << endl;
    //pq.push(cnt);
    return;
}
int main(){
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int a,b;cin>>a>>b;
        v[b].push_back(a);
    }
   for(int i=1 ; i<=n ; i++){
    DFS(i);
    mx = (mx>cnt)?mx:cnt;
    pq.push({cnt,i});
    //cout<<i<< " " <<cnt << endl;
    for(int j=0;j<=10000;j++)vis[j]=0;
    cnt=0;
   }
   while(not pq.empty()){
    int x  = pq.top().second;
    int y = pq.top().first;
    if(y==mx) cout<<x<<" ";
    pq.pop();
   }
}

// 처음에는 말을 어렵게 써둬서 무슨말인지 했는데
// 하나씩 그려보면서 따져가면 이건 DFS문제구나 하고 이해가 감
// Check each node(virus) that can go as far as it can be 

