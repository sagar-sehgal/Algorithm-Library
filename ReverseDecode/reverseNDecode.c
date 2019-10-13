#include <stdio.h>
#include<stdlib.h>
void reverseNDelete(int a[],int k,int size)
{
	int i;
	int lastElem,ElemIndexToDelete;
	//Rotated
	lastElem=a[size];
	for(i=size;i>=1;i--)
		a[i]=a[i-1];
	a[0]=lastElem;

		
	//Deleting Element by shifting
	ElemIndexToDelete=size-k+1;
	if(ElemIndexToDelete<0)
		ElemIndexToDelete=0;
		
	for(i=ElemIndexToDelete;i<size;i++)
		a[i]=a[i+1];

}
int main(int argc, char const *argv[])
{
	int t,n;
	int test,i,j;
	scanf("%d",&t);
	for(test=0;test<t;test++)
	{
		scanf("%d",&n);
		int* a = malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		//printf("%d\n",a[0]);
		for(i=0;i<n-1;i++)
			reverseNDelete(a,i+1,n-i-1);
		printf("%d\n",a[0]);
		free(a);
	}
	return 0;
}