/*
 * Shortest path with exactly k edges in a directed and weighted graph.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: Apratim
 */

#include <cstdio>
#include <iostream>
#include<climits>
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

// Define number of vertices in the graph and inifinite value
#define V 4
#define INF INT_MAX

//int shortestPath(int graph[V][V], int src, int dest, int k) {
//
//	if (k == 0) {
//		if (src == dest)
//			return 0;
//		else
//			return INF;
//	}
//
//	if (k == 1) {
//		return graph[src][dest];
//	}
//
//	int min = INF;
//	int temp;
//
//	for (int i = 0; i < V; i++) {
//		if (i != src && i != dest && graph[src][i] != INF) {
//			temp = shortestPath(graph, i, dest, k - 1);
//			if (min > temp + graph[src][i])
//				min = temp + graph[src][i];
//		}
//	}
//
//	return min;
//}
//
//
//
//// driver program to test above function
//int main() {
//	/* Let us create the graph shown in above diagram*/
//	int graph[V][V] = { { 0, 10, 3, 2 }, { INF, 0, INF, 7 },
//			{ INF, INF, 0, 6 }, { INF, INF, INF, 0 } };
//	int u = 0, v = 3, k = 2;
//	cout << "Weight of the shortest path is " << shortestPath(graph, u, v, k);
//	return 0;
//}


int shortestPath(int graph[][V], int u, int v, int k) {
	// Table to be filled up using DP. The value sp[i][j][e] will store
	// weight of the shortest path from i to j with exactly k edges
	int sp[V][V][k + 1];

	// Loop for number of edges from 0 to k
	for (int e = 0; e <= k; e++) {
		for (int i = 0; i < V; i++) // for source
		{
			for (int j = 0; j < V; j++) // for destination
			{
				// initialize value
				sp[i][j][e] = INF;

				// from base cases
				if (e == 0 && i == j)
					sp[i][j][e] = 0;
				if (e == 1 && graph[i][j] != INF)
					sp[i][j][e] = graph[i][j];

				//go to adjacent only when number of edges is more than 1
				if (e > 1) {
					for (int a = 0; a < V; a++) {
						// There should be an edge from i to a and a
						// should not be same as either i or j
						if (graph[a][j] != INF && i != a && j != a	)
							sp[i][j][e] = min(sp[i][j][e],
									graph[a][j] + sp[i][a][e - 1]);
					}
				}
			}
		}
	}
	return sp[u][v][k];
}

// driver program to test above function
int main() {
	/* Let us create the graph shown in above diagram*/
	int graph[V][V] = { { 0, 10, 3, 2 }, { INF, 0, INF, 7 },
			{ INF, INF, 0, 6 }, { INF, INF, INF, 0 } };
	int u = 0, v = 3, k = 2;
	cout << shortestPath(graph, u, v, k);
	return 0;
}
