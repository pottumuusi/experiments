#include<pthread.h>
#include<stdio.h>

#define FIBONACCI_LEN 80
#define FIBONACCI_TAIL -1

#define DEBUG_ENABLE 0
#define PRINT_ONCE_ONLY 1

void print_fibonacci_numbers(unsigned long long const * const fibonacci_head);

void print_fibonacci_numbers(unsigned long long const * const fibonacci_head)
{
	unsigned long long const * fibonacci_walk = fibonacci_head;

	while (1) {
		if (FIBONACCI_TAIL == *fibonacci_walk) {
			// Encountered end of fibonacci list
			break;
		}

		printf("%llu, ", *fibonacci_walk);

		fibonacci_walk++;
	}

	printf("\n");
}

int main(void)
{
	int ret = 0;
	unsigned long long fibonacci_numbers[FIBONACCI_LEN] = {0};
	unsigned long long* fibonacci_walk = fibonacci_numbers;
	fibonacci_numbers[FIBONACCI_LEN - 1] = FIBONACCI_TAIL;

	fibonacci_numbers[1] = 1;
	fibonacci_walk++;

	pthread_t thread_print,
		  thread_test;

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

		if (FIBONACCI_TAIL == *fibonacci_walk) {
			// Encountered end of fibonacci list
			break;
		}

		if (FIBONACCI_TAIL == *(fibonacci_walk + 1)) {
			// Avoid overwriting -1 at the end of list
			break;
		}

		*(fibonacci_walk + 1) = *fibonacci_walk + *(fibonacci_walk - 1);

#if DEBUG_ENABLE
		printf("fibonacci_walk is: %llu\n", *fibonacci_walk);
		printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

#if !PRINT_ONCE_ONLY
		print_fibonacci_numbers(fibonacci_numbers);
#endif // PRINT_ONCE_ONLY

		fibonacci_walk++;
	}

#if PRINT_ONCE_ONLY
	print_fibonacci_numbers(fibonacci_numbers);
#if 0 // Reference for handling threads
	ret = pthread_create(&thread_print, NULL, print_fibonacci_numbers, (void*) fibonacci_numbers);
	if (0 != ret) {
		printf("Failed to create thread: %d\n", ret);
		thread_print = 0;
	}
	if (0 != thread_print) {
		pthread_join(thread_print, NULL);
	}
#endif
#endif // PRINT_ONCE_ONLY

	return 0;
}
