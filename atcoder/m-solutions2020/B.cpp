/*input

*/
#include<bits/stdc++.h>
using namespace std;

int fun(int a,int b,int c,int k)
{
	if(c>b && b>a) return 1;
	if(k==0) return 0;

	int ans = 0;
	ans|=fun(a*2,b,c,k-1);
	ans|=fun(a,b*2,c,k-1);
	ans|=fun(a,b,c*2,k-1);
	return ans;
}

int main()
{
	int a,b,c;cin>>a>>b>>c;
	int k;cin>>k;


	if(fun(a,b,c,k)) cout<<"Yes\n";
	else cout<<"No\n";

	return 0;
}
