// 단어 뒤집기 - B1 - 2023/04/09
// 별 내용 없음. cin.ignore() 사용법만 알아두셈
// https://namwhis.tistory.com/entry/cin%EA%B3%BC-getline%EC%9D%84-%EA%B0%99%EC%9D%B4-%EC%82%AC%EC%9A%A9%ED%95%A0%EB%95%8C-cinignore%EC%9D%B4-%ED%95%84%EC%9A%94%ED%95%9C-%EC%9D%B4%EC%9C%A0-%EA%B8%B0%EB%A1%9D

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int tc;
int main() {
    cin >> tc;
    cin.ignore(); // ignore를 여기다 붙여하됨.. 그래야 뒤에서 getline을 용이하게 쓰지
    while(tc--) {
        string s;
        getline(cin, s);//띄어쓰기포함 string
        vector<string> words;
        string tmp="";
        for (char &e : s) {
            if (e == ' ') {
                words.push_back(tmp);
                tmp="";
            }
            else tmp.push_back(e);
        }
        words.push_back(tmp);
        for(int i=0 ; i<words.size() ; i++){
            for(int j=words[i].size()-1 ; j>=0 ; j--){
                cout<<words[i][j];
            }
            if(i==words.size()-1) cout<<endl;
            else cout<<" ";
        }
    }
}