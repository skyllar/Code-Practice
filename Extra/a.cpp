/*
 * 
 */\

/*
 * Complete the function below.
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<string.h>

using namespace std;

bool isPalindrome[100][100];

struct indexStore {
	int start;
	int end;
	indexStore(int i, int j) {
		start = i;
		end = j;
	}
};

struct trie {
	trie * child[26];
	bool isLeaf[26];

	vector<indexStore *> indexes;

	trie() {
		for (int i = 0; i < 26; i++) {
			child[i] = NULL;
			isLeaf[i] = false;
		}
	}
};

trie* insertInTrie(string st, int start, int end, trie *root) {
	trie* ptr = root;
	trie *old;

	if (root == NULL) {
		root = ptr = new trie();
	}

	for (int i = start; i <= end; i++) {
		if (ptr->child[st[i] - 'a'] != NULL) {

			//printf("--%c  \n", st[i]);

			old = ptr;
			ptr = ptr->child[st[i] - 'a'];

		} else {

			//printf("$$%c  \n", st[i]);
			ptr->child[st[i] - 'a'] = new trie();
			old = ptr;
			//ptr->isLastLevel = false;
			ptr = ptr->child[st[i] - 'a'];
		}
	}

	if (old->isLeaf[st[end] - 'a'] != true) {
		old->indexes.push_back(new indexStore(start, end));
	}

	old->isLeaf[st[end] - 'a'] = true;

	//printf("return\n");
	return root;
}

long int countSubstring(trie *root) {
	long int count = 0;

	if (root == NULL)
		return 0;
	else {

		for (int i = 0; i < 26; i++) {

			//printf("Calling on:%d\n", i);

			count += countSubstring(root->child[i]);

			if (root->isLeaf[i] == true)
				count++;
		}
	}

	//printf("----\n");

	return count;
}

long substringCalculator(string st) {

	trie *root = NULL;
	int i, k, j;

	int len = st.length();

	for (j = 0; j < len; j++) {
		for (k = j; k < len; k++) {
			//printf("j =%d,k=%d\n", j, k);
			root = insertInTrie(st, j, k, root);
		}
	}

	return countSubstring(root);
}

int palindromicSubstringCalculator(string st) {
	int count = 0;

	int totalLength = st.length();

	for (int i = 0; i < totalLength; i++) {

		for (int i = 0; i < totalLength; i++) {
			isPalindrome[i][i] = false;
		}
	}

	//printf("For Length: 1\n");
	for (int i = 0; i < totalLength; i++) {
		isPalindrome[i][i] = true;
		//printf("start: %d ,end: %d\n", i, i);
	}

	printf("For Length: 2\n");
	for (int i = 0; i < totalLength - 1; i++) {
		if (st[i] == st[i + 1]) {
			isPalindrome[i][i + 1] = true;
			//printf("start: %d ,end: %d\n", i, i + 1);
			printf("%c%c\n", st[i],st[i + 1]);

		}
	}

	int length;
	int start, end;

	for (length = 3; length <= totalLength; length++) {

		printf("\nFor Length: %d\n", length);

		for (start = 0; start + length <= totalLength; start++) {
			end = start + length - 1;

			if (isPalindrome[start + 1][end - 1] == true && st[start]
					== st[end]) {
				isPalindrome[start][end] = true;

				//printf("start: %d ,end: %d\n", start, end);

				for (int i = start; i <= end; i++) {
					printf("%c", st[i]);
				}
				printf("\n");
			}
		}
	}

	return count;
}

int main() {

	string a = "ababa";

	//cout<<a[0]<<"\n";

	cout << "Total Distinct Substring: " << substringCalculator(a) << "\n";

	cout << "Total Distinct Palindromic Substring: "
			<< palindromicSubstringCalculator(a) << "\n";

	return 0;
}
