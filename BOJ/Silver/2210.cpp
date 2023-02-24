// 숫자판 점프 - S2 - 2023/02/23
// 숫자판의 크기도 작고 충분히 DFS로 풀릴것 같고 시간 제한도 2초
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int arr[5][5];
bool visited[5][5];
string temp="";
vector<string>v;
//backtracking 내 방식대로 짜보자
void DFS(int x, int y){
    // int now = arr[x][y];
    // visited[x][y]=1;
    // temp.push_back(now+48);
    if(temp.size()==6){
        bool flag=0;
        for(auto &e : v){
            if(e==temp)flag=1;
        }
        if(flag==1){ return;}
        else{v.push_back(temp);return;} 
    }
    for(int i=0 ; i<4 ; i++){
        int nx = dx[i]+x;
        int ny= dy[i]+y;
        if(nx<0 or ny<0 or nx>=5 or ny>=5)continue;
       // if(visited[nx][ny])continue;
       // visited[nx][ny]=1;
        temp.push_back(arr[nx][ny]+48);
        DFS(nx,ny);
        temp.pop_back();
       // visited[nx][ny]=0;
    }
}
int main(){
    for(int i=0 ; i<5 ; i++)
        for(int j=0 ; j<5 ; j++)
            cin>>arr[i][j];
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
          //  visited[i][j]=1;
            temp.push_back(arr[i][j]+48);
            DFS(i,j);
           // memset(visited,0,sizeof(visited));
            temp="";
        }
    }
    for(auto &e : v){
        cout<<e<<endl;
    }
}