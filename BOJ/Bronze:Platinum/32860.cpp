// 수수수수퍼노바 - B2 - 2024/12/26
#include<iostream>
#include<queue>
using namespace std;
int a,b;
queue<int>q;
int main(){
    cin>>a>>b;
    if(b<=26){
        cout<<"SN "<<a<<char(b+'A'-1)<<endl;
    }
    else{
        for(int i = 'a'; i<='z';i++){
            if(b>26*(i-'a'+1) and q.empty()){
                q.push(26*(i-'a'+1));
            }
            if(b>26*(i-'a'+1) and not q.empty()){
                q.pop();
                q.push(26*(i-'a'+1));
            }
        }
        cout<<"SN "<<a;
        cout<<char((q.front()/26) + 'a'-1);
        for(int i='a'; i<='z'; i++){
            if(i-'a'+1 == b-q.front()){cout<<char(i);break;}      
        }
    }
}