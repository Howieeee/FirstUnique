// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<unordered_map>
#include<limits>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, pair<int,int>> ans; //num , <index,count>

    for(int i=0;i<A.size();i++){  //從頭開始跑
        if(ans[A[i]].second >0) //count >0 比index大小
            ans[A[i]].first = min(ans[A[i]].first,i);
        else //count =0 index = i
            ans[A[i]].first = i;
        ans[A[i]].second +=1; // count ++
    }
    int index = std::numeric_limits<int>::max(); 
    for(auto a:ans){ //從計算好的開始找
        if(a.second.second == 1){ //count =1
            if(index > a.second.first) // 比大小
                index = a.second.first;
        }
    }
    if(index == std::numeric_limits<int>::max())
        return -1;
    else
        return A[index];
}
