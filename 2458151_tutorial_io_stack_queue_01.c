
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUSTOMER_ID_FILENAME "customers.txt"
#define STR_LEN 	 1000
#define MAX_ID_COUNT 100

struct stack
{
	int top;
	unsigned int capacity; 
	int* array; 
};

struct queue {
	int front, rear, size;
	unsigned int capacity;
	int* array;
};

void readCustomerID(char string[STR_LEN]);

void addToStack(struct stack** Stack);
struct stack* createStack(unsigned int capacity);
int isFullStack(struct stack* Stack);
void push(struct stack* Stack, int item);

void addToQueue(struct queue** Queue);
struct queue* createQueue(unsigned int capacity);
int isFullQueue(struct queue* Queue);
void enqueue(struct queue* Queue, int item);

int main()
{
	struct stack* Stack;
	struct queue* Queue;
	
	int running = 1;
	while (running)
	{
		printf("\n[S]tack\n");
		printf("[Q]ueue\n");
		printf("E[x]it\n");
		
		char input;
		scanf(" %c", &input);
		putchar('\n');
		
		switch(input)
		{
			case 'S':
			case 's':
				// stack
				addToStack(&Stack);
			break;
			
			case 'Q':
			case 'q':
				// queue
				addToQueue(&Queue);
			break;
			
			case 'X':
			case 'x':
				// exit
				running = 0;
			break;
			
			default:
				printf("Invalid option\n");
			break;
		}
	}
	
	return 0;
}

void addToStack(struct stack** Stack)
{
	*Stack = createStack(MAX_ID_COUNT);
	
	char string[STR_LEN];
	readCustomerID(string);
	
	char* separated_string = strtok(string, " ,.-");
	
	while (separated_string != NULL)
	{
		int id;
		sscanf(separated_string, "%d", &id);
		push(*Stack, id);
		separated_string = strtok(NULL, " ,.-");
	}
}

void addToQueue(struct queue** Queue)
{
	*Queue = createQueue(MAX_ID_COUNT);
	
	char string[STR_LEN];
	readCustomerID(string);
	
	char* separated_string = strtok(string, " ,.-");
	
	while(separated_string != NULL)
	{
		int id;
		sscanf(separated_string, "%d", &id);
		enqueue(*Queue, id);
		separated_string = strtok(NULL, " ,.-");
	}
}

void readCustomerID(char string[STR_LEN])
{
	FILE* pfile;
	char* filename = CUSTOMER_ID_FILENAME;
	
	pfile = fopen(filename, "r");
	
	if (pfile == NULL)
	{
		printf("unable to open file %s", filename);
	}
	
	fgets(string, STR_LEN, pfile);
}

struct stack* createStack(unsigned int capacity)
{
	struct stack* Stack = (struct stack*) malloc (sizeof(struct stack));
	Stack->capacity = capacity;
	Stack->top = -1;
	Stack->array = (int*) malloc(Stack->capacity * sizeof(int));
	return Stack;
}

int isFullStack(struct stack* Stack)
{
	return Stack->top == Stack->capacity - 1;
}

void push(struct stack* Stack, int item)
{
	if (isFullStack(Stack))
	{
		return;
	}
	
	Stack->array[++Stack->top] = item;
	printf("%d pushed\n", item);
}

struct queue* createQueue(unsigned int capacity)
{
	struct queue* Queue = (struct queue*) malloc(sizeof(struct queue));
	
	Queue->capacity = capacity;
	Queue->front = Queue->size = 0;
	Queue->rear = capacity - 1;
	Queue->array = (int*) malloc(Queue->capacity * sizeof(int));
	
	return Queue;
}

int isFullQueue(struct queue* Queue)
{
	return (Queue->size == Queue->capacity);
}

void enqueue(struct queue* Queue, int item)
{
	if (isFullQueue(Queue))
	{
		return;
	}
	
	Queue->rear = (Queue->rear + 1) % Queue->capacity;
	Queue->array[Queue->rear] = item;
	Queue->size = Queue->size + 1;
	
	printf("%d enqueued\n", item);
}
