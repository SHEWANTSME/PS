// 정수삼각형 - LV3 - 2023/03/06
// 예전에 백준에서 푼 1932과 똑같은 문제 다만, 내가 vector<vector<int>>꼴을
// 잘 안써서 헷갈렸던 부분의 문법이 존재했음
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[502][502];
int solution(vector<vector<int>> semo) {
    int sz = semo.size();
    // 이처럼 그냥 이중벡터의 size를 말할때는 
    // arr[x][y] 일때 x 값임. y는 push_back되는 벡터마다 다르겠죵
    dp[0][0]=semo[0][0];
    if(sz==1)return dp[0][0];
    dp[1][0] = dp[0][0]+semo[1][0];
    dp[1][1] = dp[0][0]+semo[1][1];
    if(sz==2)return max(dp[1][0],dp[1][1]);
    else{
        for(int i=2 ; i<sz; i++){
            for(int j=0 ; j<=i ; j++){
                if(j==0)dp[i][j] = dp[i-1][j]+semo[i][j];
                else if(j==i)dp[i][j]=dp[i-1][j-1]+semo[i][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+semo[i][j];
            }
        }
    int mx = -1;
    for (int i = 0; i <sz; i++) 
        mx = (mx > dp[sz-1][i]) ? mx : dp[sz-1][i]; 
    return mx;
    }
    // 알고리즘은 딱히 뭐 없음. 바로 생각이 나기 때문
}

// 요기서부터는 헷갈려서 테스트 해보려고 해둠
int main(){
    vector<vector<int>>v;// 일단 선언하면
    vector<int>c;c.push_back(7);// 일차원 벡터를 선언 후 , 그 일차원 벡터에 값을 push_back한다
    vector<int>cc;cc.push_back(3);cc.push_back(8); // 이런식으로
    vector<int>ccc;ccc.push_back(8);ccc.push_back(1);ccc.push_back(0);
    vector<int>cccc;cccc.push_back(2);cccc.push_back(7);cccc.push_back(4);cccc.push_back(4);
    vector<int>ccccc;ccccc.push_back(4);ccccc.push_back(5);ccccc.push_back(2);ccccc.push_back(6);ccccc.push_back(5);
    v.push_back(c);// 그리고 이차원벡터에 저 위의 c~ccccc를 각각 push_back 한다.
    v.push_back(cc);
    v.push_back(ccc);
    v.push_back(cccc);
    v.push_back(ccccc);
    v.push_back(c); // 사이즈가 궁금해서 마지막 하나 더 해본결과 
   // cout<<v[0][0]<<endl;
cout<<v.size()<<endl; // 6이 나옴 (따지고 보면 현재 arr[6][5] 인 셈이니까)
   
   for(int i=0 ; i<4 ; i++){
        for(auto &e : v[i]){
            cout<< e << " ";
        }cout<<endl;
    }
                                // 7 
                                // 3 8 
                                // 8 1 0 
                                // 2 7 4 4 
}