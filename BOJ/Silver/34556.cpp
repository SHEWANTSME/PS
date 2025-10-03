// MBTI 소개팅 - S2 - 2025.10.03
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<int>arr(n);
    vector<string>man(n);
    vector<string>woman(n);
    for(int i=0; i<n; i++)cin>>man[i];
    for(int i=0; i<n; i++){cin>>woman[i];arr[i]=i;}
    int ans=0;
    do{ 
        int tmp=0;
        for(int i=0;i<n;i++){
            int dif=0;
            for(int k=0; k<4;k++){
                if(man[i][k]!=woman[arr[i]][k])dif++;
            }
            tmp+=dif;
        }
        ans=max(ans,tmp);
    }while(next_permutation(arr.begin(),arr.end())); 
    cout<<ans<<endl;
}