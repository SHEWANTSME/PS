
// // #include <iostream>
// // #include <vector>
// // #include <queue>
// // using namespace std;
// // // 트럭의 수, 다리의 길이, 최대하중
// // // 이해가 안되니까 나중에 다시 보자.
// // int N, W, L;
// // int Time = 0;
// // int cL=0; // 현재 하중
// // vector<int> v;
// // queue<pair<int,int>> q;
// // //q에는 다리 위에 올라가 있는 트럭의 정보를 넣어줄 겁니다 < 남은 다리 길이, 트럭의 무게 >
// // void solve(){
// // 	int i = 0;
// // 	while(1){

// // 		if (i<N && cL + v[i] <= L)
// // 		{
// // 			q.push(make_pair(W, v[i]));
// // 			cL += v[i];
// // 			i++;
// // 		}

// // 		int s = q.size();

// // 		for (int j = 0; j < s ; j++)
// // 		{
// // 			if (!q.empty())
// // 			{
// // 				int ctime = q.front().first;
// // 				int weight = q.front().second;
// // 				q.pop();

// // 				if (ctime - 1 != 0)
// // 					q.push(make_pair(ctime - 1, weight));
// // 				else
// // 					cL -= weight;

// // 			}
// // 		}

// // 		Time++;

// // 		if (i == N && q.empty())
// // 			break;
// // 	}

// // 	cout << Time+1<<endl;
// // }

// // int main(void)
// // {
// // 	cin >> N >> W >> L;
// // 	for (int i = 0; i < N; i++)
// // 	{
// // 		int n;
// // 		cin >> n;
// // 		v.push_back(n);
// // 	}

// // 	solve();
// // }
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int n;
// int arr[225];
// int dp[50001][5];
// int ddp[50001];
// vector<int>v;
// int main(){
//     //dp[i]=min(dp[i-j*j])+1;
//     cin>>n;
//     v.push_back(0);
//     ddp[1]=1;
//     for(int i=1 ; i<=50000 ; i++){
//         for(int j=1; j<=224;j++){
//             if(i-j*j<=0)break;

//         }
//     }




//     for(int i=1 ; i<=224; i++){
//         v.push_back(i*i);
//     }
//     for(auto &e : v){
//         if(n==e){
//             cout<<1<<endl;
//             exit(0);
//         }
//     }
//     for(int i=1 ; i<=224; i++)


//     for(int i=1; i<=224; i++){
//         int now = n - v[i];
//         if(now<0)break;
//         else{
//             for(int i=1 ; i<now ; i++){
//                 if(i*i>now)break;
//                 if(i*i == now){
//                     cout<<2<<endl;
//                     exit(0);
//                 }
//             }
//         }
//     }

    
// }

// 은근 까다롭네..
// 트럭- S1 - 2023/04/26
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int n , w , l;
//int truck[1001];
deque<int>truck_L; // 다리를 지나기 전 truck들
deque<pair<int,int>>truck_M;// 다리에 있는 truck들(weight, 위치)
// deque<int>truck_R;// 다리를 지나고 나서 truck들 ->필요없는애..
int main(){
    cin>>n>>w>>l; // w : 다리길이, l : 다리최대하중
    for(int i=0  ; i<n ; i++){
        int t; cin>>t ; truck_L.push_back(t);
    }
    int cnt =0;
    int temp=0;
    // 간단하게 생각하면 된다
    // 1. truck_M에 올라탈 수 있으면 올라타고(temp계산해두고)
    // 2. truck_M에 있는애들 전진시키고
    // 3. 전진후 빠질애들은 빠지고(temp계산해두고)
    while(not(truck_L.empty() and truck_M.empty())){
        int now = truck_L.front();
        cnt++;
        if(not truck_L.empty() and temp+now<=l){ //truck_M에 올라탈 수 있는 경우엔
            truck_M.push_back({now,0});// 올라타고
            temp+=now; // temp(하중계산)더해주고
            truck_L.pop_front();// L의 맨처음애 빼주고
        }
        for(auto &e : truck_M){//truck_M에 있는애들을 전진시켜야지
            e.second++;//한번의 cnt에서 전진시키는게 포함되는거니까 이렇게 짜야함
        }
        int weight = truck_M.front().first;
        int idx = truck_M.front().second;
        if(idx==w){  // 그중 truck_M의 앞대가리가 w랑 길이 같으면
            temp-=weight; // temp(하중계산) 빼버리고
            truck_M.pop_front();// truck_M에서도 빼버리고
        }
    }
    cout<<cnt+1<<endl;
}




// while(not truck_L.empty()){
//         if(dari_where>=w){ // 2>=2
//             int fr = truck_M.front();// 7
//             truck_M.pop_front();
//             temp-=fr;// 7-7  =0
//             truck_R.push_front(fr); // truck_R : {7}
//             dari_where--;// 2->1
//         }
//         int now = truck_L.front();// 7 , 4
//         temp+=now;// temp =7 -> 11
//         if(temp>l){
//             truck_L.pop_front();// truck_L:{5, 6}
//             temp-=now; // 11-4 -> temp = 7
//             dari_where++;// 1->2
//             continue;
//         }
//         if(temp<=l){
//             dari_where++; // 0->1
//             truck_M.push_front(temp);// truck_M:{7}
//             truck_L.pop_front();
//             continue;
//         }
//     }