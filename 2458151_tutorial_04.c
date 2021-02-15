#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMS	  20
#define BUFFER_SIZE   1024
#define DATA_1_NAME   "numbers1.csv"
#define DATA_2_NAME   "numbers2.csv"
#define COMBINED_NAME "unsorted.csv"
#define PATH 		  ""

void combineNumbers();
void parseNumbers(int numbers[MAX_NUMS]);
void bubbleSortFast(int numbers[MAX_NUMS]);
void bubbleSortSlow(int numbers[MAX_NUMS]);

int main()
{
	int running = 1;
	while (running)
	{
		int numbers[MAX_NUMS];
		
		combineNumbers();
		parseNumbers(numbers);
		
		printf("BubbleSort [s]low\n");
		printf("BubbleSort [f]ast\n");
		printf("E[x]it\n");
		
		char input;
		scanf(" %c", &input);
		
		putchar('\n');
		
		switch(input)
		{
			case 'S':
			case 's':
				// bubblesort slow
				bubbleSortSlow(numbers);
			break;
			
			case 'F':
			case 'f':
				// bubblesort fast
				bubbleSortFast(numbers);
			break;
			
			case 'X':
			case 'x':
				// exit
				running = 0;
			break;
		}
		putchar('\n');
	}
	
	return 0;
}

void combineNumbers()
{
	char buffer1[BUFFER_SIZE];
	FILE* file = fopen(PATH DATA_1_NAME, "r");
	if (!file)
	{
		printf("Unable to open " DATA_1_NAME);
		return;
	}
	
	fgets(buffer1, BUFFER_SIZE, file);
	fclose(file);
	
	char buffer2[BUFFER_SIZE];
	file = fopen(PATH DATA_2_NAME, "r");
	if (!file)
	{
		printf("Unable to open " DATA_2_NAME);
		return;
	}
	
	fgets(buffer2, BUFFER_SIZE, file);
	fclose(file);
	
	char combinedBuffer[BUFFER_SIZE];
	strcpy(combinedBuffer, strcat(buffer1, buffer2));
	
	file = fopen(PATH COMBINED_NAME, "w");
	fprintf(file, "%s", combinedBuffer);
	
	fclose(file);
	
}

void parseNumbers(int numbers[MAX_NUMS])
{
	char buffer[BUFFER_SIZE];
	FILE* file = fopen(PATH COMBINED_NAME, "r");
	if (!file)
	{
		printf("Unable to open " COMBINED_NAME);
		return;
	}
	
	int i = 0;
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		char* num = strtok(buffer, ",");
		while (num)
		{
			numbers[i] = atoi(num);
			num = strtok(NULL, ",");
			i++;
		}
	}
	
	fclose(file);
	
}

void bubbleSortFast(int numbers[MAX_NUMS])
{
	int passes = 0;
	int swaps = 0;
	
	printf("PASS %-3d | ", passes);
	for (int i = 0; i < MAX_NUMS; i++)
	{
		printf("%d ", numbers[i]);
	}
	
	putchar('\n');
	
	do
	{
		swaps = 0;
		passes++;
		for (int i = 0; i < MAX_NUMS - 1; i++)
		{
			if (numbers[i] > numbers[i+1])
			{
				int temp = numbers[i+1];
				numbers[i+1] = numbers[i];
				numbers[i] = temp;
				swaps = 1;
			}
		}
		
		if (swaps < 1)
			break;
		
		printf("PASS %-3d | ", passes);
		for (int i = 0; i < MAX_NUMS; i++)
		{
			printf("%d ", numbers[i]);
		}
		putchar('\n');
	}
	while (swaps > 0);
	
}

void bubbleSortSlow(int numbers[MAX_NUMS])
{
	int passes = 0;
	
	printf("PASS %-3d | ", passes);
	for (int i = 0; i < MAX_NUMS; i++)
	{
		printf("%d ", numbers[i]);
	}
	
	putchar('\n');
	
	for (int i = 0; i < MAX_NUMS - 1; i++)
	{
		passes++;
		for (int j = 0; j < MAX_NUMS - i - 1; j++)
		{
			if (numbers[j] > numbers[j+1])
			{
				int temp = numbers[j+1];
				numbers[j+1] = numbers[j];
				numbers[j] = temp;
			}
		}
		printf("PASS %-3d | ", passes);
		for (int i = 0; i < MAX_NUMS; i++)
		{
			printf("%d ", numbers[i]);
		}
		putchar('\n');
	}
}
