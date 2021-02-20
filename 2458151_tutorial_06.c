#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUSTOMERS 5
#define NAME_LEN  10
#define ID_LEN 	  6

#define BUFFER_SIZE 1024

struct customer
{
	char id[ID_LEN];
	char name[NAME_LEN];
	int frequentTraveller;
};

struct queue
{
	struct customer* elements;
	int capacity;
	int front;
	int size;
};

struct queue* createQueue(int capacity);
int isFullQueue(struct queue* Queue);
void enqueue(struct queue* Queue, struct customer item);
struct customer dequeue(struct queue* Queue);
void importCustomers(struct queue* customerQueue, char filename[BUFFER_SIZE]);

int main()
{
	struct queue* customerQueue;
	
	int running = 1;
	while (running)
	{
		printf("[I]mport\n");
		printf("[S]imulation\n");
		printf("E[x]it\n");
		
		char input;
		scanf(" %c", &input);
		
		putchar('\n');
		
		switch (input)
		{
			case 'I':
			case 'i':
				// import
				customerQueue = createQueue(CUSTOMERS);
				printf("Please enter the filename > ");
				
				char filename[BUFFER_SIZE];
				scanf(" %s", filename);
				
				importCustomers(customerQueue, filename);
				printf("\n%-5s   %-10s   %-15s\n", "ID", "NAME", "FREQUENT TRAVELER");
				for (int i = 0; i < customerQueue->size; i++)
				{
					printf("%-5s | %-10s | %-15s\n", customerQueue->elements[i].id, customerQueue->elements[i].name, customerQueue->elements[i].frequentTraveller == 1 ? "YES" : "NO");
				}
				
			break;
			
			case 'S':
			case 's':
				// simulation
				putchar('\n');
				
				//~ for (int i = 0; i < CUSTOMERS; i++)
				//~ {
					//~ dequeue(customerQueue);
				//~ }
				while (customerQueue->size > 0)
				{
					printf("QUEUE:\n");
					int i = 0;
					for (int j = 0; j < CUSTOMERS; j++)
					{
						printf(" | ");
						if (i < customerQueue->size)
						{
							printf("%s", customerQueue->elements[j].name);
						}
						putchar('\n');
						i++;
					}
					
					putchar('\n');
					dequeue(customerQueue);
					putchar('\n');
				}
				
				
				
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

struct queue* createQueue(int capacity)
{
	struct queue* Queue = (struct queue*) malloc(sizeof(struct queue));
	
	Queue->capacity = capacity;
	Queue->front = Queue->size = 0;
	Queue->elements = (struct customer*) malloc(Queue->capacity * sizeof(struct customer));
	
	return Queue;
}

int isFullQueue(struct queue* Queue)
{
	return (Queue->size == Queue->capacity);
}

void enqueue(struct queue* Queue, struct customer item)
{
	if (isFullQueue(Queue))
	{
		printf("Queue is full\n");
		return;
	}
	
	Queue->elements[Queue->size] = item;
	Queue->size += 1;
	
	printf("%s entered the queue\n", item.name);
}

struct customer dequeue(struct queue* Queue)
{
	struct customer firstItem = Queue->elements[0];
	Queue->size -= 1;
	
	for (int i = 0; i < Queue->size; i++)
	{
		Queue->elements[i] = Queue->elements[i+1];
	}
	
	printf("%s left the queue\n", firstItem.name);
	return firstItem;
}

void importCustomers(struct queue* customerQueue, char filename[BUFFER_SIZE])
{
	char buffer[BUFFER_SIZE];
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		printf("Unable to open file \n");
		return;
	}
	
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		struct customer cust;
		int row = 0;
		
		char* field = strtok(buffer, ",");
		while (field)
		{
			switch (row)
			{
				case 0:
					strcpy(cust.id, field);
				break;
				
				case 1:
					strcpy(cust.name, field);
				break;
				
				case 2:
					cust.frequentTraveller = atoi(field);
				break;
			}
			
			field = strtok(NULL, ",");
			row++;
			
		}
		enqueue(customerQueue, cust);
	}
	
}
