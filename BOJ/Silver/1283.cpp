#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define endl "\n"
using namespace std; 

int n; 
int Alpha[26];
vector<pair<char, int>> ans;

int main() {
    cin >> n;
    cin.ignore();// 버퍼비우기
    int cnt = 0;
    while (n--) {
        string s;
        getline(cin, s);// 공백포함해서 입력받기 
        string tmp = "";
        vector<string> v;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                v.push_back(tmp);
                tmp = "";
            } else {
                tmp.push_back(s[i]);
            }
        }
        v.push_back(tmp); // v에 공백을 기준으로 나눠서 넣어줌

        bool flag = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i][0] >= 'a' && v[i][0] <= 'z') {
                if (Alpha[v[i][0] - 'a'] != 1) {
                    Alpha[v[i][0] - 'a'] = 1;
                    flag = 1;
                    int pos = s.find(v[i][0], s.find(v[i]));// find함수는 찾는 문자가 없으면 npos를 반환
                    // s.find( 찾을 문자열 , 시작 위치 , 찾을 문자열의 길이 )
                    // v[i]의 첫번째 문자열을 찾고, 그 문자열이 나온 위치를 반환
                    ans.push_back({v[i][0], pos});
                    break;
                }
            }
            if (v[i][0] >= 'A' && v[i][0] <= 'Z') {
                if (Alpha[v[i][0] - 'A'] != 1) {
                    Alpha[v[i][0] - 'A'] = 1;
                    flag = 1;
                    int pos = s.find(v[i][0], s.find(v[i]));
                    ans.push_back({v[i][0], pos});
                    break;
                }
            }
        }

        if (not flag) {
            bool fflag = 0;
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v[i].size(); j++) {
                    char e = v[i][j];
                    if (e >= 'a' && e <= 'z') {
                        if (Alpha[e - 'a'] == 1) continue;
                        else {
                            Alpha[e - 'a'] = 1;
                            fflag = 1;
                            ans.push_back({e, s.find(e, s.find(v[i]))});
                            break;
                        }
                    }
                    if (e >= 'A' && e <= 'Z') {
                        if (Alpha[e - 'A'] == 1) continue;
                        else {
                            Alpha[e - 'A'] = 1;
                            fflag = 1;
                            ans.push_back({e, s.find(e, s.find(v[i]))});
                            break;
                        }
                    }
                }
                if (fflag) break;
            }

            if (not fflag) {
                ans.push_back({'-', -1});
            }
        }

        string realans = "";
        for (int i = 0; i < s.size(); i++) {
            if (i == ans[cnt].second) {
                realans.push_back('[');
                realans.push_back(s[i]);
                realans.push_back(']');
            } else {
                realans.push_back(s[i]);
            }
        }
        cout << realans << endl;
        cnt++;
    }
}