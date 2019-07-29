/*input
1 1
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
ll dp[base][base];
int solve()
{
	ll n,m;cin>>n>>m;
	ll pn=0,pm=0,cnt=0;
	ll dup=n-1;
	if(!dup) pn=1;
	while(dup) dup/=7,pn++;
	dup=m-1;
	if(!dup) pm=1;
	while(dup) dup/=7,pm++;


	if(pn+pm>7) cout<<"0";
	else
	{
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				ll dup1=i,dup2=j;
				vi n1(pn,0),n2(pm,0);
				ll k1=0;
				bool flag=true;
				while(dup1) n1[k1]=(dup1%7),dup1/=7,k1++;
				k1=0;
				while(dup2) n2[k1]=(dup2%7),dup2/=7,k1++;
				vi fq(7,0);
				rep(k,0,sz(n1)) fq[n1[k]]++;
				rep(k,0,sz(n2)) fq[n2[k]]++;
				rep(k,0,7) if(fq[k]>1) flag=false; 
				if(flag) cnt++;
			}
		}
		cout<<cnt;
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
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}