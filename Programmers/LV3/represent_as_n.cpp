#include <iostream>
#include <unordered_set> // 중복을 허용하지 않는 set
#include <vector>
#include <string>
using namespace std;
// 프로그래머스 - LV3 - N으로 표현
/*
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
따라서 n=5, number=12인 경우에는 4를 return 하면 됩니다.

제한사항
* N은 1 이상 9 이하입니다.
* number는 1 이상 32,000 이하입니다.
* 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
* 최솟값이 8보다 크면 -1을 return 합니다.
*/

int solution(int n, int goal_num) {
    // dp[i]는 n을 정확히 i번 사용하여 만들 수 있는 모든 숫자의 집합입니다.
    vector<unordered_set<int>> dp(9);
    dp[1].insert(n);// 맨처음 경우 -> n을 1번 사용해서 만들 수 있는 수는 n밖에 없음
    if(n==goal_num){ // 예를 들어 n=5이고 goal_num =5이면 그냥 그 숫자를 바로 반환하면 되므로 1 리턴
        return 1;
    }
    // 최대 8번까지 시도
    for (int i = 2; i <= 8; i++) {// possible return value is 1~8 else return -1
        for (int j = 1; j < i; j++) {
            for (auto &x : dp[j]) {
                for (int y : dp[i - j]) {// 이렇게 해야 i=4이면 (1,3), (2,2), (3,1) 이런식으로 나눠서 계산 가능
                    dp[i].insert(x + y);// plus
                    dp[i].insert(x - y);// minus
                    dp[i].insert(x * y);// multiply
                    if (y != 0) {
                        dp[i].insert(x / y);// divide
                    }
                }
            }
        }
       //  dp[i].insert(10*i + i%10);// concatenate -> 이거 아님
        dp[i].insert(stoi(string(i, '0' + n)));// concatenate
        
        // 목표 숫자가 dp[i]에 포함되면 반환
        if (dp[i].find(goal_num) != dp[i].end()) {
            return i;
        }
    }
    
    // 목표 숫자를 만들 수 없을 경우 -1 반환
    return -1;
}

int main(){
    int n, goal_num;
    cin>>n>>goal_num;
    cout<<solution(n, goal_num)<<endl;
}
