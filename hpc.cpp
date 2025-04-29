#include <iostream>
#include <omp.h>
#include <climits>
using namespace std;

void min_reduction(int arr[], int n){
    int min_val = INT_MAX;
    #pragma omp parallel for reduction(min:min_val)
    for(int i=0;i<n;i++){
        if(arr[i]<min_val){
            min_val = arr[i];
        }
    }
    cout<<"Minimum value: "<<min_val<<endl;
}

void max_reduction(int arr[], int n){
    int max_val = INT_MIN;
    #pragma omp parallel for reduction(max:max_val)
    for(int i=0;i<n;i++){
        if(arr[i]>max_val){
            max_val = arr[i];
        }
    }
    cout<<"Maximum value: "<<max_val<<endl;
}

void sum_reduction(int arr[], int n){
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout<<"Sum is: "<<sum<<endl;
}

void average_reduction(int arr[],int n){
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout<<"Average value is: "<<(double)sum/n<<endl;
}
int main(){
    int* arr;
    int n;
    cout<<"Enter total no of elements: ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    min_reduction(arr,n);
    max_reduction(arr,n);
    sum_reduction(arr,n);
    average_reduction(arr,n);
    delete[] arr;
    return 0;
}