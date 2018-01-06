/*
 * HuffmansEncoding.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Apratim
 */

#include<cstdio>
#include<iostream>
#include<queue>
#include<stdlib.h>
#include <functional>
#include<string.h>
using namespace std;

struct myContainer {
	char c;
	int frequency;
	struct myContainer *left;
	struct myContainer *right;
};

class Comp {
public:
	bool operator()(myContainer *mc1, myContainer *mc2) {
		return (mc1)->frequency > (mc2)->frequency;
	}
};

priority_queue<myContainer*, vector<myContainer* > , Comp> pQ;

myContainer *constructContainer(char *charArray, int *freqArray, int i) {
 myContainer *mC = (myContainer*) malloc(sizeof(myContainer));
 mC->c = charArray[i];
 mC->frequency = freqArray[i];
 mC->left = NULL;
 mC->right = NULL;
 return mC;
 }

void printQueue(priority_queue<myContainer*, vector<myContainer* > , Comp> pQ) {

	while (pQ.size() > 0) {
		myContainer *mC = pQ.top();
		pQ.pop();
		cout <<"--" <<mC->frequency << "\n";
	}

}
// A utility function to print an array of size n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
void printCodes(myContainer * root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    // Assign 1 to right edge and recur
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (root->c != '\0')
    {
        printf("%c: ", root->c);
        printArr(arr, top);
    }
}
void process(priority_queue<myContainer *,vector<myContainer*>,Comp>& pQ)
{
	while( pQ.size() > 1)
	{
		myContainer *mC1 = pQ.top();
		pQ.pop();
	 	myContainer *mC2 = pQ.top();
		pQ.pop();
		
		myContainer *mC = new myContainer;
		mC->left = mC1;
		mC->right = mC2;
		mC->c = '\0';
		mC->frequency = mC1->frequency + mC2->frequency;
		pQ.push(mC);
	}
}

void HuffmanCodes(char *charArray, int *freqArray, int size) {

 myContainer * mC;

 for (int i = 0; i < size; i++) {
	 mC = constructContainer(charArray, freqArray, i);
	 pQ.push(mC);
 }

	process(pQ);
	//printQueue(pQ);
	int arr[100], top = 0;
	printCodes(pQ.top(), arr,top);
 }

// Driver program to test above functions
int main() {
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0;
}
