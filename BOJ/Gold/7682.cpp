//틱택토 - G5 - 2024/09/25
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int comp_cnt=0;

// 최종상태인지 아닌지!! Find
// 조졌네.. 이 로직이 아닌가보다

// 반례
// XXXOOOX..    => Invalid
// OXXXOXXOO -> invalid

/*
이기는 경우
빈칸 4 -> fastest way  ending -> 무조건 x가 이길때 -> X개수 = O개수+1 (3,2,4)
3개 -> O가 이길때 -> O개수 = X개수 (3,3,3)
2개 -> X가 이길떄 -> X개수 = O개수+1 (4,3,2)
1개 -> O가 이길때 -> O개수 = X개수 (4,4,1)
0개 -> X가 꽉채우고 이길 때 -> X개수 = O개수+1 (5,4,0)

비기는 경우
비기는 경우는 무조건 꽉 채우고 비겨야함

        // 0 1 2
        // 3 4 5
        // 6 7 8
        // row completion -> 012 , 345, 678
        // col completion -> 036 , 147, 258
        // 오른대각 -> 0 4 8
        // 왼대각 -> 2 4 6
*/
bool row_completion(string st, char now){
    if((st[0] == now) and (st[1]==now) and (st[2]==now)){
        return 1;
    }
    else if((st[3] == now) and (st[4]==now) and (st[5]==now)){
        return 1;
    }
    else if((st[6] == now) and (st[7]==now) and (st[8]==now)){
        return 1;
    }
    else return 0;
}
bool col_completion(string st, char now){
    if((st[0] == now) and (st[3]==now) and (st[6]==now)){
        return 1;
    }
    else if((st[1] == now) and (st[4]==now) and (st[7]==now)){
        return 1;
    }
    else if((st[2] == now) and (st[5]==now) and (st[8]==now)){
        return 1;
    }
    else return 0;
}
bool diag_completion(string st, char now){
    if((st[0] == now) and (st[4]==now) and (st[8]==now)){
        return 1;
    }
    else if((st[2] == now) and (st[4]==now) and (st[6]==now)){
        return 1;
    }
    else return 0;
}

int main(){
    while(1){
        string s; cin>>s;
        if(s=="end") exit(0);
        int cnt_O=0;
        int cnt_X=0;
        int cnt_dot = 0;
        for(auto &e : s){
            if(e == 'O')cnt_O++;
            if(e == 'X')cnt_X++;
            if(e == '.')cnt_dot++;
        }
        if((cnt_X-cnt_O>1) or (cnt_X-cnt_O<0)){
            cout<<"invalid"<<endl;continue;
        }
        if(cnt_dot>=5){
            cout<<"invalid"<<endl;continue;
        }
        if(cnt_dot==4){// X가 이기는 경우
            if(cnt_X==3 and cnt_O==2){
                bool flag1 = row_completion(s,'X'); 
                bool flag2 = col_completion(s,'X'); 
                bool flag3 = diag_completion(s,'X'); 
                if(((flag1|flag2)|flag3)==1){
                    cout<<"valid"<<endl;continue;
                }
                else{
                    cout<<"invalid"<<endl;continue;
                }
            }
            else{
                cout<<"invalid"<<endl;continue;
            }
        }
        if(cnt_dot==3){//O가 이기는 경우
            if(cnt_X==3 and cnt_O==3){
                // find completion
                bool flag1 = row_completion(s,'O'); 
                bool flag2 = col_completion(s,'O'); 
                bool flag3 = diag_completion(s,'O');
                bool ff1 = row_completion(s,'X'); 
                bool ff2 = col_completion(s,'X'); 
                bool ff3 = diag_completion(s,'X');  
                if(((flag1|flag2)|flag3)==1){
                    if(((ff1|ff2)|ff3)==1){
                        cout<<"invalid"<<endl;continue;    
                    }
                    else cout<<"valid"<<endl;continue;
                }
                else{
                    cout<<"invalid"<<endl;continue;
                }

            }
            else{
                cout<<"invalid"<<endl;continue;
            }
        }
        if(cnt_dot==2){//X가 이기는 경우4 3 2
            if(cnt_X==4 and cnt_O==3){
                // find completion
                bool flag1 = row_completion(s,'X'); 
                bool flag2 = col_completion(s,'X'); 
                bool flag3 = diag_completion(s,'X');
                bool ff1 = row_completion(s,'O'); 
                bool ff2 = col_completion(s,'O'); 
                bool ff3 = diag_completion(s,'O');  
                
                if(((flag1|flag2)|flag3)==1){
                    if(((ff1|ff2)|ff3)==1){
                        cout<<"invalid"<<endl;continue;    
                    }
                    else cout<<"valid"<<endl;continue;
                }
                else{
                    cout<<"invalid"<<endl;continue;
                }
            }
            else{
                cout<<"invalid"<<endl;continue;
            }

        }
        if(cnt_dot==1){//O가 이기는 경우
            if(cnt_X==4 and cnt_O==4){
                // find completion
                bool flag1 = row_completion(s,'O'); 
                bool flag2 = col_completion(s,'O'); 
                bool flag3 = diag_completion(s,'O'); 
                bool ff1 = row_completion(s,'X'); 
                bool ff2 = col_completion(s,'X'); 
                bool ff3 = diag_completion(s,'X');
                if(((flag1|flag2)|flag3)==1){
                    if(((ff1|ff2)|ff3)==1){
                        cout<<"invalid"<<endl;continue;    
                    }
                    else cout<<"valid"<<endl;continue;
                }
                else{
                    cout<<"invalid"<<endl;continue;
                }
            }
            else{
                cout<<"invalid"<<endl;continue;
            }
        }
        if(cnt_dot==0){//X가 이기거나 비기는 경우
            // 1. X가 이기는 경우
            bool flag1 = row_completion(s,'X'); 
            bool flag2 = col_completion(s,'X'); 
            bool flag3 = diag_completion(s,'X');
            bool ff1 = row_completion(s,'O'); 
            bool ff2 = col_completion(s,'O'); 
            bool ff3 = diag_completion(s,'O');
            if(s[4]=='X' and (cnt_X==5 and cnt_O==4)){
                if(((flag1|flag2)|flag3)==1){
                        if(((ff1|ff2)|ff3)==1){
                            cout<<"invalid"<<endl;continue;    
                        }
                        else {cout<<"valid"<<endl;continue;}
                }
                else {
                    if(((flag1&flag2)&flag3)==0){
                        if(((ff1&ff2)&ff3)==0){
                            cout<<"valid"<<endl;continue;    
                        }
                        else{cout<<"invalid"<<endl;continue;}
                    }
                    else{cout<<"invalid"<<endl;continue;}
                }
            }
            else{// 비기는경우
                if((flag1 ==0) and (flag2 ==0) and (flag3 ==0)){
                    if((ff1 ==0)and (ff2 ==0)and(ff3 ==0)){
                        cout<<"valid"<<endl;continue;
                    }
                    else{cout<<"invalid"<<endl;continue;}
                }
                else{
                    //가운데 O이면서 X가 한줄로 완성되서 valid한 경우
                    if((ff1 ==0)and (ff2 ==0)and(ff3 ==0)){
                        if((flag1 ==1) or (flag2 ==1) or (flag3 ==1)){
                            cout<<"valid"<<endl;continue;
                        }
                        else{cout<<"invalid"<<endl;continue;}
                    }
                }
            }
        }   
    }
}


