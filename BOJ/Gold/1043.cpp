//거짓말 - G4 - 2024/10/02
// graph traversal을 하면 풀릴듯
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[51][51];
vector<int>infected;
vector<int>node[51];
vector<int>chk[51];
int vis[51];
int n,m;
int inf_num;
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
            vis[k]=1;
        }
        for(int i=0;i<tmp.size();i++){
            for(int j=0;j<=n;j++){
                if(vis[j]==1){
                    //if(j==tmp[i])continue;
                    /*else*/ node[tmp[i]].push_back(j);
                }
            }
        }
        if(tmp.size()==1){
            node[tmp[0]].push_back(tmp[0]);
        }
        for(int i=0;i<=n;i++)vis[i]=0;
    }

    // for(int i=0;i<=50;i++){
    //     if(not node[i].empty()){
    //         cout<<" node " <<i<<endl;
    //         for(auto &e: node[i]){
    //             cout<<e<<" ";
    //         }cout<<endl;
    //     }
    // }
    for(int i=0;i<=50;i++){
        if(not node[i].empty()){
            for(auto &k : infected){
                bool flag=0;
                for(auto &e : node[i]){
                    if(flag){
                        vis[e]=1;
                    }
                    if(e==k){
                        vis[e]=1;flag=1;
                    }
                }
            }
            // for(auto &e : node[i]){
            //     for(auto &k : infected){
            //         if(e==k)vis[e]=1;
            //     }
            // }
        }
    }
    int cnt =0;
    for(int i=0;i<50;i++){
        if(vis[i]==1)cout<<i<<endl;
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<chk[i].size();j++){
    //         cout<<chk[i][j]<<" ";
    //     }cout<<endl;
    // }
    for(int i=0;i<m;i++){
        // for(int j=0;j<chk[i].size();j++){
        //     if(vis[chk[i][j]]==1){
        //         cout<<"rr"<<vis[chk[i][j]]<<" ";
        //     }cout<<endl;
        // }
        bool flag=0;
        for(auto &e : chk[i]){
            if(flag)continue;
            if(vis[e]==1){
                flag=1;
                //cnt++;
            }
        }
        if(flag)cnt++;
    }

    if(inf_num==0){
        cout<<m<<endl;exit(0);
    }
    else{
        cout<<m-cnt<<endl;
    }
}

/*
4 3
0
2 1 2
1 3
3 2 3 4

3

8 5
3 1 2 7
2 3 4
1 5
2 5 6
2 6 8
1 8

5
*/