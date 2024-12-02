// 네 또 수열입니다 - S4 - 2024/12/02
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
vector<int>tmp;
int n,l,r;
int main() {
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        int t;cin>>t;v.push_back(t);
    }
    tmp = vector<int>(v.begin() + l-1, v.begin()+r);//l-1부터 r까지의 원소를 tmp에 저장
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<tmp.size();i++)
        v[l-1+i]=tmp[i];//l-1부터 r까지의 원소를 정렬된 tmp로 바꿔줌
    bool flag=1;
    for(int i=1; i<n;i++){
        if(v[i-1]>v[i]){
            flag=0;break;
        }
    }
    cout<<flag<<endl;
}