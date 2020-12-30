/*input
8
4
1 2 4 5
3
1 3 5
3
2 6 8
2
1 2
1
50
5
3 4 5 6 8
3
1 25 26
6
1 2 4 8 16 32

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
		set<int> st;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				st.insert(a[j]-a[i]);
		cout<<st.size()<<"\n";
	}
	return 0;
}
