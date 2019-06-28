/*input
4
0011
0101


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
	string s1,s2;cin>>s1>>s2; 
	vi a(n),c(n);
	rep(i,0,n)
		c[i]=s1[i]-'0';
	rep(i,0,n)
		a[i]=s2[i]-'0';

	ll t1=0,t2=0,t3=0,t4=0;
	rep(i,0,n)
	{
		if(a[i]==1 && c[i]==1)
			t1++;
		else if(a[i]==0 && c[i]==0)
			t2++;
		else if(a[i]==1 && c[i]==0)
			t3++;
		else
			t4++;
	}

	vi ans;
	// cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<"\n";

	rep(aa,0,t1+1)
	{
		rep(cc,0,t3+1)
		{
			ll dd = t1+t3-cc-aa-aa;
			ll bb = n/2-aa-cc-dd;

			// cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<"\n";
			if(dd<=t4 && bb<=t2 && bb>=0 && dd>=0)
			{
				// cout<<t2<<" ";
				// cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<"\n";
				rep(i,0,n)
				{
					if(a[i]==1 && c[i]==1 && aa>0)
					{
						aa--;
						ans.pb(i+1);
					}
					else if(a[i]==0 && c[i]==0 && bb>0)
					{
						// cout<<"YES";
						bb--;
						ans.pb(i+1);
					}
					else if(a[i]==1 && c[i]==0 && cc>0)
					{
						cc--;
						ans.pb(i+1);
					}
					else if(a[i]==0 && c[i]==1 && dd>0)
					{
						dd--;
						ans.pb(i+1);
					}
				}

				rep(i,0,sz(ans))
					cout<<ans[i]<<" ";

				return 0;
			}
		}
	}

	cout<<"-1";
	return 0;
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