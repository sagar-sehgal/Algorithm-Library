
#include<bits/stdc++.h>

using namespace std;
int longest_len(string s,int start,int end,int n)
{
	if(start>=0 && end<n && s[start]==s[end] && end-start==1){
		cout << "s[start]==s[end]" << s[start]<< " "<<s[end]<< "\n";
		return 2+2*longest_len(s,start-1,end+1,n);
	}
	else if(start>=0 && end<n && s[start]==s[end]){
		return 1+2*longest_len(s,start-1,end+1,n);
	}
	else
		return 0;
	
}

int main()
{
	int l1,l2,i,j,end,start,len;
	string s="HeyaFallas";
	int n=s.length();
	for(i=0;i<(n);i++)
	{	
		l1=longest_len(s,i,i,n);
		l2=longest_len(s,i,i+1,n);

		len=l1>l2?l1:l2;
		end=i+len/2;
		start=i-(len-1)/2;

		cout << "Length :"<<l1<< " " << l2 <<"\n";
		for(j=start;j<=end;j++)
		{
			cout << s[j];
		}
		cout << "\n";
	}
}