/*
if(cnt_dot==0){// X가 이기거나 비기는 경우
        // X가 이길땐 무조건 두개가 생기고(/ \이렇거나 \ ㅡ 이렇거나 두개가 나옴) 아닐땐 뭣도 없을떄(겹치는게 없어야함)
            if(cnt_X==5 and cnt_O==4){
                int tmp_cnt=0;
                //1. X가 이길 때
                // 두개로 이길 때
                // 0 2 4 6 8
                if((s[0]=='X') and (s[2]=='X') and (s[4]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 4 6 7 8
                if((s[0]=='X') and (s[4]=='X') and (s[6]=='X') and (s[7]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 2 4 5 8
                if((s[0]=='X') and (s[2]=='X') and (s[4]=='X') and (s[5]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 1 2 4 8
                if((s[0]=='X') and (s[1]=='X') and (s[2]=='X') and (s[4]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 3 4 6 8
                if((s[0]=='X') and (s[3]=='X') and (s[4]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 2 4 6 7 8
                if((s[2]=='X') and (s[4]=='X') and (s[6]=='X') and (s[7]=='X') and (s[8]=='X'))tmp_cnt++;
                // 2 4 5 6 8
                if((s[2]=='X') and (s[4]=='X') and (s[5]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 1 2 4 6
                if((s[0]=='X') and (s[1]=='X') and (s[2]=='X') and (s[4]=='X') and (s[6]=='X'))tmp_cnt++;
                // 0 2 3 4 6
                if((s[0]=='X') and (s[2]=='X') and (s[3]=='X') and (s[4]=='X') and (s[6]=='X'))tmp_cnt++;

                // 하나로 이길때
                // \ 이렇게 이길 때
                // 0 4 5 6 8
                if((s[0]=='X') and (s[4]=='X') and (s[5]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 1 4 6 8
                if((s[0]=='X') and (s[1]=='X') and (s[4]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 2 3 4 8
                if((s[0]=='X') and (s[2]=='X') and (s[3]=='X') and (s[4]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 2 4 7 8
                if((s[0]=='X') and (s[2]=='X') and (s[4]=='X') and (s[7]=='X') and (s[8]=='X'))tmp_cnt++;

                // / 이렇게 이길 떄
                // 1 2 4 6 8
                if((s[1]=='X') and (s[2]=='X') and (s[4]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 2 3 4 6 8
                if((s[2]=='X') and (s[3]=='X') and (s[4]=='X') and (s[6]=='X') and (s[8]=='X'))tmp_cnt++;
                // 0 2 4 5 6
                if((s[0]=='X') and (s[2]=='X') and (s[4]=='X') and (s[5]=='X') and (s[6]=='X'))tmp_cnt++;
                // 0 2 4 6 7
                if((s[0]=='X') and (s[2]=='X') and (s[4]=='X') and (s[6]=='X') and (s[7]=='X'))tmp_cnt++;

                if(tmp_cnt==1){
                    cout<<"valid"<<endl;continue;
                }
                //2. 비길 떄
                bool flag1 = row_completion(s,'X'); 
                bool flag2 = col_completion(s,'X'); 
                bool flag3 = diag_completion(s,'X'); 
                if(((flag1&flag2)&flag3)==0){
                    cout<<"valid"<<endl;continue;
                }
                else{
                    cout<<"invalid"<<endl;continue;
                }

            }
            else{
                cout<<"invalid"<<endl;continue;
            }

        }
*/