// 그램팬 - S1 - 2023/05/03
/*
내 풀이 방식은 맞았다. int를 넘어가는 overflow때문에.. 많은 시간을 쏟았지
아무리 떠올려봐도 반례가 생각나지 않을때는 -> 자료형 overflow가 아닐까 생각해보자(50퍼틀)
단톡방에서 이렇게 "B~Y까지 24개니까 (99976/2)^2 이면 24억어쩌고 나오는거같은데" 라고 했는데
정확히 뭔뜻인지는 모르겠다.. ((십만-24)/2)^2 인가 ㅇㅅㅇ?
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
string s;
vector<pair<string,ll>>temp;
ll ans =0;
bool vis[100002];
int main(){
    cin>>s;
    for(ll i=0 ; i<s.size() ; i++){
        if(s[i] == 'A'){
            temp.push_back({"A", i});
        }
    }
    if(temp.empty() or s.size()<26){cout<<0<<endl;exit(0);}
    vector<ll>t;
  
    for(auto &e : temp){
        t.push_back(e.second);
    }
    ll chk = 0;
    for(ll i=1 ; i<t.size() ;i++){
        if(t[i]-t[chk]==1){vis[t[i]]=1; chk=i;continue;}
        else {chk=i;continue;}
    }
    while(not temp.empty()){
        string tmp="A";
        ll index=0;
        ll idx = temp.back().second;
        //cout<< "idx"<<idx << endl;
        if(vis[idx]==1){
            temp.pop_back();
            continue;
        }
        temp.pop_back();
        for(ll i = idx+1; i<s.size() ; i++){
            if(s[i] >=tmp[index] and s[i]<tmp[index]+2){tmp.push_back(s[i]);index++;}
            else break;
        }
        // 문자열.substr(시작 위치, 길이)
        //tmp = tmp.substr(1,tmp.size());
        if(tmp.size() <26)continue;
        ll acnt =0;
        ll zcnt=0;
        for(auto &e : tmp){
            if(e=='A')acnt++;
            if(e=='Z')zcnt++;
        }
        ans+=acnt*zcnt;
        //cout<<tmp<<endl;
    }
    cout<<ans<<endl;
}
/*
주석 달아둔 부분
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector<pair<string,int>>temp;
int ans =0;
bool vis[100002];
int main(){
    cin>>s;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] == 'A'){ // s에서 A가 나오는부분만 따로
            temp.push_back({"A", i});// temp에 넣어둡니다 인덱스와 함께
        }
    }
    if(temp.empty() or s.size()<26){cout<<0<<endl;exit(0);}
    // A가 없거나 s가 최소가능길이보다 작다면 0출력하고 끝
    vector<int>t;
  
    for(auto &e : temp){
        t.push_back(e.second);// temp에서 두번째값인 A가 나오는 부분의 인덱스를 t벡터에 push
    }
    int chk = 0;
    for(int i=1 ; i<t.size() ;i++){// t의 사이즈가 2이상이면 해당 for문으로 진입
        if(t[i]-t[chk]==1){//A가 붙어있을때
            vis[t[i]]=1; // 그때의 인덱스를 1로 두기
            chk=i; // 현재값을 chk i는 ++됨
            continue;
        }
        else {chk=i;continue;} // 아니면 chk값만 i로 바꾸기
    }
    while(not temp.empty()){// temp가 비어있지않을때 while문 계속 실행
        string tmp="A";
        int index=0;
        int idx = temp.back().second;
        if(vis[idx]==1){// 아까 위에서 vis값이 1이면 AAABCD~ 이런식으로 A가 붙어있다는뜻이므로
            temp.pop_back();// temp를 뒤에서 pop하고 
            continue;// continue
        }
        temp.pop_back(); // vis값이 1이 아니면 일단 temp를 pop하고
        for(int i = idx+1; i<s.size() ; i++){// idx+1부터 s가 끝날때까지 for문
            if(s[i] >=tmp[index] and s[i]<tmp[index]+2){// idx+1부터 끝날때까지의 char값이 
                // 현재위치의 char값과 같거나 크지만 그렇다고 2 이상 차이가 나지 않을때(ABBCC~는 되지만, ABBDK~ 는 안됨)
                tmp.push_back(s[i]);//tmp라는 string에 push하고
                index++;// index값을 ++해서 다음값과 비교
            }
            else break;// ABBDK~같은 경우면 바로 break
        }
        if(tmp.size() <26)continue;// 만들어진 tmp가 26보다 작으면 최소가능 그램팬 길이보다 작은거니까 무시하고 continue
        int acnt =0;
        int zcnt=0;
        for(auto &e : tmp){// 만들어진 tmp는 A~Z까지 순서대로 있는 string이므로 
            if(e=='A')acnt++;
            if(e=='Z')zcnt++;
        }// 해당 string에서 a와 z를 카운트한것의 곱셉이 
        ans+=acnt*zcnt; // 최종 answer에 더해지면 답
    }
    cout<<ans<<endl;//이라고 생각하는데 왜 50퍼틀일까요 ㅜ
}
*/