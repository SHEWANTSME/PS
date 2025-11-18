//제설 작업 - G4 - 2025.11.18
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long
#define endl '\n'
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,m;
struct Edge{ // Edge 구조체
    int u, v; // 두 정점
    ll w;// 가중치
    bool flag; // connected or not
};
int main(){
    fastio;
    int n,m; cin>>n>>m;
    vector<vector<ll>> arr(n,vector<ll>(m)); // n by m arr grid
    ll tot = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            tot += arr[i][j];
        }
    }
    int nodes = n + m;
    vector<Edge> edges; // edge 정보 저장
    vector<ll> degree(nodes,0); // 행,열의 정점을 degree로 저장
    edges.reserve(n*m);// 최대 n*m개의 간선
    vector<vector<int>>adj_list(nodes);

    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            ll w = arr[i][j];
            int uu = i; 
            int vv = n + j; 
            edges.push_back({uu,vv,w,1});
            int idx = edges.size() - 1;
            degree[uu]+=w; degree[vv]+=w;
            adj_list[uu].push_back(idx);
            adj_list[vv].push_back(idx);
        }
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for(int i=0; i<nodes; i++) pq.push({degree[i],i});
    vector<bool> visited(nodes,0);
    ll ans = 0;
    while(not pq.empty()){
        auto [deg, v] = pq.top();pq.pop();// pair를 auto로 받을 때는 auto [first, second] 형태로 받을 수 있음
        if(visited[v]) continue;
        if(deg != degree[v]) continue;
        visited[v]=1;
        ans = max(ans,deg);

        for(auto &edge_idx : adj_list[v]){
            Edge &e = edges[edge_idx]; // struct name이 변수처럼 쓰이는거임
            if(not e.flag) continue;// flag=0이면 끊김 -> pass
            e.flag=0;
            int to = (e.u == v)? e.v : e.u;
            if(visited[to]) continue;
            degree[to]-=e.w;
            pq.push({degree[to], to});
        }
    }
    cout<<ans<<endl;
}