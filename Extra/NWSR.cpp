/*
 A person wants to go from origin to a particular location, he can move in only 4 directions(i.e East, West, North, South) but his friend gave him a long route, help a person to find minimum Moves so that he can reach to the destination.
 Input – NESNWES
 Output – E

 E.g – SSSNEEEW
 output – EESS

 Explanation : its very easy code :
 1st way to think is with parenthesis matching there you have to match { , [ , ( and closing of it.
 While here you have just four directions N,S,E,W.
 instead of using Stack and increasing memory usage, we can take two variables say "north" and "east" which will take care of N,S and E,W.
 for every occurrence of N or E, increment north or east by one.
 and decrease for occurrences of  S and W.
 Finally in both north and east variable, there will be some value, just convert them in Direction and print it.
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int NSValue(char exp) {
	if (exp == 'N' or exp == 'n')
		return 1;
	else if (exp == 'S' or exp == 's')
		return -1;
}//NSValue
int EWValue(char exp) {
	if (exp == 'E' or exp == 'e')
		return 1;
	else if (exp == 'W' or exp == 'w')
		return -1;
}//EWValue

int getDirection(char exp[]) {
	int east = 0;
	int north = 0;
	int i, j, temp, l;
	l = strlen(exp);
	for (i = 0; i < l; i++) {
		if ((exp[i] == 'N' or exp[i] == 'n')
				|| (exp[i] == 'S' or exp[i] == 's')) {
			north += NSValue(exp[i]);
		}
		if ((exp[i] == 'E' or exp[i] == 'e')
				|| (exp[i] == 'W' or exp[i] == 'w')) {
			east += EWValue(exp[i]);
		}
	}//for
	if (east > 0) {
		for (i = 0; i < east; i++) {
			printf("%c", 'E');
		}
	}//if
	else if (east < 0) {
		east = -east;
		for (i = 0; i < east; i++) {
			printf("%c", 'S');
		}
	}//if


	if (north > 0) {
		for (i = 0; i < north; i++) {
			printf("%c", 'N');
		}
	}//if
	else if (north < 0) {
		north = -north;
		for (i = 0; i < north; i++) {
			printf("%c", 'S');
		}
	}//elseif

}//getDirection
int main() {
	//char exp[100] = "NESNWES";
	char exp[100] = "SSSNEEEW";
	getDirection(exp);
	return 0;
}
