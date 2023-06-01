// 중력 큐 - S1 - 2023/06/01 
// #include<iostream>
// #include<deque>
// #include<algorithm>
// #include<string>
// #define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
// #define endl "\n"
// using namespace std;
// deque<char>dq;
// int n;
// int cnt_b=0;
// int cnt_w=0;
// int rot_chk=0;
// void Push(char ch){ 
//     if(rot_chk==0){
//         if(ch=='b'){cnt_b++;dq.push_front(ch);}
//         else{cnt_w++;dq.push_front(ch);}        
//     }
//     if(rot_chk==1){
//         if(ch=='b' and dq.empty()) return;
//         if(ch=='b' and not dq.empty()){cnt_b++;dq.push_front(ch);}
//         if(ch=='w'){cnt_w++;dq.push_front(ch);}
//     }
//     if(rot_chk==2){
//         if(ch=='b'){cnt_b++;dq.push_back(ch);}
//         else{cnt_w++;dq.push_back(ch);}        
//     }
//     if(rot_chk==3){
//         if(ch=='w'){cnt_w++;dq.push_back(ch);}
//         else return;
//     }
// }
// void Pop(){ 
//     if(dq.empty())return;
//     else{
//         if(rot_chk==0 or rot_chk==1){
//             char bck = dq.back();
//             if(bck=='b'){dq.pop_back();cnt_b--;return;}
//             else{dq.pop_back();cnt_w--;return;}
//         }
//         if(rot_chk==2 or rot_chk==3){
//             char bck = dq.front();
//             if(bck=='b'){dq.pop_front();cnt_b--;return;}
//             else{dq.pop_front();cnt_w--;return;}
//         }
//     }
// }
// void Rotate(char ch){
//     if(ch=='l'){
//         rot_chk--;
//         if(rot_chk<0)rot_chk+=4;
//         if(rot_chk%2==0)return;
//         else{
//             while(not dq.empty()){
//                  char bck = dq.back();
//                  if(bck=='b'){dq.pop_back();cnt_b--;}
//                  else break;
//             }
//             return;
//         }
//     }
//     else{
//         rot_chk++;
//         if(rot_chk>3)rot_chk-=4;
//         if(rot_chk%2==0)return;
//         else{
//              while(not dq.empty()){
//                  char bck = dq.back();
//                  if(bck=='b'){dq.pop_back();cnt_b--;}
//                  else break;
//              }  
//             return;
//         }
//     }
// }
// void Count(char ch){
//     if(ch=='b') cout<<cnt_b<<endl;
//     else cout<<cnt_w<<endl;
// }
// int main(){
//     fastio;
//     cin>>n;
//     while(n--){
//         string s;cin>>s;
//         if(s=="pop"){
//             Pop();continue;
//         }
//         else{
//             char t;cin>>t;
//             if(s=="push") Push(t);
//             if(s=="count") Count(t);
//             if(s=="rotate") Rotate(t);
//         }
//     }   
// }


// #include <iostream>
// #include <deque>
// #include <vector>
// #define endl '\n'
// using namespace std;

// deque<char> q;
// bool flag = 1; // 가로 방향이면 1, 세로 방향이면 0
// int ball = 0;
// int wall = 0;
// int isLeft = 1;  // 가로 방향일 때, 뒤 쪽 방향이 왼쪽에 있다면 1, 오른쪽에 있다면 0
// int isUpper = 1; // 세로 방향일 때, 뒤 쪽 방향이 위에 있다면 1, 아래에 있다면 0

