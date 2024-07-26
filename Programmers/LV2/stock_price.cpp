#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans;
    for(int i=0; i<prices.size()-1;i++){
        int now = prices[i]; int cnt=0;bool flag=0;
        for(int j=i+1;j<prices.size();j++){
            int nxt = prices[j];
            if(now<=nxt)cnt++;
            else {flag=1;break;}
        }
        if(flag) ans.push_back(cnt+1);
        else ans.push_back(cnt);
    }
    ans.push_back(0);
    return ans;
}