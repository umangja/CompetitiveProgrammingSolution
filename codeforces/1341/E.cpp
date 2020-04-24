/*input

*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}
const ll M = 1e4+5,G = 1e3+5 , N = 1e6+5; 
ll n,m,g,r;
vi cor,pos;
vvi dist;

void BFS01()
{

	dist[0][g]=0;

	deque<pii> q;
	q.push_front(mp(0,g));

	vvi vis;
	vis.assign(m+1,vi(g+1,0));


	while(!q.empty())
	{	
		pii cur = q.front();
		q.pop_front();

		if(vis[cur.F][cur.S]==1) continue;
		vis[cur.F][cur.S]=1;

		ll i = cur.F;
		ll j = cur.S;
		rep(sign,-1,2)
		{
			if(sign==0) continue;
			if(i+sign<m && i+sign>=0)
			{
				ll nc = cor[i+sign];	
				ll k = abs(nc-cor[i]);	
				if(k>j) continue;

				ll len = (j==k);	
				ll nd = dist[cur.F][cur.S]+len;
				ll left = (j==k?g:j-k); 
				if(nd<dist[i+sign][left])
				{
					dist[i+sign][left] = nd;
					if(len==0) q.push_front(mp(i+sign,left));
					else       q.push_back(mp(i+sign,left))	;
				}
			}
		}

	}

	ll poss = dist[m-1][g];
	rep(k,1,g) poss=min(poss,dist[m-1][k]);
	if(poss>=inf)
	{
		cout<<"-1\n";
		return ;
	}	


	ll ans = (dist[m-1][g]<inf?dist[m-1][g]*(g+r)-r:inf);
	rep(k,1,g) if(dist[m-1][k]<inf) ans=min(ans,dist[m-1][k]*(r+g)+g-k);
	cout<<ans<<"\n";
	return ;
}

int solve()
{
	cin>>n>>m;
	pos.assign(n+1,-1);
	cor.assign(m,-1);

	rep(i,0,m) cin>>cor[i];
	sort(cor.begin(), cor.end());
	rep(i,0,m) pos[cor[i]]=i;
	cin>>g>>r;

	dist.assign(m+1,vi(g+1,inf));

	BFS01();


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
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}