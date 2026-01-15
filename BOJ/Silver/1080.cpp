// Greedy인 이유는 좌상단부터 탐색할 때, 좌상단값이 서로 다르면 이후 진행될 때 다시 바꿀 수가 없음
// 행렬 - S1 - 2026.01.15
#include<iostream>
using namespace std;
int n,m;
int arr1[51][51];
int arr2[51][51];
int cnt=0;
void change(int x, int y){
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if(arr1[i][j]==1) arr1[i][j]=0;
            else arr1[i][j]=1;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d",&arr1[i][j]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d",&arr2[i][j]);
    for(int i=0;i<n-2; i++){
        for(int j=0; j<m-2; j++){
            if(arr1[i][j]!= arr2[i][j]){
                change(i,j);cnt++;
            }
        }
    }
    bool flag=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            if(flag)break;
            if(arr1[i][j]!=arr2[i][j]) flag=1;
        }
    }
    if(flag) cout<<-1<<endl;
    else cout<<cnt<<endl;
}