//에르다 노바와 오리진 스킬 - S4 - 2023/09/08
// 문제가 좀 긴데, 잘 읽고 정렬하고 풀면 됨
// 면역시간은 필요 없는 조건이란걸 알 수 있음
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int n,m;
int cnt_erda=1,cnt_orig=1;
deque<int>erda;
deque<int>orig;
int main(){
    cin>>n>>m;
    for(int i=1; i<=n;i++){
        int t;cin>>t;erda.push_back(t);
    }
    for(int i=1; i<=m;i++){
        int t;cin>>t;orig.push_back(t);
    }
    sort(erda.begin(),erda.end());
    sort(orig.begin(),orig.end());
    int erda_fir = erda[0];
    int orig_fir=orig[0];
    for(int i=1; i<erda.size(); i++){
        int now = erda[i];
        if(now-erda_fir>=100){
            cnt_erda++;
            erda_fir=now;
            continue;
        }
        else continue;
    }
    for(int i=1; i<orig.size();i++){
        int now = orig[i];
        if(now-orig_fir>=360){
            cnt_orig++;
            orig_fir=now;
            continue;
        }
        else continue;
    }
    cout<<cnt_erda<<" "<<cnt_orig<<endl;
}