// 창영이의 일기장 - B2 - 2023/03/28
// 그냥 하라고 하는대로 하면 된다. index 넘기기 
//1. 그냥 하라는대로 하기
#include<iostream>
#include<string>
using namespace std;
int main(){
    string t;
    getline(cin,t);
    string ans="";
    for(int i=0 ; i<t.size() ; i++){
        if(i==t.size()-1)ans.push_back(t[i]);
        else{
            ans.push_back(t[i]);
             if(t[i] == 'a' or t[i]=='e' or t[i]=='i' or t[i]=='o' or t[i]=='u'){
                 i+=2;continue;
             }   
            else continue;
        }
    }
    cout<<ans<<endl;
}

//2. Regex 사용
#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s); // ' ' 포함한 cin -> using getline(cin,s);
    regex pattern("([aeiou])(p\\1)"); // 소문자 aeiou와  "p"는 그대로 소문자 p를 나타냅니다. 
    //, 첫 번째 모음을 찾아내고 그것을 역참조(\1)하여 그 뒤에 "p"와 같은 모음이 나오는지를 확인해야 합니다.
    //예를 들어, 문자열 "aba"가 주어졌을 때, 이 문자열에서는 "a" 다음에 "b"가 나오므로 해당 패턴에 일치하지 않습니다. 
    // 그러나 "a" 다음에 "b"가 아닌 "a"가 나오므로, "a"와 "a" 사이의 "b"를 제거한 결과 "aa"가 출력되어야 합니다.
    // 역참조!! \1
    string result = regex_replace(s, pattern, "$1");
    // 문자열에서 정규표현식와 일치하는 부분을 다른 문자열로 대체해주는 regex_replace
    // regex_replace의 처음인자 -> 대상 문자열, 두번쨰인자 -> regex패턴, 세번쨰-> 대체할 문자열
    cout << result << endl;
    // 위에서 예시로 든 코드에서는, std::regex_replace() 함수를 사용하여
    // "모음+p+같은 모음" 패턴을 찾아 첫 번째 모음으로 대체.
    // 이렇게 대체된 문자열을 새로운 문자열로 저장해서 출력.
    return 0;
}
