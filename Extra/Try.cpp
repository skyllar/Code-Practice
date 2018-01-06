#include<iostream>
using namespace std;

class Type2;

class Type1 {
public:
	int i;
public:

	Type1(int i) {
		this->i = i;
	}

	void show() {
		cout << i << "\n";
	}

	//	int operator +(Type2& t) {
	//		i = i + t.i1;
	//		return i;
	//	}


};

class Type2 {
public:
	int i;
public:

	Type2(int i) {
		this->i = i;
	}

	void show() {
		cout << i << "\n";
	}

	//	int operator +(Type1 t) {
	//		i = i + t.i;
	//		return i;
	//	}

	friend void operator <<(ostream& out, Type2 t);
};

int operator +(Type1 t1, Type2 t2) {
	return t1.i + t2.i;
}

int operator +(Type2 t1, Type1 t2) {
	return t1.i + t2.i;
}

void operator <<(ostream& out, Type2 t) {
	out << t.i;
	//cout << "\ny2222\n";
}

int main(void) {

	Type1 t1(10);
	Type2 t2(12);

	//int a = t2 + t1;

	cout << t2;

	return 0;
}
