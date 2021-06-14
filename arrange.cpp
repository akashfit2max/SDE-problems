#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int i=-1;
    for(int j=0;j<n;j++) {
        if(arr[j]<0) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    for(auto i:arr) {
        cout<<i<<" ";
    }
    int pos=i+1;
    int neg=0;
    while(pos<n && neg<pos && arr[neg]<0) {
        swap(arr[pos],arr[neg]);
        pos++;
        neg+=2;
    }
    cout<<endl;
    for(auto i:arr) {
        cout<<i<<" ";
    }
    return 0;
}
