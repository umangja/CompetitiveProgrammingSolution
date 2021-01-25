/*input
6
2
3
4
5
998244353
1099511627776

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		long long int N; cin>>N;
		while(N%2==0) N/=2;

		cout<<(N>1?"YES\n":"NO\n");
	}
	return 0;
}
