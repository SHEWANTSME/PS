// 캠핑장 부지 평탄화 - S4 - 2025.05.21
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int a,b,c,d;
int arr[1001][1001];
int mapp[10][10];
int ans=0;
int main(){
    cin>>a>>b>>c>>d;
    for(int i=1; i<=a;i++)
        for(int j=1; j<=b; j++)
            cin>>arr[i][j];
        
    for(int i=1; i<=c; i++)
        for(int j=1; j<=d; j++)
            cin>>mapp[i][j];
    
    int tmp1=0; int tmp2=0;
    while(tmp2+d<=b and tmp1+c<=a){
        map<int,int>mp;
        int xx = 100;
        for(int i=1+tmp1; i<=c+tmp1; i++){
            for(int j=1+tmp2; j<=d+tmp2; j++){
                xx =arr[i][j] - mapp[i-tmp1][j-tmp2];
                mp[xx]++;
            }
        }
        if(mp[xx] == c*d)ans++;
        tmp2++;
        if(tmp2+d >b){
            tmp2=0;tmp1++;
        }
    }
    cout<<ans<<endl;
}