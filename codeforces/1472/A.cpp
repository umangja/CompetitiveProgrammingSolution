/*input
5
2 2 3
3 3 2
5 10 2
11 13 1
1 4 4

*/
#include<bits/stdc++.h>
using namespace std;

int fun(int x)
{
	int cnt=1;
	while(x%2==0) cnt*=2,x/=2;
	return cnt;
}

int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int h,w,n;cin>>h>>w>>n;
		cout<<(fun(h)*fun(w)>=n?"YES\n":"NO\n");
	}
	return 0;
}
