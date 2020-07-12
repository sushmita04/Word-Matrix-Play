/*
Code to check if a given graph is word representable or not
*/

#include <bits/stdc++.h>
using namespace std;

string str;			//configuration
int n, i, j, k, adj[10][10]={0}, diag[10][10]={0}, tran[10][10];
vector <pair <int, int> > vect;
void make_matrix_to(int diag[][10], int n, int value) {
	for(int m=0; m<n; ++m)
        	for(int l=0; l<n; ++l)
            		diag[m][l]=value;
}

int find_edges(int adj[][10], int n) {
    	int edges=0;
		for(i=0; i<n; ++i) {
			for(j=i+1; j<n; ++j) {
				if(adj[i][j]==1) {
					vect.push_back(make_pair (i, j));
					++edges;
				}
			}
		}
	return edges;
}

void reverse(char temp[], int length) {
	int start = 0;
	int end = length -1;
	while (start < end) {
		swap(*(temp+start), *(temp+end));
		start++;
		end--;
	}
}

char* itoa_(int num, char* temp, int base) {
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
	str=itoa_(n, temp, 2);			        //finds the unique binary configuration
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

bool transitivity_check(int diag[][10], int n) {
	int ordering[n][n]={0};
    	make_matrix_to(tran, n, 0);
    	for(int i=0; i<n; ++i) {
        	for(int j=0; j<n; ++j) {
            	if(diag[i][j]==1)
                	tran[i][j]=1;
        	}
    	}
    	for(int i=0; i<n; ++i) {
        	for(int j=0; j<n; ++j) {
            		for(int k=0; k<n; ++k) {
                		if(tran[i][j]==1 && tran[j][k]==1)
                    			tran[i][k]=1;
            		}
        	}
    	}
    
    	bool flag=0;
    	int count1=0;
    
    	//for semi-transitivity
    	for(int i=0; i<n; ++i) {
        	for(int k=0; k<n; ++k) {
            		if(tran[i][k]==1 && adj[i][k]==1) {
                		for(int j=0; j<n; ++j) {
                    			if(tran[i][j]==1 && tran[j][k]==1) {
                        			count1++;
                        			if(diag[i][j]==1 && diag[j][k]==1 && diag[i][k]==1) {
                            				return 0;
                        			}
                    				else {
                        				flag=1;
                    				}
                    			}
                    			if(count1==0)
                        			flag=1;
                		}
            		}
        	}
    	}
    	return flag;
}

bool find_all_digraph(int n, int edges, int diag[][10]) {
	//finds all the (2^edges) digraph configurations/ adjacency matrices
	int x=pow(2,edges);
	for(i=0; i<x; ++i) {
		binary_orientation(i, edges);			//gets the orientation
		make_matrix_to(diag, n, 0);				//initialise the digraph to 0 before marking the directed edges
		for(j=0; j<str.size(); ++j) {		//edges=str.size()
			if(str[j]=='0')
				diag[vect[j].first][vect[j].second]=1;
			else if(str[j]=='1')
				diag[vect[j].second][vect[j].first]=1;
		}
        	if(transitivity_check(diag, n)) {
            		return 1;
        	}
        	else 
            		continue;
	}
    	return 0;
}

int main() {
	n=5;
	fstream file;
	ofstream fout;
	string word, filename="final_nauty.txt", checkword="5.", nextword="6.";
	file.open(filename.c_str());
	fout.open("OUTPUT.txt");
	if(file.is_open() && fout.is_open()) {
		while(file>>word)
		{
			if(word==checkword)
			{
	    			file>>word;
				for(i=0; i<n; ++i)
				{
					for(j=0; j<n; ++j)
					{
                				int tempo;
				    		stringstream test_word(word);
			    			test_word>>tempo;
			    			adj[i][j]=tempo;
				    		//fout<<adj[i][j];
				    		file>>word;
					}
					//fout<<endl;
				}
				//fout<<endl;
				int EDGES=find_edges(adj, n);

    				if(EDGES!=(n*(n-1))/2) {
       					bool ANS=find_all_digraph(n, EDGES, diag);
        				if(ANS==0)
            					fout<<"NO\n";
            		            	else
                	                	fout<<"YES\n";
    				}
    				else {
        				fout<<"YES\n";
    				}

			}
			if(word==nextword)
        			break;
		}
	}
	else
    		cout<<"Error in file opening.";
	file.close();
	fout.close();
	cout<<"\nDone\n";
	return 0;
}
