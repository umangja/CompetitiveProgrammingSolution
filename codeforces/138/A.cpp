#include<bits/stdc++.h>
using namespace std;
string a[10010];
char s[10010];
int n,k;
bool isvowel(char c)
{
	return c=='a'||c=='e'||c=='o'||c=='i'||c=='u';
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<4*n;i++)
	{
		cin>>s;
		int len=strlen(s);
		int cnt=0;
		for(int j=len-1;j>=0;j--)
		{
			if(isvowel(s[j]))
			cnt++;
			if(cnt==k)
			{
				a[i]=string (s+j);
				break;
			}
		}
		if(a[i].size()==0)
		a[i]+='0'+(i%4);
	}
	bool aabb=true,abba=true,abab=true;
	for(int i=0;i<4*n;i+=4)
	{
		aabb &=a[i]==a[i+1] and a[i+2]==a[i+3];
		abba &=a[i]==a[i+3] and a[i+1]==a[i+2];
		abab &=a[i]==a[i+2] and a[i+1]==a[i+3];
	}
	if(aabb and abba and abab)
	cout<<"aaaa";
	else if(aabb) cout<<"aabb";
	else if(abba) cout<<"abba";
	else if(abab) cout<<"abab";
	else 
	cout<<"NO";
    return 0;
}