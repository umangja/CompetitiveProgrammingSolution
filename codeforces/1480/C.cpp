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
const ll maxQuery = 100;
ll queryDone = 0;
ll n;
vi a;
ll query(ll x){
	assert(queryDone<maxQuery);
	assert(x>=1 && x<=n);
	queryDone++;

	cout<<"? "<<x<<"\n"; 
	cout<<flush;

	cin>>x;
	return x;
}

void printAns(ll x){
	cout<<"! "<<x<<"\n";
	cout<<flush;
	exit(0) ;
}

pair<pii,ll> check(ll idx){
	pair< pii,ll > p;
	
	if(idx-1>=1) p.F.F = query(idx-1);
	else p.F.F = inf;

	p.F.S = query(idx);

	if(idx+1<=n) p.S = query(idx+1);
	else p.S = inf;

	return p;
}

int solve()
{
	cin>>n;
	a.resize(n+2);
	a[0] = inf;
	a[n+1] = inf;



	ll Low = 1,High = n;
	while(Low<High){
		ll mid = Low + (High-Low+1)/2;
		pair< pii,ll > cur  = check( mid );
		// cout<<cur.F.F<<" "<<cur.F.S<<" "<<cur.S<<"\n";
		if( cur.F.F > cur.F.S  && cur.S > cur.F.S ){
			printAns(mid);
			return 0;
		}
		else if( cur.F.F < cur.F.S   )  High = mid-1;
		else Low = mid + 1;
	}
// 	assert(0);
    printAns(Low);
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
	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}