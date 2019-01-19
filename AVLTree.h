#ifndef AVLTREE_H
#define AVLTREE_H
#include<bits/stdc++.h>
#include"AVLNode.h"
using namespace std;

class AVLTree
{
private:
	Node * root;
	int size;
public:
	AVLTree();
	Node * Rigthrotate(Node * );
	Node * Leftrotate(Node * );
	int getdifference(Node * );
	int height(Node *);
	Node * createnode(string,string);
	int compar(string,string);
	void add(string,string);
	void search(Node *,string);
	Node * minright(Node *);
	int number();
	Node * deletenode(Node *, string );
	void helpsearch(string);
	void helpdelete(string);
	void inorder(Node * );
	void levelorder(Node * );
	void printlevel(Node *, int );
	void helpinorder();
	void helplevel();
	void helpprint(string,string);
	void print(Node *,string,string);
	int helpcount(string,string);
	Node * insert(Node *,string, string);
	int search1(Node * root,string key);
	int count(Node *,string);
};

#endif
