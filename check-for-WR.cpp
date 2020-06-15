#include <bits/stdc++.h>
using namespace std;

string str;			//configuration

void bin(unsigned n, int edges) { 
	char temp[edges];
	itoa(n, temp, 2);		//finds the unique configuration
	str=temp;
	if(str.size()!=edges) {
		int a=str.size();
		for(int i=0; i<edges; ++i) {
			if(i<edges-a)
				str[i]='0';
			else
				str[i]=temp[edges-a-i];
			
		}
	}
}

int find_digraph() {
	
	
}

int main() {

 	vector <pair <int, int>> vect;
	int n, i, j, edges=0;
	cin>> n;				//order of the matrix; number of vertices
	int adj[n][n], Clone[n][n]={0};

	//input of adjacency matrix
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			cin>>adj[i][j];
		}
	}
	
	
	for(i=0; i<n; ++i) {
		for(j=i+1; j<n; ++j) {
			if(adj[i][j]==1) {
				vect.push_back(make_pair (i, j));
				++edges;	
			}
		}
	}
	
	

}
