#include<iostream>

using namespace std;
#include<queue>

struct node {

	int aNo, value;
	node(int aNo, int value) {

		this->aNo = aNo;
		this->value = value;
	}
};

class Comp {

public:
	bool operator ()(node * n1, node*n2) {
		return n1->value > n2->value;
	}
};

int *mergeKArrays(int mat[3][4], int a, int b) {

	priority_queue<vector<node*> , vector<node*> , Comp> pQ;

	int cur[a];

	pQ.push(new node(0, 10));
	pQ.push(new node(0, 12));
	pQ.push(new node(0, 9));

	for (int j = 0; j < b; j++)
		cur[j] = 1;

	for (int i = 0; i < a; i++)
		pQ.push(new node(i, mat[i][0]));

	while (!pQ.empty()) {
		node *temp = pQ.top();
		cout << temp->aNo << ":" << temp->value << "\n";
		pQ.pop();

		if (cur[temp->aNo] != b) {
			pQ.push(new node(temp->aNo, mat[temp->aNo][cur[temp->aNo]++]));
		}
	}

	//	while (!pQ.empty()) {
	//		node *temp = pQ.top();
	//		cout << temp->aNo << ":" << temp->value << "\n";
	//		pQ.pop();
	//	}

	return NULL;
}

// Driver program to test above functions
int main() {
	// Change n at the top to change number of elements
	// in an array
	int arr[3][4] = { { 2, 6, 12, 34 }, { 1, 9, 20, 1000 },
			{ 23, 34, 90, 2000 } };
	int k = sizeof(arr) / sizeof(arr[0]);

	int *output = mergeKArrays(arr, 3, 4);

	//cout << "Merged array is " << endl;
	//printArray(output, n * k);

	return 0;
}
