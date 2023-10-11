//타이핑 - S1 - 2023/10/08
// 1. greedy 풀이
#include <iostream>
#include <string>
#include <cctype>// islower(),isupper()
using namespace std;
string s;
int main() {
    cin>>s;
    bool flag=0;//마름모 activate 여부
    int cnt=0;//특수문자 타이핑 횟수
    for (int i=0; i <s.size(); i++) {
        if (i == s.size() - 1) {//마지막 문자
            if (not flag && isupper(s[i])) cnt++;//마름모 비활성 + 마지막문자 대문자-> 별 눌러줘야하니 cnt++
            else if (flag && islower(s[i])) cnt++;//마름모 활성 + 마지막문자 소문자-> 별 눌러줘야하니 cnt++
        } else {
            if (not flag) {//마름모 비활성
                if (isupper(s[i])) {//현재문자 대문자
                    if (isupper(s[i+1])) flag=1;//다음문자도 대문자면 마름모 활성
                    cnt++;//다음문자는 소문자니까 별 눌러줘야하니 cnt++
                }
            } else {//마름모 활성
                if (islower(s[i])) {//현재문자 소문자
                    if (islower(s[i+1])) flag=0;//다음문자도 소문자면 마름모 비활성
                    cnt++;//다음문자는 대문자니까 별 눌러줘야하니 cnt++
                }
            }
        }
    }
    cout<<s.size()+cnt<<endl;//문자열 길이 + cnt횟수
}
// 2. dp 풀이
int dp[3001][2];
string s;
int main(){
    cin>>s;
    if(islower(s[0])){
        dp[0][0]=1;
        dp[0][1]=2;
    }
    if(isupper(s[0])){ 
        dp[0][0]=2;
        dp[0][1]=2;
    }
    for(int i=1; i<s.size() ; i++){
        if(islower(s[i])){
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
        }
        else{
            dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
        }
    }
    cout << min(dp[s.size() - 1][0], dp[s.size() - 1][1]);   
}
