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
// 이전 로그를 보면 DFS풀이도 존재함.

int cnt=0;
int wolf=0, yang=0;
/*

이 문제를 통해 느낀것 : 
1. DFS로 풀때는 이중 for문에서 자체적으로 if로 거른다음, DFS수행 
   -> 왜냐면 void로 구현했기 때문 (void 구현이 젤 쉬움)
2. BFS로 풀때는 이중 for문에서 자체적으로 if로 거르고 q에 담고 해도 되겠지만
   -> 그냥 무지성 q대입 후 안되는 애들을 거르는게 더욱 맞는듯
    -> if로 거르고 queue에서도 거르고 찔끔찔끔 거르면 오히려 다 안걸러짐..
*/

int main(){
    cin>>r>>c;
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
            cin>>arr[i][j];
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            // DFS는 여기서 if(방문안했고, arr가 # 아니면){DFS} 였지만
            // BFS는 일단 queue에 담고 한번에 거르자!!
            queue<pair<int,int>>q;
            q.push({i,j});// 일단넣어
            int wolf_cnt =0,yang_cnt =0;
            while(not q.empty()){
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                for(int k=0 ; k<4 ; k++){
                    int nx = dx[k]+xx;
                    int ny = dy[k]+yy;
                    char now = arr[nx][ny];
                    if(nx<0 or ny<0 or nx>=r or ny>=c)continue;
                    if(now=='#' or visited[nx][ny])continue;
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                    if(now=='.')continue;
                    if(now=='o')yang_cnt++;
                    if(now=='v')wolf_cnt++;
                }
            }
            if(yang_cnt<=wolf_cnt)wolf+=wolf_cnt;
            else yang+=yang_cnt;
        }
    }
    cout<<yang << " " <<wolf << endl;
}