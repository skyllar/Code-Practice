/*
 * SortedArrayToBST.cpp
 *
 *  Created on: Dec 2, 2014
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
	node *left;
	node *right;
	int value;

	node(node *l, node *r, int v) {
		left = l;
		right = r;
		value = v;
	}
};

int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

node *getRoot(int *a, int start, int end) {
	if (start > end)
		return NULL;
	else {
		int mid = (end - start) / 2 + start;

		node *l = getRoot(a, start, mid - 1);
		node *r = getRoot(a, mid + 1, end);
		node *root = new node(l, r, a[mid]);
		return root;
	}

}

#include<queue>

void bfs(node *root, int size) {

	node **bfsLevel = new node*[size];
	int start = 0;
	int end = 0;
	queue<node*> q;
	node *temp;
	node *temp1;
	q.push(root);
	int flag;
	bfsLevel[end++] = root;
	bfsLevel[end++] = new node(NULL, NULL, -1);
	int cur = 0;
	while (!q.empty()) {
		int count = q.size();

		while (count--) {
			temp = q.front();
			q.pop();
			printf("%d ", temp->value);
			if (temp->left != NULL) {
				q.push(temp->left);

			}
			if (temp->right != NULL) {
				q.push(temp->right);

			}
		}
		printf("\n-------------\n");

	}
}

void inorder(node *root) {
	if (root == NULL)
		return;
	else {
		inorder(root->left);
		printf("%d ", root->value);
		inorder(root->right);
	}
}

void constructTree(int *a, int size) {
	node *root = getRoot(a, 0, size - 1);

	printf("\n");

	//inorder(root);
	bfs(root, size);
}

int main(int argc, char * argv[]) {

	constructTree(a, sizeof(a) / sizeof(int));
	return 0;
}
