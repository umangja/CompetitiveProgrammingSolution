/*input
6
7
3 4 5 2 9 1 1
4
9 2 7 1
11
8 4 3 1 2 7 8 7 9 4 2
1
42
2
11 7
8
1 1 1 1 1 1 1 1

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> b(n),a(n);
		for(int i=0;i<n;i++) cin>>b[i];
		int L = 0,R = n-1,cur=0;
		while(L<=R)
		{
			a[cur++] = b[L++];
			a[cur++] = b[R--];
		}

		for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";
	}
	return 0;
}
