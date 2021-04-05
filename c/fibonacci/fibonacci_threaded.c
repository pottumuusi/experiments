#include<stdio.h>

// FIBONACCI_NUMBERS_TO_PROCESS is expected to be passed here by compiler.
#define FIBONACCI_LEN FIBONACCI_NUMBERS_TO_PROCESS

#define DEBUG_ENABLE 0
#define PRINT_ONCE_ONLY 1

int main(void)
{
	unsigned long long fibonacci_numbers[FIBONACCI_LEN] = {0};
	unsigned long long* fibonacci_walk = fibonacci_numbers;
	fibonacci_numbers[FIBONACCI_LEN - 1] = -1; // -1 marks the end of list

	fibonacci_numbers[1] = 1;
	fibonacci_walk++;

#if DEBUG_ENABLE
	printf("fibonacci_walk is: %llu\n", *fibonacci_walk);
	printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

	if (-1 != fibonacci_numbers[FIBONACCI_LEN - 1]) {
		printf("Expecting the last number of fibonacci list to be -1. Stopping.");
		return 1;
	}

	while(1) {
		if (*fibonacci_walk < 0) {
			// Encountered negative fibonacci number
			break;
		}

		if (-1 == *fibonacci_walk) {
			// Encountered end of fibonacci list
			break;
		}

		if (-1 == *(fibonacci_walk + 1)) {
			// Avoid overwriting -1 at the end of list
			break;
		}

		*(fibonacci_walk + 1) = *fibonacci_walk + *(fibonacci_walk - 1);

#if DEBUG_ENABLE
		printf("fibonacci_walk is: %llu\n", *fibonacci_walk);
		printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

#if !PRINT_ONCE_ONLY
		for (unsigned int k = 0; k < FIBONACCI_LEN; k++) {
			printf("%llu, ", fibonacci_numbers[k]);
		}
		printf("\n");
#endif // PRINT_ONCE_ONLY

		fibonacci_walk++;
	}

#if PRINT_ONCE_ONLY
	for (unsigned int k = 0; k < FIBONACCI_LEN; k++) {
		printf("%llu, ", fibonacci_numbers[k]);
	}
	printf("\n");
#endif // PRINT_ONCE_ONLY

	return 0;
}
