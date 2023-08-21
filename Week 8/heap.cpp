#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest=root; //initialize largest as root
   int left=root*2+1; //left child
   int right=root*2+2; //right child

   if(left<n && arr[left]>arr[largest]){ //if left child is higher than the largest
      largest=left;
   }

 

   if(right<n && arr[right]>arr[largest]){ //if right child is higher than the largest
      largest=right;
   }


   if(largest!=root){
      swap(arr[largest],arr[root]); //swap largest th with root th element when largest value has been changed
      heapify(arr,n,largest);
   }
   else{
      return; //base case
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=n/2-1;i>=0;i--){
      heapify(arr,n,i);
   }
   
  
   // extracting elements from heap one by one
   for(int j=n-1;j>=0;j--){
      swap(arr[j],arr[0]); // moving the j th element to the end
      heapify(arr,j,0); // calling heapify function for the new array
   }

   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{  cout<<"Notice: Enter \"-1\" at the end to terminate entering elements to the array!"<<endl;
   int x;
   vector<int>heap_vec;
   
   while(x!=-1){
      cin>>x;
      heap_vec.push_back(x);
   }
   heap_vec.pop_back(); //preventing from -1 adding to the array as an element

   int n = heap_vec.size();
   cout<<"Input array"<<endl;

   int heap_arr[n];
   for(int i=0;i<n;i++){ //putting vector elements into an array
      heap_arr[i]=heap_vec[i];
   }
   
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}