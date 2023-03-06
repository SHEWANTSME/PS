// 타겟 넘버 - LV2 - 2023/03/04
// 순서를 바꾸지 않고 적절히 더하고 빼서 타겟 넘버와 일치할때 cnt++하면 되겠군
// programmers는 내가 첨부터 짤 수가 없어서 불편하네..

#include <string>
#include <vector>
using namespace std;
// you don't actually have to use the solution function itself.
// just change the function to the customed one that can have more variables on it.
// this problem can be optimized with DP + DFS which I am not that much good at.

// 1. Just DFS
int ans=0; // 그냥 답을 전역으로 두고
void Func(vector<int>arr,int tar,int sum, int idx){
    if(idx==arr.size() and sum==tar){ans++;return;}
    if(idx==arr.size() and sum!=tar)return;
    Func(arr,tar,sum+arr[idx],idx+1);
    Func(arr,tar,sum-arr[idx],idx+1);
}
int solution(vector<int> numbers, int target) {
    Func(numbers,target,0,0); // 내가 다시 parameter를 조정해서 새로운 함수를 만드는게 편함
    // 앞으로 programmers는 이런식으로 하는게 나을듯
    return ans; // ans를 리턴하고
}


// 2. DP + DFS
#include <string>
#include <vector>
#include<string.h> // memset
using namespace std;

int dp[2001][20];//주어지는 숫자 개수 max=20
// dp배열이 int dp[가능숫자range][주어지는숫자개수]
int DP(vector<int>&arr, int tar,int sum,int idx){
    int &ret = dp[1000+sum][idx];// 각 숫자가 1 이상 50 이한데 
    // 극단적으로 -50 * 20개 하면 -1000이고 50*20 하면 1000이니까 
    // dp배열이 int dp[가능숫자range][주어지는숫자개수]
    if(ret != -1)return ret;
    if(idx == arr.size() and sum == tar)return 1;
    if(idx == arr.size() and sum!=tar)return 0;
    ret =0;
    ret+=DP(arr,tar,sum+arr[idx],idx+1);
    ret+=DP(arr,tar,sum-arr[idx],idx+1);
    return ret;
}

int solution(vector<int> numbers, int target) {
    int Ans = 0;
    memset(dp, -1, sizeof(dp));
    Ans = DP(numbers, target,0, 0);
    return Ans;
}
