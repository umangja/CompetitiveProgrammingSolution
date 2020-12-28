/*input
3
6 3
0 0 2 5 1 1
2 3
0 2
3 2
3 0 2

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		ll n,k;cin>>n>>k;
		vector<ll> h(n);
		for(int i=0;i<n;i++) cin>>h[i];


		ll L = h[0],R = h[0];
		ll pos=1;
		for(int i=1;i<n;i++)
		{
			ll Lcur = h[i];
			ll Rcur = h[i];
			if(i<(n-1)) Rcur+=k-1;

			ll Lmin = max(Lcur,L-k+1);
			ll Rmax = min(R+k-1,Rcur);
			
			L = Lmin;
			R = Rmax;

			if(R<L)
			{
				pos=0;
				break;
			} 
		}



		cout<<(pos==1?"Yes\n":"No\n");
	}
	return 0;
}
