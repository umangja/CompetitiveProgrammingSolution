/*input
5
3
000
122
001
2
57
75
4
0123
4012
3401
2340
1
9
8
42987101
98289412
38949562
87599023
92834718
83917348
19823743
38947912

*/
#include<bits/stdc++.h>
using namespace std;


int n;
void rotateMatrix(vector<vector<int>> &mat) 
{ 
	int N = n;
    for (int x = 0; x < N / 2; x++) { 
        for (int y = x; y < N - x - 1; y++) { 
            int temp = mat[x][y]; 
            mat[x][y] = mat[y][N - 1 - x]; 
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y]; 
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x]; 
            mat[N - 1 - y][x] = temp; 
        } 
    } 
} 


vector<int> fun(vector<vector<int>> &mat)
{
	vector<int> ans(10,0);
	vector<int> mxRow(10,-1);
	vector<int> mnRow(10,n);
	vector<vector<int>> mxCol(10,vector<int> (n,-1));
	vector<vector<int>> mnCol(10,vector<int> (n,n)); 

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int d = mat[i][j];
			mxRow[d] = max(mxRow[d],i);
			mnRow[d] = min(mnRow[d],i);
			mxCol[d][i] = max(mxCol[d][i],j);
			mnCol[d][i] = min(mnCol[d][i],j);
		}
	} 

	for(int d=0;d<10;d++)
	{
		for(int r=0;r<n;r++) if(mxCol[d][r]>mnCol[d][r]) ans[d]=max(ans[d],max((n-r-1)*(mxCol[d][r]-mnCol[d][r]),r*(mxCol[d][r]-mnCol[d][r])));
		for(int r=0;r<n;r++) if(mxCol[d][r]!=-1 && mxRow[d]!=-1) ans[d]=max(ans[d],max(mxRow[d]-r,r-mnRow[d])*max({mnCol[d][r],n-mnCol[d][r]-1,n-mxCol[d][r]-1}));
	} 

	return ans;
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		vector<vector<int>> mat(n,vector<int> (n));
		for(int i=0;i<n;i++){
			string s;cin>>s;
			for(int j=0;j<n;j++) mat[i][j]=s[j]-'0';
		}

		vector<int> ans1 = fun(mat); rotateMatrix(mat);
		vector<int> ans2 = fun(mat); rotateMatrix(mat);
		vector<int> ans3 = fun(mat); rotateMatrix(mat);
		vector<int> ans4 = fun(mat); rotateMatrix(mat);
		for(int i=0;i<10;i++) cout<<max({ans1[i],ans4[i],ans3[i],ans2[i]})<<" ";cout<<"\n";

	}
	return 0;
}



	// for(int d=0;d<10;d++)
	// {
	// 	for(int r=0;r<n;r++)
	// 	{
	// 		if(mxRow[d]<=r)
	// 		{
	// 			int h = n-r;
	// 			int b = mxCol[d][r]-mnCol[d][r];
	// 			if(b>0) ans[d]=max(ans[d],h*b);
	// 		}
	// 		else
	// 		{
	// 			if(mxCol[d][r]!=-1)
	// 			{
	// 				if(mxCol[d][r]==mnCol[d][r])
	// 				{
	// 					int h = mxRow[d]-r;
	// 					int b = max(n-mxCol[d][r],mxCol[d][r]);
	// 					ans[d]=max(ans[d],h*b);
	// 				}
	// 				else
	// 				{
	// 					{
	// 						int h = n-r;
	// 						int b = max(n-mxCol[d][r],mxCol[d][r]);
	// 						ans[d]=max(ans[d],h*b);
	// 					}

						

	// 				}
	// 			}
	// 		}
	// 	}

	// }