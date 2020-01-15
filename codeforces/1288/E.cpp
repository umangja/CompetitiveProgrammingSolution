#include <new>
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

const ll N = 6e5+10;
vi pos(N,-1);
vi last_pos(N,-1);
vi vis(N,0);
vi mn(N),mx(N);
ll n,m;

ll bit[2][N];

void add(ll idx,ll val,ll tree)
{
	for(ll i=idx;i<(tree==0?n:m);i=i|(i+1)) bit[tree][i]+=val;
	return ;
}

ll query_single(ll idx,ll tree)
{
	ll ans=0;
	for(ll i=idx;i>=0;i=((i&(i+1))-1)) ans+=bit[tree][i];
	return ans;
}

ll query(ll l,ll r,ll tree)
{
	return query_single(r,tree)-query_single(l-1,tree);
}

int solve()
{
	cin>>n>>m;
	rep(i,0,n) mn[i]=mx[i]=i;
	vi q(m);
	rep(i,0,m) cin>>q[i],q[i]--;
	// add(0,1,0);
	// add(1,1,0);
	// add(2,1,0);
	// add(3,3,0);

	// cout<<query(0,3,0);
	// cout<<query(0,2,0);
	// cout<<query(0,1,0);
	// cout<<query(0,0,0);
	// cout<<query(1,3,0);



	rep(i,0,m)
	{
		ll x=q[i];

		mn[x]=0;

		if(vis[x]==0)
		{
			vis[x]=1;
			add(x,1,0);
		}

		add(i,1,1);

		if(last_pos[x]==-1)
		{
			// whatis(x);
			// if(x==11)
			// {
			// 	whatis(query(x+1,n-1,0));
			// 	ll ans_temp=0;
			// 	vi temp_vis(n,0);
			// 	rep(j,0,i) if(q[j]>x && temp_vis[q[j]]==0) ans_temp++,temp_vis[q[j]]=1;
			// 	whatis(ans_temp);
			// } 
			mx[x]=max(mx[x],x+query(x+1,n-1,0));
			last_pos[x]=i;
			continue;
		}
		else
		{
			ll last = last_pos[x];
			add(last,-1,1);
			last_pos[x]=i;
			// if(x==11)
			// {
			// 	whatis(last);
			// 	whatis(i);
			// 	whatis(query(last+1,i-1,1));
			// 	ll ans_temp=0;
			// 	vi temp_vis(n,0);
			// 	rep(j,last,i) if(temp_vis[q[j]]==0) ans_temp++,temp_vis[q[j]]=1;
			// 	whatis(ans_temp);
			// }
			mx[x]=max(mx[x],query(last+1,i-1,1));
		}
	}

	rep(x,0,n)
	{
		ll last = last_pos[x];
		if(last!=-1) mx[x]=max(mx[x],query(last,m-1,1)-1);
		else mx[x]=max(mx[x],x+query(x+1,n-1,0));
	}

	rep(i,0,n) cout<<mn[i]+1<<" "<<mx[i]+1<<"\n";
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