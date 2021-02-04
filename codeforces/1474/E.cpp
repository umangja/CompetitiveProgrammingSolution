/*input
1
5
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

/*

1 2 3 4 

3 1 4 2

4 2 3 1

1 2 3 4 5

5 2 3 4 1

1 2 3 4 5 6

6 2 3 4 5 1 

5 1 3 4 6 2 



9 + 4 + 4 = 17 

16 + 9 + 9 + 4  = 38

25 + 16 + 16 + 9 + 9 = 75

36+25 + 25 + 16 + 16 + 16 = 

*/

int solve()
{
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) a[i] = i+1;

	long long int cost = 0;
	vector<pair<int,int>> ans;

	int L = 2,R = n-1;

	for(int i=0;i<n-1;i++){
		if(i==0){
			ans.push_back({1,n});
			swap(a[0],a[n-1]);
			cost += (long long int)(n-1)*(long long int)(n-1);
		}
		else{

			int ii= R,j = 1;

			ans.push_back({ii,j});
			swap(a[ii-1],a[j-1]);

			cost += (long long int)(j-ii)*(long long int)(j-ii);

			i++;R--;

			if(i<n-1){
				ii= L,j = n;
				ans.push_back({ii,j});
				swap(a[ii-1],a[j-1]);
				cost += (long long int)(j-ii)*(long long int)(j-ii);
				L++;
			}
		}

	}

	reverse(ans.begin(),ans.end());

	cout<<cost<<"\n";
	for(int i=0;i<n;i++) cout<<a[i]<<" "; 
	cout<<"\n";
	cout<<n-1<<"\n";
	for(int i=0;i<n-1;i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}