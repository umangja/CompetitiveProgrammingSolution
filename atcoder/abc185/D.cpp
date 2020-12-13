/*input
1 0



*/
#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<int> B;
vector<int> A;
int main()
{
	cin>>N>>M; 
	B.resize(M);
	for(int i=0;i<M;i++) cin>>B[i];

	if(M==0)
	{
		cout<<1<<"\n";
	}
	else
	{

		sort(B.begin(), B.end());
		int last = 0;
		for(int i=0;i<M;i++)
		{
			if(B[i]-last-1>0) A.push_back(B[i]-last-1);
			last = B[i];
		}

		if(M>=1 && N-B[M-1]>0) A.push_back(N-B[M-1]);
		if((int)A.size()==0) cout<<"0\n";
		else
		{
			sort(A.begin(), A.end());
			long long int kmax = A[0],ans=0;
			if(A[0]<=0) cout<<"-1\n";
			else
			{
				for(int i=0;i<A.size();i++) ans+=(long long int)(A[i]+kmax-1)/kmax;
				cout<<ans<<"\n";
			}

		}
	}





	return 0;
}
