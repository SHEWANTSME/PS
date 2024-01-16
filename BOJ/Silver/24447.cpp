//알고리즘 수업 - 너비 우선 탐색 4 - S2 - 2024/01/17
//1번 + 4번 MIX
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,m,r;
vector<int>arr[100001];
vector<int>arr2[100001];
int vis[100001];
int vis2[100001];
int main(){
    fastio;
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        arr[u].push_back(v);arr[v].push_back(u);
        arr2[u].push_back(v);arr2[v].push_back(u);
    }
    queue<int>q;
    deque<int>dq;
    while(not arr2[r].empty()){
        int nxt = arr2[r].back();
        arr2[r].pop_back();
        dq.push_front(nxt);
    }
    vis2[r]=1;
    sort(dq.begin(),dq.end());
    int pre=1;
    int now2;
    while(not dq.empty()){
        now2 = dq.front();dq.pop_front();
        if(vis2[now2]>=1)continue;
        pre++;
        vis2[now2]=pre;
        deque<int>temp;
        while(not arr2[now2].empty()){
            int nxt = arr2[now2].back();
            arr2[now2].pop_back();
            temp.push_front(nxt);
        }
        sort(temp.begin(),temp.end());
        while(not temp.empty()){
            int nxt = temp.front();temp.pop_front();
            dq.push_back(nxt);
        }
    }
    q.push(r);
    vis[r]=1;
    while(not q.empty()){
        int now = q.front();q.pop();
        for(auto &e:arr[now]){
            if(vis[e]>=1)continue;
            vis[e]=vis[now]+1;
            q.push(e);
        }
    }
    int ans =0;
    for(int i=1;i<=n;i++)
        ans+=((vis[i]-1)*vis2[i]);
    cout<<ans<<"/n";
}