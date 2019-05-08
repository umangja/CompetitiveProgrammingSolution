/*input
1
5




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
	vi a(n);
	rep(i,0,n)
		cin>>a[i];

	ll l=0,r=n-1;
	ll f=1;
	ll low = -1;
	string  ans = "";
	while(l<=r && f)
	{
		if(a[l]<=low && a[r]<=low)
			break;
		else if(a[l]<=low)
		{
			ans+='R';
			low = a[r];
			r--;
		}
		else if(a[r]<=low)
		{
			ans+='L';
			low = a[l];

			l++;
		}
		else
		{
			if(a[l]!=a[r])
			{
				if(a[l]>a[r])
				{
					ans+='R';
					low = a[r];

					r--;
				}
				else
				{
					ans+='L';
					low = a[l];

					l++;
				}
			}
			else
			{
				if((l+1)!=(r-1))
				{
					if(a[l+1]==a[r-1])
					{
						ans+='L';
						low = a[l];

						break;
					}
					else if(a[l+1]<a[r-1])
					{
						ans+='L';
						low = a[l];

						l++;
					}
					else
					{
						ans+='R';
						low = a[r];

						r--;
					}

				} 
				else
				{
					ans+='L';
					low = a[l];

					l++;
				} 
			}
		}
	}

	cout<<sz(ans)<<"\n"<<ans;
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