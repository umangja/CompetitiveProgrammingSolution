/*input
6
1 1
1
1
1
5 2
1 2 2 1 1
1 2 2 1 1
1 2
3 3
2 2 2
2 2 2
2 3 2
10 5
7 3 2 1 7 9 4 2 7 9
9 9 2 1 4 9 4 2 3 9
9 9 7 4 3
5 2
1 2 2 1 1
1 2 2 1 1
3 3
6 4
3 4 2 4 1 2
2 3 1 3 1 1
2 2 3 4

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n,m,pos=1;;cin>>n>>m;
		vector<int> a(n),b(n),c(m),ans(m);
		vector<set<int>> plank(n),finalCol(n);
		set<int> left;
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
		} 
		
		for(int i=0;i<n;i++){
			cin>>b[i];
			b[i]--;
			finalCol[b[i]].insert(i);
			if(a[i]!=b[i]){
				left.insert(i);
				plank[b[i]].insert(i);
			} 
		} 

		for(int i=0;i<m;i++){
			cin>>c[i];
			c[i]--;
		}

		for(int i=0;i<m;i++){

			if( ((int)plank[c[i]].size())>0){
				int plankNo = *plank[c[i]].begin();
				ans[i] = plankNo;

				a[plankNo] = c[i];
				plank[c[i]].erase(plankNo);
				left.erase(plankNo);
			}
			else {

				if((int)left.size()>0){
					int plankNo = *left.begin();
					ans[i] = plankNo;
					a[plankNo] = c[i];
				}
				else {
					// if( (int)finalCol[c[i]].size()>0 ){
					// 	int plankNo = *finalCol[c[i]].begin();
					// 	ans[i] = plankNo;
					// 	a[plankNo] = c[i];
					// }
					// else {
						if((int)finalCol[c[m-1]].size()>0){
							int plankNo = *finalCol[c[m-1]].begin();
							for(int j=i;j<m;j++){
								ans[j] = plankNo;
								a[plankNo] = c[j];
							}
						}
						else pos=0;
						break;
					// }
				}

			}


		} 

		for(int i=0;i<n;i++) if(a[i]!=b[i]) pos=0;

		if(pos==1){
			cout<<"Yes\n";
			for(int i=0;i<m;i++) cout<<ans[i]+1<<" "; 
			cout<<"\n";
		}
		else cout<<"No\n";

	}
	return 0;
}
