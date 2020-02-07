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
const ll NN = 61;
const double inf64 = 3e18;
vi mobi_fun(NN);
vi last(NN,-1),last_num(NN,-1);


ll pow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)
		{
			// whatis(((double)inf64/(double)x));

			if((double)ans<inf64/(double)x)	ans = (ans*x);
			else return inf64;
		} 
		if(y>1)
		{
			if((double)x<inf64/(double)x) x=(x*x);
			else return inf64;

		}
		y>>=1;
	}
	return ans;
}
		


void find_mobi()
{
	// cout<<pow(2,1000);
	mobi_fun[1]=1;
	rep(j,2,NN)
	{
		ll n=j,f=1;
		map<ll,ll> pf;
		for(ll i=2;i*i<=n;i++) if(n%i==0) while(n%i==0) pf[i]++,n/=i;
		if(n!=1) pf[n]++;
		all(it,pf) if(it->S>1) f=0;
		if(!f) mobi_fun[j]=0;
		else mobi_fun[j] = (sz(pf)%2==0?1:-1);
	}
	return ;
}

ll my_sqrt(ll n)
{
	ll ans = (ll)sqrt(n);
	if(ans*ans==n) return ans;
	if((ans+1)*(ans+1)<=n) return ans+1;
	if(ans*ans<n) return ans;
	return ans-1;
}


int solve()
{
	ll t,n;cin>>t;
	vpii q;
	rep(i,0,t) {cin>>n; q.pb(mp(n,i));}
	sort(q.begin(), q.end(),greater<pii> ());

	rep(i,3,NN)
	{
		n = inf;
		ll low = 0,high = 1e6;
		while(low<high)
		{
			ll mid = low+(high-low+1)/2;
			ll v = (ll)pow(mid,i);
			// whatis(v);
			if(v==n) { low=mid; break; }
			else if(v<n)  low=mid; 
			else high=mid-1; 
		}

		// cout<<low<<"\n";

		last[i] = low;
		last_num[i] = (ll)pow(low,i);
	}

	vi ans(t);
	rep(j,0,t)
	{
		n = q[j].F;
		ll temp_ans=n-(ll)my_sqrt(n);

		rep(i,3,NN)
		{	
			while(last_num[i]>n)
			{
				last[i]--;
				last_num[i] = (ll)pow(last[i],i);
			}
			temp_ans+=(last[i]-1)*mobi_fun[i];
		}	
		ans[q[j].S] = temp_ans;
	}

	rep(i,0,t) cout<<ans[i]<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	find_mobi();

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}