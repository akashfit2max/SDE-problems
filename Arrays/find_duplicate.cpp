/* author : akash kumar */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f first
#define s second
#define ss string
#define mp make_pair
#define map map<int, int>
#define umap unordered_map<int,int>
#define pb push_back
#define p pair<int, int>
#define pp pair<int, p>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvl vector<vl>
#define vvp vector<vp>
#define el endl
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <(n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define Pi 3.14159
const int mod = 1e9+7;
ll gcd(ll a, ll b){ll temp;while (b > 0){temp = a%b;a = b;b = temp;} return a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
void findDuplicates(vector<int>& nums) {
        cout << "The repeating elements are:" <<el;
        rep(i,nums.size()) {
            if(nums[abs(nums[i])] > 0) {
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
            else {
                cout<<nums[i]<<" ";
            }
        }
    }
void solve() {
    int n;
    cin>>n;
    v nums(n);
    rep(i,n) {
        cin>>nums[i];
    }
    findDuplicates(nums);    
}
//Akash_Kumar --main function
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
