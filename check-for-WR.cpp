#include <bits/stdc++.h>
using namespace std;

string str;			//configuration
int n, i, j, k, adj[7][7]={0}, diag[7][7]={0};
vector <pair <int, int> > vect;
void make_matrix_zero(int diag[][7], int n) {
    for(int m=0; m<n; ++m)
        for(int l=0; l<n; ++l)
            diag[m][l]=0;

}

int find_edges(int adj[][7], int n) {						//*********
    int edges=0;
	for(i=0; i<n; ++i) {
		for(j=i+1; j<n; ++j) {
			if(adj[i][j]==1) {
				vect.push_back(make_pair (i, j));
				++edges;
			}
		}
	}
	cout<<edges<<endl;
	return edges;
}
void reverse(char temp[], int length)
{
	int start = 0;
	int end = length -1;
	while (start < end)
	{
		swap(*(temp+start), *(temp+end));
		start++;
		end--;
	}
}

char* itoa_(int num, char* temp, int base)
{
	int i = 0;
	bool isNegative = false;
	if (num == 0) {
		temp[i++] = '0';
		temp[i] = '\0';
		return temp;
	}
	if (num < 0 && base == 10) {
		isNegative = true;
		num = -num;
	}
	while (num != 0) {
		int rem = num % base;
		temp[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}
	if (isNegative)
		temp[i++] = '-';

	reverse(temp, i);
	return temp;
}

void binary_orientation(unsigned n, int edges) {
	char temp[edges+1]={};
			//finds the unique binary configuration
	str=itoa_(n, temp, 2);
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
	cout<<str<<endl;
}

void find_all_digraph(int n, int edges, int diag[][7]) {					//**********
	//finds all the (2^edges) digraph configurations/ adjacency matrices
	int x=pow(2,edges);
	for(i=0; i<x; ++i) {
		binary_orientation(i, edges);			//gets the orientation
		make_matrix_zero(diag, n);				//initialise the digraph to 0 before marking the directed edges
		for(j=0; j<str.size(); ++j) {		//edges=str.size()
			if(str[j]=='0')
				diag[vect[j].first][vect[j].second]=1;
			else if(str[j]=='1')
				diag[vect[j].second][vect[j].first]=1;
		}
		for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                cout<<diag[j][k]<<" ";
            cout<<"\n";
        }
        cout<<endl;
	}

}

int main() {
	cin>> n;				//order of the matrix; number of vertices

	//input of adjacency matrix
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			cin>>adj[i][j];
		}
	}
	//if edges==((n*(n-1))/2) then WR  i.e. k-complete graph
    int EDGES=find_edges(adj, n);
    find_all_digraph(n, EDGES, diag);

}
