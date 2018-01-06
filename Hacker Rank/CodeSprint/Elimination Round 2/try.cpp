/*
 You are given a tree consisting of n vertices. Let's introduce the definition of diameter of the tree.

 Let d(x,y) is shortest distance between vertices x and y (each edge has length 1). Diameter of a tree is the value:

 maxv,udist(v,u)
 .

 You can perform the following operation at most k times: delete a single leaf of the tree (the operation can produce new leafs, that can be deleted later). The resulting tree must have as small diameter as possible. Find the minimum possible diameter.

 Input Format
 The first line contains two space separated integers n and k. Each of the next n−1 lines contains two space separated integers vi,ui, describing the current tree edge. It's guaranteed that the given graph is a tree.

 Constraints
 2≤n≤300; 0≤k≤n−2
 1≤vi,ui≤n

 Output Format

 Output a single integer − the resulting diameter.

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

 In the first example k=0 that is you don't need to delete anything. The diameter of the given tree equals 3.
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>          // std::priority_queue
using namespace std;

int currentLeaf, noOfVertices;
int visited[310], degreeOfVertices[310];
//vector<int> diameters;
//vector<int> diameterLeaf;
//vector<int> diameterLeafparent;

int maxDiameter = -1;
int maxDiameterLeafparent;
int maxDiameterLeaf;

vector<int> adjList[310];
priority_queue<int> mypq;
void initVisitedArr() {
	int i;

	for (i = 0; i <= 310; i++)
		visited[i] = 0;
}

void recDFSForCalculatingDia(int u, int dia) {
	if (degreeOfVertices[u] != -1) {
		vector<int>::iterator it = adjList[u].begin();

		dia++;
		visited[u] = 1;
		for (; it != adjList[u].end(); it++) {
			if (!visited[*it] && degreeOfVertices[u] != -1) {
				if (degreeOfVertices[*it] == 1 && *it > currentLeaf) {

					if (maxDiameter < dia) {
						maxDiameterLeafparent = u;
						maxDiameterLeaf = *it;
						maxDiameter = dia;
					}
				} else
					recDFSForCalculatingDia(*it, dia);
			}
		}
	}
}

void calculateDiameters(int k) {
	int i;

	if (k == 0) {
		for (i = 1; i <= noOfVertices; i++) {
			if (degreeOfVertices[i] == 1) {
				initVisitedArr();
				currentLeaf = i;
				recDFSForCalculatingDia(i, 0);
			}
		}
	} else {

		for (int i = 0; i <= k; i++) {
			maxDiameter = -1;
			for (i = 1; i <= noOfVertices; i++) {
				if (degreeOfVertices[i] == 1) {
					initVisitedArr();
					currentLeaf = i;
					recDFSForCalculatingDia(i, 0);
				}
			}
			degreeOfVertices[maxDiameterLeafparent]--;
			degreeOfVertices[maxDiameterLeaf] = -1;
		}
	}
}

int main() {
	int i, u, v, k, val;

	scanf("%d %d", &noOfVertices, &k);
	for (i = 0; i < noOfVertices - 1; i++) {
		scanf("%d %d", &u, &v);
		adjList[u].push_back(v);
		adjList[v].push_back(u);
		degreeOfVertices[u]++;
		degreeOfVertices[v]++;
	}
	calculateDiameters(k);

	//	vector<int>::iterator it = diameters.begin();
	//	for (; it != diameters.end(); it++)
	//		mypq.push(*it);
	//	for (i = 0; i < k; i++) {
	//		val = mypq.top();
	//		val--;
	//		mypq.pop();
	//		mypq.push(val);
	//	}
	//
	//	printf("%d\n", mypq.top());

	printf("%d\n", maxDiameter);

	return 0;
}
