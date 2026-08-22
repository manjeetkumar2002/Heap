#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// problem 3: Kth Largest in a Stream
vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        // min heap
        priority_queue<int,vector<int>,greater<int>> p;
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            if(p.size()<k){
                p.push(arr[i]);
                
                if(p.size()==k){
                    ans.push_back(p.top());
                }
                else{
                    ans.push_back(-1);
                }
            }
            else{
                if(arr[i]>p.top()){
                    p.pop();
                    p.push(arr[i]);
                }
                
                ans.push_back(p.top());
            }
        }
        return ans;
}

int main(){
    // problem 6:
    vector<int>arr = {1, 2, 3, 4, 5, 6};
    // cout<<kthLargest(arr,4);
    vector<int> ans = kthLargest(arr,4);
    for(int i:ans)
    cout<<i<<" ";
}