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


int solve()
{
	ll n;cin>>n;
	vvi a(2,vi (n));
	rep(i,0,n) cin>>a[0][i];
	rep(i,0,n) cin>>a[1][i];

	vvi sum1(2,vi (n)),sum2(2,vi(n)),sum3(2,vi(n,0));
	rep(i,0,2) rep(j,0,n) sum1[i][j]+=a[i][j]+(j-1>=0?sum1[i][j-1]:0);
	rep(i,0,2) rep(j,0,n) sum2[i][j]+=a[i][j]*(j+i)+(j-1>=0?sum2[i][j-1]:0);
	rep(i,0,2) repr(j,n-1,-1) sum3[i][j]+=a[i][j]*(2*n-j-i)+(j+1<=n-1?sum3[i][j+1]:0);

	ll last0=-1,last1=0;
	ll ans=0,last_ans=0;
	rep(i,0,n)
	{
		if(2*i<=n)
		{
			if(i!=0)
			{
				last0++;
				last_ans +=last0*a[0][2*i-2]+(last0+3)*a[0][2*i-1];
				last0+=3;

				last1++;
				last_ans+=last1*a[1][2*i-2]+(last1+1)*a[1][2*i-1];
				last1+=3;

			}

			ll temp = last_ans;
			if(2*i<=n-1)
			{
				ll ans1 = sum2[0][n-1]-(2*i-1>=0?sum2[0][2*i-1]:0)+(2*i)*(sum1[0][n-1] - (2*i-1>=0?sum1[0][2*i-1]:0));
				ans1 += sum3[1][2*i]+(2*i)*(sum1[1][n-1] - (2*i-1>=0?sum1[1][2*i-1]:0));

				ll ans2 = sum2[1][n-1]-(2*i-1>=0?sum2[1][2*i-1]:0) + (2*i)*(sum1[1][n-1] - (2*i-1>=0?sum1[1][2*i-1]:0));
				ans2+=2*i*a[0][2*i]+(2*i)*(sum1[0][n-1] - (2*i-1>=0?sum1[0][2*i-1]:0))+(2*i+1<n?sum3[0][2*i+1]:0);
			
				ans=max(ans,temp+max(ans1,ans2));
			}

		}
		else break;
	}

	cout<<ans<<"\n";

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