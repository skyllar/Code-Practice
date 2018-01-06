/*
 * Sort a scrambled itinerary.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: Apratim
 */

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

#define fup(i, a, b) for(int i=a;i<b;i++)
#define fdn(i, a, b) for(int i=a;i>=b;i--)

#define gc getchar
#define ll long long

#include<stdio.h>
#include <iostream>
#include <map>
#include<string>

using namespace std;

int main(int argc, char *argv[]) {

    map<string, int> mymap;
    map<string, string> m;

    string start;
    int t;
    scanf("%d", &t);
    int n;
    string s1, s2;

    for (int j = 0; j < t; j++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {

            cin >> s1;
            cin >> s2;

            m[s1] = s2;

            if (mymap.find(s1) != mymap.end()) {
                mymap[s1]++;
            } else
                mymap[s1] = 1;

            if (mymap.find(s2) != mymap.end()) {
                mymap[s2]++;
            }


            else
                mymap[s2] = 1;
        }

        //cout << "____" << m["DFW"] << "\n";
        //cout << "\n_______________________________\n";
        map<string, int>::iterator it;
        cout << "Case #" << j + 1 << ": ";
        for (it = mymap.begin(); it != mymap.end(); ++it) {
            if (it->second == 1) {

                if (m.find(it->first) != m.end()) {

                    start = it->first;

                    while (m.find(start) != m.end()) {
                        cout << start << "-" << m[start] << " ";
                        start = m[start];
                        //cout << "Start:" << start << "\n";
                    }
                    break;
                }
            }
        }
        cout << "\n";
        mymap.clear();
        m.clear();
    }
    return 0;
}
