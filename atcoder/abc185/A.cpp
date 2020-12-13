/*input
5 3 7 11

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> a(4);
	for(int i=0;i<4;i++) cin>>a[i];
	cout<<min({a[0],a[1],a[2],a[3]})<<"\n";
	return 0;
}
