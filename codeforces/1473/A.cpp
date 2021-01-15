/*input
3
5 3
2 3 2 5 4
3 4
2 4 4
5 4
2 1 5 3 6

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		int n,d;cin>>n>>d;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a.begin(), a.end());
		if(a[n-1]<=d || (n>=2 && a[0]+a[1]<=d)) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
