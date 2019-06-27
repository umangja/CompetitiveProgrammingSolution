/*input
10
code??????
??????test



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
	string s,r;cin>>s>>r;
	vector< vector< ll > > fs(27,vector< ll >() ),fr(27,vector< ll >() );
	vector< pair< ll,ll > > ans;
	ll id;
	rep(i,0,n)
	{
		if(s[i]=='?')
			id=26;
		else
			id=s[i]-'a';
		fs[id].pb(i+1);

		if(r[i]=='?')
			id=26;
		else
			id=r[i]-'a';
		fr[id].pb(i+1);
	}

	ll l;
	rep(i,0,26)
	{
		l = min(sz(fs[i]),sz(fr[i]));
		rep(j,0,l)
			ans.pb(mp(fs[i][j],fr[i][j]));
	}

	l = 0;
	rep(k,0,26)
	{
		ll l2 = min(sz(fs[k]),sz(fr[k]));
		rep(i,l2,max(sz(fs[k]),sz(fr[k])))
		{
			if(l<sz(fs[26]) && sz(fr[k])>i)
				ans.pb(mp(fs[26][l],fr[k][i]));
			else
				break;
			l++;
		}
	}

	ll s1=l;

	l = 0;
	rep(k,0,26)
	{
		ll l2 = min(sz(fs[k]),sz(fr[k]));
		rep(i,l2,max(sz(fs[k]),sz(fr[k])))
		{
			if(l<sz(fr[26]) && sz(fs[k])>i)
				ans.pb(mp(fs[k][i],fr[26][l]));
			else
				break;

			l++;
		}
	}

	ll s2=l;

	while(s1<sz(fs[26]) && s2<sz(fr[26]))
	{
		ans.pb(mp(fs[26][s1],fr[26][s2]));
		s1++;
		s2++;
	}




	cout<<sz(ans)<<"\n";
	rep(i,0,sz(ans))
	{
		cout<<ans[i].F<<" "<<ans[i].S<<"\n";
	}

	return 0;

	// string s1="",s2="";
	// ll a=0,b=0;
	// rep(i,0,n)
	// {
	// 	if(s[i]!='?')
	// 		s1+=s[i];
	// 	else
	// 		a++;
	// 	if(r[i]!='?')
	// 		s2+=r[i];
	// 	else
	// 		b++;
	// }

	// s=s1;
	// r=s2;

	// sort(s.begin(), s.end());
	// sort(r.begin(), r.end());

	// ll i=0,j=0;
	// vector< pair< ll,ll > > ans;
	// while(i<sz(s) && j<sz(r))
	// {
	// 	if(s[i]==r[j])
	// 	{
	// 		ans++;
	// 		i++;
	// 		j++;
	// 	}
	// 	else if(s[i]>r[j])
	// 		j++;
	// 	else
	// 		i++;
	// }

	// cout<<ans;
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