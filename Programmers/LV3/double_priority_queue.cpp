

// 1. 맨처음 생각
// 1) 최댓값을 저장하는 pq1, 최솟값을 저장하는 pq2를 만들고
// 2) pq1은 내림차순(for 최댓값), pq2는 오름차순(for 최솟값)으로 만들어서
// 3) 두개의 pq로 요리조리 해보려고 했는데, 생각보다 복잡하고 variable도 많아지고 
// 하다보니까 이정도급은 아닌거 같아서 포기
#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include<deque>
using namespace std;
priority_queue<int>pq1; // 내림차순 for 최댓값
priority_queue<int,vector<int>,greater<int>>pq2;//오름차순 for 최소값

vector<pair<char,int>>split(vector<string> oper){
    vector<pair<char,int>>v;
    for(auto &e : oper){
        char op = e[0]; bool flag = 0;
        if(e[2]=='-')flag=1;
        if(flag){
            string temp="";
            for(int i=3;i<e.size();i++) temp.push_back(e[i]);
            int sec = stoi(temp);
            v.push_back({op,-sec});
        }
        if(!flag){
            string temp="";
            for(int i=2;i<e.size();i++) temp.push_back(e[i]);
            int sec = stoi(temp);
            v.push_back({op,sec});
        }
    }
    return v;
}
void swap(priority_queue<int>&a, priority_queue<int,vector<int>,greater<int>>&b){
    if(a.empty()){
        int x = b.top();
        b.pop();
        int y = b.top();
        a.push(y);
        b.push(x);
    }
    if(b.empty()){
        int x = a.top();
        a.pop();
        int y = a.top();
        b.push(y);
        a.push(x);
    }
}


vector<int> solution(vector<string> operations) {
    auto x = split(operations);
    int cnt =0;
    for(auto &e : x){
        char ch = e.first;
        int num = e.second;
        if(ch=='I'){
            if(cnt==0){
                if(num>=0) pq1.push(num);
                else pq2.push(num);
                cnt++;
            }
            if(cnt==1){
                if(pq1.empty() and not pq2.empty()){
                    if(pq2.top() > num)pq2.push(num);
                    else pq1.push(num);
                }
                if(not pq1.empty() and pq2.empty()){
                    if(num>=pq1.top())pq1.push(num);
                    else pq2.push(num);
                }
                cnt++;
                if((pq1.size()==2 and pq2.empty()) or (pq2.size()==2 and pq1.empty())){
                    swap(pq1,pq2);
                }
            }
            else{
                if(not pq1.empty() and not pq2.empty()){
                    if(num<pq2.top())pq2.push(num);
                    else pq1.push(num);
                }
                if(not pq1.empty() and pq2.empty()){
                    if(num>=pq1.top())pq1.push(num);
                    
                }
                if(pq1.empty() and not pq2.empty()){
                    
                }
                if(pq1.empty() and pq2.empty()){
                    
                }
            }
            
        }
        if(ch=='D'){
            del_cnt++;
            if(num==1){// 최댓값 삭제
                pq1.pop();
            }
            else{// num=-1 최솟값 삭제
                pq2.pop();
            }
        }
    }
    
    vector<int> answer;
    
    
    return answer;
}

// 2. 두번째 생각
// timelimit에 걸릴줄 알았는데 그냥 통과..;; 머쓱
// 그냥 deque<int>만들고 sort하는 그냥 알고리즘이라 하기도 뭐한 코드를 혹시 내봤는데 통과함
// 근데 멋지진 않음
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
deque<int>ret;

vector<pair<char,int>>split(vector<string> oper){
    vector<pair<char,int>>v;
    for(auto &e : oper){
        char op = e[0]; bool flag = 0;
        if(e[2]=='-')flag=1;
        if(flag){
            string temp="";
            for(int i=3;i<e.size();i++) temp.push_back(e[i]);
            int sec = stoi(temp);
            v.push_back({op,-sec});
        }
        if(!flag){
            string temp="";
            for(int i=2;i<e.size();i++) temp.push_back(e[i]);
            int sec = stoi(temp);
            v.push_back({op,sec});
        }
    }
    return v;
}

