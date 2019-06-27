/*input
01:02
03:02

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
	ll h1,m1,h2,m2;
	string s,r;cin>>s>>r;
	h1 = (s[0]-'0')*10+(s[1]-'0');
	m1 = (s[3]-'0')*10+(s[4]-'0');
	h2 = (r[0]-'0')*10+(r[1]-'0');
	m2 = (r[3]-'0')*10+(r[4]-'0');

	// cout<<h1<<"\n";
	ll mini = (60 - m1)+ (h2-h1-1)*60 + m2;
	// cout<<mini<<"\n";
	ll ans = mini/2;

	ll t = min(60-m1,ans);
	m1 = (m1+t)%60;
	ans-=t;

	if(m1==0)
		h1++;
	h1+=ans/60;
	ans%=60;

	m1+=ans;
	string ansh = to_string(h1);
	string ansm = to_string(m1);

	if(sz(ansh)==1)
		ansh='0'+ansh;

	if(sz(ansm)==1)
		ansm='0'+ansm;

	cout<<ansh<<":"<<ansm;

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