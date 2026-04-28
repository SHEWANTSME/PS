//Good Bye, 별 찍기! - B1 - 2026.04.28(백준 서버 종료날)
#include <iostream>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int n;
char arr[500][500];
int main(){
    fastio;cin>>n;
    for(int i=2*n-1,j=0;i>=0 and j<2*n; i--,j++) arr[i][j]='*';
    for(int i=n-1, j=2*n+1,k=4*n+1;i>=0 and j<3*n+1 and k>3*n+1; i--,j++,k--){
        arr[i][j]='*';
        arr[i][k]='*';
    }
    for(int i=n,j=2*n+1,k=4*n+1;i<2*n and j<3*n+1 and k>3*n+1; i++,j++,k--){
        arr[i][j]='*';
        arr[i][k]='*';
    }
    for(int i=0;i<2*n;i++){
        for(int j=0; j<4*n+2;j++){
            if(arr[i][j])cout<<arr[i][j];
            else cout<<" ";
        }cout<<endl;
    }
    
}