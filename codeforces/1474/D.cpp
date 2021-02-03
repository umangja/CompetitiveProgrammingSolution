/*input
6
5
111111111 111111111 111111111 111111111 333333333
3
1 2 1
3
1 1 2
5
2 2 2 1 3
5
2100 1900 1600 3000 1600
2
2443 2445

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)     cout << #x << " " << x << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}

bool fun(vi &a){
	if(a[1]>=a[0]) a[1]-=a[0];
	else return false;
	if(a[2]>=a[3]) a[2]-=a[3];
	else return false;

	return (a[1]==a[2]);
}

int solve()
{
	ll n;cin>>n;
	vi a(n+2,0);
	rep(i,1,n+1) cin>>a[i];


	// [0,n+1]

	vi L(n+2,-1);
	vi R(n+2,-1);

	ll last = 0;
	rep(i,0,n+2){
		if(a[i]>=last) {
			L[i] = a[i] - last;
			last = a[i] - last;
		}
		else break;
	}

	last=0;
	repr(i,n+1,-1){
		if(a[i] >= last){
			R[i] = a[i] - last;
			last = a[i] - last;
		}
		else break;
	}

	// debug_v(L);
	// debug_v(R);

	ll pos= (L[n+1]==0 || R[0]==0) ;



	rep(i,1,n){

		if(L[i-1]!=-1 && R[i+2]!=-1){
			vi temp = {L[i-1],a[i+1],a[i],R[i+2]};

			// whatis(i);
			// debug_v(temp);

			pos |= ( fun(temp) );
		}

		if(pos){
			break;
		} 
	}

	cout<<(pos==1?"Yes\n":"No\n");


	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	//cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}