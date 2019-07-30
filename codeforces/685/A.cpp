/*input
344 344
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

const ll base = 7;
ll n,m;
ll pn=0,pm=0,cnt=0;
ll po[7];
vi fq(7);

void dfs(ll pos,ll flag)
{
	if(pos==(pn+pm))
	{
		ll ans1=0,ans2=0;
		rep(i,0,pn) ans1+=(ll)po[i]*(ll)pow(7,i);
		rep(i,pn,pn+pm) ans2+=(ll)po[i]*(ll)pow(7,i-pn);

		if(ans1<n && ans2<m)
		{
			rep(i,0,7) fq[i]=0;
			rep(i,0,pn+pm) fq[po[i]]++;		
			if(*max_element(fq.begin(), fq.end())==1) cnt++;
		}
		return ;
	}
	else
	{
		rep(i,0,7) if(!(flag&(1<<i))) po[pos]=i,dfs(pos+1,flag|(1<<i));
		return ;
	}
}

int solve()
{
	cin>>n>>m;
	ll dup=n-1;
	if(!dup) pn=1;
	while(dup) dup/=7,pn++;
	dup=m-1;
	if(!dup) pm=1;
	while(dup) dup/=7,pm++;


	if(pn+pm>7) cout<<"0";
	else
	{dfs(0,0);
	cout<<cnt;}
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