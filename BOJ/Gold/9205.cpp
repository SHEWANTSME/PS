// 맥주 마시면서 걸어가기 - G5 - 2025.07.01
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int tc; 
int ans;
void DFS(int &x, int &y, vector<pair<int,int>>&v, map<pair<int, int>, int>&vis, int &rock_x, int &rock_y){
    for(int i=0; i<v.size();i++){
        if(ans) return;
        int nx = v[i].first;
        int ny= v[i].second;
        if(vis.find({nx,ny})!=vis.end())continue;
        int dist = abs(x-nx) + abs(y-ny);
        if(dist<=1000){
            vis.insert({{nx,ny},1});
            DFS(nx,ny,v,vis,rock_x,rock_y);
        }
    }
    if(abs(x-rock_x) + abs(y-rock_y)<=1000){
        ans=1;
        return;
    }
}
int main(){
    cin>>tc;
    while(tc--){
        ans=0;
        int conv_cnt; cin>>conv_cnt;
        int home_x, home_y; cin>>home_x>>home_y;
        vector<pair<int,int>>v;
        for(int i=0; i<conv_cnt;i++){
            int x,y; cin>>x>>y;
            v.push_back({x,y});
        }
        int rock_x, rock_y; cin>>rock_x>>rock_y;
        map<pair<int,int>,int>vis;
        vis.insert({{home_x,home_y},1});
        DFS(home_x,home_y, v, vis, rock_x, rock_y);
        if(ans)cout<<"happy"<<endl;
        else cout<<"sad"<<endl;
    }
}