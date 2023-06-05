//후보 추천하기 - S1 - 2023/06/01
// 문제 이해에 되게 오래 걸렸던 문제.. 
// 다른사람들 코드도 보고 이해해두자..! 
// 이 문제로 pq + 구조체를 잘 알아두자..!!!
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#define ff first 
#define sc second 
#define pp pair<pair<int,int>,int>
using namespace std;
int n,rec;
priority_queue<int,vector<int>,greater<int>>ans;
int stu[101];
struct Compare { // 아직도 pq에서의 Compare가 익숙하지 않네.. 더 공부해야지
    bool operator()(pp& a, pp& b) {
        if (a.ff.sc == b.ff.sc) {
            return a.sc > b.sc; // pq.second가 작은 순서로 정렬
        }
        return a.ff.sc > b.ff.sc; // pq.first.second가 작은 순서로 정렬
    }
};
// 지금 내가 넣는 순서가 {{학생, 학생추천빈도} , 나온 순서} 인데
// 추천빈도가 같을때는 나온순서가 작은게 위로 가도록
// 같지 않을때는 추천빈도가 작은게 위로 가도록!
priority_queue<pp,vector<pp>,Compare>pic;
int main(){
    // pic.push({{1, 2}, 2});
    // pic.push({{1, 2}, 5});
    // pic.push({{2, 1}, 4});
    // pic.push({{2, 1}, 1});
    // while (!pic.empty()) {
    //     const auto& p = pic.top();
    //     std::cout << "(" << p.first.first << ", " << p.first.second << ", " << p.second << ")" << std::endl;
    //     pic.pop();
    // }
    // 잘 몰라서 하나씩 찍어봄

    cin>>n>>rec; // 3 9 

    //1. 학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
    //2. 어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
    for(int i=0; i<rec ; i++){
        int t; cin>>t;
        if(pic.size() < n){
            if(stu[t]>=1){// 첨에 여기 안해줘서 20퍼?에서 틀림
            /*
            3
            3
            1 1 1 같은놈이면 답이 1인데  여기서 if문 알걸어두면 1 1 1이 찍힘
            */
                priority_queue<pp,vector<pp>,Compare>tmp;
                while(not pic.empty()){
                    auto tp = pic.top();
                    if(tp.ff.ff == t){
                        stu[t]++;
                        tmp.push({{t,stu[t]},tp.sc});
                        pic.pop();
                    }
                    else{
                        tmp.push({{tp.ff.ff,tp.ff.sc},tp.sc});
                        pic.pop();
                    }
                }
                pic = tmp;continue;
            }
            stu[t]++;
            pic.push({{t,stu[t]},i});
        }
        else{
            if(stu[t]>=1){
                priority_queue<pp,vector<pp>,Compare>tmp;
                while(not pic.empty()){
                    auto tp = pic.top();
                    if(tp.ff.ff == t){
                        stu[t]++;
                        tmp.push({{t,stu[t]},tp.sc});
                        pic.pop();
                    }
                    else{
                        tmp.push({{tp.ff.ff,tp.ff.sc},tp.sc});
                        pic.pop();
                    }
                }
                pic = tmp;continue;
                //stu[t]++;

                //pic.push({{t,stu[t]},i});continue;
                continue;
            }
            else{
                auto fr = pic.top();
                stu[fr.ff.ff]=0;
                stu[t]++;
                pic.pop();
                pic.push({{t,stu[t]},i});
            }
        }
    }
    // 진짜 ㅈㄴ 더럽게 풀었네.. 
    while(not pic.empty()){
        auto fr = pic.top();
        pic.pop();
        ans.push(fr.ff.ff);
    }
    while(not ans.empty()){ // pq는 기본적으로 큰숫자가 위로가니까 반대로 해주려고 이짓함
        int tp = ans.top();
        cout<<tp<<" ";
        ans.pop();
    }

}