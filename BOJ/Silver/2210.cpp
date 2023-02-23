// 숫자판 점프 - S2 - 2023/02/23
// 숫자판의 크기도 작고 충분히 DFS로 풀릴것 같고 시간 제한도 2초
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int arr[5][5];
string temp="";
vector<string>v;
void DFS(int x, int y,int cnt){
    if(temp.size()==6){
        bool flag=0;
        cnt=0;
        for(auto &e : v){
            if(e==temp)flag=1;
        }
        if(flag==1){temp=""; return;}
        else{v.push_back(temp);return;} 
    }
    cnt++;
    temp.push_back(arr[x][y]+48);
    for(int i=0;i<4;i++){
        int nx = dx[i]+x;
        int ny=dy[i]+y;
        if(nx<0 or ny<0 or nx>=5 or ny>=5)continue;
        DFS(nx,ny,cnt);

    }
}
int main(){
    for(int i=0 ; i<5 ; i++)
        for(int j=0 ; j<5 ; j++)
            cin>>arr[i][j];
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<5 ; j++){
            DFS(i,j,0);
        }
    }
    for(auto &e : v){
        cout<<e<<endl;
    }
}