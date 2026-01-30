 
 #include <iostream>
 #include <vector>
using namespace std;

//
void Merge(vector<int>&arr,int st,int mid,int en){
vector<int> temp;
int i=st; int j=mid+1;
while(i<=mid && j<=en){
    if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
    }else{
        temp.push_back(arr[j]);
        j++;
    }
}

while(i<=mid){
    temp.push_back(arr[i]);
    i++;
}
while(j<=en){
    temp.push_back(arr[j]);
    j++;
}
for(int idx=st; idx<=en; idx++){
    arr[idx]=temp[idx-st];

}
}

void MergeSort(vector<int>&arr,int st,int en){
    if(st<en){
        int mid=st+(en-st)/2;
        MergeSort(arr,st,mid);
        MergeSort(arr,mid+1,en);
        Merge(arr,st,mid,en);
        // Merging two sorted halves
        }
    
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
   MergeSort(arr,0,n-1);

   
    cout<<"Sorted array: \n";   
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}