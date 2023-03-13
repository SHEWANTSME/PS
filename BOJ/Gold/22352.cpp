// 항체 인식 - G5 - 2023/03/13
// 처음에는 2중for문 마다의 각각의 지점에서 DFS를 돌린값에서
// 가지치기를 하려다보니 exception이 생각보다 많고 까다로웠음
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int arr[31][31];
int visited[31][31];
int temp_arr[31][31];
int check_arr[31][31];

void DFS(int x, int y,int now,int t){
    visited[x][y]=1;
    arr[x][y] = t;
    for(int i=0; i<4 ; i++){
        int nx = dx[i]+x;
        int ny= dy[i]+y;
        if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
        if(not visited[nx][ny] and arr[nx][ny]==now){
            visited[nx][ny]=1;
            DFS(nx,ny,now,t);
        }
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
    if(chk==0){cout<<"YES"<<endl;exit(0);}
    bool flag=1;// 이 부분부터 잘 알아두자!
    // 자세한건 그림으로 첨부
	for (int i = 0;i<n;i++) {
		for (int j= 0;j <m;j++) {
			if (flag and arr[i][j] != check_arr[i][j]) {
                DFS(i,j,arr[i][j],check_arr[i][j]);
                flag=0;
			}
		}
	}
	bool res = 1;
	for (int i = 0; i<n;i++) {
		for (int j = 0; j<m; j++){
			if (arr[i][j] != check_arr[i][j])res=0;
        }
    }
    if(res)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
    // 여기부터 밑의 내용은 무시해도 되고
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
    // if(chk==0){
    //     cout<<"YES"<<endl; exit(0);
    // }
    // for(int i=0; i<n ; i++){
    //     for(int j=0 ; j<m ; j++){
    //         //if(visited[i][j]!=0)continue;
    //         //DFS(i,j,arr[i][j]);
    //         //cnt++;
    //         if(check_arr[i][j]!=arr[i][j]){
    //             DFS(i,j,arr[i][j]);
    //             for (int i = 0; i < n; ++i) {
	// 	            for (int j = 0; j < m; ++j) {
	// 		            if (arr[i][j] != check_arr[i][j]) ansans=1;
	// 	            }
	//             }
    //             if(ansans==1)
    //             if(ansans==0)cout<<"YES";
    //             else cout<<"NO";
    //             exit(0);
    //         }
    //     }
    // }
   // cout<<cnt<<endl;
   /*
    1 4
    1 1 2 2
    3 2 2 2
    NO가 나와야지 YES가 아니고
   */
//   int xxnt = 0;
//   for(int i=0; i<cnt;i++){
//     for(auto &e : vec[i]){
//         if(arr[e.first][e.second] != check_arr[e.first][e.second])xxnt++;
//         cout<<i<<" "<<e.first<<" "<<e.second<<endl;
//     }
//   }
//   cout<< xxnt << " "<<cnt-1<<endl;
  //if(xxnt != cnt-1 ){cout<<"NO"<<endl;}
  //else cout<<"YES"<<endl;








    //cnt-1로 봐야함
    // for(int i=0 ; i<cnt; i++){
    //     int chk_1=0;
    //     int chk_2=0;
    //     for(auto &e : vec[i]){
    //         if(check_arr[e.first][e.second] != arr[e.first][e.second])chk_1++;
    //         else chk_2++;
    //     }
    //     if(chk_1 == vec[i].size()){
    //         int xnt = 0;
    //         for(int t=0; t<n;t++){
    //             for(int k=0;k<m;k++){
    //                 if(check_arr[t][k] == arr[t][k])xnt++;
    //             }
    //         }
    //         if(cnt==1){
    //             if(xnt + chk_1 == n*m){
    //                 cout<<"YES"<<endl; exit(0);
    //             }
    //         }
    //         if(cnt!=1){
    //             if(xnt + chk_1 == n*m and xnt>0){
    //                 cout<<"YES"<<endl; exit(0);
    //             }
    //         }
    //     }
    // }
    // cout<<"NO"<<endl;




    // for(int i=0 ; i<8 ; i++){
    //     for(auto &e : vec[i]){
    //         cout << i<<" "<<e.first<< " "<<e.second<<endl;
    //     }
    // }

