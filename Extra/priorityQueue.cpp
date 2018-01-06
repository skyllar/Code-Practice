#include<queue>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string.h>

#include<queue>

#include<algorithm>

struct ByLength {
	bool operator()(int lhs, int rhs) {
		return (lhs > rhs);
	}
};

int main() {

	int array[3] = { 0, 1, 2 };

	priority_queue<int, vector<int> , ByLength> pq;

	for (int i = 0; i < 3; i++)
		pq.push(array[i]);

	//pq.push(10);
	//pq.push(20);

	while (!pq.empty()) {
		int top = pq.top();

		cout << top << "  ";

		pq.pop();
	}
	//	queue<int> q;
	//	q.push(10);
	//	q.push(20);
	//
	//	while (!q.empty()) {
	//		cout << q.back() << " ";
	//		q.pop();
	//	}

	//	typedef map<string, string, ByLength> lenmap;
	//	lenmap mymap;

	//	vector<int> v1;
	//	//	v1.add(10);
	//	//	v1.add(20);
	//	//	v1.add(1);
	//
	//	v1.push_back(10);
	//	v1.push_back(20);
	//
	//	vector<int>::iterator it = upper_bound(v1.begin(), v1.end(), 10);
	//
	//	cout<<*it;
	//cout << "$ " << v1[0] << "\n";

	//v1.erase(v1.begin());

	//	mymap["one"] = "one";
	//	mymap["a"] = "a";
	//	mymap["b"] = "j";

	//mymap["fewbahr"] = "foobar";

	//	for (lenmap::const_iterator it = mymap.begin(), end = mymap.end(); it
	//			!= end; ++it)
	//		cout << it->first << "->" << it->second << "\n";


	//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
	//		cout << *it << " ";
	//	}

}
