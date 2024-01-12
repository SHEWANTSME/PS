//알고리즘 수업 - 너비 우선 탐색 1 - S2 - 2024/01/10
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
int n,m,r;
vector<int>arr[100001];
int vis[100001];
int main(){
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    //queue<int>q;
    priority_queue<int, vector<int>, greater<int> > q;
    deque<int>dq;
    while(not arr[r].empty()){
        int nxt = arr[r].back();
        arr[r].pop_back();
        dq.push_front(nxt);
    }
    vis[r]=1;
    sort(dq.begin(),dq.end());
    int pre=1;
    int now;
    while(not dq.empty()){
        now = dq.front();dq.pop_front();
        if(vis[now]>=1)continue;
        pre++;//1->2
        vis[now]=pre;// vis[2]=2
        deque<int>temp;
        while(not arr[now].empty()){
            int nxt = arr[now].back();//
            arr[now].pop_back();
            temp.push_front(nxt);
        }
        sort(temp.begin(),temp.end());
        while(not temp.empty()){
            int nxt = temp.front();temp.pop_front();
            dq.push_back(nxt);
        }

    }
    for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";
    }
}