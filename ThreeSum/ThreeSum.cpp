#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,sum,r,l;
	cout << "Enter n" << endl;
	cin >> n;
	cout << "Enter the sum" << endl;
	cin >> sum;
	int A[n];
	for(i=0;i<n;i++)
	{
		cin >> A[i];
	}

	sort(A,A+n);
	for(i=0;i<n;i++)
	{
		l=i+1;
		r=n-1;
		while(l<r){
			if(A[i]+A[l]+A[r]==sum){
				cout << "The values are" << A[i] << " "<< A[l]<<" "<<A[r];
				r--;
				l++;
			}
			else if(A[i]+A[l]+A[r]>sum){
				r--;
			}
			else
				l++;
		}
	}
	return 0;
}