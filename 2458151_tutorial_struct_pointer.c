#define NAME_LEN 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct article
{
	int id;
	char name[NAME_LEN];
	char group;
	float price;
};

void print(struct article *item, int num_articles);
void addArticle(struct article **item, struct article *newItem, int *num_articles);

int main()
{
	struct article* articles;
	int num_articles = 0;
	
	int running = 1;
	while (running)
	{
		printf("\n[A]dd\n");
		printf("[P]rint\n");
		printf("E[x]it\n");
		
		char input;
		scanf(" %c", &input);
		putchar('\n');
		
		switch(input)
		{
			case 'A':
			case 'a':
				; // empty operation because C does not allow declarations immediately after labels
				// add
				int idInput;
				char nameInput[NAME_LEN];
				char groupInput;
				float priceInput;
				
				printf("ID > ");
				scanf(" %d", &idInput);
				
				printf("NAME > ");
				scanf(" %s", nameInput);
				
				printf("GROUP > ");
				scanf(" %c", &groupInput);
				
				printf("PRICE > ");
				scanf(" %f", &priceInput);
				
				struct article newArticle = {idInput, " ", groupInput, priceInput};
				strncpy(newArticle.name, nameInput, NAME_LEN);
				
				addArticle(&articles, &newArticle, &num_articles);
			break;
			
			case 'P':
			case 'p':
				// print
				print(articles, num_articles);
			break;
			
			case 'X':
			case 'x':
				// exit
				running = 0;
			break;
		}
	}
	
	return 0;
}

void addArticle(struct article **articles, struct article *newArticle, int *num_articles)
{
	struct article *buffer = (struct article*) malloc((long unsigned int)(*num_articles + 1) * sizeof(struct article));
	
	for (int i = 0; i < *num_articles; i++)
	{
		*(buffer + i) = **(articles + i);
	}
	*(buffer + *num_articles) = *newArticle;
	*articles = buffer;
	*num_articles += 1;
}

void print(struct article *item, int num_articles)
{
	for (int i = 0; i < num_articles; i++)
	{
		printf("%-2d | %-10s | %-3c | %-6.2f\n", (item + i)->id, (item + i)->name, (item + i)->group, (item + i)->price);
	}
}
