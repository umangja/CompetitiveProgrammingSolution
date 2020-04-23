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

const ll N = 2e3+3, K = 2e3+3;
ll pos[N][K];
ll dig[N][K];
ll used[N][K];

vi ans;
vector< vpii > adj(N,vpii ());
ll n,k;

inline ll fun(ll p,ll k_left)
{
	if(k_left<0) return 0;
	if(p==n) return (k_left==0);
	if(pos[p][k_left]!=-1) return pos[p][k_left];

	rep(i,0,sz(adj[p]))
	{
		ll d = adj[p][i].F;
		ll u = adj[p][i].S;

		if(k_left-u>=0 && fun(p+1,k_left-u)==1)
		{
			ans[p] = d;
			return pos[p][k_left]=1;			
		}
	}

	return 0;
}

int solve()
{
	map<ll,string> m;
	m[0] = "1110111";
	m[1] = "0010010";
	m[2] = "1011101";
	m[3] = "1011011";
	m[4] = "0111010";
	m[5] = "1101011";
	m[6] = "1101111";
	m[7] = "1010010";
	m[8] = "1111111";
	m[9] = "1111011";

	cin>>n>>k;
	vs a(n);

	ans.assign(n,-1);

	memset(pos,-1,sizeof pos);
	memset(dig,-1,sizeof dig);
	memset(dig,-1,sizeof dig);


	rep(i,0,n)
	{
		string s;
		cin>>s;
		a[i] = s;
		repr(num,9,-1)
		{
			string r = m[num];
			ll poss=1;
			ll req=0;
			rep(j,0,7)
			{
				if(r[j]=='0' && s[j]=='1') poss=0;
				else if(r[j]=='1' && s[j]=='0') req++;
			} 

			if(poss==1) adj[i].pb(mp(num,req));
		}
	}


	for(ll p = n-1;p>=0;p--)
	{
		for(ll k_left = k;k_left>=0;k_left--)
		{
			rep(i,0,sz(adj[p]))
			{
				ll d = adj[p][i].F;
				ll u = adj[p][i].S;

				if(p==n-1)
				{
					if(k_left==u)
					{
						pos[p][k_left]=1;
						dig[p][k_left]=d;
						used[p][k_left]=u;
						break;
					}
				}
				else if(k_left-u>=0 && pos[p+1][k_left-u]==1)
				{
					pos[p][k_left]=1;
					dig[p][k_left]=d;
					used[p][k_left]=u;
					break;
				}
			}
		}
	}




	
	if(	pos[0][k]==1)
	{
		rep(i,0,n)
		{
			ll d = dig[i][k];
			k-=used[i][k];
			cout<<d;
		} 
		cout<<"\n";
	} 
	else cout<<-1<<"\n";

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	// cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}