//  뱀 - G4 - 2023/06/21
/*
으아아ㅏ 너무 시간 오래끌어따아ㅏ
1. vector로 했는데 v.front(), v.pop_back()으로 1시간 날림
2. 사과는 먹으면 사라짐
3. 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다. 그 후에 꼬리 길이를 줄이는 것이다.
 따라서 꼬리를 줄이기 이전에 뱀이 부딪힐 수 있다. 
이 조건들을 유의하면서 풀어야함!
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
int dx[4]= {0,1,0,-1};
int dy[4] = {1,0,-1,0};
// (0,1) -> (1,0)-> (0,-1) -> (-1,0)
// dir의 현재 상태에서 왼쪽으로 90도면 -1 오른쪽으로 90도면 +1 하면 되겠네
/*
    [0,1,2,3] -> 오른쪽이면 +1 -> if(now ==4)now = 0;
    왼쪽이면 -1 -> if(now == -1)now = 3;
*/
int n, k,l;
int arr[101][101];// 현재 뱀의 위치를 알려주는 arr
char apple[101][101];// 사과가 어디있는지 알려주는 apple
int vis[101][101];// 
queue<pair<int,char>>q;

deque<pair<int,int>>dq;// deque는 현재 뱀의 위치를 {x,y} pair로 나타내는 놈


int Check(int x, int y, int dir, int cnt){
    if(x>=n+1 or y>=n+1 or x<=0 or y<=0) return cnt;
    if(vis[x][y])return cnt;
    // 1. 현재 위치 방문체크
    vis[x][y]=1;
    // 2. deque에 넣고
    dq.push_front({x,y});
    cout<<x<<" "<<y<<" "<<dir<<" "<<cnt<<" "<<dq.size()<<endl;
    auto chk = q.front();
    // 2. 현재 위치가 로테이션 되는 위치인지 확인
    if(chk.first == cnt){
        //cout<<"여기에 몇번이나 오려나"<<endl;
        q.pop();
        //cout<<"v.size()의 변화"<<v.size()<<endl;
        if(chk.second == 'D'){// D is for Right
            dir++;
            if(dir==4)dir=0;
        }
        else{// L is for Left
            dir--;
            if(dir==-1)dir=3;
        }
    }
    // 현 위치
    char current = apple[x][y];
    int nx = x+dx[dir];
    int ny=y+dy[dir];
    cnt++;
    if(current!='A'){ // 현 위치에 사과가 없으면
        auto xx = dq.back();// dq에서 맨뒤에있는 놈을 빼버리고
        vis[xx.first][xx.second]=0;// 방문해제
        dq.pop_back();
        return Check(nx,ny,dir,cnt);
    }
    else{
        return Check(nx,ny,dir,cnt);
    }
}
int main(){

    cin>>n>>k; // n : 보드의 크기 , k : 사과의 개수
    for(int i=0; i<k ; i++){
        int x, y;cin>>x>>y;
        apple[x][y]='A';
    }
    cin>>l;// 뱀의 방황 변환 횟수
    while(l--){
        int z;char ch;
        cin>>z>>ch;
        q.push({z,ch});
        //v.push_back({z,ch});
    }
    vis[1][1]=1;
    dq.push_front({1,1});
    //dq.push_front
    cout<< Check(1,2,0,1)<<endl;
}