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


int solve()
{
	ll n;cin>>n;
	ll n1=0,n0=0;
	vs words(n);
	set<string> tot;
	map<string,ll> idx;
	rep(i,0,n) cin>>words[i],tot.insert(words[i]),idx[words[i]]=i+1;
	vi ans;

	vector< set<string> > s(2);

	rep(i,0,n)
	{
		ll nt = sz(words[i]);
		string r = words[i];
		if(r[0]!=r[nt-1]) s[(words[i][nt-1]-'0')].insert(words[i]);
		else
		{
			if((words[i][nt-1]-'0')==0) n0++;
			else n1++;
		} 

	} 

	ll t = (sz(s[0])<sz(s[1])); /// index of bigger set
	n=(sz(s[0])+sz(s[1]));
	ll cnt=0;

	ll x1 = sz(s[!t])+cnt;
	ll y1 = sz(s[t])-cnt;
	if(x1==y1 && y1==0 && n1!=0 && n0!=0) 
	{
		cout<<"-1\n";
		return 0;
	}

	all(it,s[t])
	{
		if( (abs(sz(s[!t])-sz(s[t])) - 2*cnt) <=(n%2) ) break;

		string r = *it;
		
		string dup = r;
		reverse(dup.begin(), dup.end());
		
		if(s[!t].find(dup)==s[!t].end())
		{
			ans.pb(idx[r]);
			cnt++;
		} 
	}


	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans)) cout<<ans[i]<<" ";
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
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}