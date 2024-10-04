//거짓말 - G4 - 2024/10/02
// graph traversal을 하면 풀릴듯 -> BFS로 하니 풀림
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>infected; 
vector<int>node[51]; // node
vector<int>chk[51];// 감염여부 for final cnt
int vis[51]; // for BFS
int n,m;
int inf_num;
void BFS(){
    queue<int> q;
    for(auto &e : infected){
        q.push(e); // 초기 감염자 push
        vis[e]=1;
    }
    while (not q.empty()){// 초기 감염자가 fix된 상태에서 
    // graph상의 변화만 바꿔주면됨
        int now=q.front();
        q.pop();
        for (auto &nxt : node[now]) {
            if (not vis[nxt]) { 
                vis[nxt]=1;
                q.push(nxt);
            }
        }
    }
}
int main(){
    cin>>n>>m>>inf_num;
    if(inf_num!=0){
        for(int i=0;i<inf_num;i++){
            int t;cin>>t;infected.push_back(t);
        }
    }
    for(int p=0; p<m;p++){
        int t;cin>>t;
        vector<int>tmp;
        for(int i=0;i<t;i++){
            int k; cin>>k;
            tmp.push_back(k);
            chk[p].push_back(k);
        }
        for(auto &e : tmp){
            for(auto &k : tmp){
                if(e!=k)node[e].push_back(k);
            }
        }
    }
    BFS();
    // 조건에 맞게 풀면 됨
    int cnt=0;
    for(int i=0; i<m; i++){
        bool flag=0;
        for(auto &e : chk[i]){
            if(vis[e]){
                flag=1;break;
            }
        }
        if(!flag)cnt++;
    }
    cout<<cnt<<endl;
}
