#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


long long cnt=0;
void totalcount(int arr[], int l, int mid, int r){
    int l1 = mid-l+1; int arr1[l1];
    int l2 = r-mid; int arr2[l2];
    int i,j,k;
    for(i=0; i<l1; i++) arr1[i]=arr[l+i];
    for(j=0; j<l2; j++) arr2[j]=arr[mid+1+j];
    i=0;j=0;k=l;
    while(i<l1 && j<l2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            cnt = cnt + (l1-i);
            j++;
        }
        k++;
    }
    while(i<l1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<l2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}
void findcount(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        findcount(arr, l, mid);
        findcount(arr, mid+1, r);
        totalcount(arr, l, mid, r);
    }
}
int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0;i<n; i++) cin>>arr[i];
	    findcount(arr, 0, n-1);
	    cout<<cnt<<endl;
	    cnt=0;
	}
	return 0;
}