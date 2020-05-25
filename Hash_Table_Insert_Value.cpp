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
	        if(flag==1)
	            cout<<R[i]<<"--"<<R[j]<<endl;
        }
    }
    return 0;
}
