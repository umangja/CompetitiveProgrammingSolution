/*input
6
2
1 2
2
1 0
3
4 4 4
2
0 0
3
0 1 0
4
1000000000 1000000000 1000000000 1000000000

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<ll> h(n);
		for(int i=0;i<n;i++) cin>>h[i];
		ll pos=1;
		for(int i=0;i<n-1;i++){
			if(h[i]>=i){
				h[i+1] += (h[i] - i);
				h[i] = i;
			} 
			else pos=0;
		}

		if(n>1 && h[n-1] <= h[n-2]) pos=0;
		if(n==1) pos=1;
		cout<<(pos?"Yes":"No")<<"\n";	
	}
	return 0;
}