vector<int> solution(vector<string> operations) {
    auto x = split(operations);
    for(auto &e : x){
        char ch = e.first;
        int num = e.second;
        if(ch=='I'){
            ret.push_back(num);
            sort(ret.begin(),ret.end());
        }
        else{
            if(num==1){
                if(ret.empty()){
                    continue;
                }
                ret.pop_back();
            }
            else{
                if(ret.empty()){
                    continue;
                }
                ret.pop_front();
            }
        }
    }
    vector<int> answer;
    if(ret.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else if(ret.size()==1){
        answer.push_back(ret.front());
        answer.push_back(ret.front());
    }
    else{
        answer.push_back(ret.back());
        answer.push_back(ret.front());
    }
    return answer;
}

// 3. 세번째 생각
// 첫번째 생각처럼 pq를 사용하긴 하되, 두개를 사용하지 않고
// 그냥 한개로 문제를 푸는데, 삭제할때 -1일때는 lazy deletion이 필요하단 아이디어가 중요했음
// 그래서 pq를 사용하되, 삭제할때 -1일때는 lazy deletion을 하고, 1일때는 그냥 pop하면 됨
// 왜 pq에서 lazy deletion이 가능하냐면, 
// 1) pq는 내부적으로 heap으로 구현되어있고, heap은 삽입, 삭제가 O(logN)임
// 2) pq는 최댓값, 최솟값을 O(1)로 구할 수 있음
// 3) 지금처럼 여러번의 update가 필요한 상황이고, heap을 재구성하여 메모리를 재할당하는 것보다
// 4) 필요 시점에 한번만 update하는게 훨씬 효율적임
// 5) 그래서 지금 문제에서 lazy deletion이 가능한거고, 지금처럼 맨 마지막 상황의 최대 최소값만 알면 되는 상황에선
// 6) 더더욱이 pq를 통한 lazy update가 효과적임


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
priority_queue<int>pq;// 내림차순

vector<pair<char,int>>split(vector<string> oper){
    vector<pair<char,int>>v;
    for(auto &e : oper){
        char op = e[0]; bool flag = 0;
        if(e[2]=='-')flag=1;
        if(flag){
            string temp="";
            for(int i=3;i<e.size();i++) temp.push_back(e[i]);
            int sec = stoi(temp);
            v.push_back({op,-sec});
        }
        if(!flag){
            string temp="";
            for(int i=2;i<e.size();i++) temp.push_back(e[i]);
            int sec = stoi(temp);
            v.push_back({op,sec});
        }
    }
    return v;
}

vector<int> solution(vector<string> operations) {
    auto x = split(operations);
    int min_del = 0;
    for(auto &e : x){
        char ch = e.first;
        int num = e.second;
        if(ch=='I') pq.push(num);
        else{
            if(pq.empty()) continue;
            else{
                if(num==-1)min_del++;
                else pq.pop();
            }
        }
    }
    // lazy deletion
    int mx=-1e9, mn=1e9;
    if(pq.empty()){
        mx = 0;
        mn = 0;
    }
    else{
        mx = pq.top();
        if(pq.size()>min_del){ // pq의 최소값들을 삭제하는게 아니고 위에서부터 pq.size()-(min_del+1)개를 pop하는거임
        //최솟값 삭제연산 호출 횟수가 남아있는 pq 사이즈로 감당되는 경우
            while(pq.size()>min_del+1)pq.pop();
        }
        else{
            while(not pq.empty())pq.pop();
        }
    }
    mn = pq.empty() ? 0 : pq.top();
    vector<int> answer;
    answer.push_back(mx);
    answer.push_back(mn);
    return answer;
}
// 근데 왜 몇몇 테케에서 오답이 나오는지 모르겠네;; ㅡㅡ