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

void loss()
{
	cout<<"NO\n";
	exit(0);
}

int solve()
{
	string s;
	set<ll > gen;
	vector<char> order;
	ll fq=0;
	while(cin>>s)
	{
		ll f=0;
		ll g=0,a=0,n=0,v=0;
		reverse(s.begin(), s.end());
		
		string r="";

		rep(i,0,min((ll)3,sz(s))) r+=s[i];
		reverse(r.begin(), r.end());
		if(r=="etr") {g=1,n=1,f=1; 		gen.insert(g);
		if(v==1) order.pb('v');
		if(n==1) order.pb('n'),fq++;
		if(a==1) order.pb('a');continue;}
		
		if(f==0 && sz(s)<4) loss();
		reverse(r.begin(), r.end());
		r+=s[3];
		reverse(r.begin(), r.end());
		if(r=="lios")  {g=1,a=1,f=1;		gen.insert(g);
		if(v==1) order.pb('v');
		if(n==1) order.pb('n'),fq++;
		if(a==1) order.pb('a'); continue;}
		if(r=="etra")  {g=0,n=1,f=1;		gen.insert(g);
		if(v==1) order.pb('v');
		if(n==1) order.pb('n'),fq++;
		if(a==1) order.pb('a'); continue;}

		if(f==0 && sz(s)<5) loss();
		reverse(r.begin(), r.end());
		r+=s[4];
		reverse(r.begin(), r.end());
		if(r=="liala") {g=0,a=1,f=1;		gen.insert(g);
		if(v==1) order.pb('v');
		if(n==1) order.pb('n'),fq++;
		if(a==1) order.pb('a'); continue;}

		if(f==0 && sz(s)<6) loss();
		reverse(r.begin(), r.end());
		r+=s[5];
		reverse(r.begin(), r.end());
		if(r=="initis") {v=1,g=1,f=1; 		gen.insert(g);
		if(v==1) order.pb('v');
		if(n==1) order.pb('n'),fq++;
		if(a==1) order.pb('a');continue;}
		if(r=="inites") {v=1,g=0,f=1; 		gen.insert(g);
		if(v==1) order.pb('v');
		if(n==1) order.pb('n'),fq++;
		if(a==1) order.pb('a');continue;}
	

		loss();

	}

	// whatis(sz(order));

	if(sz(order)==1)
	{
		cout<<"YES\n";
		return 0;
	}

	// whatis(sz(gen));

	if(sz(gen)>1 || fq!=1) loss();
	
	rep(i,1,sz(order))
	{
		// cout<<order[i]<<" "<<order[i-1]<<"\n";
		// if(order[i]=='n') continue;
		if(order[i]=='n' && order[i-1]!='a') loss();
		if((order[i]=='v' && (order[i-1]!='v' && order[i-1]!='n'))) loss();
		if((order[i]=='a' && order[i-1]!='a')) loss();

	}

	// if(c!=2 || order[0]!='a' || order[sz(order)-1]!='v') loss();



	cout<<"YES\n";
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