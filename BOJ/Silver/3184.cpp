// 양 - S1 - 2023/03/02
//'.' -> 빈칸, '#' -> 울타리, 'o'->양 , 'v'-> 늑대
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int r,c;
char arr[251][251];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
bool visited[251][251];
vector<string>vec;
vector<pair<int,int>>p[251];
int cnt=0;
int wolf=0, yang=0;
void Func(int x, int y){
    if(visited[x][y] or arr[x][y]=='#'){return;}
   // if(arr[x][y]=='#')return;
    visited[x][y]=1;
    p[cnt].push_back({x,y});
    //cnt++;
    for(int i=0 ; i<4 ; i++){
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(nx<0 or ny<0 or nx>=r or ny>=c)continue;
        if(visited[nx][ny])continue;
        Func(nx,ny);
    }
    
}
int main(){
    cin>>r>>c;
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
            cin>>arr[i][j];
     for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            // 왜 밑의 if문이 중요하냐면, 뭉텅이의 개수를 알 수 있기 때문
            // DFS면 갈수 있는 길을 다 가고 vis체크 하고 안될때 최종적으로 빠져 나오는데
            // 방문하지 않고, 벽이 아니여야(vis조건만 있고 벽 조건이 없다면 -> 벽이면 return은 되겠지만 cnt++도 되겠지?)
            if(not visited[i][j] and arr[i][j]!='#'){
                Func(i,j);
                cnt++;
            }
            //Func(i,j);
        }
     }
     cout << cnt <<endl;
     //cout<<cnt<<" "<<cnt1<<endl;
     for(int i=0 ; i<cnt ; i++){
        int ccnt = 0;
        int yang_cnt =0;
        int wolf_cnt=0;
        for(auto &e : p[i]){
            if(arr[e.first][e.second]=='v'){
                wolf_cnt++;
            }
            if(arr[e.first][e.second]=='o'){
                yang_cnt++;
            }
        }
        if(wolf_cnt==0 and yang_cnt==0)continue;
        if(wolf_cnt>=yang_cnt)wolf+=wolf_cnt;
        if(wolf_cnt<yang_cnt)yang+=yang_cnt;
        //if(changed==1 and ccnt >=0)wolf++;
        //if(changed==1 and ccnt <0)yang++;
     } 
     cout<<yang << " " << wolf << endl;  
}
