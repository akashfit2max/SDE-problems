#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partion(int arr[],int l, int r) {
    int pivot = arr[l];
    int i=l;
    int j=r;
    while(i<j) {
        
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        
        if(i<j) {
            swap(&arr[i],&arr[j]);
        }
        
    }
    
    swap(&arr[j],&arr[l]);
    
    return j;
    
}

void quicksort(int arr[],int l, int r) {
    if(l<r) {
        int p=partion(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
    
}

void print(int arr[],int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    print(arr,n);
}
