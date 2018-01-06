/*
 * Largest Independent Set Problem.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: Apratim
 */

#include <cstdio>
#include <iostream>

using namespace std;

#define TRACE
#define DEBUG
#ifdef TRACE
#define trace1(x)                cerr <<"\n"<< #x << ": " << x << endl;
#define trace2(x, y)             cerr<<"\n" << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr<<"\n" << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr <<"\n"<< #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define pi(x) printf("%d\n" , x)
#define pl(x) printf("%ld\n" , x)
#define pll(x) printf("%lld\n" , x)
#define pc(x) printf("%c\n" , x)
#define ps(x) printf("%s\n" , x)

#define fup(i,a,b) for(int i=a;i<b;i++)
#define fdn(i,a,b) for(int i=a;i>=b;i--)

#define gc getchar
#define ll long long

struct node {

	int data;
	struct node *left;
	struct node *right;
	int maxIncludingThis;
};

#include <stdio.h>
#include <stdlib.h>

// A utility function to find max of two integers
int max(int x, int y) {
	return (x > y) ? x : y;
}

// A utility function to create a node
struct node* newNode(int data) {
	struct node* temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	temp->maxIncludingThis = -1;
	return temp;
}

/* A binary tree node has data, pointer to left child and a pointer to
 right child */

int LISS(struct node *root) {
	if (root == NULL)
		return 0;

	int s1 = 0;
	int s2 = 0;

	if (root->left != NULL) {
		s1
				+= (root->left->left->maxIncludingThis != -1) ? root->left->maxIncludingThis
						: LISS(root->left) + (root->left->maxIncludingThis
								!= -1) ? root->left->maxIncludingThis : LISS(
								root->left);
		s2
				+= (root->left->maxIncludingThis != -1) ? root->left->maxIncludingThis
						: LISS(root->left);
	}
	if (root->right != NULL) {
		s1 += root->right->left + root->right->right;
		s2
				+= (root->right->maxIncludingThis != -1) ? root->right->maxIncludingThis
						: LISS(root->right);
	}

	return (root->maxIncludingThis = max(s1, s2));

}

// Driver program to test above functions
int main() {
	// Let us construct the tree given in the above diagram
	struct node *root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	printf("Size of the Largest Independent Set is %d ", LISS(root));

	return 0;
}
