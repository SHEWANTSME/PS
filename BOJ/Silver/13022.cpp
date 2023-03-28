// 늑대와 올바른 단어- S2 - 2023/03/28
// 규칙을 잘 지키고 풀어보자 (regex가 익숙해지면 regex로도 풀어보자)
/*
1. 임의의 양의 정수 n에 대해서, 'w'가 n번 나오고, 그 다음에 'o'가 n번, 그 다음에 'l'이 n번, 그 다음에 'f'가 n번 나온 단어는 올바른 단어이다.
2. 올바른 단어 두 개를 이은 단어도 올바른 단어이다.
3. 1번과 2번 조건으로 만들 수 있는 단어만 올바른 단어이다.

*/
// 단어의 길이가 50보다 작기 때문에 -> wwwooolllfff 6*4 8*4 9*4 12*4
// 한 단어의 맥시멈 길이가 wwwwwwwwwwwwoooooooooooollllllllllllffffffffffff임.
// 조금 생각할게 있긴 하지만 그렇다고 너무 어려운 편은 아님 
// 규칙에 따라 풀어주면 된다.
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
string s;
map<char,int>mp;
int chk_idx=0;
void chk_str(string pre, int sz){
    if(chk_idx>=s.size()){
        //cout<<pre<<endl;
        if(pre == s){
            cout<<1<<endl;
            exit(0);
        }
        else{
            cout<<0<<endl;
            exit(0);
        }
        //cout<<1<<endl;
        return;
    }
    string temp ="";
    int cnt =0;
    for(int i=sz ; i<s.size() ;i++){
        if(s[i]=='w')cnt++;
        else break;
    }
    if(cnt==0){//wolffwwoollf -> 반례 
        cout<<0<<endl;exit(0);
    }
    //wwwooolllfff  였다면 처음에
    // cnt=3 -> sz+cnt-1
    // ww oo ll ff www ooolllfff 이면
    // 8+3-1
    
    for(int i=0 ; i<cnt ; i++) temp.push_back('w');
    for(int i=0 ; i<cnt ; i++) temp.push_back('o');
    for(int i=0 ; i<cnt ; i++) temp.push_back('l');
    for(int i=0 ; i<cnt ; i++) temp.push_back('f');
    pre+=temp;
    
   // cout<<pre<<endl;
    if(pre == s){
        cout<<1<<endl; exit(0);
    }
    else{
        chk_idx+=(cnt*4);
        chk_str(pre, chk_idx);
    }
}
int main(){
    cin>>s;
    for(int i=0 ; i<s.size() ;i++){
        mp[s[i]]++;
    }
    if(mp['w'] == mp['o'] and mp['o']==mp['l'] and mp['l']==mp['f']){
        chk_str("",0);
        //cout<<0<<endl;
    }
    else{
        cout<<0<<endl;
        exit(0);
    }
}