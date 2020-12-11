/*input
1
5 7
..*.*..
.*****.
*******
.*****.
..*.*..


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		vector<vector<int>> mat(n,vector<int> (m));
		vector<vector<int>> right(n,vector<int> (m,0));
		vector<vector<int>> left(n,vector<int> (m,0));
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			string s;cin>>s;
			for(int j=0;j<m;j++) mat[i][j]=(s[j]=='*'?1:0);
		}


		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mat[i][j]==0) left[i][j]=0;
				else left[i][j] = 1+(j-1>=0?left[i][j-1]:0);
				// cout<<left[i][j]<<" ";
			}
			// cout<<"\n";
		}

		// cout<<"\n";

		for(int i=0;i<n;i++)
		{
			for(int j=m-1;j>=0;j--)
			{
				if(mat[i][j]==0) right[i][j]=0;
				else right[i][j] = 1+(j+1<m?right[i][j+1]:0);
				// cout<<right[i][j]<<" ";
			}
			// cout<<"\n";
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(int h=0;h<=m;h++)
				{
					if(i+h<n && left[i+h][j]>=h+1 && right[i+h][j]>=h+1)
					{
						// cout<<i<<" "<<j<<" "<<h<<"\n";
						ans++;
					} 
					else break;
				}

			}
		}

		cout<<ans<<"\n";

	}
	return 0;
}
