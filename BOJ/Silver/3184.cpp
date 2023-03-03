// 양 - S1 - 2023/03/02
//'.' -> 빈칸, '#' -> 울타리, 'o'->양 , 'v'-> 늑대
// 이번엔 BFS로 풀어보자.
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue> // for using bfs
using namespace std;
int r,c;
char arr[251][251];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
bool visited[251][251];
vector<string>vec;
vector<pair<int,int>>p[1000];// 이거의 사이즈마다 사용하는 메모리의 양이 다른데
// 정확히 어떻게 달라지는진 모르겠음 250*250 /2 하면 삼만 언저리까진 가능한데
// 그보다 아래 숫자인 1000까지 왜 통과가 되는걸까
int cnt=0;
int wolf=0, yang=0;
int wolf_cnt =0,yang_cnt =0;
void Func(int x, int y){
    if(visited[x][y] or arr[x][y]=='#'){return;}
   // if(arr[x][y]=='#')return;
    visited[x][y]=1;
    p[cnt].push_back({x,y});
    //cnt++; -> cnt를 여기다가 넣으면 그냥 벽이 아닐때마다 카운트가 됨 
    // 그걸 방지하기 위해선 어떤 조치가 필요한데, void 함수 내에선 가능한게 없어서
    // 맨처음 함수가 호출되기 전 for문 안에서 방문하지 않고, 벽이 아닌애를 미리 거르면 
    // 뭉텅이의 개수를 알 수 있고, 뭉텅이별로 p벡터에 넣을 수 있음
    for(int i=0 ; i<4 ; i++){
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(nx<0 or ny<0 or nx>=r or ny>=c)continue;
        if(visited[nx][ny])continue;
        Func(nx,ny);
    }
}

int main(){
    // 이따 좀 더 think
    cin>>r>>c;
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
            cin>>arr[i][j];
     for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            // 이번엔 아예 처음부터 체크하자
            
            
            if(not visited[i][j] and arr[i][j]!='#'){
                bool dotcheck=0;
                queue<char>q;
                q.push(arr[i][j]);
                visited[i][j]=1;
                while(not q.empty()){
                    char now = q.front();
                    if(now=='v'){dotcheck=1;wolf_cnt++;}
                    if(now=='o'){dotcheck=1;yang_cnt++;}
                    q.pop();

                    for(int k=0 ; k<4 ; k++){
                        int nx = dx[k]+i;
                        int ny = dy[k]+j;
                        if(nx<0 or ny<0 or nx>=r or ny>=c)continue;
                        if(visited[nx][ny])continue;
                        if(arr[nx][ny]=='#')continue;
                        q.push(arr[nx][ny]);
                        visited[nx][ny]=1;
                    }
                }
               // yang+=yang_cnt;
               // wolf+=wolf_cnt;
                if(dotcheck==0)continue;
                if(yang_cnt>wolf_cnt)yang+=yang_cnt;
                if(yang_cnt<=wolf_cnt) wolf+=wolf_cnt;
                cout<<i<<" "<<j<<" "<<yang_cnt << " " << wolf_cnt<<endl;
                
               

            }
        }yang_cnt=0,wolf_cnt=0;
     }
    cout<<yang<< " " <<wolf<<endl;
    // 찍어보면 알겠지만,, 지금처럼 queue를 좌표로 받지 않으면, nx ny의 상속이 이뤄지지 않음
    // 지금은 queue를 char 하나로만 받아두니깐 갱신이 이뤄지지 않고 이중for문이 도는대로
    // 그냥 하나씩 체크하는것 밖엔 뭐 없음.. 
    // 결론은 BFS든 DFS든 queue나 재귀를 통해 새로 갱신된 값이 다음 queue,재귀에 영향을 끼쳐야함
    
}
