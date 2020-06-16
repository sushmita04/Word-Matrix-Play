#include <bits/stdc++.h>
using namespace std;

string str;			//configuration

int find_all_digraph() {
	
	
}

void bin(unsigned n, int edges) { 
	char temp[edges];
	itoa(n, temp, 2);		//finds the unique configuration
	str=temp;
	if(str.size()!=edges) {
		int a=str.size();
		for(int i=0; i<edges; ++i) {
			if(i<edges-a)
				temp[i]='0';
			else
				temp[i]=str[a+i-edges];
		}
		str=temp;
	}
}

int main() {

 	vector <pair <int, int>> vect;
	int n, i, j, edges=0;
	cin>> n;				//order of the matrix; number of vertices
	int adj[n][n], diag[n][n]={0};

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
	
	//finds all the (2^edges) digraph configurations/ adjacency matrices 
	for(i=0; i<pow(2,edges); ++i) {
		bin(i, edges);				//gets the orientation
		for(j=0; j<str.size(); ++j) {		//edges=str.size()
			if(str[j]=='0')
				diag[vect[j].first][vect[j].second]=1;
			else if(str[j]=='1')
				diag[vect[j].second][vect[j].first]=1;
			
		}
		
	}
	
	

}
