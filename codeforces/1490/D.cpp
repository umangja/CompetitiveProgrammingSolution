/*input
3
5
3 5 2 1 4
1
1
4
4 3 1 2

*/
#include<bits/stdc++.h>
using namespace std;

void fun(int L,int R,int parDep,vector<int> &a,vector<int> &pos,vector<int> &d){
	
	if(R<L) return ;

	int mxEl = -1;
	for(int i=L;i<=R;i++){
		mxEl = max(mxEl,a[i]);
	}

	d[pos[mxEl]] = parDep + 1;

	if(L==R) return ;


	fun(L,pos[mxEl]-1,d[pos[mxEl]],a,pos,d);
	fun(pos[mxEl]+1,R,d[pos[mxEl]],a,pos,d);
}



int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> a(n+1);
		vector<int> pos(n+1);
		vector<int> d(n+1);
		for(int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
		fun(1,n,-1,a,pos,d);
		for(int i=1;i<=n;i++) cout<<d[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
