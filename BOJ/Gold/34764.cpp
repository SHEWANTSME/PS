// 고양이 게임 - G4 - 2025.11.27
// 건구스가 게임의 판도를 가지고 있어서 케이스 몇개 찾다보면 규칙이 보임
#include<iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n%4==1)cout<<"goose"<<endl;
    if(n%4==2)cout<<"duck"<<endl;
    if(n%4==3)cout<<"duck"<<endl;
    if(n%4==0)cout<<"goose"<<endl;
}