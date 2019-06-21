/*input
5
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5 5 6 6 7 7 8 8 9
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
	ll n;cin>>n;
	vi a(n*n);
	vector< vector< ll > > v(n,vector< ll >(n,0) );
	vi f(1001,0);

	rep(i,0,n*n)
		cin>>a[i];

	rep(i,0,n*n)
		f[a[i]]++;


	rep(i,0,(n+1)/2)
	{
		rep(j,0,(n+1)/2)
		{
			if(i!=n/2 && j!=n/2)
			{
				ll k=1;
				for(;k<1001;k++)
				{
					if(f[k]>=4)
					{
						v[i][j]=k;v[n-i-1][j]=k;v[i][n-j-1]=k;v[n-i-1][n-j-1]=k;
						f[k]-=4;
						break;
					}

				}

				if(k==1001)
				{
					cout<<"NO";
					return 0;
				}
			}
		}
	}

	rep(i,0,(n+1)/2)
	{
		rep(j,0,(n+1)/2)
		{
			if(i!=n/2 && j!=n/2)
				continue;
			else if(!(i==n/2 && j==n/2))
			{
				ll k=1;
				for(;k<1001;k++)
				{
					if(f[k]>=2)
					{
						// cout<<i<<" "<<j;
						v[i][j]=k;v[n-i-1][j]=k;v[i][n-j-1]=k;v[n-i-1][n-j-1]=k;
						f[k]-=2;
						break;
					}
				}


				if(k==1001)
				{
					cout<<"NO";
					return 0;
				}
			}
			else
			{
				v[i][j]=-1;
			}
		}
	}

	ll f1=0;
	rep(i,1,1001)
	{
		if(!f1 && f[i]>0)
		{
			f1=i;
		}
		else if(f1>0 && f[i]>0)
		{
			cout<<"NO";
			return 0;
		}
	}

	cout<<"YES\n";
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			if(v[i][j]!=-1)
				cout<<v[i][j]<<" ";
			else
				cout<<f1<<" ";
		}

		cout<<"\n";
	}

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