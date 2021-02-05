/*input
6
10 5
RRRRRRRRRRUUUUU
1 1
UDDDRLLL
-3 -5
LDLDLDDDR
1 2
LLLLUU
3 -2
RDULRLLDR
-1 6
RUDURUUUUR

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int px,py;
		cin>>px>>py;
	
		string s;cin>>s;
		map<char,int> cnt;
		for(int i=0;i<(int)s.size();i++) cnt[s[i]]++;

		int pos=1;
		if(px>0 && cnt['R']<px)  pos=0;
		if(px<0 && cnt['L']<-px)   pos=0;
		if(py>0 && cnt['U']<py)  pos=0;
		if(py<0 && cnt['D']<-py) pos=0;
		cout<<(pos==0?"No":"Yes")<<"\n";
	}
	return 0;
}
