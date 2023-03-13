// 항체 인식 - G5 - 2023/03/13
// 처음에는 2중for문 마다의 각각의 지점에서 DFS를 돌린값에서
// 가지치기를 하려다보니 exception이 생각보다 많고 까다로웠음
// 그래서 그냥 vector<pair<int,int>p[] 이런식으로 해서
// 경우마다의 좌표값, value를 담는 벡터를 만들어서 한번에 계산하는게 용이하다고 판단함.
// 이렇게 풀면 87퍼에서 틀렸다고 나옴.. RE
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
vector<pair<int,int>>vec[1000];
vector<pair<int,int>>v;
int cnt =0;
void DFS(int x, int y,int now){
    if(visited[x][y]!=0) return;
    visited[x][y]=1000+arr[x][y];
    //v.push_back({x,y});
    vec[cnt].push_back({x,y});
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
    if(n==1 and m==1){cout<<"YES"<<endl;exit(0);}

    //1 3 1 1 2 2 2 2
    // if(n==1 and m!=1){
    //     int t= arr[0][0];
    //     int tt=0;
    //     for(int k=0 ; k<m ; k++){
    //         if(t!=check_arr[0][k]){t = check_arr[0][k];tt++;}
    //     }
    //     int ttt=0;
    //     t = arr[0][0];
    //     for(int k=1 ; k<m ; k++){
    //         if(t!=arr[0][k])
    //     }
    // }
    // if(n!=1 and m==1){

    // }
    if(chk==0){
        cout<<"YES"<<endl; exit(0);
    }
    for(int i=0; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(visited[i][j]!=0)continue;
            DFS(i,j,arr[i][j]);
            cnt++;
        }
    }
   // cout<<cnt<<endl;
    //cnt-1로 봐야함
    for(int i=0 ; i<cnt; i++){
        int chk_1=0;
        int chk_2=0;
        for(auto &e : vec[i]){
            if(check_arr[e.first][e.second] != arr[e.first][e.second])chk_1++;
            else chk_2++;
        }
        if(chk_1 == vec[i].size()){
            int xnt = 0;
            for(int t=0; t<n;t++){
                for(int k=0;k<m;k++){
                    if(check_arr[t][k] == arr[t][k])xnt++;
                }
            }
            if(cnt==1){
                if(xnt + chk_1 == n*m){
                    cout<<"YES"<<endl; exit(0);
                }
            }
            if(cnt!=1){
                if(xnt + chk_1 == n*m and xnt>0){
                    cout<<"YES"<<endl; exit(0);
                }
            }
        }
    }
    cout<<"NO"<<endl;
    // for(int i=0 ; i<8 ; i++){
    //     for(auto &e : vec[i]){
    //         cout << i<<" "<<e.first<< " "<<e.second<<endl;
    //     }
    // }

}