// void query(string s, char c) {
// 	if (s == "push") {
// 		if (flag == 1) { // 가로
// 			q.push_back(c); // 이 뜻은.. 일단 가로인 상태면 무조건 덱의 뒤에 push한다는 얘기?
// 			if (c == 'w') wall++;
// 			else ball++;
// 		}
// 		else {  // 세로
// 			if (c == 'w') {// 벽일때는 기존에 하던것처럼 하면 되지만 
// 				q.push_back(c);
// 				wall++;
// 			}
// 			else { // 벽 아닐때는 중력을 받으니까
// 				if (isUpper) { // 뒤가 위에 있는 경우
// 					if (!q.empty()) {
// 						char nc = q.front();
// 						if (nc == 'w') {
// 							q.push_back(c);
// 							ball++;
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 	else if (s == "count") {
// 		if (c == 'b') {
// 			cout << ball << endl;
// 		}
// 		else
// 			cout << wall << endl;
// 	}
// 	else if (s == "pop") {
// 		if (!q.empty()) {
// 			if (flag) {//flag =1 -> 가로
// 				char nc = q.front();
// 				if (nc == 'b') ball--;
// 				else wall--;
// 				q.pop_front();
// 			}
// 			else { // 세로 방향인 경우
// 				if (isUpper) {  // 아래에서 꺼내는 경우
// 					wall--; 
// 					q.pop_front();
// 					while (!q.empty()) {
// 						char nc = q.front(); 
// 						if (nc == 'w') break;
// 						q.pop_front(); 
// 						ball--; 
// 					} // 가림막 위에 있던 공이 쏟아진다.
// 				}
// 				else { // 위에서 꺼내는 경우
// 					char nc = q.front(); 
// 					if (nc == 'b') ball--;
// 					else wall--; 
// 					q.pop_front(); 
// 				}
// 			}
// 		}
// 	}
// 	else if (s == "rotate") {
// 		flag = 1 - flag;
// 		if (!flag) { // 세로 방향이 되었다면
// 			if (c == 'l') { // 반시계 방향 회전
// 				// 위가 앞, 아래가 뒤가 된 경우
// 				if (isLeft == 1) {
// 					if (!q.empty()) {
// 						char nc = q.back();
// 						while (!q.empty()) {
// 							nc = q.back();
// 							if (nc == 'w') break;
// 							q.pop_back();
// 							ball--;
// 						}
// 					}
// 					isUpper = 0;
// 				}
// 				else { //  위가 뒤, 아래가 앞이 된 경우
// 					// 앞에 있는 공들이 쏟아져나온다. 
// 					if (!q.empty()) {
// 						char nc = q.front();
// 						while (!q.empty()) {
// 							nc = q.front();
// 							if (nc == 'w') break;
// 							q.pop_front();
// 							ball--;
// 						}
// 					}
// 					isUpper = 1;
// 				}
// 			}
// 			else if (c == 'r') { // 시계 방향 회전 
// 				if (isLeft == 1) {
// 					if (!q.empty()) {
// 						char nc = q.front();
// 						while (!q.empty()) {
// 							nc = q.front();
// 							if (nc == 'w') break;
// 							q.pop_front();
// 							ball--;
// 						}
// 					}
// 					isUpper = 1;
// 				}
// 				else {
// 					if (!q.empty()) {
// 						char nc = q.back();
// 						while (!q.empty()) {
// 							nc = q.back();
// 							if (nc == 'w') break;
// 							q.pop_back();
// 							ball--;
// 						}
// 					}
// 					isUpper = 0;
// 				}

// 			}
// 		}
// 		else {  // 가로 방향이 되었다면
// 			if (c == 'l') { // 반시계 방향 회전
// 				if (isUpper == 1)
// 					isLeft = 1;
// 				else
// 					isLeft = 0;
// 			}
// 			else {
// 				if (isUpper == 1)
// 					isLeft = 0;
// 				else
// 					isLeft = 1;
// 			}
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cout.tie(NULL); cin.tie(NULL);

// 	int q; cin >> q;
// 	for (int i = 0; i < q; i++) {
// 		string s; cin >> s;
// 		char c;
// 		if (s != "pop") {
// 			cin >> c;
// 		}
// 		query(s, c);
// 	}
// 	return 0;
// }

#include <iostream>
#include <deque>
#include <vector>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int ball = 0;
int wall = 0;
deque<char> q;
bool flag = 1;
int isLeft = 1;
int isUpper = 1; 

void push(char c) {
    if (flag) { 
        q.push_back(c);
        if (c == 'w') wall++;
        else ball++;
    }
    else {
        if (c == 'w') {
            q.push_back(c);
            wall++;
        }
        else {
            if (isUpper && !q.empty() && q.front() == 'w') {
                q.push_back(c);
                ball++;
            }
        }
    }
}
void count(char c) {
    if (c == 'b') cout << ball << endl;
    else cout << wall << endl;
}
void pop() {
    if (!q.empty()) {
        if (flag) { 
            if (q.front() == 'b') ball--;
            else wall--;
            q.pop_front();
        }
        else { 
            if (isUpper) { 
                wall--;
                q.pop_front();
                while (!q.empty()) {
                    if (q.front() == 'w') break;
                    q.pop_front();
                    ball--;
                }
            }
            else { 
                if (q.front() == 'b') ball--;
                else wall--;
                q.pop_front();
            }
        }
    }
}

void rotate(char c) {
    flag = !flag;
    if (!flag) { 
        if (c == 'l') { 
            if (isLeft) {
                if (!q.empty()) {
                    while (!q.empty() && q.back() != 'w') {
                        q.pop_back();
                        ball--;
                    }
                }
                isUpper = false;
            }
            else {
                if (!q.empty()) {
                    while (!q.empty() && q.front() != 'w') {
                        q.pop_front();
                        ball--;
                    }
                }
                isUpper = true;
            }
        }
        else if (c == 'r') {
            if (isLeft) {
                if (!q.empty()) {
                    while (!q.empty() && q.front() != 'w') {
                        q.pop_front();
                        ball--;
                    }
                }
                isUpper = true;
            }
            else {
                if (!q.empty()) {
                    while (!q.empty() && q.back() != 'w') {
                        q.pop_back();
                        ball--;
                    }
                }
                isUpper = false;
            }
        }
    }
    else { 
        if (c == 'l') isLeft = isUpper;
        else if (c == 'r') isLeft = !isUpper;
    }
}

int main() {
    fastio;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        char c;
        if (s != "pop")  cin >> c;
        if (s == "push") push(c);
        if (s == "count") count(c);
        if (s == "pop") pop();
        if (s == "rotate") rotate(c);
    }
    return 0;
}
