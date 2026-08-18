#include<iostream>
using namespace std;

// Building maxHeap using setup approach 
void BuildHeapSetupUp(int arr[],int n){
    // You are given a array of element     
    // convert the array into max heap
    // approach -> suppose there is only one element in array -> it is already a heap
    // now think like this from index =1 to last you have to place the elment to its correct position using set up approach
    // it is like you are inserting new element into the heap which was of single element initiallly
    for(int i=1;i<n;i++){
        int index = i;
        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[(index-1)/2],arr[index]);
            index = (index-1)/2;
        }
    }
}

void BuildHeapStepDown(int arr[],int n){
    // start from index (n/2 - 1) because all other have no children
    // place element to its correct position using step down approach

    for(int i=n/2-1;i>=0;i--){
        int index = i;
        while(true){
            int largest = index;
            int left = 2*index+1;
            int right = 2*index+2;

            if(left<n&&arr[left]>arr[largest]){
                largest = left;
            }
            if(right<n&&arr[right]>arr[largest]){
                largest = right;
            }
            if(largest==index){
                break;
            }
            
            swap(arr[largest],arr[index]);
            index = largest;
            
        }
        
    }
}
int main(){
    
    int arr[]={14,15,12,22,17,20,18,24,23,30,19};
    int n = sizeof(arr)/sizeof(int);
    
    // BuildHeapSetupUp(arr,n);
    BuildHeapStepDown(arr,n);
    cout<<"Max Heap : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Max Heap : 30 24 20 22 23 12 18 14 17 15 19 
}