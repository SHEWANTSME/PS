//Potato - S5 - 2023/08/21
// 정렬 + 반띵씩 
#include<iostream>
#include<algorithm>
using namespace std;
int arr[200001];
int n;
int main(){
   cin>>n;
   for(int i=1; i<=n;i++)
       cin>>arr[i];
   sort(arr,arr+n+1);
   int s=0;
   int park=0;
   for(int i=1; i<=(n/2); i++)
       s+=arr[i];
   for(int i=(n/2)+1;i<=n;i++)
       park+=arr[i];
   cout<<s<<" "<<park<<endl;
}