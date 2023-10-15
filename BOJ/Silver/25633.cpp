//도미노 넘어뜨리기 - S1 - 2023/10/14
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int n;
// int arr[1002];
// int summ[1002];
// //arr:    2   1  6   5    4
// //sum:    2   3  9   14   18
// // if(sum[i-1]>=arr[i])


// //3 1 2 6
// //3 4 6 12
// // sum[i-1]>=arr[i]

// // 1 2 3
// // 1 3 6
// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     summ[0]=arr[0];
//     for(int i=1; i<n;i++)
//         summ[i]=summ[i-1]+arr[i];
//     int ans =0;
//     int tmp=0;
//     for(int i=1;i<n;i++){
//         if(summ[i-1]>=arr[i]) {
//             ans++;
//             tmp=i;
//         }
//         else break;
//     }
//     if(tmp!=n-1)ans++;
//     else ans =0;
//     if(ans ==1) cout<<ans<<endl;
//     //cout << ans <<" "<<tmp<<endl;
//     else cout <<n-ans<<endl;
//     // if(tmp==n-1){
//     //     ans++;
//     // }
//     // cout<<tmp << " "<<ans<<endl;
//     //cout<<ans<<endl;
// }

// LIS문제라는것을 알 수 있음
// 대신 ascending이 아니고 descending이다.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int arr[1002];//입력받은 배열
int dp[1002];//dp[i]: i번째 원소를 마지막으로 하는 LIS의 길이
int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++){
        int now = arr[i];//현재 원소
        int cnt=1;//현재 원소를 포함한 LIS의 길이 1로 초기화
        for(int j=i+1; j<n;j++){
            int nxt = arr[j];//다음 원소
            if(now>=nxt){//현재 원소가 다음 원소보다 크거나같으면
                now+=nxt;cnt++;//현재 원소에 다음 원소를 더하고 cnt++ 
                dp[j]=max(dp[j],cnt);//dp[j]와 cnt중 큰값을 dp[j]에 저장
                // dp에는 j번째 원소를 마지막으로 하는 LIS의 길이가 저장됨
            }
        }
    }
    int ans = *max_element(dp,dp+n);
    if(ans==0)cout<<1<<endl;
    else cout<<ans<<endl;
}