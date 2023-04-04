// // 괄호의 값 - S1 - 2023/03/29
// #include<iostream>
// #include<stack>
// #include<algorithm>
// #include<vector>
// #include<map>
// #include<string>
// using namespace std;
// string s; 
// // ( :40 , ) :41 , [ : 91, ] : 93
// // (()[[]]) : correct
// // (())[][] : correct
// // ([)] , (()()[] : incorrect
// // () = 2, [] = 3 , (alpha) - >2*alpha , [alpha]-> 3*alpha, alphabeta = alpha+beta
// //   [()[()[()]]]
// //[2[2[2]]] = [2[2 6]] = [2[8]] = [2 24] = [26] = 26*3 = 78
// //([)]  , )(
// // 그리고 중첩되었는지, 나란한지 여부 조건을 나눠야함
// //[[(([[([(([]))])]]))]]
// //stack<char>stk;
// stack<pair<char,int>>stk; // 현재 괄호와 인덱스를 pair로 받자
// map<char,int>mp;
// int main(){
//     cin>>s;
//     for(int i=0 ; i<s.size() ; i++) mp[s[i]]++;
//     if((mp['('] == mp[')']) and (mp['['] == mp[']']) and (s[0]=='(' or s[0]=='[')){
//         stk.push(s[0]);
//         for(int i=1; i<s.size() ; i++){
//             char now = s[i];
//             stk.push(now);
//             if(stk.top() == '(' and now == ')')
//         }
//     }
//     else cout<<0<<endl;

// }

// // 규칙을 찾아따
// // 빈 string을 따로 만든다음 거기에 계산된 값을 넣어둬
// // 중첩된놈은 음.. 아냐 저렇게 하면 반드시 꼬임

// 늦었지만 4월4일 다시 시도해보도록 한다.
// 분배법칙을 사용해서 해보자.
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
string s;
stack<char>stk;
vector<int>realans;
// int main(){
//     cin>>s;
//     int temp = 1;
//     int ans = 1;
//     for(int i=0; i<s.size() ; i++){
//         char now = s[i];
//         if(stk.empty()){
//             if(now == ')' or now ==']'){
//                 cout<<i<<endl;
//                 cout<<"맨첨"<<endl; exit(0);
//             }
//             stk.push(now);
//             if(now =='('){
//                 temp*=2;
//                 ans= temp;
//             }
//             if(now == '['){
//                 temp*=3;
//                 ans = temp;
//             }
//         }
//         else{
//             if(stk.top()=='('){
//                 if(now == ')'){
//                   //  ans *=2;
//                     realans.push_back(ans);
//                     ans =1;
//                     stk.pop();
//                     temp/=2;
//                     continue;
//                 }
//                 if(now == '('){
//                     temp*=2;
//                     ans = temp;
//                     stk.push('(');
//                     continue;
//                 }
//                 if(now == '['){
//                     temp*=3;
//                     ans=temp;
//                     stk.push('[');
//                     continue;
//                 }
//                 else{cout<<"두번"<<endl;exit(0);}
//             }
//             if(stk.top()=='['){
//                 if(now == ']'){
//                    // ans*=3;
//                     realans.push_back(ans);
//                     ans =1;
//                     stk.pop();
//                     temp/=3;
//                     continue;
//                 }
//                 if(now == '['){
//                     temp*=3;ans=temp;
//                     stk.push('[');
//                     continue;
//                 }
//                 if(now == '('){
//                     temp*=2;ans=temp;
//                     stk.push('(');
//                     continue;
//                 }
//                 else{cout<<"세번"<<endl;exit(0);}
//             }

//         }


//     }
//     int res = 0;
//     for(auto &e : realans){
//         if(e==1)continue;
//         cout<<e<<endl;
//         res+=e;
//     }
//     cout<<res<<endl;
// }
int main(){
    cin>>s;
    int temp = 1;
    int ans = 1;
    for(int i=0; i<s.size() ; i++){
        char now = s[i];
        if(stk.empty()){
            if(now == ')' or now ==']'){
                //cout<<i<<endl;
                cout<<0<<endl; exit(0);
            }
            stk.push(now);
            if(now =='('){
                temp*=2;
                ans= temp;
            }
            if(now == '['){
                temp*=3;
                ans = temp;
            }
        }
        else{
            if(stk.top()=='('){
                if(now == ')'){
                  //  ans *=2;
                    realans.push_back(ans);
                    ans =1;
                    stk.pop();
                    temp/=2;
                    continue;
                }
                if(now == '('){
                    temp*=2;
                    ans = temp;
                    stk.push('(');
                    continue;
                }
                if(now == '['){
                    temp*=3;
                    ans=temp;
                    stk.push('[');
                    continue;
                }
                else{cout<<0<<endl;exit(0);}
            }
            if(stk.top()=='['){
                if(now == ']'){
                   // ans*=3;
                    realans.push_back(ans);
                    ans =1;
                    stk.pop();
                    temp/=3;
                    continue;
                }
                if(now == '['){
                    temp*=3;ans=temp;
                    stk.push('[');
                    continue;
                }
                if(now == '('){
                    temp*=2;ans=temp;
                    stk.push('(');
                    continue;
                }
                else{cout<<0<<endl;exit(0);}
            }

        }


    }
    int res = 0;
    for(auto &e : realans){
        if(e==1)continue;
        //cout<<e<<endl;
        res+=e;
    }
    if(not stk.empty()){
        cout<<0<<endl;
        exit(0);
    }
    cout<<"여긴가";
    cout<<res<<endl;
}