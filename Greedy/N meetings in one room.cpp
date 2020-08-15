#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(const pair<int,int> & a ,const pair <int,int>& b){
  return a.second<b.second;    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);   
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];         
   
   vector< pair<int, int> > v;
   vector< pair<int, int> >pos;
   for(int i=0;i<n;i++)    v.push_back(make_pair(a[i],b[i]));
   for(int i=0;i<n;i++)    pos.push_back(make_pair(i+1,b[i]));
   
   sort(v.begin(),v.end(), comp);
   sort(pos.begin(),pos.end() ,comp);  
    
    int i=0;
    cout<<pos[i].first<<" ";
    
    for(int j=1;j<n;j++){
        if(v[j].first>=v[i].second){
            cout<<pos[j].first<<" ";
            i=j;
        }
    }
    cout<<endl;
     }    
	return 0;
}