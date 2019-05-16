/*input

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

ll q(ll i,ll j)
{
	cout<<"? "<<i<<" "<<j<<"\n";
	cout<<flush;
	ll ans;cin>>ans;
	if(ans==0)
	{
		exit(0);
	}
	else
		return ans;
}

vi v = {4,8,15,16,23,42};
int solve()
{
	set< ll > s;
	s.insert(4);
	s.insert(8);
	s.insert(16);
	s.insert(15);
	s.insert(23);
	s.insert(42);

	vi ans(6);
	ll a1 = q(1,2);
	ll a2 = q(1,3);
	ll a3 = q(1,4);
	ll a4 = q(1,5);

	ll f=0;
	rep(i,0,6)
	{
		rep(j,0,6)
		{
			if(v[i]*v[j]==a1)
			{
				if(((a2*1.0)/v[i] == (a2)/v[i]) && ((a3*1.0)/v[i] == (a3)/v[i]) && ((a4*1.0)/v[i] == (a4)/v[i]))
				{
					if( s.find((a2)/v[i])!=s.end() && s.find((a3)/v[i])!=s.end() && s.find((a4)/v[i])!=s.end() )
					{
						ans[0]=v[i];
						f=1;
						break;

					}
				}
			}
		}
		if(f)
			break;
	}

	ans[1]=a1/ans[0];
	ans[2]=a2/ans[0];
	ans[3]=a3/ans[0];
	ans[4]=a4/ans[0];

	rep(i,0,5)
	{
		s.erase(ans[i]);
	}

	ans[5]=*s.begin();

	cout<<"! ";
	rep(i,0,6)
		cout<<ans[i]<<" ";
	cout<<"\n"<<flush;




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