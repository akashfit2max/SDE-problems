#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *prev;
    node(int data) {
        this->data=data;
        this->prev=nullptr;
    }
};

void print(node *tail) {
    if(tail==nullptr) {
        return;
    }
    print(tail->prev);
    cout<<(tail->data);
}

void multiply(node *tail, int n) {
    node *temp=tail, *prevnode = tail;
    int carry=0;
    while(temp!=nullptr) {
        int data = temp->data * n +  carry;
        temp->data = data%10;
        carry=data/10;
        prevnode=temp;
        temp=temp->prev;
    }
    
    while(carry!=0) {
        prevnode->prev = new node((int)(carry%10));
        carry/=10;
        prevnode = prevnode->prev;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        node *tail = new node(1);
        for(int i=2;i<=n;i++) {
            multiply(tail,i);
        }
        print(tail);
        cout<<endl;
    }
}
