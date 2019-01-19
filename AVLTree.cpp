#include<bits/stdc++.h>
#include"AVLTree.h"
#include"AVLNode.h"
using namespace std;

AVLTree::AVLTree()
	{
		size=0;
		root=NULL;
	}
Node * AVLTree::Rigthrotate(Node * y)
	{
		Node * temp1 = y->left;
		Node * temp2 = temp1->right;

		temp1->right = y;
		y->left = temp2;

		y->height = max(height(y->left),height(y->right))+1;
		y->numberofnodes=1;
		if(y->left!=NULL)
		{
			y->numberofnodes+=y->left->numberofnodes;
			
		}
		if(y->right!=NULL)
				y->numberofnodes+=y->right->numberofnodes;
		temp1->height = max(height(temp1->left),height(temp1->left))+1;
		temp1->numberofnodes=1;
		if(temp1->left!=NULL)
		{
			temp1->numberofnodes+=temp1->left->numberofnodes;
			
		}
		if(temp1->right!=NULL)
				temp1->numberofnodes+=temp1->right->numberofnodes;
		return temp1;
	}

Node * AVLTree::Leftrotate(Node * y)
	{
		Node * temp1 = y->right;
		Node * temp2 = temp1->left;

		temp1->left = y;
		y->right = temp2;

		y->height = max(height(y->left),height(y->right))+1;
		y->numberofnodes=1;
		if(y->left!=NULL)
		{
			y->numberofnodes+=y->left->numberofnodes;
			
		}
		if(y->right!=NULL)
			y->numberofnodes+=y->right->numberofnodes;

		temp1->height = max(height(temp1->left),height(temp1->left))+1;
		temp1->numberofnodes=1;
		if(temp1->left!=NULL)
		{
			temp1->numberofnodes+=temp1->left->numberofnodes;
			
		}
		if(temp1->right!=NULL)
				temp1->numberofnodes+=temp1->right->numberofnodes;
		return temp1;
	}

int AVLTree::getdifference(Node * root)
	{
		if(root==NULL)
			return 0;
		return height(root->left) - height(root->right);
	}

int AVLTree::height(Node * root)
	{
		if(root==NULL)
			return 0;
		return root->height;
	}

