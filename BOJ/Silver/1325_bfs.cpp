// 효율적인해킹 - S1 - 2023/02/22
// 이번엔 BFS로 풀어보도록 하자
// layer별로 쌓인다는게 이해가 되면 된다.
// 현재노드가 갈수있는 모든경우 먼저 살피고+ 다음노드들중에 갈 수 있는 모든경우 먼저 ~~
// DFS랑 생각하는거 자체가 다르쥬
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
vector<int>ans;
priority_queue<pp,vector<pp>, greater<pp>>pq;
int cnt=0;
int mx = -1;
queue<int>q;
int main(){
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int a,b;cin>>a>>b;
        v[b].push_back(a);
    }
    for(int i=1 ; i<=n ; i++){
        q.push(i);// 아니 이거까지 해놓구
        vis[i]=1;// 어떻게 이걸
        cnt++;// 까먹을수고 있죠? 멍청대갈
        while(not q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto &e : v[now]){
            if(vis[e])continue;
            
            vis[e]=1;
            cnt++;
            q.push(e);
        //cout<<" 안에서 "<<e << " "<< cnt << " "<< now << endl;
        }
    }
    if (mx < cnt) {
            ans.clear();
            mx = cnt;
            ans.push_back(i);

        } else if (mx == cnt) {
            ans.push_back(i);
        }
   // cout<<i<<" "<<cnt<<endl;
    //mx = (mx>cnt)?mx:cnt;
   // pq.push({cnt,i});
    for(int j=0 ; j<=10000;j++)vis[j]=0;
    cnt=0;
    }
    sort(ans.begin(),ans.end());
     for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    // while(not pq.empty()){
    //     int x  = pq.top().second;
    //     int y = pq.top().first;
    //     cout << x << " " << y<<" "<<mx <<endl;
    //     //if(y==mx) cout<<x<<" ";
    //     pq.pop();
    // }
}

// 처음에는 말을 어렵게 써둬서 무슨말인지 했는데
// 하나씩 그려보면서 따져가면 이건 DFS문제구나 하고 이해가 감
// Check each node(virus) that can go as far as it can be 
