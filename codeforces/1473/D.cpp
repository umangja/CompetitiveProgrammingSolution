/*input
1
8 1
-+--+--+
2 5

1 8
2 8
1 1
4 10
+-++
1 1
1 2
2 2
1 3
2 3
3 3
1 4
2 4
3 4
4 4




*/
#include<bits/stdc++.h>
using namespace std;



int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		string s;cin>>s;
		int x=0;

		vector<int> a(n+1,0);
		vector<int> b(n+1,0);

		vector<int> mxL(n+1,0);
		vector<int> mnL(n+1,0);




		for(int i=1;i<=n;i++){
			if(s[i-1]=='+') x++;
			else x--;
			a[i] = x;

			mxL[i] = max(mxL[i-1],x);
			mnL[i] = min(mnL[i-1],x);
		}

		// for(int i=1;i<=n;i++) cout<<mxR[i]<<" "; cout<<"\n";
		// for(int i=1;i<=n;i++) cout<<mnR[i]<<" "; cout<<"\n";


		vector<int> mxR(n+2);
		vector<int> mnR(n+2);

		mxR[n+1] = 0;
		mnR[n+1] = 0;

		x = 0;

		for(int i = n;i>=1;i--)
		{
			if(s[i-1]=='+')
			{
				mxR[i] = max(mxR[i+1]+1,1);
				mnR[i] = min(mnR[i+1]+1,0);
			} 
			else
			{
				mxR[i] = max(mxR[i+1]-1,0);
				mnR[i] = min(mnR[i+1]-1,-1);
			} 
		} 

		// for(int i=1;i<=n;i++) cout<<mxR[i]<<" "; cout<<"\n";
		// for(int i=1;i<=n;i++) cout<<mnR[i]<<" "; cout<<"\n";
			


		for(int i=0;i<m;i++)
		{
			int L,R;cin>>L>>R;
			int dif = a[R] - a[L-1];
			int mn = min(mnL[L-1],a[L-1]+mnR[R+1]);
			int mx = max(mxL[L-1],a[L-1]+mxR[R+1]);
			// cout<<dif<<" "<<mx<<" "<<mn<<"\n";
			cout<<mx-mn+1<<"\n";
		}



	}

	return 0;
}
