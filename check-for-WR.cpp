#include <bits/stdc++.h>
using namespace std;

int main() {

  vector <pair <int, int>> vect;
	int n, i, j;
	cin>> n;
	int arr[n][n], clone[n][n]={0};

	//input of adjacency matrix
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			cin>>arr[i][j];
		}
	}
	
	for(i=0; i<n; ++i) {
		for(j=i+1; j<n; ++j) {
			if(arr[i][j]==1) {
				vect.push_back(make_pair (i, j));

			}
		}
	}
	
	

}
