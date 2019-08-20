/*input
2
01
10
2
1 2

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
ll n;
const ll N = 101;
ll adj[101][101];
ll sd[100][100];
ll sptSet[N];
ll dist[N];

ll min_dist()
{
   ll mini = inf, min_index=-1; 
   for (int v = 0; v < n; v++) 
     if (sptSet[v] == 0 && dist[v] <= mini) 
         mini = dist[v], min_index = v; 
   return min_index; 
}


void fun(ll src)
{

	rep(i,0,n)
	{
		dist[i]=inf;
		sptSet[i]=0;
	} 

	dist[src]=0;
	for(ll count=0;count<n-1;count++)
	{
		ll u=min_dist();
		sptSet[u]=1;
		rep(i,0,n)
		{
			if(sptSet[i]==0 && adj[u][i] && dist[u]!=inf && dist[u]+1<dist[i]){
				dist[i]=dist[u]+1;
				// cout<<i<<" "<<u<<"\n";
			}
		}

	}
	rep(i,0,n) sd[src][i]=dist[i];
	return ;
}

int solve()
{
	cin>>n;
	rep(i,0,n)
	{
		string s;cin>>s;
		rep(j,0,n) adj[i][j]=(s[j]-'0');
	} 

	// rep(i,0,n) rep(j,0,n) cout<<adj[i][j]<<" ";

	rep(i,0,n)
	{
		fun(i);
		// rep(j,0,n) cout<<sd[i][j]<<" ";
		// cout<<"\n";
	}
	ll m;cin>>m;
	vi v(m);
	rep(i,0,m) 
	{
		cin>>v[i];
		v[i]--;
	}


	vi ans;
	if(m==2)
	{
		ans.pb(v[0]);
		if(v[0]!=v[1]) ans.pb(v[1]);
		cout<<sz(ans)<<"\n";
		rep(i,0,sz(ans)) cout<<ans[i]+1<<" ";
		return 0;
	}
	else
	{
		ll i=0,j=2,k=1;
		ans.pb(v[0]);
		while(j<m)
		{
			if(sd[v[i]][v[k]]+sd[v[k]][v[j]]>sd[v[i]][v[j]] && ans[sz(ans)-1]!=v[k]) ans.pb(v[k]),i=k;
			k++,j++;
		}
		if(ans[sz(ans)-1]!=v[j-1]) ans.pb(v[j-1]);

		cout<<sz(ans)<<"\n";
		rep(l,0,sz(ans)) cout<<ans[l]+1<<" ";
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