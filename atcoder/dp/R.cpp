/*input
10 1000000000000000000
0 0 1 1 0 0 0 1 1 0
0 0 0 0 0 1 1 1 0 0
0 1 0 0 0 1 0 1 0 1
1 1 1 0 1 1 0 1 1 0
0 1 1 1 0 1 0 1 1 1
0 0 0 1 0 0 1 0 1 0
0 0 0 1 1 0 0 1 0 1
1 0 0 0 1 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
1 0 1 1 1 0 1 1 1 0
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 55,mod=1e9+7;
int n;
long  int k;
vector<vector<long int>> g;

class Matrix
{
public:
	vector<vector<long int>> Mat;
	int Row,Col;

	//cont
	Matrix(vector<vector<long int>> mat) : Mat(mat), Row((int)mat.size()) ,Col((int)mat[0].size()) {};

	//Identity Martix
	Matrix(int siz)
	{
		Row=siz;Col=siz;
		vector<vector<long int>> mat(siz,vector<long int> (siz,0));
		for(int i=0;i<siz;i++) mat[i][i]=1;
		Mat=mat;
	}

	//multiple Matrix
	Matrix operator* (const Matrix &oth)
	{
		assert(Col==oth.Row);
		vector<vector<long int>> mat(Row,vector<long int> (oth.Col));
		for(int i=0;i<Row;i++)
		{
			for(int j=0;j<oth.Col;j++)
			{
				mat[i][j]=0;
				for(int k=0;k<Col;k++)
				{
					mat[i][j] += (Mat[i][k]*oth.Mat[k][j])%mod;
					if(mat[i][j]>=mod) mat[i][j]-=mod;
				} 
			}
		}

		return Matrix(mat);
	}

	// matrix power
	Matrix MatrixPower(long int y)
	{
		if(k==0) return Matrix(Row);
		Matrix ans = Matrix(Row);
		Matrix mat = *this;
		while(k>0)
		{
			if(k&1) ans=ans*mat;
			k>>=1;
			mat=mat*mat;
		}

		return ans;
	}

	//print mat
	void Print()
	{
		for(int i=0;i<Row;i++)
		{
			for(int j=0;j<Col;j++) cout<<Mat[i][j]<<" ";
			cout<<"\n";
		}
		return ;
	}
};



int main()
{
	cin>>n>>k;
	g.resize(n,vector<long int> (n));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];


	Matrix ansMat = (Matrix(g).MatrixPower(k));
	int ans = 0;
	for(int i=0;i<ansMat.Row;i++) for(int j=0;j<ansMat.Col;j++) ans+=ansMat.Mat[i][j],ans%=mod;
	cout<<ans<<"\n";


	// Matrix m1 = Matrix(3);
	// m1.Print();

	// Matrix m2 = Matrix(g);
	// m2.Print();
	// cout<<"\n";

	// m1=m1*m1;
	// m1.Print();

	// Matrix m3=m2*m2;
	// m3.Print();

	// m2 = m2.MatrixPower(2l);
	// m2.Print();

	return 0;
}
