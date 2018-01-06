#include<stdio.h>
#include<iostream>

#include<cstring>
using namespace std;

int dp[100];

int countDecodingDP(char *digits, int len) {
	if (len == 1)
		return 1;

	dp[0] = 1;
	if (digits[0] == '1') {
		if (digits[1] == '0') {
			dp[1] = 1;
		} else {
			dp[1] = 2;
		}
	} else if (digits[0] == '2' && digits[1] < '7')
		dp[1] = 2;
	else
		dp[1] = 1;

	for (int i = 2; i < len; i++) {
		if (digits[i] != '0')
			dp[i] += dp[i - 1];

		if (digits[i - 1] == '1') {
			dp[i] += dp[i - 2];
		}

		else if (digits[i - 1] == '2' && digits[1] < '7')
			dp[i] += dp[i - 2];
	}

	return dp[len - 1];

}

// Driver program to test above function
int main() {
	char digits[] = "1234";
	int n = strlen(digits);
	cout << "Count is " << countDecodingDP(digits, n);
	return 0;
}
