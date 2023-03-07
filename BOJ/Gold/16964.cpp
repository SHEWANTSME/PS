// DFS 스페셜저지 - G3 - 2023/03/07
// find how DFS's visiting way is valid or not

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;
int n; // 노드 갯수
vector<int>v[100001];
vector<int>chk;
vector<int>temp;
int visited[100001];
void DFS(int x){
    if(visited[x])return;
    visited[x]=1;
    cout<<x<<" ";
    for(auto &e : v[x]){
        if(not visited[e]){
            DFS(e);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1 ; i<n ; i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1; i<=n; i++){
        int t;cin>>t;chk.push_back(t);
    } // 여기서 나오는 예상 결과를 바탕으로 어떤 노드부터 방문할지 볼 수 있음! 이게 이 문제의 핵심
    

    for(int i=1; i<=n ; i++){ // 근데 이러면 누가봐도 시간초과..
        if(v[i].size()>=2){
            deque<int>dq;
            for(auto &e : v[i]){
                dq.push_back(e);
            }
            int x = dq.front();
            dq.pop_front();
            dq.push_back(x);
            for()
        }
    }
    DFS(1);
}