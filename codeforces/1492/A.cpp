/*input
4
9 5 4 8
2 6 10 9
10 2 5 10
10 9 9 9

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		long long int a,b,c,p;cin>>p>>a>>b>>c;
		long long int w1 = ((p+a-1)/a) * a - p;
		long long int w2 = ((p+b-1)/b) * b - p;
		long long int w3 = ((p+c-1)/c) * c - p;
		cout<<min({w1,w2,w3})<<"\n";
	}
	return 0;
}
