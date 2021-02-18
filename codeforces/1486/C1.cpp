/*input
10
*/


// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll          long long int
#define pb          push_back
#define pii         pair<ll ,ll >
#define vpii        vector< pii >
#define vi          vector<ll >
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

int mxQuery = 40;
int n,cnt;
vector<int> a;

void init(){
	a.resize(n+1);
	for(int i=0;i<=n;i++) a[i] = i;
	ll times =rng()%1000;
	while(times--) random_shuffle(a.begin(), a.end());
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}

int fun(int L,int R){
	vector<pair<int,int>> temp;
	for(int i=L;i<=R;i++) temp.push_back(make_pair(a[i],i));
	sort(temp.begin(), temp.end());
	return temp[temp.size()-2].second;
}


int query(int L,int R){
	assert(L>=1 && L<=n && R>=1 && R<=n && L<R);
	assert(cnt<mxQuery);
	cnt++;
	cout<<"? "<<L<<" "<<R<<"\n"; 
	cout<<flush;
	int x;
	cin>>x;
	// x = fun(L,R);
	// cout<<x<<"\n";
	return x;
}
int main()
{
	cin>>n;
	// init();

	int pos = query(1,n);
	int ans = (pos>1?query(1,pos):-1);
	int low = -1,high = -1;
	if(ans==pos){

		low  = 1;high = pos-1;
		while(high - low >= 2) {
			int mid = low + (high-low+1)/2;
			int temp = query(mid,pos);
			if(temp==pos) low = mid;
			else high = mid-1;
		}

	
	}
	else{
		low = pos+1;high = n;
		
		while(high-low>=2) {
			int mid = low + (high-low)/2;
			ll temp = query(pos,mid);
			if(temp==pos) high = mid;
			else low = mid+1;
		}

	} 

	if(low<high){
		ll temp = query(low,high);
		if(temp==low) low = high;
		else high = low;
	}
		
	cout<<"! "<<low<<"\n";
	cout<<flush;

	// assert(a[low]==*max_element(a.begin()+1,a.end()));

	return 0;
}
