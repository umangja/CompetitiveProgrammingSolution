/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		reverse(a.begin(), a.end());
		for(int i=0;i<n;i++) 
		{
			cout<<a[i];
			if(i!=n-1) cout<<" ";
			else cout<<"\n";
		} 
	}
	return 0;
}
