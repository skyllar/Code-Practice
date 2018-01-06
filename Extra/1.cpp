#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
	int  x = 7;

	//int y = ++x + x++;
	int y =x +  x++ + ++x;

	//printf("%d %d\n",x++, ++x);
	//printf("%d %d\n",++x, x++);
	cout << y << "\n";
	return 0;
}
