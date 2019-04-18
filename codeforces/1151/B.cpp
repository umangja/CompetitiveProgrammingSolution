/*input
2 3
7 7 7
7 7 10
*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define is_empty(v) v.empty()
#define vs			vector< string >
#define vvi			vector< vector< ll,ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define reprr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define sum(v)      accumulate(v.begin(),v.end(),(ll)0)
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;


int solve()
{
	ll n,m;cin>>n>>m;
	vector< vector< ll > > a(n,vector< ll > (m) );

	rep(i,0,n)
	{
		rep(j,0,m)
			cin>>a[i][j];
	}

	ll o;
	rep(k,0,11)
	{
		ll y =0;
		ll no =0;
		ll bot = 0;
		ll mask = 1<<k;
		// cout<<mask;
		vi ans(n,-1);
		rep(i,0,n)
		{
			ll f=0;
			ll g=0;
			rep(j,0,m)
			{
				// cout<<(a[i][j] & mask);
				if( (a[i][j] & mask)==mask ) 
				{
					f=1;
				}
				if((a[i][j] & mask)!=mask )
				{
					g=1;
				}

			}
			if(f==1 && !g)
			{
				ans[i]=1;
				y++;
			}
			else if(g==1 && !f)
			{
				ans[i]=2;
				no++;
			}
			else if(f==1 && g==1)
			{
				bot++;
				ans[i]=3;
			}
		}

		// cout<<y<<" ";

		if(y%2==1 || (y==0 && bot>=1) || (y%2==0 && y!=0 && bot>=1))
		{
			cout<<"TAK\n";
			ll f=0;
			if(y%2==1)
				f=1;

			rep(i,0,n)
			{
				rep(j,0,m)
				{
					if(ans[i]==1 &&( (a[i][j] & mask)==mask ) )
					{
						cout<<j+1<<" ";
						break;
					}

					if(ans[i]==2 &&( (a[i][j] & mask)!=mask ) )
					{
						cout<<j+1<<" ";
						break;
					}

					if(ans[i]==3)
					{
						if((f && ( (a[i][j] & mask)!=mask )) ||(!f && ( (a[i][j] & mask)==mask )) )
						{
							f=1;
							cout<<j+1<<" ";
							break;
						}

					}
				}
			}
			return 0;
		}


	}

	cout<<"NIE";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}