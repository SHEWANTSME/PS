// 투명- S5 - 2023/06/29
// 쉬운문제.
#include<iostream>
using namespace std;
int arr[101][101];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1; j<=x2;j++){
            for(int k=y1; k<=y2; k++){
                 arr[j][k]++;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
            if(arr[i][j] > m)ans++;
    cout<<ans<<endl;
}