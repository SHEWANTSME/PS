// 여행가자 - G4 - 2025.06.27
// union-find로 풀린다는데, 걍 bfs로 해봤음
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n,m;
vector<int>city[201];
vector<int>plan;
int vis[201];
int main(){
    cin>>n>>m;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            int t; cin>>t;
            if(t==1){
                bool flag=0;
                for(auto &e : city[i]){
                    if(e == j){flag=1;break;}
                }
                if(!flag) city[i].push_back(j);
                flag=0;
                for(auto &e : city[j]){
                    if(e == i){flag=1;break;}
                }
                if(!flag) city[j].push_back(i);
            }
        }
    }
    for(int i=1; i<=m; i++){
        int t; cin>>t;
        plan.push_back(t);
    }
    if(m==1){
        if(city[plan[0]].empty()){cout<<"NO"<<endl;}
        else cout<<"YES"<<endl;
    }
    if(m==2){
        int cit1 = plan[0];
        int cit2= plan[1];
        queue<int>q;
        q.push(cit1);
        //vis[cit1]=1;
        bool fflag=0;
        while(not q.empty()){
            int city_st = q.front();
            if(vis[city_st]==1){q.pop();continue;}
            if(vis[city_st]==0){vis[city_st]=1;q.pop();}
            for(auto&e : city[city_st]){
                if(e == cit2){fflag=1;break;}
                q.push(e);
            }
            if(fflag)break;
        }
        if(fflag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    if(m>=3){
        int cit1= plan[0];
        queue<int>q;
        q.push(cit1);
        vis[cit1]=1;
        while(not q.empty()){
            int x = q.front();
            q.pop();
            for(auto&e : city[x]){
                if(vis[e])continue;
                q.push(e);
                vis[e]=1;
            }
        }
        for(int i=0 ; i<m; i++){
            if(vis[plan[i]] == 0){
                //cout<<i<<" "<<plan[i]<<" "<<endl;
                cout<<"NO"<<endl;
                exit(0);
            }
        }
        cout<<"YES"<<endl;
    }
    
}