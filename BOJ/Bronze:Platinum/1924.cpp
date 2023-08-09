// 2007년 -B1 - 2023/08/07
// 처음은 chrono를 써봐서 하려고 했지만 왜인지 안되므로
// 걍 하라는대로 함
#include<iostream>
#include<string>
using namespace std;
int x,y;// x월 y일
int date[13][32]; // 1~12월 1~31일
string days[7]= {"SUN","MON","TUE","WED","THU","FRI","SAT"};//0~6
int t1[13]={-1,1,-1,4,-1,2,-1,0,3,-1,1,-1,6};// 31일 까지 있는 type1
int t2[13]={-1,-1,4,-1,0,-1,5,-1,-1,6,-1,4,-1};//30,28일까지 있는 type2
int main(){
    cin>>x>>y;// 3 12 -> 3월 12일
    for(int i=1; i<=12; i++){
        int temp;
        if(t1[i]<0 and t2[i]>=0)temp=t2[i];
        if(t1[i]>=0 and t2[i]<0)temp=t1[i];
        if(temp==t2[i]){
            if(i==2){// 2월
                for(int j=1; j<=28;j++){
                    date[i][j]=temp%7;
                    temp++;
                }
            }
            else{
                for(int j=1;j<=30;j++){
                    date[i][j]=temp%7;
                    temp++;
                }
            }
        }
        if(temp==t1[i]){
            for(int j=1;j<=31;j++){
                date[i][j]=temp%7;
                temp++;
            }
        }
    }
    cout<<days[date[x][y]]<<endl;
}