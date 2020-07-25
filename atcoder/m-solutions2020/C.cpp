/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;cin>>N>>K;
	vector<long int> a(N+1);
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=K+1;i<=N;i++) cout<<(a[i]>a[i-K]?"Yes\n":"No\n");
	return 0;
}
