#include <iostream>
#include <iomanip>

using namespace std;
/*sort the array using bubble sort*/
void sortArray(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped=false){
            break;
        }
    }
}
/*find the median for given array*/
void findMedian(int arr[],int n){
    if(n%2!=0){
        int index=(n-1)/2;
        cout<<"Median: "<<fixed<<setprecision(1)<<static_cast<double>(arr[index])<<endl;
    }
    else{
        int index=(n)/2;
        double median = static_cast<double>(arr[index]+arr[index-1])/2.0;
        cout<<"Median: "<<fixed<<setprecision(1)<<median<<endl;
    }
}

int main(){
    cout<<"Enter the size of array: ";
    /*input the array size*/
    int n;
    cin>>n;
    int arrTemp[n];
    /*input the elements in array*/
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arrTemp[i];
    }
    /*creating sub arrays and sorting them*/
    /*and then finding median of each sub array*/
    for(int i=0;i<=n-1;i++){
        int arr[i+1];
        int j=i+1;
        for(int k=0;k<j;k++){
            arr[k]=arrTemp[k];
        }
        sortArray(arr,j);
        cout<<"Sorted array: "<<endl;
        for(int temp: arr){
            cout<<temp<<" ";
        }
        cout<<endl;
        findMedian(arr,i+1);
        cout<<endl;
        cout<<endl;

    }
}