#include<iostream>
#include<string>
#include<map>
// 베스트셀러 - S4- 2023/05/17
// PS좀 다시 제대로 하자
#include<algorithm>
#include<vector>
#define pp pair<string,int>
using namespace std;
int n;
map<string,int>mp;
int main(){
    cin>>n;
    while(n--){
        string s;cin>>s;
        mp[s]++;// 아 참고로 multimap은 이거 안되고 무조건 insert로만 해야함
        ///mp.insert({s,1}); -> using multimap 이런식으로
    }
    vector<pp>v(mp.begin(),mp.end());
    sort(v.begin(), v.end(), [](pp a, pp b) {// 이건 lambda func
        if(a.second==b.second){ // std::sort가 unstable한 sort라서 미심쩍을때는 항상 조건을 달아두는게 좋음
            return a.first<b.first;// 같은횟수 -> 기존대로
        }
		else return a.second > b.second;// 아니면 sec가 더 큰놈으로 sort
	});
    cout<<v.front().first;
}
// 자세한 그림+ 채팅내용은 내아이디로 로그인하고 https://www.acmicpc.net/problem/1302 가보셈