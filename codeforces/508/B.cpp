/*input
 3
4 5 6

*/
 
 
//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9+7;
const ll N = 1e6+5;
vi is_prime(N,1);
void preprocess()
{
	is_prime[0]=is_prime[1]=0;
	rep(i,2,N)
		if(is_prime[i])
			for(ll j=i*i;j<N;j+=i) is_prime[j]=0;
}
 
int solve()
{
	string s;cin>>s;
	ll n=sz(s);
	ll ld = s[n-1]-'0';
	string ans=s;
	ll temp=-1;
	rep(i,0,n)
	{
		ll d = s[i]-'0';
		if(!(d&1))
		{
			if(d<ld)
			{
				swap(ans[n-1],ans[i]);
				cout<<ans<<"\n";
				return 0;
			}
			else temp=i;
		}
	} 

	if(temp==-1) cout<<"-1\n";
	else {
		swap(ans[temp],ans[n-1]);
		cout<<ans<<"\n";
	}
	return 0;
}
 
int main()
{
	auto start = chrono::high_resolution_clock::now();
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();
 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}