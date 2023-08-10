//Java vs C++ - S3 - 2023/08/10
// 조건분기 많긴한데 한방에 풀어따 후후
#include<iostream>
#include<string>
using namespace std;
string s;
void Error(){
    cout<<"Error!"<<endl;
    exit(0);
}
void java_to_cpp(string s){
    string tmp ="";
    for(int i=0; i<s.size() ;i++){
        if(s[i]>='a' and s[i]<='z')tmp+=s[i];
        if(s[i]>='A' and s[i]<='Z'){
            tmp.push_back('_');
            tmp.push_back(char(s[i]-'A'+'a'));// 소문자로 바꿔서 넣어줌
            // s[i]-'A'만 하면 숫자로 나오니까 'a'만큼의 숫자를 더해줘서
            //소문자로 바꾸고 char로 해줘야 문자로 바뀜
        }
    }
    cout<<tmp<<endl;
}
void cpp_to_java(string s){
    string tmp=""; 
    bool flag=0; 
    for(int i=0; i<s.size() ;i++){
        if(flag==1){
            tmp.push_back(char(s[i]-'a'+'A'));
            flag=0;continue;
        }
        else{
            if(s[i]=='_'){flag=1;continue;}
            else tmp+=s[i];
        }
    }
    cout<<tmp<<endl;
}
int main(){
    cin>>s;
    // tele_com_ -> 이런건 에러
    // cpp형태 -> long_and_mnemonic_identifier
    // java형태 -> longAndMnemonicIdentifier, bAEKjoon
    bool flag= 0;
    // cpp형태인지 확인
    for(int i=0; i<s.size() ;i++){
        if(s[i]>='a' and s[i]<='z')continue;
        if(s[i]=='_'){
            if(i==0 or i==s.size()-1) Error(); // cpp도 아니고 java도 아닌 경우
            if(i<s.size()-1 and s[i+1]=='_')Error();// __이런 경우
            else continue;
        }
        if(s[i]>='A' and s[i]<='Z')flag=1;
    }
    if(flag==0){//cpp 형태이거나 둘다 되는 형태
        bool chk=0;
        for(int i=0; i<s.size();i++){
            if(s[i]>='a' and s[i]<='z')continue;
            else {chk=1;break;}
        }
        if(chk==1){cpp_to_java(s);}
        else{ cout<<s<<endl;exit(0);}// 둘다되는 형태니까
    }
    if(flag==1){// 일단 cpp은 아니니까 java형태인지 확인
        for(int i=0; i<s.size() ;i++){
            if(i==0){
                if(s[i]>='A' and s[i]<='Z') Error();// 첫글자가 대문자인 경우
                else continue;
            }
            else{
                if(s[i]>= 'a' and s[i]<='z' or s[i]>='A' and s[i]<='Z')continue;//대문자,소문자면 pass
                else Error();// 그 외의 경우
            }
        }
        java_to_cpp(s);
    }
}