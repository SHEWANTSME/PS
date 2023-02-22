// cpp로는 까다로움.. biginteger를 제공하지 않기 때문에
// string으로 바꿔준 다음 , 자리수에 있는 숫자마다 따로 계산을 해줘야함
// 비숍 - S3 - 2023/02/22
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
string Sum(string a, string b) {
    int as = a.size(); int bs = b.size();
    int diff = max(as, bs) - min(as, bs);
    if(as < bs) for(int i=0; i<diff; i++) a = "0" + a;
    if(as > bs) for(int i=0; i<diff; i++) b = "0" + b;
    vector<int> v;
    as=a.size();bs=b.size();
    for(int i=0; i<as; i++) v.push_back(a[i] - '0' + b[i] - '0');
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        if(v[i] < 10) continue;
        if(i==v.size()-1){v.push_back(v[i]/10);v[i] %= 10;}
        if(i!=v.size()-1){
            v[i+1] += v[i]/10;
            v[i] %= 10;
        }
    }
    reverse(v.begin(), v.end());
    string ans="";
    for(auto &e : v){
        if(e>=0 and e<=9)ans+=e+48;
        else continue;
    }
    char last = ans[ans.size()-1];
    if(last>='2'){// '0'=48 , '1'= 49  , '2'= 50 이니까
        ans.pop_back();
        ans.push_back(last-2);
        return ans;
    }
    else{ // 차근차근 생각해보면 로직 따라갈 수 있음
            string temp = "";
            bool chk= false;
            if(last=='1') temp.push_back('9');
            else if(last =='0')temp.push_back('8');
            for(int i = ans.size()-2 ; i>=0 ; i--){
                char now = ans[i];
                if(chk==true){temp.push_back(now);continue;}
                if(now=='0') temp.push_back('9');
                else {temp.push_back(now-1);chk=1;}
            }
            reverse(temp.begin(),temp.end());
            string realans="";
            for(int i=0 ; i<temp.size() ; i++){
                if(i==0 and temp[i]=='0')continue;
                realans.push_back(temp[i]);
            }
            return realans;
    }
 }
int main(){
    string s; cin>>s;
    if(s=="1" or s=="2") cout<<s<<endl;
    else cout<<Sum(s,s)<<endl;
}
/*
예를 들면
1. string 형태로 받음
a = 456   
b = 78    

2. 자릿수 맞춰줌
"456"
"078" 

3. 뒤집음(using reverse)
"654"
"870"

4. 올림 무시하고 걍 자리수마다의 값을 vector에 저장
a': "654"
b': "870"
-----------
v :    [14, 12, 4] 

5. 올림계산
[14,12,4] -> [4,13,4] -> [4,3,5]

6. 뒤집어주고 string화 해줘서 return
[4,3,5] -> [5,3,4] -> "534"
*/