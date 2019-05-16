/*input
9
1 1 2 1 1 1 2 1 1



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
const ll N = 4e6+5;
vi prime(N,0);

void fun()
{
	prime[0]=1;
	prime[1]=1;

	for(ll i=2;i*i<=N;i++)
	{
		if(prime[i]==0)
		{
			for(ll j=i*i;j<=N;j+=i)
				prime[j]=1;
		}
	}

}

int solve()
{
	fun();
	ll n;cin>>n;
	vi a(n);
	ll c1=0,c2=0,ts=0;
	rep(i,0,n)
	{
		cin>>a[i];
		if(a[i]==1)
			c1++;
		else
			c2++;

		ts+=a[i];
	}

	vi ans(n);
	ll index=0;
	ts=0;
	while(index<n)
	{
		if(prime[ts+1]==0 && c1>0)
		{
			ans[index]=1;
			c1--;ts++;
		}
		else if(prime[ts+2]==0 && c2>0)
		{
			ans[index]=2;
			c2--;ts+=2;
		}
		else
		{
			if(c2>0)
			{
				ans[index]=2;
				c2--;ts+=2;
			}
			else if(c1>0)
			{
				ans[index]=1;
				c1--;ts++;
			}
		}

		index++;
	}
	// c1--;c2--;
	// ll index=n-1;
	// while(ts)
	// {
	// 	if(prime[ts-2]==0 && c2>0)
	// 	{
	// 		ans[index]=2;
	// 		c2--;ts-=2;
	// 	}
	// 	else if(prime[ts-1]==0 && c1>0)
	// 	{
	// 		ans[index]=1;
	// 		c1--;ts--;
	// 	}
	// 	else
	// 	{
	// 		if(c2>0)
	// 		{
	// 			ans[index]=2;
	// 			c2--;ts-=2;
	// 		}
	// 		else if(c1>0)
	// 		{
	// 			ans[index]=1;
	// 			c1--;ts--;
	// 		}
	// 	}
	// 	index--;
	// 	if(c1==0 && c2==0)
	// 		break;
	// }

	rep(i,0,n)
	{
		cout<<ans[i]<<" ";
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