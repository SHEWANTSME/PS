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