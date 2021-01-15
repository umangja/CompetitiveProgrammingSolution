/*input
4
1 1
2 2
3 2
4 3

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
		ll mx = ((n-k)*(n-k+1))/2;
		
		set<ll> st;
		for(int i=1;i<=k;i++) st.insert(i);

		ll L = 1,R = k;
		for(int i=1;i<=k;i++)
		{	
			if(i<(2*k-n)) cout<<(L++);
			else cout<<(R--);
			cout<<" ";	
		}
		cout<<"\n";


	}
	return 0;
}
