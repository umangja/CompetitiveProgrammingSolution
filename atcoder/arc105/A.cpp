/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
	vector<int> a(4);
	for(int i=0;i<4;i++) cin>>a[i];
	sort(a.begin(), a.end());

	rep(i,0,1<<4)
	{
		int sum1 = 0;
		int sum2 = 0;
		rep(j,0,4)
		{
			if(((i>>j)&1)==1) sum1+=a[j];
			else sum2+=a[j];
		}

		if(sum1==sum2) 
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";

	return 0;
}
