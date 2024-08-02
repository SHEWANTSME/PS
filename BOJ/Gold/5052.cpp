// 전화번호 목록 - G4 - 2024/08/02

// 트라이로 풀 수 있다고 하는데 트라이 아직 모르니까 걍 정렬하고 해보자

//1. 그냥 푸는 방법
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string>phone_num;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for(int i=0;i<n;i++){
            string s; cin>>s;
            phone_num.push_back(s);
        }
        sort(phone_num.begin(), phone_num.end());
        // for(auto &e : phone_num){
        //     cout<<e<<endl;
        // }
        bool flag = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (phone_num[i].size() <= phone_num[i + 1].size() and phone_num[i] == phone_num[i + 1].substr(0, phone_num[i].size())) {
                //substr(a,b) -> a 인덱스부터 b길이만큼 문자열을 반환
                // substr(a)-> a 인덱스부터 끝까지 문자열을 반환
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        phone_num.clear();
    }
}

// 2. 트라이로 푸는 방법
// 그림 그려가면서 생각해보면 그나마 쉬움
//https://blog.encrypted.gg/1059 -> 참고

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

const int root = 1;//루트노드
int trie_size;// trie_size는 2부터 시작 -> 트라이
const int mx = 100001;//전화번호의 최대길이
bool chk[mx]; // 끝나는 지점인지 확인
int trie[mx][10];// trie[0][0]은 루트노드
int c2i(char c) { return c - '0'; }//문자를 숫자로 바꿔주는 함수
int n;
vector<string>phone_num;

void insert(string &s){//문자열을 트라이에 넣는 함수
    int cur = root;//루트노드부터 시작
    for(auto &c : s){//문자열을 돌면서
        int next = c2i(c);
        if(trie[cur][next]==0){//만약 다음 노드가 없다면
            trie[cur][next] = trie_size++;//새로운 노드를 만들어준다 -> 기존 trie_size를 trie[cur][next]에 넣어주고 trie_size를 1 증가시킨다
        }
        cur = trie[cur][next];//다음 노드로 이동
    }
    chk[cur] = 1;//끝나는 지점(마지막 노드)체크
}

bool find(string &s){//문자열이 트라이에 있는지 확인하는 함수
    int cur = root;//루트노드부터 시작
    for(auto &c : s){
        int next = c2i(c);
        if(trie[cur][next]==0){//만약 다음 노드가 없다면
            return 0;//없다고 반환
        }
        cur = trie[cur][next];//다음 노드로 이동
    }
    int sum = 0;
    for(int i=0;i<10;i++){
        sum+=trie[cur][i];//만약 끝나는 지점이라면 다음 노드가 없어야 하므로 sum이 0이어야 한다
    }
    if(sum==0) return 1;//sum이 0이면 끝나는 지점이므로 1 반환
    else return 0;//아니면 0 반환
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        memset(trie,0,sizeof(trie));
        memset(chk,0,sizeof(chk));
        // 초기화
        trie_size = 2;//루트노드와 끝나는 지점을 포함한 2부터 시작
        phone_num.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            string s; cin>>s;
            phone_num.push_back(s);
            insert(phone_num[i]);//트라이에 전화번호를 넣어준다
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=find(phone_num[i]);//트라이에 있는지 확인
        }
        if(ans<n)cout<<"NO"<<endl;//하나라도 통과하지 못하면 NO -> 포함되는 전화번호가 있으니 NO
        else cout<<"YES"<<endl;//모두 통과하면 YES -> 포함되는 전화번호가 없으니 YES
    }
}