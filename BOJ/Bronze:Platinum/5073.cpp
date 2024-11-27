// 삼각형과 세 변 - B3 - 2024/11/26
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    while(1){
        int a,b,c;cin>>a>>b>>c;
        vector<int>v;
        if(a==0 and b==0 and c==0)exit(0);
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        int z = v.back();
        int x = v[0];
        int y = v[1];
        //cout<<x<< " "<<y<<" "<<z<<endl;
        if(x+y<=z){cout<<"Invalid"<<endl;continue;}
        if(x==y and y ==z){cout<<"Equilateral"<<endl;continue;}
        if(x!=y and y!=z and z!=x){cout<<"Scalene"<<endl;continue;}
        if((y==z and y!=x) or (x==y and y!=z) ){cout<<"Isosceles"<<endl;continue;}
    }
}