/*input
3
3 2 4
1 1 1
10 1 7

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int a,b,c;cin>>a>>b>>c;
		int sum = a+b+c;
		if(sum%9==0)
		{
			sum/=9;
			if(a>=sum && b>=sum && c>=sum) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
