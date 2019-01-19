#include<bits/stdc++.h>
#include"AVLTree.h"
#include"AVLNode.h"
using namespace std;

int main()
{
	AVLTree tree;
	cout<<"Following is the list of Functions: "<<endl;
	cout<<"1. To add an item: "<<endl;
	cout<<"2. To remove an item: "<<endl;
	cout<<"3. To search an item: "<<endl;
	cout<<"4. Size of the Tree: "<<endl;
	cout<<"5. Range Function: "<<endl;
	cout<<"6. To take input from file: "<<endl;
	cout<<"7. To print level order traversal: "<<endl;
	cout<<"8. To print number of keys in given range: "<<endl;
	cout<<"0. Exit: "<<endl;
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		else if(n==1)
		{
			string word;
			cout<<"Enter Word: "<<endl;;
			cin>>word;
			cout<<"Enter Meaning: "<<endl;
			string mean;
			getline(cin,mean);
			getline(cin,mean);
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			tree.add(word,mean);
		}
		else if(n==2)
		{
			string word;
			cout<<"Enter Word: "<<endl;
			cin>>word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			tree.helpdelete(word);
		}
		else if(n==3)
		{
			string word;
			cout<<"Enter Word: "<<endl;
			cin>>word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			tree.helpsearch(word);
		}
		else if(n==4)
		{
			cout<<"Size of the tree is: "<<tree.number()<<endl;
		}
		else if(n==5)
		{
			cout<<"Enter Lower Range "<<endl;
			string word1;
			cin>>word1;
			transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
			cout<<"Enter Upper Range "<<endl;
			string word2;
			cin>>word2;
			transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
			cout<<"Words in given Range are "<<endl;
			tree.helpprint(word1,word2);
		}
		else if(n==6)
		{
			cout<<"Enter the File name to be used: "<<endl;
			char fname[10001];
			cin>>fname;
			ifstream f2(fname);
			string c;
			int t=0;
			int count=0;
			while(f2)
			{	
				string er;
				f2>>er;
				if(er[0]=='\0')
					break;
				getline(f2,c);
				transform(er.begin(), er.end(), er.begin(), ::tolower);
				tree.add(er,c);
			}
		}
		else if(n==7)
		{
			tree.helplevel();
		}
		else if(n==8)
		{
			cout<<"Enter Lower Range "<<endl;
			string word1;
			cin>>word1;
			transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
			cout<<"Enter Upper Range "<<endl;
			string word2;
			cin>>word2;
			transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
			cout<<"Number of keys in Range"<<" "<<tree.helpcount(word1,word2)<<endl;
		}
	}

}
