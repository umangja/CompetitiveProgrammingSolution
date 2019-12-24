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

void print(string s)
{
	cout<<sz(s)<<"\n";
	cout<<s<<"\n";
	return ;
}

int solve()
{

	// ll n;cin>>n;


	ll n,k;cin>>n>>k;
	string num;
	cin>>num;
	string dup = num;
	rep(i,0,n-k) dup[i+k]=dup[i];

	// cout<<dup<<"\n";

	rep(i,0,n)
	{
		if((dup[i]-'0')>(num[i]-'0'))
		{
			print(dup);
			return 0;
		}

		if((dup[i]-'0')<(num[i]-'0')) break;

		if(i==n-1)
		{
			print(dup);
			return 0;
		}
	}

	ll nd=n-k;

	ll st = n-nd-1;
	for(ll i=st;i>=0;i--)
	{
		if(dup[i]!='9')
		{
			ll d = dup[i]-'0';d++;
			dup[i] = (char)(d+'0');

			rep(j,i+1,n) dup[j]='0';

			rep(j,0,n-k) dup[j+k]=dup[j];

			print(dup);
			return 0;
		}
	}

	string r = "1";
	rep(i,0,n) r+='0';
	rep(i,0,n-k) r[i+k]=r[k];
	print(r);
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}