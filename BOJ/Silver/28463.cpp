// Toe Jumps - S5 - 2023/08/21
// 구현 귀찮..
#include<iostream>
#include<string>
using namespace std;
char ch;
char arr[4][4];
char fir_l;    
char fir_r;
char sec_l;    
char sec_r;
int main(){
    cin>>ch;
    for(int i=0; i<2; i++)
        for(int j=0; j<2;j++)
            cin>>arr[i][j];
    if(ch=='N'){
        fir_l=arr[1][0];   fir_r=arr[1][1];
        sec_l=arr[0][0];   sec_r=arr[0][1];
    }
    if(ch=='S'){
        fir_l = arr[0][1];  fir_r = arr[0][0];
        sec_l = arr[1][1];  sec_r = arr[1][0];
    }
    if(ch=='E'){
        fir_l=arr[0][0];    fir_r=arr[1][0];
        sec_l=arr[0][1];    sec_r=arr[1][1];
    }
    if(ch=='W'){
        fir_l=arr[1][1];    fir_r=arr[0][1];
        sec_l=arr[1][0];    sec_r=arr[0][0];
    }
    if(fir_l == 'O' and sec_r=='P' and fir_r == '.' and sec_l=='.'){
        cout<<'T'<<endl;exit(0);
    }
    if(fir_r =='I' and sec_l == 'P' and fir_l=='.' and sec_r=='.'){
        cout<<'F'<<endl;exit(0);
    }
    if(fir_r =='O' and sec_l == 'P' and fir_l=='.' and sec_r=='.'){cout<<"Lz"<<endl;exit(0);}
    else{cout<<"?"<<endl;exit(0);}
}