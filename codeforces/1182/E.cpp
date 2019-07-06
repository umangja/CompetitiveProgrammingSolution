/*input
27230 83472 9488 55320 2081
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
#define inf			1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll Mod =1e9+7,Mod2 = Mod-1,MOD = Mod;
const ll Max_k = 50;
ll n,f1,f2,f3,c;

struct Matrix{
	vvi mat;
	ll n_row,n_col;
	Matrix (vvi values):mat(values),n_row(sz(values)),n_col(sz(values[0])){}

	static Matrix create_identity(ll size_mat){
		vvi identity(size_mat,vector<ll> (size_mat,0));
		rep(i,0,size_mat) identity[i][i]=1;
		return identity;
	}

	Matrix operator*(const Matrix &other) const
	{
		ll ans_row = n_row,ans_col = other.n_col;
		vvi ans(ans_row,vi (ans_col));
		rep(i,0,ans_row)
		{
			rep(j,0,ans_col)
			{
				ll temp=0;
				rep(k,0,n_col)
				{
					temp=(temp+(mat[i][k]*other.mat[k][j])%Mod2)%Mod2;
				}
				ans[i][j]=temp%Mod2;
			}
		}
		return move(Matrix(move(ans)));
	}

};

Matrix fast_exponentiation(Matrix m,ll p)
{
	Matrix ans = Matrix::create_identity(m.n_row);

	while(p)
	{
		if(p&1) ans=ans*m;
		p>>=1;
		m=m*m;
	}

	return ans;
}

ll cal(ll pos)
{
	if(pos<4){
		vvi v = {{1,1,1},{1,0,0},{0,1,0}};
		Matrix m(v);
		m=fast_exponentiation(m,n-3);
		return (m.mat)[0][3-pos];
	}

	vvi v = {{1,1,1,2,-6},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};
	Matrix m(v);
	m=fast_exponentiation(m,n-3);
	return 4*((m.mat)[0][3])+(m.mat)[0][4];
}

ll pow(ll x, ll y)
{
	ll ans=1;
	while(y>0)
	{
		if(y&1) ans=(ans*x)%MOD;
		y>>=1;
		x=(x*x)%MOD;
	}
	return ans;
}

int solve()
{
	cin>>n>>f1>>f2>>f3>>c;
	ll p1 = cal(1),p2 = cal(2),p3=cal(3),p4=cal(4);
	ll ans = ((((pow(f1,p1)*pow(f2,p2))%MOD)*((pow(f3,p3)*pow(c,p4))%MOD))%MOD);
	cout<<ans;
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}