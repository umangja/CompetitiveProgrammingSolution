/*input
-44 47
24
96 -18
-50 86
84 68
-25 80
-11 -15
-62 0
-42 50
-57 11
-5 27
-44 67
-77 -3
-27 -46
32 63
86 13
-21 -51
-25 -62
-14 -2
-21 86
-92 -94
-44 -34
-74 55
91 -35
-10 55
-34 16
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
 
ll bx,by;
ll n;
ll total_mask;
vpii object;
// vpii ans;
ll dp[1<<24];
vpii bt(1<<24);
 
ll dist(ll i,ll j)
{
	ll ans1 = (object[i].F-object[j].F)*(object[i].F-object[j].F)+(object[i].S-object[j].S)*(object[i].S-object[j].S);
	ll ans2 = (object[i].F-bx)*(object[i].F-bx)+(object[i].S-by)*(object[i].S-by);
	ll ans3 = (object[j].F-bx)*(object[j].F-bx)+(object[j].S-by)*(object[j].S-by);
	return ans1+ans2+ans3;
}
 
// ll fun(ll mask)
// {
// 	if(mask==total_mask) return 0;
// 	if(dp[mask]!=-1) return dp[mask];
 
// 	ll min_time = inf;
// 	pii anst=mp(0,0);
// 	rep(i,0,n) if(!(mask&(1<<i))) rep(j,0,n) if(!(mask&(1<<j)))
// 	{
// 		ll nm = mask|(1<<j);nm = nm|(1<<i);
// 		ll temp = dist(i,j)+fun(nm);
// 		// cout<<i<<" "<<j<<" "<<temp<<"\n";
// 		if(temp<min_time)
// 		{
// 			min_time=temp;
// 			anst = mp(i,j);
// 		}
// 	}
// 	bt[mask]=anst;
// 	return dp[mask]=min_time;
// }
int solve()
{
	dp[0]=0;
	cin>>bx>>by;
	cin>>n;
	total_mask=(1<<n)-1;
	rep(i,1,total_mask+1) dp[i]=inf; 
	rep(i,0,n)
	{
		ll x,y;cin>>x>>y;
		object.pb(mp(x,y));
	}
 
	rep(mask,0,total_mask+1)
	    if(dp[mask]<inf)
		rep(i,0,n) if(!(mask&(1<<i))) 
		{
			rep(j,0,n) if(!(mask&(1<<j)))
			{
				ll nm = mask|(1<<j);nm = nm|(1<<i);
				ll temp = dist(i,j)+dp[mask];
				// cout<<i<<" "<<j<<" "<<temp<<"\n";
				if(temp<dp[nm])
				{
					dp[nm]=temp;
					bt[nm]=mp(i,j);
				}
			}
			break;
		}
 
 
	cout<<dp[total_mask]<<"\n";
	ll mask=total_mask;
	vi ans;
	ll prev_m=mask;
	while(mask>0)
	{
		pii p = bt[mask];
		if(p.F==p.S) ans.pb(0),ans.pb(p.F+1),mask=mask^(1<<p.F);
		else ans.pb(0),ans.pb(p.F+1),ans.pb(p.S+1),mask=mask^(1<<p.F),mask=mask^(1<<p.S);
		if(mask>prev_m) {cout<<"NOTOK\n";break;}
		prev_m=mask;
	}
	ans.pb(0);
	reverse(ans.begin(), ans.end());
	rep(i,0,sz(ans)) cout<<ans[i]<<" ";
 
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