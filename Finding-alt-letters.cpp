#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int k, m, n;
	bool flag;
	string S,R="";
	cin>>S;

	unordered_set<char>H;

	for(auto ch:S){
        	if(H.find(ch)==H.end()){
        		R+=ch;
        		H.insert(ch);
		}
	}

	int size=R.length();
	vector<vector<int> > vec(size, vector<int> (size, 0));		//adjacency matrix
	
	for(int i=0;i<R.length();i++){
        	for(int j=i+1;j<R.length();j++){
    			k=0; m=0; n=1; flag=1;
			while(S[k]!='\0') {            
	    			if(S[k]==R[i] && n==1)
	        		{   m=1; n=0;       }
	        		else if(S[k]==R[j] && m==1)
	        		{   n=1; m=0;       }
	        		else if(S[k]==R[i] || S[k]==R[j])
	        		{   flag=0; break;  }	            
	        		++k;
            		}
	    		if(flag==1) {
	    			cout<<R[i]<<"--"<<R[j]<<endl;
	        		vec[i][j]=1;
	        		vec[j][i]=1;   
	    		}
        	}
	}
	cout<<"\nThe adjacency matrix is:\n";
	for (int i = -1; i < size; i++) {
		if(i==-1) {
			cout<<"  ";
			for(char c:R)
				cout<<c<<" ";
			cout<<"\n";
		}
		else {
			cout<<R[i]<<" ";
			for (int j = 0; j < size; j++) { 
				cout<< vec[i][j]<< " "; 
			} 
			cout<< "\n"; 
		}
	}
	return 0;
}
