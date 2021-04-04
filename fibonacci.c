#include<stdio.h>

#define FIBONACCI_NUMBERS_TO_PROCESS 20 // TODO pass this to compiler, instead of coding here
#define FIBONACCI_LEN FIBONACCI_NUMBERS_TO_PROCESS

#define DEBUG_ENABLE 1

int main(void)
{
	int i = 0;
	int fibonacci_numbers[FIBONACCI_LEN] = {0};
	int* fibonacci_walk = fibonacci_numbers;
	// TODO fibonacci_numbers[FIBONACCI_LEN - 1] = -1;

	fibonacci_numbers[1] = 1;
	fibonacci_walk++;

#if DEBUG_ENABLE
	printf("fibonacci_walk is: %d\n", *fibonacci_walk);
	printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

	// TODO get rid of variable "i" and force stop by inserting -1 to the
	// end of list. Also should then make the list 1 slot longer as one of
	// the slots is always used for marking end of list.
	while(i < FIBONACCI_LEN) {
		if (fibonacci_numbers[i] < 0) {
			printf("Encountered negative fibonacci number. Stopping");
			break;
		}

#if DEBUG_ENABLE
		printf("i is: %d\n", i);
		// printf("fibonacci_walk is: %d\n", *fibonacci_walk);
		// printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);

		for (int k = 0; k < FIBONACCI_LEN; k++) {
			printf("%d, ", fibonacci_numbers[k]);
		}

		printf("\n");
#endif // DEBUG_ENABLE

		i++;
	}

	return 0;
}
