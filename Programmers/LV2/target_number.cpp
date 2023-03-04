// 타겟 넘버 - LV2 - 2023/03/04
// 순서를 바꾸지 않고 적절히 더하고 빼서 타겟 넘버와 일치할때 cnt++하면 되겠군
// programmers는 내가 첨부터 짤 수가 없어서 불편하네..
#include <string>
#include <vector>
#include <cstring>
 
using namespace std;
 
int cache[2001][20];
int dfs(int here, const vector<int>& numbers, const int& target, int sum)
{
    int& ret = cache[1000 + sum][here];
    if(ret != -1) return ret;
    if(here == numbers.size())
        if(sum == target) return 1;
        else return 0;
    
    ret = 0;
    ret += dfs(here + 1, numbers, target, sum + numbers[here]);
    ret += dfs(here + 1, numbers, target, sum - numbers[here]);
    
    return ret;
}
 
int solution(vector<int> numbers, int target) {
    int answer = 0;
    memset(cache, -1, sizeof cache);
    answer = dfs(0, numbers, target, 0);
    
    return answer;
}

#include <string>
#include <vector>
using namespace std;
// you don't actually have to use the solution function itself.
// just change the function to the customed one that can have more variables on it.
// this problem can be optimized with DP + DFS which I am not that much good at.
int ans=0;
void Func(vector<int>arr,int tar,int sum, int idx){
    if(idx==arr.size() and sum==tar){ans++;return;}
    if(idx==arr.size() and sum!=tar)return;
    Func(arr,tar,sum+arr[idx],idx+1);
    Func(arr,tar,sum-arr[idx],idx+1);
}
int solution(vector<int> numbers, int target) {
    Func(numbers,target,0,0);
    return ans;
}
// comment는 이따가 다시 수정해서 달아두자.