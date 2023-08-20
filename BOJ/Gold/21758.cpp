// 꿀따기 - G5 - 2023/08/20
// 벌통(green)이 1개고 벌(red)가 2개라서
// RGR, RRG, GRR 세가지의 경우로 나눌 수 있었고
// 2중for문을 쓰는순간 시초에 걸릴걸 알 수 있었고(n<=100000)
// 다양한 경우를 나름 그려가면서 생각해봤는데, RGR경우를 제외하고는
// G랑 R2가 양끝에 붙어있고, R1이 양끝을 제외한 나머지 구간에서 누적합의 max를 갱신하는
// 형태로 풀면 답이 나오는 문제였다.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[100001];// for RGR, GRR
int arr2[100001]; // for RRG
int sum[100001];// for GRR
int sum2[100001];// for RRG
int ans1=0,ans2=0,ans3=0,mx=-1;
// ans1,mx for RGR, ans2 for GRR, ans3 for RRG

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        arr2[n-i+1]=arr[i];// RRG는 어차피 순서 뒤집어서 GRR이랑 똑같이 생각하면 되므로
        if(i!=1 or i!=n){
            mx=(mx>arr[i])?mx:arr[i];
        }
    }
    // ans1계산은 양끝값 빼고 싹다 더한값에 green값을 더하면 되는 건데
    // green이 max가 되어야 최대값이 되니까 위에서 입력받을때 아예 mx를 구한것임
    for(int i=2; i<=n-1;i++)
        ans1+=arr[i];
    ans1+=mx; // ans1 계산 완료

    // 나머지(GRR, RRG) 계산을 위한 누적합 계산
    sum[1]=arr[1];
    sum2[1]=arr2[1];
    for(int i=2; i<=n;i++){
        sum[i]=arr[i]+sum[i-1];
        sum2[i]=arr2[i]+sum2[i-1];
    }

    for(int i=2; i<=n-1;i++){
        // 그림보면 확실히 이해가는 식
        int tmp1= sum[i-1] + sum[n-1]-arr[i];
        int tmp2=sum2[i-1]+sum2[n-1]-arr2[i];
       // cout<<tmp1<<" "<<tmp2<<endl;
        ans2= max(ans2,tmp1);
        ans3= max(ans3,tmp2);
    }
    //cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

    // 셋중 젤 maximum값 출력
    cout<<max(ans1,max(ans2,ans3))<<endl;
}