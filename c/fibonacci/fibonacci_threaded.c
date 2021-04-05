#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define FIBONACCI_LEN 80
#define FIBONACCI_TAIL -1

#define DEBUG_ENABLE 0
#define PRINT_AT_START_ENABLE 1
#define PRINT_PROGRESS_ENABLE 0
#define PRINT_AT_END_ENABLE 1

#define PRINT_MANY_NUMBERS_PER_ROW 0
#define PRINT_ONE_NUMBER_PER_ROW 1
#define NUMBERS_TO_PRINT_PER_ROW PRINT_MANY_NUMBERS_PER_ROW

void fibonacci_print_numbers(
		unsigned long long const * const fibonacci_head,
		char one_per_row);
void fibonacci_array_calculate_full(unsigned long long* fibonacci_numbers);
void fibonacci_array_calculate_slice(unsigned long long* fibonacci_numbers);

void fibonacci_print_numbers(
		unsigned long long const * const fibonacci_head,
		char numbers_to_print_per_row)
{
	unsigned long long const * fibonacci_walk = fibonacci_head;
	char separator[3] = {0};

	if (PRINT_ONE_NUMBER_PER_ROW == numbers_to_print_per_row) {
		(void) strncpy(separator, "\n\0", 3);
	} else {
		(void) strncpy(separator, ", \0", 3);
	}

	while (1) {
		printf("%llu%s", *fibonacci_walk, separator);

		if (FIBONACCI_TAIL == *fibonacci_walk) {
			// Encountered end of fibonacci list
			break;
		}

		fibonacci_walk++;
	}

	printf("\n");
}

void fibonacci_array_calculate_full(unsigned long long* fibonacci_numbers)
{
	unsigned long long* fibonacci_walk = fibonacci_numbers;

#if DEBUG_ENABLE
	printf("fibonacci_walk is: %llu\n", *fibonacci_walk);
	printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

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

#if PRINT_PROGRESS_ENABLE
		fibonacci_print_numbers(
				fibonacci_numbers,
				NUMBERS_TO_PRINT_PER_ROW);
#endif // PRINT_PROGRESS_ENABLE

		fibonacci_walk++;
	}
}

void fibonacci_array_calculate_slice(unsigned long long* fibonacci_numbers)
{
	unsigned long long* fibonacci_walk = fibonacci_numbers;

#if DEBUG_ENABLE
	printf("fibonacci_walk is: %llu\n", *fibonacci_walk);
	printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

	while (1) {
		if (*fibonacci_walk < 0) {
			// Encountered negative fibonacci number
			break;
		}

		if (0 != *(fibonacci_walk + 1)) {
			// Reached a precalculated number
			break;
		}

		*(fibonacci_walk + 1) = *fibonacci_walk + *(fibonacci_walk - 1);

#if DEBUG_ENABLE
		printf("fibonacci_walk is: %llu\n", *fibonacci_walk);
		printf("fibonacci_walk points to: %p\n\n", fibonacci_walk);
#endif // DEBUG_ENABLE

#if PRINT_PROGRESS_ENABLE
		fibonacci_print_numbers(
				fibonacci_numbers,
				NUMBERS_TO_PRINT_PER_ROW);
#endif // PRINT_PROGRESS_ENABLE

		fibonacci_walk++;
	}
}

int main(void)
{
	int ret = 0;
	unsigned long long fibonacci_numbers[FIBONACCI_LEN] = {0};

	pthread_t thread_print,
		  thread_test;

	fibonacci_numbers[1] = 1;
	fibonacci_numbers[18] = 2584;
	fibonacci_numbers[19] = 4181;
	fibonacci_numbers[38] = 39088169;
	fibonacci_numbers[39] = 63245986;
	fibonacci_numbers[58] = 591286729879;
	fibonacci_numbers[59] = 956722026041;
	fibonacci_numbers[FIBONACCI_LEN - 1] = FIBONACCI_TAIL;

#if PRINT_AT_START_ENABLE
	fibonacci_print_numbers(fibonacci_numbers, NUMBERS_TO_PRINT_PER_ROW);
#endif // PRINT_AT_START_ENABLE

	if (-1 != fibonacci_numbers[FIBONACCI_LEN - 1]) {
		printf("Expecting the last number of fibonacci list to be -1. Stopping.");
		return 1;
	}

	fibonacci_array_calculate_slice(&fibonacci_numbers[19]);

#if PRINT_AT_END_ENABLE
	fibonacci_print_numbers(fibonacci_numbers, NUMBERS_TO_PRINT_PER_ROW);
#if 0 // Reference for handling threads
	ret = pthread_create(&thread_print, NULL, fibonacci_print_numbers, (void*) fibonacci_numbers);
	if (0 != ret) {
		printf("Failed to create thread: %d\n", ret);
		thread_print = 0;
	}
	if (0 != thread_print) {
		pthread_join(thread_print, NULL);
	}
#endif
#endif // PRINT_AT_END_ENABLE

	return 0;
}
