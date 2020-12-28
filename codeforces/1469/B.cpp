/*input
4
4
6 -5 7 -3
3
2 3 -4
2
1 1
4
10 -3 2 2
5
-1 -2 -3 -4 -5
5
-1 -2 -3 -4 -5
1
0
1
0

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
		vector<int> r(n);
		for(int i=0;i<n;i++) cin>>r[i];

		int m;cin>>m;
		vector<int> b(m);
		for(int j=0;j<m;j++) cin>>b[j];


		int mxa = 0,mxapos = 0,cur=0;
		for(int i=0;i<n;i++)
		{
			cur+=r[i];
			if(cur>mxa)
			{
				mxa=cur;
				mxapos = i+1;
			}
		}

		cur=0;
		int mxb=0,mxbpos=0;
		for(int i=0;i<m;i++)
		{
			cur+=b[i];
			if(cur>mxb)
			{
				mxb = cur;
				mxbpos = i+1;
			}
		}

		cout<<mxa+mxb<<"\n";



	}
	return 0;
}
