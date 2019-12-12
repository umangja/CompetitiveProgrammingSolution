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
	vvi mat(n,vi (n,0));

	rep(i,0,n-1) 
	{
		ll x,y;cin>>x>>y;
		x--,y--;
		mat[x][y]=1;
	}

	// rep(i,0,n) {rep(j,0,n) cout<<mat[i][j]<<" "; cout<<"\n";} cout<<"\n";


	vector< pair< ll,pii > > ans;
	vi row(n,0);
	rep(i,0,n) rep(j,0,n) row[i]+=mat[i][j];


	
	ll tot=0;	

	rep(i,0,n) rep(j,i,n) if(row[i] > row[j] && i!=j){
		swap(mat[i],mat[j]);
		swap(row[i],row[j]);
		ans.pb(mp(1,mp(i,j)));
	}

	// sort(row.begin(), row.end());
	rep(i,0,n)
	{
		rep(j,i,n)
		{
			if(row[j]+tot==i)
			{
				ll x = row[j];
				tot+=x;
				if(j!=i)
				{
					swap(mat[i],mat[j]);
					swap(row[i],row[j]);
					ans.pb(mp(1,mp(i,j)));
				}
				
				rep(k,i-x,i)
				{
					if(mat[i][k]!=1)
					{
						rep(k1,i,n) if(mat[i][k1]==1)
						{
							ans.pb(mp(2,mp(k,k1)));
							rep(s,0,n) swap(mat[s][k],mat[s][k1]);
						} 
					}
				}

				break;				
			}

			ll x = row[i];
			rep(k,i,n)
			{
				if(mat[i][k]==1)
				{
					// if(i==7) cout<<"OK\n";
					rep(k1,i-x,i) if(mat[i][k1]==0)
					{
						ans.pb(mp(2,mp(k,k1)));
						rep(s,0,n) swap(mat[s][k],mat[s][k1]);
					} 
				}
			}

		}		
	}

	// rep(i,0,n) {rep(j,0,n) cout<<mat[i][j]<<" "; cout<<"\n";} cout<<"\n";

	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans))
	{
		cout<<ans[i].F<<" "<<ans[i].S.F+1<<" "<<ans[i].S.S+1<<"\n";
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