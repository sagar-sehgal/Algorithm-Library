#include<bits/stdc++.h>
using namespace std;
int V=9;
int minimumIndex(int visited[],int d[],int V)
{
	int min=0;
	int distance=INT_MAX;
	for(auto i=0;i<V;i++)
	{
		if(visited[i]==0 && d[i]<distance)
		{
			min=i;
			distance=d[i];
		}
	}
	cout << "Min: "<< min << endl; 
	return min;
}

bool all_visted(int visited[])//Send True if all visited
{
	for(auto i=0;i<9;i++)
	{
		if(visited[i]==0)
			return false;
	}
	return true;
}
void print(int visited[])
{
	for(auto i=0;i<9;i++)
		cout << visited[i] << " " ;
	cout<< endl;
}
int shortest_path1(int graph[][9],int V,int s,int e)
{
	int i,j;
	int visited[V]={0};
	int d[V];
	std::fill_n(d,9,INT_MAX);
	int curr=s;
	int distance;
	d[s]=0;
	while(!(all_visted(visited)))
	{

		visited[curr]=1;
		//print(visited);
		for(i=0;i<V;i++)
		{
			//cout << i << endl;
			if(graph[curr][i]!=0)
			{
				distance=d[curr]+graph[curr][i];
				d[i]=(distance < d[i])?distance:d[i];
			}
		}
		cout << "Distance :";
		print(d);
		curr=minimumIndex(visited,d,V);
		cout << "Current Node:"<<curr<<endl;
	}
	return d[e];
}

int main()
{
	int graph[9][9]= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    cout << graph[0][0];

    cout << (shortest_path1(graph,V,0,8));                    
}