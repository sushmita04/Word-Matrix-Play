/* Given a word, the program lists all the pairs of alternating letters in the context of word-representable graphs. */

#include <bits/stdc++.h>
using namespace std;

int main() {

	int k, m, n;
	bool flag;
	string Word, UniqueW = "";
	cin>>Word;

	unordered_set<char>H;

	cout << "\nEnter the word: ";
	for(auto ch:Word)
	{
        	if(H.find(ch)==H.end())
		{
        		UniqueW += ch;
        		H.insert(ch);
		}
	}

	int size = UniqueW.length();
	vector<vector<int> > vec(size, vector<int> (size, 0));		//adjacency matrix

	cout << "\nThe alternating letters are:\n";
	for(int i=0; i<size; i++)
	{
        	for(int j=i+1; j<size; j++)
		{
    			k = 0;
			m = 0;
			n = 1;
			flag = 1;
			while(Word[k]!='\0') {
	    			if(Word[k]==UniqueW[i] && n==1)
	        		{
					m = 1;
				 	n = 0;
				}
	        		else if(Word[k]==UniqueW[j] && m==1)
	        		{
					n = 1;
					m = 0;
				}
	        		else if(Word[k]==UniqueW[i] || Word[k]==UniqueW[j])
	        		{
					flag = 0;
					break;
				}
	        		++k;
            		}
	    		if(flag==1)
			{
	    			cout << UniqueW[i] << "--" << UniqueW[j] << endl;
	        		vec[i][j] = 1;
	        		vec[j][i] = 1;
	    		}
        	}
	}
	
	cout << "\nThe adjacency matrix is:\n";
	for(int i = -1; i < size; i++)
	{
		if(i==-1)
		{
			cout<<"  ";
			for(char c:UniqueW)
			{
				cout << c << " ";
			}
			cout << endl;
		}
		else
		{
			cout << UniqueW[i] << " ";
			for(int j = 0; j < size; j++)
			{
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
