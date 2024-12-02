//f(A+B) -S4 - 2024.12.02
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[10];
int A,B;
string Find(int x){
    string tmp = to_string(x);
    string ret = "";
    for(auto &e : tmp){
        for(int i=0; i<10; i++){
            if(arr[i]==(e-'0'))ret.push_back(i+'0');
        }
    }
    return ret;
}
int main(){
    for(int i=0;i<10;i++)
        cin>>arr[i];
    cin>>A>>B;
    string s1 = Find(A);
    string s2 = Find(B);
    int a_1 = stoi(s1);
    int b_1 = stoi(s2);
    string tt = to_string(a_1+b_1);
    for(auto &e : tt){
        cout<<arr[e-'0'];
    }
}