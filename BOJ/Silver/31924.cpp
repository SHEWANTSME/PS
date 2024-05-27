// //31924번 - S5 - 현대모비스 특별상의 주인공은? 2
// // 시간초과.. 1초제한임
// #include<iostream>
// #include<algorithm>
// #include<queue>
// #include<vector>
// using namespace std;
// int n;
// char arr[101][101];
// vector<pair<int,int>>v;
// int ans=0;
// int dx[8] = {0,0,1,-1,1,-1,1,-1};
// int dy[8] = {1,-1,0,0,1,-1,-1,1};
// int visited[101][101];
// int xx,yy;
// string s = "";
// void check(int x, int y,int idx){
//     if(idx==8){
//         return;
//     }
//     char now = arr[x][y];
//     int nx = x + dx[idx];
//     int ny = y + dy[idx];
//     s.push_back(now);
//     if(s=="MOBIS"){
//         ans++; s="";check(xx,yy,idx+1);
//     }
//     if(s.size()==5 and s!="MOBIS"){
//         s="";check(xx,yy,idx+1);
//     }
//     if(nx>=0&&ny>=0&&nx<n&&ny<n) check(nx,ny,idx);
//     //check(xx,yy,idx+1);
// }
// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             scanf("%1s",&arr[i][j]);
//             if(arr[i][j]=='M'){
//                 v.push_back({i,j});
//             }
//         }
//     }
//     while(not v.empty()){
//         xx =v.back().first;
//         yy =v.back().second;
//         v.pop_back();
//         check(xx,yy,0);
//         s="";
//     }
//     cout<<ans<<endl;

// }

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n;
char arr[101][101];
vector<pair<int,int>>v;
int ans;
void check_MOBIS(int x, int y){
    if(x+4>n and y+4>n){
        if(x-4>=0 and y-4>=0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x-1][y-1] == 'O' and arr[x-2][y-2] == 'B' and arr[x-3][y-3] == 'I' and arr[x-4][y-4] == 'S'){
                ans++;
            }
        }
        if(x-4>=0 and y-4<0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4>=0){
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
        }
    }
    if(x+4>n and y+4<=n){
        if(x-4>=0 and y-4>=0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x-1][y-1] == 'O' and arr[x-2][y-2] == 'B' and arr[x-3][y-3] == 'I' and arr[x-4][y-4] == 'S'){
                ans++;
            }
            if(arr[x-1][y+1] == 'O' and arr[x-2][y+2] == 'B' and arr[x-3][y+3] == 'I' and arr[x-4][y+4] == 'S'){
                ans++;
            }
            if(arr[x][y+1] == 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
        }
        if(x-4>=0 and y-4<0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x-1][y+1] == 'O' and arr[x-2][y+2] == 'B' and arr[x-3][y+3] == 'I' and arr[x-4][y+4] == 'S'){
                ans++;
            }
            if(arr[x][y+1] == 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4>=0){
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x][y+1] == 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4<0){
            if(arr[x][y+1] == 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
        }
    }
    if(x+4<=n and y+4>n){
        if(x-4>=0 and y-4>=0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
            if(arr[x+1][y-1] == 'O' and arr[x+2][y-2] == 'B' and arr[x+3][y-3] == 'I' and arr[x+4][y-4] == 'S'){
                ans++;
            }
            if(arr[x-1][y-1] == 'O' and arr[x-2][y-2] == 'B' and arr[x-3][y-3] == 'I' and arr[x-4][y-4] == 'S'){
                ans++;
            }
        }
        if(x-4>=0 and y-4<0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4>=0){
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
            if(arr[x+1][y-1] == 'O' and arr[x+2][y-2] == 'B' and arr[x+3][y-3] == 'I' and arr[x+4][y-4] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4<0){
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
        }
    }
    if(x+4<=n and y+4<=n){
        if(x-4>=0 and y-4>=0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
            if(arr[x][y+1]== 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
            if(arr[x+1][y+1] == 'O' and arr[x+2][y+2] == 'B' and arr[x+3][y+3] == 'I' and arr[x+4][y+4] == 'S'){
                ans++;
            }
            if(arr[x-1][y-1] == 'O' and arr[x-2][y-2] == 'B' and arr[x-3][y-3] == 'I' and arr[x-4][y-4] == 'S'){
                ans++;
            }
            if(arr[x+1][y-1] == 'O' and arr[x+2][y-2] == 'B' and arr[x+3][y-3] == 'I' and arr[x+4][y-4] == 'S'){
                ans++;
            }
            if(arr[x-1][y+1] == 'O' and arr[x-2][y+2] == 'B' and arr[x-3][y+3] == 'I' and arr[x-4][y+4] == 'S'){
                ans++;
            }
        }
        if(x-4>=0 and y-4<0){
            if(arr[x-1][y] == 'O' and arr[x-2][y] == 'B' and arr[x-3][y] == 'I' and arr[x-4][y] == 'S'){
                ans++;
            }
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
            if(arr[x][y+1]== 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
            if(arr[x+1][y+1] == 'O' and arr[x+2][y+2] == 'B' and arr[x+3][y+3] == 'I' and arr[x+4][y+4] == 'S'){
                ans++;
            }
            if(arr[x-1][y+1] == 'O' and arr[x-2][y+2] == 'B' and arr[x-3][y+3] == 'I' and arr[x-4][y+4] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4>=0){
            if(arr[x][y-1] == 'O' and arr[x][y-2] == 'B' and arr[x][y-3] == 'I' and arr[x][y-4] == 'S'){
                ans++;
            }
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
            if(arr[x][y+1]== 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
            if(arr[x+1][y-1] == 'O' and arr[x+2][y-2] == 'B' and arr[x+3][y-3] == 'I' and arr[x+4][y-4] == 'S'){
                ans++;
            }
            if(arr[x+1][y+1] == 'O' and arr[x+2][y+2] == 'B' and arr[x+3][y+3] == 'I' and arr[x+4][y+4] == 'S'){
                ans++;
            }
        }
        if(x-4<0 and y-4<0){
            if(arr[x+1][y] == 'O' and arr[x+2][y] == 'B' and arr[x+3][y] == 'I' and arr[x+4][y] == 'S'){
                ans++;
            }
            if(arr[x][y+1]== 'O' and arr[x][y+2] == 'B' and arr[x][y+3] == 'I' and arr[x][y+4] == 'S'){
                ans++;
            }
            if(arr[x+1][y+1] == 'O' and arr[x+2][y+2] == 'B' and arr[x+3][y+3] == 'I' and arr[x+4][y+4] == 'S'){
                ans++;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='M'){
                v.push_back({i,j});
            }
        }
    }
    while(not v.empty()){
        int x = v.back().first;
        int y = v.back().second;
        v.pop_back();
        check_MOBIS(x,y);
    }
    cout<<ans<<endl;


}