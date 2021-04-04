#include<stdio.h>

#define FIBONACCI_NUMBERS_TO_PROCESS 20 // TODO pass this to compiler, instead of coding here
#define FIBONACCI_LEN FIBONACCI_NUMBERS_TO_PROCESS

#define DEBUG_ENABLE 0

int main(void)
{
	int fibonacci_numbers[FIBONACCI_LEN] = {0};
	int* fibonacci_walk = fibonacci_numbers;
	fibonacci_numbers[FIBONACCI_LEN - 1] = -1; // -1 marks the end of list

	fibonacci_numbers[1] = 1;
	fibonacci_walk++;

#if DEBUG_ENABLE
	printf("fibonacci_walk is: %d\n", *fibonacci_walk);
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

		// Avoid overwriting -1 at the end of list.
		if (-1 != *(fibonacci_walk + 1)) {
			*(fibonacci_walk + 1) = *fibonacci_walk + *(fibonacci_walk - 1);
		}

#if DEBUG_ENABLE
		printf("fibonacci_walk is: %d\n", *fibonacci_walk);
		printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

		for (int k = 0; k < FIBONACCI_LEN; k++) {
			printf("%d, ", fibonacci_numbers[k]);
		}

		printf("\n");

		fibonacci_walk++;
	}

	return 0;
}
