


#include <stdio.h>

#define MAX_LENGTH 100000

int main()
{
	int n;
	scanf("%d", &n);

	int idx, narray[MAX_LENGTH];

	idx = 1;
	narray[0] = 1;
	for (int i = 1; i <= n; i++) {
		int tmp, carry = 0;
		for (int j = 1; j <= idx; j++) {
			tmp = narray[j-1] * i + carry;
			narray[j-1] = tmp % 10;	//存储小于10的整数
			carry = tmp / 10;	//计算机进位数
		}

		//更新进位
		while (carry) {
			narray[++idx-1] = carry % 10;
			carry /= 10;
		}
	}

	for (int i = idx; i >= 1; i--) {
		printf("%d", narray[i-1]);
	}
}
