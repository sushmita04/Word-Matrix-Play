#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char a[]="rtirtm", unique[6]={};
	int arr[256]={}, k=0, i=0, m, n;
	bool flag;
	while(a[i]!='\0') {                     //loop to get the unique substring of letters from the word
	    ++arr[a[i]];
	    if(arr[a[i]]==1) {
	        unique[k++]=a[i];
	    }
	    ++i;
	}
	for(i=0; i<strlen(unique)-1; ++i) {
	    for(int j=i+1; j<strlen(unique); ++j) {
	        k=0; m=0; n=1, flag=1;
	        while(a[k]!='\0') {            //for each pair of unique letters, check if they alternate in word
	            if(a[k]==unique[i] && n==1)
	            {   m=1; n=0;       }
	            else if(a[k]==unique[j] && m==1)
	            {   n=1; m=0;       }
	            else if(a[k]==unique[i] || a[k]==unique[j])
	            {   flag=0; break;  }
	            //else ignore if unique[i] or unique[j] != a[k] (ignore if the letter is not in consideration)
	        }
	        if(flag==1)
	            cout<<unique[i]<<"  "<<unique[j]<<endl;
	    }
	}
	return 0;
}
