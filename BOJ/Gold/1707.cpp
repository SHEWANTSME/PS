// 이분 그래프 - 2024/11/12
// bipartite graph는 graph coloring을 통해 판별할 수 있다.
// https://www.geeksforgeeks.org/bipartite-graph/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int tc;
vector<int>node[20001];
int vis[20001];
// void Combination(vector<int>v , vector<int>res , int r , int idx, int depth){
//     if(r==0){
//         for(auto &e : res){
//             cout<<e<<" ";
//         }cout<<endl;
//     }
//     else if(depth == v.size()) return;
//     else{
//         // v[depth]를 뽑은 경우
//         res[idx]=v[depth];
//         Combination(v,res,r-1,idx+1,depth+1);
//         // 안뽑은 경우
//         Combination(v,res,r,idx,depth+1);
//     }
// }
int check_bipartite(int Node){
    vis[Node]=1;
    queue<int>q;
    q.push(Node);
    while(not q.empty()){
        int now = q.front();
        //flag = vis[now];
        q.pop();
        for (auto &e : node[now]) {
            if (vis[e] == vis[now]) return 0; // 같은 색이면 bipartite가 아님
            if (!vis[e]) {
                vis[e] = -vis[now];
                q.push(e);
            }
        }

        //flag*=-1; -> 이걸 쓰면 error가 나왔음
    }
    return 1;
}
int main(){
    // vector<int>v = {1,2,3};
    // for(int i=1; i<=3; i++){
    //     vector<int>comb(i);
    //     Combination(v, comb,i,0,0);
    // }
    cin>>tc;
    while(tc--){
        int vertex,edge;
        cin>>vertex>>edge;
        for(int k=0;k<edge;k++){
            int n1,n2;
            cin>>n1>>n2;
            node[n1].push_back(n2);
            node[n2].push_back(n1);
        }
        vector<int>ans;
        for(int i=1;i<=vertex;i++){
            if(!vis[i]) ans.push_back(check_bipartite(i));
        }
        bool flag=0;
        for(auto &e : ans){
            if(flag)break;
            if(e==0)flag=1;
        }
        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        // bool ans = check_bipartite(1);
        // if(ans)cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
        // for(int i=1;i<=5;i++){
        //     cout<<vis[i]<<endl;
        // }
        for(int i=0;i<=20000;i++){node[i].clear();vis[i]=0;}
    }
}