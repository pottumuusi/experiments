#include<stdio.h>

#define FIBONACCI_NUMBERS_TO_PROCESS 20 // TODO pass this to compiler, instead of coding here
#define FIBONACCI_LEN FIBONACCI_NUMBERS_TO_PROCESS

#define DEBUG_ENABLE 1

int main(void)
{
	int i = 0;
	int fibonacci_numbers[FIBONACCI_LEN] = {0};

	while(i < FIBONACCI_LEN) {
		if (fibonacci_numbers[i] < 0) {
			printf("Encountered negative fibonacci number. Stopping");
			break;
		}

#if DEBUG_ENABLE
		printf("%d\n", fibonacci_numbers[i]);
#endif // DEBUG_ENABLE

		i++;
	}

	return 0;
}
