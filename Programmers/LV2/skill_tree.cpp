// 스킬트리 - LV2 - 2023/06/17
/*
구현문제인데 생각을 못했던 부분이 뭐냐면
1 2 3 4 이런 애들은 되는데
1 3 4 는 안되는거야
그래서 sort하고 나서 +1씩 되는 숫자의 오름차순을 계산했어야했음!
*/
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int chk[26];
int solution(string s, vector<string> st) {
    int tt=1;
    for(int i=0 ; i<s.size() ; i++){
        chk[s[i]-'A']=tt;
        tt++;
    }
    int ans =0;
    for(auto &e : st){
        // 2 0 1 3 0
        // 1 2 0 3 0
        // 0 0 1 2 
        // 2 3 0
        vector<int>tmp;
        for(int i=0; i<e.size();i++){
            char now = e[i];// B
            if(chk[now-'A']==0){
                continue;
            }
            else{
                tmp.push_back(chk[now-'A']);
            }
        }
        // 0 0  1 2 
        if(tmp.empty()){ans++;continue;}
        vector<int>tmp2;
        tmp2=tmp;
        sort(tmp.begin(), tmp.end());
        int tk=1;
        if(tmp2 == tmp and tmp2.front() == 1){
            bool flag =0;
            for(auto &e : tmp){
                if(e==tk){
                    tk++;
                }
                else {flag=1;break;}
            }
            if(flag==1)continue;
            else ans++;
        }
        else continue;
    }
    return ans;   
}