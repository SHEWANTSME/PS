#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int cnt =0;
void DFS(int k, int depth, vector<bool>&vis ,vector<vector<int>> &dungeons){
    cnt=max(cnt,depth);
    for(int i=0; i<dungeons.size(); i++){
        if(vis[i])continue;
        if(k<dungeons[i][0])continue;
        vis[i]=1;
        DFS(k-dungeons[i][1],depth+1,vis,dungeons);
        vis[i]=0;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> vis(dungeons.size(),0);
    DFS(k, 1,vis, dungeons);
    return cnt-1;
}