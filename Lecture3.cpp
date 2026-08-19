#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// problem2: Min Cost to Connect Ropes
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. Return the minimum possible cost.
int minCost(vector<int>& arr) {
        // code here
        if(arr.size()==1) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i:arr){
            pq.push(i);
        }
        
        int cost = 0;
        
        while(pq.size()>1){
            int sum = pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            
            cost+=sum;
            
            pq.push(sum);
        }
        return cost;
}

int main(){
    vector<int> arr = {4, 3, 2, 6};
    cout<<minCost(arr)<<endl;
}