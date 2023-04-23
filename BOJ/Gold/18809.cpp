// // Gaaaaaaaaaarden - G1 - 2023/04/21
// /*
// https://junseok.tistory.com/85
//  시뮬레이션 골드상위급 -> 고려해야할 사항이 무지많다
//  일단 땅의 색이 3개임
//  0-> 물
//  1->배양액을 뿌릴 수 없는 땅
//  2->배양액을 뿌릴 수 있는 땅
//  n , m , G, R -> G, R for each 배양액 
//  맥시멈 꽃의 개수를 찾는다 -> G이랑 R이 동시에 만나는 순간-> 꽃을 만든다 -> 꽃을 만드는 것도 vis 로 둬야
//  생각해야 할 arr -> int arr[][]
//  뿌릴 수 있는 땅 개수 
//  8C3 * 5C2 -> 56* 10 = 560   어차피 같은 값임
//  8C2 * 6C3 -> 28 * 20 = 560     
//  예제 입출력
//  5 5 2 2
// 0 0 0 0 1
// 0 0 0 0 2
// 1 2 1 2 1
// 2 1 2 0 1
// 1 0 1 1 1

// 조합의 개수를찾는건 그렇게 어렵지 않으나,, 조합들의 경우를 하나하나씩 중복되지 않게 찾은 후
// 그 조합들로 꽃을 만들 수 있는 경우를 찾는게 어려움..(Max flower를 찾아야하니까)
// */
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<queue>
// using namespace std;
// int arr[51][51];
// vector<pair<int,int>>v;
// int tot_vis[51][51];
// int G_vis[51][51];
// int R_vis[51][51];
// int n,m,G,R;
// int sec=0;
// int flower=0;
// int dx[4]={0,1,-1,0};
// int dy[4] = {1,0,0,-1};
// int Combination(int x , int y){
//     if(y==1) return x;
//     if(y==0 or x==y) return 1;
//     return Combination(x-1,y-1) + Combination(x-1,y);
// }
// void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
// {
//     if (r == 0)
//     {
//         for(int i = 0; i < comb.size(); i++)
//             cout << comb[i] << " ";
//         cout << endl;
//     }
//     else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
//     {
//         return;
//     }
//     else
//     {
//         // arr[depth] 를 뽑은 경우
//         comb[index] = arr[depth];
//         Combination(arr, comb, r - 1, index + 1, depth + 1);
        
//         // arr[depth] 를 뽑지 않은 경우
//         Combination(arr, comb, r, index, depth + 1);
//     }
// }
// // void Comb(vector<int>tmp, int r , int index, int depth){
// //     if(r ==0){
// //         for(auto &e : tmp)){
// //             cout<<e<<" ";
// //         }cout<<endl;
// //     }
// //     else if(depth == v.size()){
// //         return;
// //     }
// //     else{
// //         tmp[index] = v[depth];
// //         Comb(tmp,r-1,index+1,depth+1);
// //         Comb(tmp,r,index,depth+1);
// //     }
// // }



// int main(){
//     cin>>n>>m>>G>>R;
//     for(int i=1 ; i<=n ; i++){
//         for(int j=1 ; j<=m ; j++){
//             cin>>arr[i][j];
//             if(arr[i][j] == 2){
//                 v.push_back({i,j});
//             }
//         }
//     }
//     int cmb = Combination(v.size() , G) * Combination(v.size()-G,R);    
//     /*
//     v[0] v[1] v[2] v[3] v[4] 가 있는데
//     1     1    2    2   0
//     1     2    1   2    0

//     */
//    vector<int>vec={0,1,2,3,4};
//     //vector<char> vec = {'a', 'b', 'c', 'd', 'e'};  // n = 5    
//     int r = 2;
//     vector<int> comb(r);
    
//     Combination(vec, comb, r, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기
//     // 일단 [01  23], [01  24],  [01 34]  , 

//     // combination
//     // while(cmb--){

//     // }
//    // cout<<cmb<<endl;

//     for(int i=0 ; i<v.size() ; i++){

//     }
// // brute로 풀 수 있음??-> 하 머리아프다
// }


