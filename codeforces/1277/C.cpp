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

string one = "one",two="two",comb="twone";
int solve()
{
	string s;cin>>s;
	ll n=sz(s);
	s+=".....";

	// vi f(n,1);
	// rep(i,1,n) if(s[i]==s[i-1]) fq[i]++; 

	vi ans;
	rep(i,0,n-2)
	{
		string r = "";
		string r1 = "";
		ll p=-1,pn=-1,pw=-1;
		rep(j,0,5)
		{
			r+=s[i+j];
			if(sz(r1)<3)
			{
				r1+=s[i+j];
				if(s[i+j]=='n') pn=i+j;
				if(s[i+j]=='w') pw=i+j;

			} 
			if(s[i+j]=='o') p=i+j;

		}

		if(r==comb)
		{
			ans.pb(p);
			i+=4;
			continue;
		}
		else if(r1==one) 
		{
			ans.pb(pn);
			i+=2;
		}
		else if(r1==two)
		{
			ans.pb(pw);
			i+=2;
		}

	}

	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i]+1<<" ";
	cout<<"\n";
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
// 	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}