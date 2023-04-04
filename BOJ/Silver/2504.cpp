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




//-----------R---------E----------------



// 늦었지만 4월4일 다시 시도해보도록 한다.
// 분배법칙을 사용해서 해보자.
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack> // 필요할 것 같은 내용들 싹 다 include
using namespace std;
string s;
stack<char>stk; // 질문 보니까 stack<char>가 overflow라던데 통과하던데?
vector<int>realans; // 최종 realans를 담는 vector
int main(){
    // 분배법칙을 사용해서 푸는것이 포인트! 
    // 분배법칙을 사용하지 않고 괄호를 어떻게 포인트를 잡을까 생각해봤는데
    // 너무 어려워짐.. -> s1이 이정도가 아닐텐데? 하고 포기
    /*
    ( ( ( []() ) []  ) )
    = 2*2*2*3 + 
    현재 temp= 2*2*2
    분배법칙 + temp + 경우 divide 하면 될듯??

    ( () [ () ] () [() ] )
    2*( 2+(3*2)+2+(3*2))
    =2*2  + 2*3*2 + 2*2 + 2*3*2
    */
    cin>>s;
    int temp = 1;
    int ans = 1;
    for(int i=0; i<s.size() ; i++){
        char now = s[i];
        if(stk.empty()){ // 스택이 비어있을떄 경우를 나눠
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
        else{// 1개 이상 있을떄는  이런식으로 ㅇㅅㅇ..
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
                else{cout<<0<<endl;exit(0);}// 각각에 말도안되는경우는 즉각 처결
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
        if(e==1)continue; // 문제는 풀었지만 왜 e=1이 나오는 경우가 있는지
        // 왜 위에서 먼저 ans=1일때 거르면 에러가 뜨는지는 모르겠지만
        // 나중에 생각해보자.
        //cout<<e<<endl;
        res+=e;
    }
    if(not stk.empty()){ // 이거때매 30분 고민함
    // 이거 안하면 -> (((())이런문제에서 걍 2*2*2*2 = 16이 나옴
        cout<<0<<endl; // 걸러주고
        exit(0);
    }
    //cout<<"여긴가";
    cout<<res<<endl; // 나머지는 res값으로 출력
}