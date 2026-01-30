#include <iostream>
using namespace std;
void InsertionSort(int arr[],int n){
    for(int i=1; i<n; i++){
       int cur=arr[i];
       int prev=i-1;

       while(prev>=0 && arr[prev]>cur){
           arr[prev+1]=arr[prev];
           prev--;
       }
      arr[prev+1]=cur;
        
      
    }
}
void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
   
    InsertionSort(arr,n);
    cout<<"Sorted array: \n";   
    printArray(arr,n);
}