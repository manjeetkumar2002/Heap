// create Max Heap
#include<iostream>
#include<vector>
using namespace std;
// using classic array
class MaxHeap{
private:
    int* arr;
    int size;
    int capacity;
public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        capacity = n;
    }
    void push(int item){
        if(size==capacity){
            cout<<"Heap Overflow!"<<endl;
            return;
        }
        cout<<item<<" is inserted successfully!"<<endl;
        // insert at last 
        arr[size] = item;
        // store the index so that we can heapify this element (stepup)
        int index = size;
        size++;

        // heapify the element
        // parent => index-1/2 
        while(index>0 and arr[(index-1)/2]<arr[index]){
            // swap if parent element is less
            swap(arr[(index-1)/2],arr[index]);
            // update the index 
            index = (index-1)/2;
        }
    }
    void heapify(int index){
        // current index and its left and right child
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        // find the large element index among current index and its childs
        if(left<size && arr[left]>arr[largest]){
            largest = left;
        } 
        if(right<size && arr[right]>arr[largest]){
            largest = right;
        }

        // swap 
        if(largest!=index){
            swap(arr[largest],arr[index]);

            // heapify again on swaped element
            heapify(largest);
        }
    }
    void pop(){
        if(size==0){
            cout<<"Heap Underflow!"<<endl;
            return;
        }
        // In heap we always remove top element ie index 0 
        cout<<arr[0]<<" deleted successfully!"<<endl;
        swap(arr[0],arr[size-1]);
        size--;

        // heapify index 0 (step down)
        heapify(0);
    }
    void print(){
        if(size==0){
            cout<<"Heap is Empty!"<<endl;
            return;
        }
        cout<<"Max Heap : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
//using vector 
class maxHeap {
private:
    vector<int> arr;

public:

    void push(int x) {
        arr.push_back(x);

        int index = arr.size() - 1;

        // Heapify up
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (arr[parent] >= arr[index])
                break;

            swap(arr[parent], arr[index]);

            index = parent;
        }
    }

    void pop() {
        if (arr.empty())
            return;

        // Move last element to root
        arr[0] = arr.back();
        arr.pop_back();

        // Heapify down
        int index = 0;
        int n = arr.size();

        while (true) {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && arr[left] > arr[largest])
                largest = left;

            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest == index)
                break;

            swap(arr[index], arr[largest]);

            index = largest;
        }
    }

    int peek() {
        if (arr.empty())
            return -1;

        return arr[0];
    }

    int size() {
        return arr.size();
    }
};
//using vector
class minHeap {
private:
         vector<int> arr;

     public:

         void push(int x) {
             arr.push_back(x);

             int index = arr.size() - 1;

             // Heapify up
             while (index > 0) {
                 int parent = (index - 1) / 2;

                 if (arr[parent] < arr[index])
                     break;

                 swap(arr[parent], arr[index]);

                 index = parent;
             }
         }

         void pop() {
             if (arr.empty())
                 return;

             // Move last element to root
             arr[0] = arr.back();
             arr.pop_back();

             // Heapify down
             int index = 0;
             int n = arr.size();

             while (true) {
                 int smallest = index;

                 int left = 2 * index + 1;
                 int right = 2 * index + 2;

                 if (left < n && arr[left] < arr[smallest])
                     smallest = left;

                 if (right < n && arr[right] < arr[smallest])
                     smallest = right;

                 if (smallest == index)
                     break;

                 swap(arr[index], arr[smallest]);

                 index = smallest;
             }
         }

         int peek() {
             if (arr.empty())
                 return -1;

             return arr[0];
         }

         int size() {
             return arr.size();
         }
};
int main(){
    
    int arr[] = {20,15,12,18,13,31,19,17,40};
    int n = sizeof(arr)/sizeof(int);
    MaxHeap* hp = new MaxHeap(n);
    for(int i=0;i<n;i++){
        hp->push(arr[i]);
    }

    hp->print();

    hp->pop();

    hp->print();
}