// 항체 인식 - G5 - 2023/03/13
// 처음에는 2중for문 마다의 각각의 지점에서 DFS를 돌린값에서
// 가지치기를 하려다보니 exception이 생각보다 많고 까다로웠음
// 그래서 그냥 vector<pair<int,int>p[] 이런식으로 해서
// 경우마다의 좌표값, value를 담는 벡터를 만들어서 한번에 계산하는게 용이하다고 판단함.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 정수가 1 이상 1000 이하
// 그러면 1000+arr[i][j]로 하면, 1000보다 큰 값이니
// 무조건 갱신된 값이고 if 갱신된값 -> 
int n, m;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int arr[31][31];
int visited[31][31];
int temp_arr[31][31];
int check_arr[31][31];
vector<pair<int,int>>v;
void DFS(int x, int y,int now){
    if(visited[x][y]!=0) return;
    visited[x][y]=1000+arr[x][y];
    for(int i=0 ; i<4 ; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
        if(visited[nx][ny]!=0)continue;
        if(arr[nx][ny]!=now)continue;
        DFS(nx,ny,arr[nx][ny]);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>arr[i][j];
            temp_arr[i][j]= arr[i][j];
        }
    }
    bool chk = 0;
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>check_arr[i][j];
            if(check_arr[i][j] != arr[i][j])chk=1;
        }
    }
    if(chk==0){
        cout<<"YES"<<endl; exit(0);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            DFS(i,j,arr[i][j]);
            for(int t=0; t<n ; t++){
                for(int k =0 ; k<m ; k++){
                    if(visited[t][k]!=0) v.push_back({t,k});
                }
            }
            for(auto &e : v){
                if(arr[e.first][e.second])
            }
            memset(visited,0,sizeof(visited));
        }
    }
    // DFS(0,3,arr[0][3]);
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<m ; j++){
    //         cout<<visited[i][j]<<" ";
    //     }cout<<endl;
    // }
    

}


/*
check_arr



*/