//----------------------------------------
// 아 일단 다시
// 아 모르겠다  존나어렵네
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, G,R;
int arr[51][51];
int new_arr[51][51];
int check_green[51][51];
int check_red[51][51];
int check_land[51][51];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int answer;
vector<pair<int,int>>land;
vector<int>green,red;
typedef struct QQ{
    int x;
    int y;
    int t;
}QQ;
void bfs(){
    queue<QQ>GQ;
    queue<QQ>RQ;
    int flower=0;
    for(int i=0 ; i<G;i++){
        int green_now = green[i];
        int xx = land[green_now].first;
        int yy = land[green_now].second;
        new_arr[xx][yy]=3;
        check_green[xx][yy]=1;
        GQ.push({xx,yy,1});
    }
    for(int i=0 ; i<R ; i++){
        int red_now = red[i];
        int xx = land[red_now].first;
        int yy = land[red_now].second;
        new_arr[xx][yy]=4;
        check_red[xx][yy]=1;
        RQ.push({xx,yy,1});
    }
    while(not GQ.empty() or not RQ.empty()){
        for(int k=0 ; k<GQ.size() ; k++){
            int x = GQ.front().x;
            int y = GQ.front().y;
            int t = GQ.front().t;
            GQ.pop();
            if(new_arr[x][y]==-1)continue;
            for(int i=0;i<4; i++){
                int nx = dx[i]+x;
                int ny =dy[i]+y;
                if(nx<1 or ny<1 or nx>n or ny>m)continue;
                if(check_green[nx][ny])continue;
                if(new_arr[nx][ny]==1 or new_arr[nx][ny]==2){
                    check_green[nx][ny]=t+1;
                    GQ.push({nx,ny,t+1});
                    new_arr[nx][ny]=3;
                }
            }
        }

        for(int k=0 ; k<RQ.size() ; k++){
            int x = RQ.front().x;
            int y = RQ.front().y;
            int t = RQ.front().t;
            RQ.pop();
            if(new_arr[x][y]==-1)continue;
            for(int i=0;i<4; i++){
                int nx = dx[i]+x;
                int ny =dy[i]+y;
                if(nx<1 or ny<1 or nx>n or ny>m)continue;
               // if(check_red[nx][ny])continue;
               if(check_red[nx][ny]==0){
                    if(new_arr[nx][ny]==1 or new_arr[nx][ny]==2){
                        check_red[nx][ny]=t+1;
                        GQ.push({nx,ny,t+1});
                        new_arr[nx][ny]=3;
                    }
                    else if(new_arr[nx][ny]==3){
                        if(check_green[nx][ny]==t+1){
                            new_arr[nx][ny]=-1;
                            check_red[nx][ny]=t+1;
                        }
                    }
               }
                
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(new_arr[i][j]==-1)flower++;
        }
    }
    answer =max(answer,flower);
}
void Red(int start, int cnt){
    if(cnt==R){
        bfs();
        for(int i=0; i<51;i++){
            for(int j=0; j<51;j++){
                check_green[i][j]=0;
                check_red[i][j]=0;
                new_arr[i][j]=arr[i][j];
            }
        }
    }
    else{
         for(int i=start; i<land.size() ; i++){
            int xx = land[i].first; int yy=land[i].second;
            if(check_land[xx][yy]==1)continue;
            check_land[xx][yy]=1;
            red.push_back(i);
            Red(i,cnt+1);
            red.pop_back();
            check_land[xx][yy]=0;
        }
    }

}
void Green(int start, int cnt){
    if(cnt == G) Red(0,0);
    else{
        for(int i=start; i<land.size() ; i++){
            int xx = land[i].first; int yy=land[i].second;
            if(check_land[xx][yy]==1)continue;
            check_land[xx][yy]=1;
            green.push_back(i);
            Green(i,cnt+1);
            green.pop_back();
            check_land[xx][yy]=0;
        }
    }
}
int main(){
    cin>>n>>m>>G>>R;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin>>arr[i][j];
            new_arr[i][j]=arr[i][j];
            if(arr[i][j]==2)land.push_back({i,j});
        }
    }
    Green(0,0);
    cout<<answer<<endl;



}