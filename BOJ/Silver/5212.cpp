// 지구 온난화- S2 - 2023/04/17
// 말을 너무 애매하게 해서 헷갈림.. -> 50년이 지나면, 인접한 세 칸 또는 네 칸에 바다가 있는 땅은 모두 잠겨버린다
// 저 말이 동서남북중 3개이상의 dir이 바다일때 잠긴다는뜻임.. 나는 x . . . t 이면 t자리가 잠긴다는줄 알았네..

// 어쩌다보니 이틀이 지나고 다시 문제를 들여다 보고 있는중인데,
// 그냥 x좌표, y좌표의 min값, x,y의 max값들을 하면 될것같은데??
// 그냥 simulation 하면 된다.
#include<iostream>
#include<vector>
#include<algorithm>
#define ff first 
#define sc second
using namespace std;
char arr[11][11];
int dx[4] = {1,0,-1,0}; // 1 0 -1  0 
int dy[4]={0,1,0,-1}; //   0 1  0 -1
char new_arr[11][11];
vector<pair<int,int>>v;
vector<pair<int,int>>cand;
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0 ; i< n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%1s",&arr[i][j]);// 문자 포함된 따닥따닥 붙어있는애들은 이런식으로 해줘야!
            if(arr[i][j]=='X')v.push_back({i,j});
        }
    }
    for(auto &e : v){
        int x = e.ff;
        int y =e.sc;
        int cnt =0;
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cnt>=3)break;
            if(nx>=n or ny>=m or nx<0 or ny<0){
                cnt++;
                continue;
            }
            if(arr[nx][ny] == '.'){cnt++;continue;}
        }
        if(cnt<3){
            cand.push_back({x,y});
            continue;
        }
    }
    int minx=1e9;
    int miny=1e9;
    int maxx=-1;
    int maxy=-1;
    for(auto &e : cand){
        minx=(minx<e.ff)?minx:e.ff;
        miny=(miny<e.sc)?miny:e.sc;
        maxx=(maxx>e.ff)?maxx:e.ff;
        maxy=(maxy>e.sc)?maxy:e.sc;
    }
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            new_arr[i][j]='.';
    for(int i=minx; i<=maxx;i++){
        for(int j=miny;j<=maxy;j++){
            for(auto &e : cand){
                if(e.first==i and e.second==j)new_arr[i][j]='X';
            }
        }
    }

    for(int i=minx;i<=maxx;i++){
        for(int j=miny;j<=maxy;j++){
            cout<<new_arr[i][j];
        }cout<<endl;
    }
}
