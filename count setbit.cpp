void solve() {
//     count the set bits of a number
    int n;
    cin>>n;
    int res=0;
    while(n>0) {
        n = n&(n-1);
        res++;
    }
    cout<<res;
}
