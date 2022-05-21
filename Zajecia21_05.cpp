// Zajecia21_05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	node *R;
	node *L;
	int val;
};

void insertBST(node*& root, int x) {
	if (root == NULL) {
		root = new node;
		root->val = x;
		root->R = root->L = NULL;
	}
	else {
		if (x < root->val) insertBST(root->L, x);
		else insertBST(root->R, x);
	}
}

void Inorder(node* root) {
	if (root != NULL) {
		Inorder(root->L);
		cout << root->val << " ";
		Inorder(root -> R);
		
	}
}
int main()
{
	
	node *root = NULL;
	insertBST(root, 13);
	insertBST(root, 8);
	insertBST(root, 10);
	insertBST(root, -3);
	insertBST(root, 8);
	insertBST(root, 12);
	insertBST(root, 36);
	insertBST(root, 18);
	insertBST(root, 22);
	Inorder(root);
	//for (;;);
	system("pause");
    return 0;
	

}

