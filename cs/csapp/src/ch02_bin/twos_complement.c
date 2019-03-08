#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main() {
	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("UINT_MAX: %ld\n", UINT_MAX);

	printf("INT8_MAX: %d\n", INT8_MAX);
	printf("INT8_MIN: %d\n", INT8_MIN);
	printf("UINT8_MAX: %ld\n", UINT8_MAX);

	printf("INT16_MAX: %d\n", INT16_MAX);
	printf("INT16_MIN: %d\n", INT16_MIN);
	printf("UINT16_MAX: %ld\n", UINT16_MAX);

	printf("INT32_MAX: %d\n", INT32_MAX);
	printf("INT32_MIN: %d\n", INT32_MIN);
	printf("UINT32_MAX: %ld\n", UINT32_MAX);

	printf("INT64_MAX: %lld\n", INT64_MAX);
	printf("INT64_MIN: %lld\n", INT64_MIN);
	printf("UINT64_MAX: %lld\n", UINT64_MAX);

	return 0;
}