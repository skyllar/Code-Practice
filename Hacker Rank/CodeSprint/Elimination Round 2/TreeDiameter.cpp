/*
 * TreeDiameter.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Apratim
 */

/*
 Tree Diameter
 You are given a tree consisting of vertices. Let's introduce the definition of diameter of the tree.
 Let is shortest distance between vertices and (each edge has length ). Diameter of a tree is the value:
 .
 You can perform the following operation at most times: delete a single leaf of the tree (the operation can produce new leafs,
 that can be deleted later). The resulting tree must have as small diameter as possible. Find the minimum possible diameter.
 Input Format
 The first line contains two space separated integers and . Each of the next lines contains two space separated integers
 , describing the current tree edge. It's guaranteed that the given graph is a tree.
 Constraints
 Output Format
 Output a single integer the resulting diameter.
 Sample Input #00
 4 0
 1 2
 2 3
 4 3
 Sample Output #00
 3
 Sample Input #01
 4 1
 2 3
 4 3
 1 4
 Sample Output #01
 2
 Explanation
 In the first example that is you don't need to delete anything. The diameter of the given tree equals .

 */

#include <list>
#include <cstdio>
#include <iostream>
#include<vector>
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

void scanint(ll int &x) {
	register ll int c = gc();
	x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		x = (x << 1) + (x << 3) + c - 48;
	}
}

int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int diameters[310];
int upperbound = 0;
int visited[310];

void diameterOpt(vector<int, list<int> > tree, int root) {

	if (root == -1) {
		diameters[upperbound++] = 0;
		return; /* diameter is also 0 */
	}

	int h;
	int max1 = 0;
	int max2 = 0;
	list<int>::iterator it;
	visited[root] = 1;
	for (it = tree[root].begin(); it != tree[root].end(); it++) {
		if (visited[*it] == 0) {
			h = diameterOpt(tree, *it);
			if (h > max1) {
				max2 = max1;
				max1 = h;
			} else {
				if (h > max2) {
					max2 = h;
				}
			}
		}
	}

	diameters[upperbound++] = max1 + max2 + 1;
}

void getFirstkMaxDiameter(int k) {
	int i, j;
	int temp;
	int maxIndex;
	int max;
	for (i = 0; i < k; i++) {
		max = diameters[i];
		for (j = i + 1; j < upperbound; j++) {
			if (max < diameters[j]) {
				max = diameters[j];
				maxIndex = j;
			}
		}
		temp = diameters[i];
		diameters[i] = max;
		diameters[maxIndex] = temp;
	}
}

int main(int argc, char * argv[]) {

	vector<int, list<int> > tree[400];

	int v, i, a = -1, b = -1, k;
	scanf("%d", &v);
	scanf("%d", &k);

	for (i = 0; i < v - 1; i++) {

		scanf("%d", &a);
		scanf("%d", &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	diameterOpt(tree, a);

	getFirstkMaxDiameter(k);
	return 0;
}