Node * AVLTree::createnode(string key,string meaning)
	{
		size++;
		Node * temp = new Node;
		temp->key=key;
		temp->meaning=meaning;
		temp->left=NULL;
		temp->right=NULL;
		temp->height=1;
		temp->numberofnodes=1;
		return temp;
	}

	int AVLTree::compar(string word1,string word2)
	{
		return word1.compare(word2);
	}

	void AVLTree::add(string key,string meaning)
	{
		root = insert(root,key,meaning);
	}

	void AVLTree::search(Node * root,string key)
	{
		if(root==NULL)
			cout<<"No Entry Found"<<endl;

		else if(compar(key,root->key)<=-1)
		{
			search(root->left,key);
		}
		else if(compar(key,root->key)>=1)
		{
			search(root->right,key);
		}
		else
		{
			cout<<"Meaning is : "<<root->meaning<<endl;
			return;
		}
	}

	Node * AVLTree::minright(Node * root)
	{
		Node * cur = root;
		while(cur->left!= NULL)
		{
			cur=cur->left;
		}

		return cur;
	}

	int AVLTree::number()
	{
		if(size<0)
			return 0;
		return size;
	}

	Node * AVLTree::deletenode(Node * root, string key)
	{
		if(root == NULL)
		{
			cout<<"No Entry Found"<<endl;
			return root;
		}
		if(compar(key,root->key) <= -1)
		{
			root->left=deletenode(root->left,key);
			root->numberofnodes=1;
			if(root->left!=NULL)
				root->numberofnodes+=root->left->numberofnodes;
			if(root->right!=NULL)
				root->numberofnodes+=root->right->numberofnodes;
		}
		else if(compar(key,root->key) >= 1)
		{
			root->right=deletenode(root->right,key);
			root->numberofnodes=1;
			if(root->left!=NULL)
				root->numberofnodes+=root->left->numberofnodes;
			if(root->right!=NULL)
				root->numberofnodes+=root->right->numberofnodes;
		}

		else
		{
			
			if((root->left == NULL) || (root->right==NULL))
			{
				Node * x = root->left ? root->left : root->right;

				if(x==NULL)
				{
					x=root;
					root=NULL;
				}
				else
					*root=*x;
				size--;
					free(x);
				
			}
			else
			{
				Node * temp = minright(root->right);
				root->key = temp->key;
				root->meaning = temp->meaning;
				root->right = deletenode(root->right,temp->key);
				root->numberofnodes=1;
				if(root->left!=NULL)
					root->numberofnodes+=root->left->numberofnodes;
				if(root->right!=NULL)
					root->numberofnodes+=root->right->numberofnodes; 
			}
		}
		if(root==NULL)
			return root;
		root->height= 1 + max(height(root->right),height(root->left));

		int check = getdifference(root);

		if(check > 1 && getdifference(root->left)>=0 )
		{
			return Rigthrotate(root);
		}
		else if(check < -1 && getdifference(root->right)<= 0)
		{
			return Leftrotate(root);
		}
		else if(check > 1 && getdifference(root->left)<0)
		{
			root->left = Leftrotate(root->left);
			return Rigthrotate(root);
		}
		else if(check < -1 && getdifference(root->right) > 0)
		{
			root->right = Rigthrotate(root->right);
			return Leftrotate(root);

		}
		
		if(root!=NULL)
		{
			root->numberofnodes=1;
			if(root->left!=NULL)
					root->numberofnodes+=root->left->numberofnodes;
			if(root->right!=NULL)
					root->numberofnodes+=root->right->numberofnodes; 
		}
		return root;

	}

	void AVLTree::helpsearch(string key)
	{
		search(root,key);
	}

	void AVLTree::helpdelete(string key)
	{
		root=deletenode(root,key);
	}

	void AVLTree::inorder(Node * root)
	{
		if(root==NULL)
			return;
		else
		{
			inorder(root->left);
			cout<<root->key<<endl;
			inorder(root->right);
		}
	}

	void AVLTree::levelorder(Node * root)
	{
		if(root==NULL)
			return ;
		int height=root->height;
		for(int i=1;i<=height;i++)
		{
			cout<<"Level "<<" "<<i<<endl;
			printlevel(root,i);
			cout<<endl;
		}
	}

	void AVLTree::printlevel(Node * root, int level)
	{
		if(root==NULL)
			return;
		if(level == 1)
		{
			cout<<root->key<<" ";
		}
		else if(level > 1)
		{
			printlevel(root->left,level-1);
			printlevel(root->right,level-1);
		}
	}

	int AVLTree::count(Node* root,string k)
	{
		if(root==NULL)
			return 0;
		else if(compar(k,root->key)<=0)
		{
				if(root->right!=NULL)
					return 1 + root->right->numberofnodes + count(root->left,k);
				else
					return 1 +count(root->left,k);
		}
		else if(compar(k,root->key)>0)
		{
			return count(root->right,k);
		}
	}

	void AVLTree::helpprint(string k1,string k2)
	{
		print(root,k1,k2);
	}
	
	int AVLTree::helpcount(string k1,string k2)
	{
		int first = size-count(root,k1);
		int second = size-count(root,k2);
		if(search1(root,k2)==1)
			second++;
		return second-first;
	}

	int AVLTree::search1(Node * root,string key)
	{
		if(root==NULL)
			return -1;

			else if(compar(key,root->key)<=-1)
			{
				return search1(root->left,key);
			}
			else if(compar(key,root->key)>=1)
			{
			
				return search1(root->right,key);
			}
			
			else
			{
				return 1;
			}
		
	}

	void AVLTree::print(Node * root,string k1,string k2)
	{
		if(root==NULL)
		{
			return;
		}
		if(compar(k1,root->key)<=0)
		{
			print(root->left,k1,k2);
		}
		if(compar(k1,root->key)<=0 && compar(k2,root->key)>=0)
		{
			cout<<root->key<<endl;
		}
		if(compar(k2,root->key)>=0)
		{
			print(root->right,k1,k2);
		}
	}

	void AVLTree::helpinorder()
	{
		inorder(root);
	}

	void AVLTree::helplevel()
	{
		levelorder(root);
	}

	Node * AVLTree::insert(Node * root,string key, string meaning)
	{
		
		if(root == NULL)
		{
			return createnode(key,meaning);
		}
		if(compar(key,root->key) <=-1)
		{
			root->left = insert(root->left,key,meaning);
			root->numberofnodes=1;
			if(root->left!=NULL)
			{
				root->numberofnodes+=root->left->numberofnodes;
				
			}
			if(root->right!=NULL)
					root->numberofnodes+=root->right->numberofnodes;
		}
		else if(compar(key,root->key) >= 1)
		{
			root->right = insert(root->right,key,meaning);
			root->numberofnodes=1;
			if(root->left!=NULL)
			{
				root->numberofnodes+=root->left->numberofnodes;
				
			}
			if(root->right!=NULL)
					root->numberofnodes+=root->right->numberofnodes;
		}
		else
		{
			root->meaning = meaning;
			return root;
		}

		root->height = 1 + max(height(root->left),height(root->right));

		int check = getdifference(root);
		if(check > 1 && compar(key,root->left->key) <= -1)
		{
			return Rigthrotate(root);
		}
		else if(check < -1 && compar(key,root->right->key) >= 1)
		{
			return Leftrotate(root);
		}
		else if(check > 1 && compar(key,root->left->key) >= 1)
		{
			root->left = Leftrotate(root->left);
			return Rigthrotate(root);
		}
		else if(check < -1 && compar(key,root->right->key) <= -1)
		{
			root->right = Rigthrotate(root->right);
			return Leftrotate(root);
		}
		if(root!=NULL)
		{
			root->numberofnodes=1;
			if(root->left!=NULL)
					root->numberofnodes+=root->left->numberofnodes;
			if(root->right!=NULL)
					root->numberofnodes+=root->right->numberofnodes; 
		}
		return root;
	}	


