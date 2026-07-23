#include <string>
#include <vector>

using namespace std;

// dp1 : 첫 번째 집을 포함하는 경우
//       => 마지막 집은 선택할 수 없음
int dp1[1000001];

// dp2 : 첫 번째 집을 포함하지 않는 경우
//       => 마지막 집 선택 가능
int dp2[1000001];

int solution(vector<int> money) {

    // 집이 3개인 경우는
    // 첫 번째와 마지막이 연결되어 있으므로
    // 한 집만 선택할 수 있다.
    if(money.size()==3){
        int maxx = -1;
        for(int i=0; i<3; i++)
            maxx = max(maxx, money[i]);
        return maxx;
    }

    //-------------------------------
    // Case 1 : 첫 번째 집을 선택하는 경우
    //-------------------------------

    // 첫 번째 집까지 고려했을 때 최대 금액
    dp1[0] = money[0];

    // 두 번째 집까지 고려
    // 첫 번째 집 또는 두 번째 집 중 큰 값 선택
    dp1[1] = max(money[0], money[1]);

    //-------------------------------
    // Case 2 : 첫 번째 집을 선택하지 않는 경우
    //-------------------------------

    // 첫 번째 집은 선택하지 않으므로 0
    dp2[0] = 0;

    // 두 번째 집부터 시작
    dp2[1] = money[1];

    // 점화식
    // dp[i] = max(
    //      i번째 집을 털지 않는 경우 : dp[i-1]
    //      i번째 집을 터는 경우     : dp[i-2] + money[i]
    // )
    for(int i=2; i<money.size(); i++){

        // 첫 번째 집을 선택한 경우
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);

        // 첫 번째 집을 선택하지 않은 경우
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }

    // Case1은 마지막 집을 선택할 수 없으므로 n-2까지의 결과 사용
    // Case2는 마지막 집까지 선택 가능하므로 n-1 사용
    int ans = max(dp1[money.size()-2],
                  dp2[money.size()-1]);

    return ans;
}