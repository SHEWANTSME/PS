//징검다리 건너기 - S1 - 2024.05.05
//딱 n번째 돌에 산삼이 있기 때문에 그 이상 뛰게 된다면 산삼을 캘 수 없다.
// 흠 금방 나올거 같은데,, 오늘안에 끝내기 -> Done
// 직접 계산해보고 식을 세워보면 구할 수 있음
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;//k: large jump
int dp[22][4];// 1: small jump, 2: big jump, 3: large jump
int arr[22][4];
int ans_1,ans_2,final_ans;
int main(){
    cin>>n;
    for(int i=1;i<22;i++){
        dp[i][3]=987654321;// lj가 없을때로 일단 ans_1구하고, lj가 있을때로 ans_2구함
        for(int j=1;j<4;j++){
            arr[i][j]=987654321;// 초기화
        }
    }
    dp[1][1]=0;dp[1][2]=0;
    for(int i=2; i<=n; i++){
        int sj,bj;//small jump, big jump
        cin>>sj>>bj;
        if(i==2){
            dp[i][1]=dp[i][2]=sj;
            arr[i][1]=sj;arr[i+1][2]=bj;
        }
        else{
            arr[i][1]=sj;arr[i+1][2]=bj;
        }
    }
    for(int i=3;i<=n;i++){
        dp[i][1] = min(dp[i-1][1],dp[i-1][2])+arr[i][1];
        dp[i][2] = min(dp[i-2][1],dp[i-2][2])+arr[i][2];
    }
    ans_1 = min(dp[n][1],dp[n][2]);
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i][1]<<" "<<dp[i][2]<<endl;
    // }


    cin>>k;
    ans_2 = 987654321;
    for(int t=4; t<=n;t++){
        dp[t][3] = min(dp[t-3][1],dp[t-3][2])+k;
        for(int i=2;i<=n;i++){
            dp[i][1] = min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+arr[i][1];
            dp[i][2] = min(min(dp[i-2][1],dp[i-2][2]),dp[i-2][3])+arr[i][2];
        }
        ans_2= min(min(min(dp[n][1],dp[n][2]),dp[n][3]),ans_2);
        dp[t][3] = 987654321;
    }
   final_ans = min(ans_1,ans_2);
   cout<<final_ans<<endl;
}