#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
// problem1: Height of Heap
int heapHeight(int n, int arr[]) {
        // code here
        if(n==1) return 1;
        int height = 0;
        while(n!=1){
            n/=2;
            height++;
        }
        return height;
}
// problem2: Min Cost to Connect Ropes
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

// problem3 :Magician and Chocolates
int nchoc(int A, vector<int> &B) {
    priority_queue<int> q;
    
    for(int i:B){
        q.push(i);
    }
    long long int total = 0;
    while(A>0&&!q.empty()){
        int choc = q.top();
        q.pop();
        total= (total+choc)%1000000007;
        if(choc/2>0)
        q.push(choc/2);
        A--;
    }
    
    return total;
}

//problem4 : Last Stone Weight
int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;

        for(int i:stones){
            q.push(i);
        }

        while(q.size()>1){
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            q.push(abs(first-second));
        }

        return q.top();
    }
//problem 5: Take Gifts From the Richest Pile
long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;

        for(int i:gifts){
            q.push(i);
        }

        while(k>0 && !q.empty()){
            int gift = q.top();
            q.pop();

            q.push(sqrt(gift));
            k--;
        }
        long long int total = 0;
        while(!q.empty()){
        total+=q.top();
        q.pop();
        }
        return total;
    }

// problem 6:Profit Maximisation
int solve(vector<int> &A, int B) {
    priority_queue<int>q;
    
    for(int i:A){
        q.push(i);
    }
    int sum = 0;
    while(B&&!q.empty()){
        sum+=q.top();
        if(q.top()-1){
            q.push(q.top()-1);
        }
        q.pop();
        B--;
    }
    return sum;
    
}

int main(){
    vector<int> arr = {4, 3, 2, 6};
    cout<<minCost(arr)<<endl;
}


// 1: Height of Heap : https://www.geeksforgeeks.org/problem...
// 2:Minimum Cost of ropes : https://www.geeksforgeeks.org/problem...[]=0&category[]=Heap&sortBy=submissions
// 3:Magician and Chocolates: https://www.interviewbit.com/problems...
// 4: Last Stone Weight: https://leetcode.com/problems/last-st...
// 5: Take Gifts From the Richest Pile: https://leetcode.com/problems/take-gi...
// 6: Profit Maximisation: https://www.interviewbit.com/problems...