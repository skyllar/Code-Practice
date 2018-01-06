#include<stdio.h>
#include<iostream>
using namespace std;

int compare1(int x, int y) {
	return x > y;
}

int compare2(int x, int y) {

	//printf("\nIn comp: X = %d,Y = %d\n", x, y);
	return x < y;
}

class Heap {
private:
	int *heapArray;
	int totalHeapSize;
	int heapSize;
	int buildHeapOrNot;
	int(*comp)(int, int);

	int leftChildIndex(int index) {

		if (2 * index + 1 < heapSize)
			return 2 * index + 1;
		else
			return -1;
	}
	int rightChildIndex(int index) {

		if (2 * index + 2 < heapSize)
			return 2 * index + 2;
		else
			return -1;
	}

	int parent(int index) {
		if (index == 0)
			return -1;
		else
			return ((int) ((index - 1) / 2));
	}
	void swap(int index1, int index2);

public:
	Heap(int size, int(*comp)(int, int)) {
		if (comp == NULL || size < 1) {
			printf("Incorrect Parameters Passed,Object Will Be Destructed\n");
			this->~Heap();
		}

		this->comp = comp;
		totalHeapSize = size;
		heapArray = new int[totalHeapSize];
		heapSize = 0;
		buildHeapOrNot = 0;
	}

	void buildHeap(int *newArray, int newArraySize);

	void insertIntoHeap(int value);

	void deleteFromHeapByValue(int value);

	int deleteTopElement();

	int getTopElementFromHeap(void);

	int getHeapSize(void);

	void printCurrentArrayElementIndexWise();
private:
	void heapify(int index);

};

void Heap::printCurrentArrayElementIndexWise() {
	for (int i = 0; i < heapSize; i++) {
		printf("%d ", heapArray[i]);
	}
	printf("\n");
}

void Heap::buildHeap(int *newArray, int newArraySize) {
	if (buildHeapOrNot == 1)
		printf(
				"Can't Proceed You Have Already Used this method,Try to Make New Object n\n");
	else {
		//cout << "$$$$$$$$$$$$$$$$$$$$$$\n";

		heapSize = newArraySize;
		for (int i = 0; i < newArraySize; i++)
			heapArray[i] = newArray[i];
		int currentIndex = parent(heapSize - 1);
		while (currentIndex > -1) {
			heapify(currentIndex);
			currentIndex--;

			//cout << "-----------------------\n";
		}
	}
}

void Heap::insertIntoHeap(int value) {

	if (totalHeapSize == heapSize) {
		printf("Cannot Insert,First delete Items\n");
		return;
	}

	printf("In Insertion........\n");
	heapArray[heapSize] = value;
	heapSize++;
	int child = heapSize - 1;
	int par;
	while (1) {
		par = parent(child);

		if (par == -1 || (*comp)(heapArray[child], heapArray[par]) > 0) {
			///printf("&&&&&&\n");
			break;
		} else {
			//printf("$$$$\n");
			swap(child, par);
			child = par;
		}
	}
}

void Heap::deleteFromHeapByValue(int value) {

}

int Heap::deleteTopElement(void) {
	if (heapSize == 0)
		return -1;
	else {
		int temp = heapArray[0];
		heapArray[0] = heapArray[heapSize - 1];
		heapSize--;
		heapify(0);
		return temp;
	}
}

void Heap::swap(int index1, int index2) {
	int temp = heapArray[index1];
	heapArray[index1] = heapArray[index2];
	heapArray[index2] = temp;
}

void Heap::heapify(int index) {
	int largest;
	int nextIndex;
	while (1) {
		nextIndex = index;
		largest = heapArray[index];
		if (leftChildIndex(index) != -1) {
			if ((*comp)(largest, heapArray[leftChildIndex(index)]) > 0) {
				largest = heapArray[leftChildIndex(index)];
				nextIndex = leftChildIndex(index);

			}
			if (rightChildIndex(index) != -1) {
				if ((*comp)(largest, heapArray[rightChildIndex(index)]) > 0) {
					largest = heapArray[rightChildIndex(index)];
					nextIndex = rightChildIndex(index);
				}
			}
			swap(index, nextIndex);
		}

		if (nextIndex == index)
			break;
		index = nextIndex;
	}

}

int Heap::getTopElementFromHeap(void) {
	if (heapSize > 0)
		return heapArray[0];
	else
		return -999;
}

int Heap::getHeapSize(void) {
	return heapSize;
}

int main() {
	Heap *myHeap = new Heap(100, compare2);

	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(a) / sizeof(int);
	myHeap->buildHeap(a, size);
	cout << "Size: " << myHeap->getHeapSize() << endl;

	//cout << "Top Element: " << myHeap->getTopElementFromHeap() << endl;


	//	cout << "Sorted Array: \n";
	//	for (int i = 0; i < size; i++) {
	//		cout << myHeap->deleteTopElement() << " ";
	//	}

	myHeap->insertIntoHeap(101);
	int l = myHeap->getHeapSize();

	cout << "Array Elements: \n";

	myHeap->printCurrentArrayElementIndexWise();
	for (int i = 0; i < l; i++) {
		cout << i << " ";
	}
	cout << "\n";

	cout << "Sorted Array: \n";
	for (int i = 0; i < l; i++) {
		cout << myHeap->deleteTopElement() << " ";
	}
	return 0;
}
