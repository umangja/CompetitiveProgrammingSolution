/*input

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

vi num;
ll n;
ll ans=0;
void fun(ll pos,ll f,ll nz,ll dd)
{
	if(pos==sz(num))
	{
		ans++;
		return ;
	}

	ll limit = 9;
	if(f==0) limit = num[pos];

	rep(i,0,limit+1)
	{
		ll nf=1,nnz=1;
		if(f==0 && i==limit) nf=0;
		if(nz==0 && i==0) nnz=0;

		if((nz==0) || i==dd ) fun(pos+1,nf,nnz,i);
	} 
}

int solve()
{
	cin>>n;
	ll dup=n;
	ans=0;	
	num.clear();
	while(dup) num.pb(dup%10),dup/=10;
	reverse(num.begin(), num.end());
	
	fun(0,0,0,0);
	cout<<ans-1<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}