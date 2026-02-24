//가지가지 - G3 - 2026.02.24
#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<vector<char>>arr(n, vector<char>(m,'.'));
    if(n<3 or m<3){cout<<-1<<endl; exit(0);}
    if(n%2==0 and m%2!=0){cout<<-1<<endl; exit(0);}
    if(n%2!=0 and m%2==0){cout<<-1<<endl; exit(0);}
    arr[n-2][0]='G';
    arr[n-1][0]='g';
    arr[n-1][1]='G';
    arr[n-1][2]='g';
    arr[n-3][2]='G';
    arr[n-2][2]='g';
    if(n==m){
        for(int i=1; i<=n;i++){
            char t = arr[i-1][n-i];
            if(t=='G')break;
            else{
                arr[i-1][n-i]='G';
                arr[i][n-i]='g';
            }
        }
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j];
            }cout<<endl;
        }
        exit(0);
    }
    if(n>m){
        int x = n-m;//2
        for(int i=0; i<x ; i++){
            arr[i][0]='G';
            arr[i][1]='g';
        }
        int xx = min(n,m);//5
        for(int i=1; i<=xx; i++){
            char t = arr[i-1+x][xx-i];
            if(t=='G')break;
            else{
                arr[i-1+x][xx-i]='G';
                arr[i+x][xx-i]='g';
            }
        }
        cout<<max(n,m)<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<arr[i][j];
            }cout<<endl;
        }
        exit(0);
    }
    if(n<m){
        int x = m-n;
        for(int i=0; i<x; i++){
            arr[0][m-1-i]='G';
            arr[1][m-1-i]='g';
        }
        int xx = min(m,n);
        for(int i=1; i<=xx; i++){
            char t = arr[i-1][xx-i];
            if(t=='G')break;
            else{
                arr[i-1][xx-i]='G';
                arr[i][xx-i]='g';
            }
        }
        cout<<max(n,m)<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<arr[i][j];
            }cout<<endl;
        }
        exit(0);        
    }
}