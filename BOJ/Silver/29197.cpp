// 아침 태권도 - S2 - 2023/09/01
// multimap을 사용해서 써보든지... 아니면 다른 방식이 있는지 체크해보기
// wrong code
// #include<iostream>
// #include<algorithm>
// #include<map>
// using namespace std;
// int n;
// map<int,int>mp;
// int maxx=-1e9;
// int minn=1e9;
// int ans=0;
// int main(){
//     cin>>n;
//     while(n--){
//         int x,y; cin>>x>>y;
//         maxx = max(maxx,x);
//         minn = min(minn,x);
//         mp[x]=y;
//     }
//     for(int i=minn; i<=maxx; i++){
//         if(mp.find(i)==mp.end())continue;
//         else{
//             bool flag=0;
//             for(int j=2; j<=10000;j++){
//                 if(mp.find(j*i)!=mp.end())flag=1;
//             }
//             if(!flag)ans++;
//         }
//     }
//     cout<<ans<<endl;
    
// }



// new code1 
// map을 사용하면, key가 고유해서 중복이 안되잖아
// 그래서 아래 코드처럼 if(mp.find(slope)!=mp.end()) 이렇게 
// 할 필요가 없음 -> 저거때문에 시간복잡도가 더 증가해서
// 시간초과가 났었는데 저 과정만 제거해주면 통과됨
// #include<iostream>
// #include<algorithm>
// #include<map>
// #include<typeinfo>
// using namespace std;
// int n;
// map<double,int>mp;
// map<int,int>mp2;
// map<int,int>mp3;
// int ans=0;
// int main(){
//     cin>>n;
//     while(n--){ 
//         int x,y;
//         cin>>x>>y;
//         if(x>0 and y>0){
//             double nx = double(x);
//             double ny = double(y);
//             double slope = ny/nx;
//             if(mp.find(slope)!=mp.end()){
//                 if(mp[slope]<0){mp[slope]=x;ans++;cout<<"x "<<x<<"y "<<y<<endl;}
//                 else continue;
//             }
//             else {mp[slope]=x;ans++;cout<<"x "<<x<<"y "<<y<<endl;}
//         }
//         if(x<0 and y>0){
//             double nx = double(x);
//             double ny = double(y);
//             double slope = ny/nx;
//             if(mp.find(slope)!=mp.end()){
//                 if(mp[slope]>0){mp[slope]=x;ans++;cout<<"x "<<x<<"y "<<y<<endl;}
//                 else continue;
//             }
//             else {mp[slope]=x;ans++;cout<<"x "<<x<<"y "<<y<<endl;}            
//         }
//         if(x>0 and y<0){
//             double nx = double(x);
//             double ny = double(y);
//             double slope = ny/nx;
//             if(mp.find(slope)!=mp.end()){
//                 if(mp[slope]<0){mp[slope]=x;ans++;cout<<"x "<<x<<"y "<<y<<endl;}
//                 else continue;
//             }
//             else {mp[slope]=x;ans++;cout<<"x "<<x<<"y "<<y<<endl;}
//         }
//         if(x<0 and y<0){
//             double nx = double(x);
//             double ny = double(y);
//             double slope = ny/nx;
//             if(mp.find(slope)!=mp.end()){
//                 if(mp[slope]>0){mp[slope]=x;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}
//                 else continue;
//             }
//             else {mp[slope]=x;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}            
//         }
//         // slope가 아닌 부분이 다 문제이넹
//         if(x==0 and y>0){
//             if(mp2.find(1)!=mp2.end()){
//                 if(mp2[1]<0){mp2[1]=1;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}
//                 else continue;
//             }
//             else {mp2[1]=1;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}
//         }
//         if(x==0 and y<0){
//             if(mp2.find(-1)!=mp2.end()){
//                 if(mp2[-1]>0){mp2[-1]=-1;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}
//                 else continue;
//             }
//             else {mp2[-1]=-1;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}            
//         }
//         if(y==0 and x>0){
//             if(mp3.find(1)!=mp3.end()){
//                 if(mp3[1]<0){mp3[1]=1;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}
//                 else continue;
//             }
//             else {mp3[1]=1;ans++;cout<<"x: "<<x<<" y: "<<y<<endl;}
//         }
//         if(y==0 and x<0){
//             if(mp3.find(-1)!=mp3.end()){
//                 if(mp3[-1]>0){mp3[-1]=-1;ans++;cout<<"여기?x: "<<x<<" y: "<<y<<endl;}
//                 else continue;
//             }
//             else {mp3[-1]=-1;ans++;cout<<"아님? x: "<<x<<" y: "<<y<<endl;}
//         }
//     }
//     cout<<ans<<endl;
// }

// new code2
// map을 사용하면, key가 고유해서 중복이 안된다는 사실을 인지하자!
// 생각보단 까다롭고 double로 바꿔주는 과정도 필요했지만
// 하라는 대로 하기 + 2차원 평면에서 직선의 기울기를
// 생각해주면 풀리는 문제
// new code
#include<iostream>
#include<algorithm>
#include<map>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n;
map<double,int>mp1;// 1사분면
map<double,int>mp2;// 2사분면
map<double,int>mp3;// 3사분면
map<double,int>mp4;// 4사분면
map<int,int>mp5;// x축
map<int,int>mp6;// y축
int ans=0;
int main(){
    fastio;
    cin>>n;
    while(n--){ 
        int x,y;
        cin>>x>>y;
        if(x>0 and y>0){
            double nx = double(x);
            double ny = double(y);
            double slope = ny/nx;
            mp1[slope]=x;
        }
        if(x<0 and y>0){
            double nx = double(x);
            double ny = double(y);
            double slope = ny/nx;
            mp4[slope]=x;          
        }
        if(x>0 and y<0){
            double nx = double(x);
            double ny = double(y);
            double slope = ny/nx;
            mp2[slope]=x;
        }
        if(x<0 and y<0){
            double nx = double(x);
            double ny = double(y);
            double slope = ny/nx;
            mp3[slope]=x;  
        }
        if(x==0 and y>0) mp5[1]=1;
        if(x==0 and y<0) mp5[-1]=-1;      
        if(y==0 and x>0) mp6[1]=1;
        if(y==0 and x<0) mp6[-1]=-1;
    }
    cout<<mp1.size()+mp2.size()+mp3.size()+mp4.size()+mp5.size()+mp6.size()<<endl;
}