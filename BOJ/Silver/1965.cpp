#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1001];
int dp[1001];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    //dp[0]=1; 이부분이 잘못됨
    // 저 경우면 8 9 10 1 2 3 4 5 에서 4만 출력하게됨
    for(int i=0;i<n;i++){
        //그래서 여기에서 dp 초기화를 해줘야지
        dp[i]=1;
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j])dp[i] = max(dp[i],dp[j]+1);
        }
    }
   // for(int i=0;i<n;i++)cout<<dp[i]<<" ";
    cout<<*max_element(dp,dp+n)<<endl;
}