/*input
5
6
1 2 2 2 5 6
2
4 4
6
1 1 3 4 4 5
1
1
6
1 1 1 2 2 2

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=1;i<n;i++) if(a[i]<=a[i-1]) a[i]++;
		// for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";
		set<int> st(a.begin(), a.end())	;
		cout<<st.size()<<"\n";
	}
	return 0;
}
