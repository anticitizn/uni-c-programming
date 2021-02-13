#include <stdio.h>
#include <string.h>

#define CITIES  5
#define MAX_LEN 15
#define KM_COST 0.22
#define MIN_SENIOR_AGE 60

void initializeArrays(int city_dist[CITIES], char city_name[CITIES][MAX_LEN]);
int getYesNoInput();

int main()
{
	int city_dist[CITIES] = {0};
	char city_name[CITIES][MAX_LEN] = {0};
	
	initializeArrays(city_dist, city_name);
	
	// print table
	for (int i = 0; i < CITIES; i++)
	{
		printf("%d %*s %d\n", i + 1, -MAX_LEN, city_name[i], city_dist[i]);
	}
	
	int destination = 0;
	while (destination < 1 || destination > 5)
	{
		printf("Please choose your destination\n> ");
		scanf(" %d", &destination);
	}
	
	int bahncardType = 0;
	printf("Do you have a Bahncard?\n);
	
	if (getYesNoInput())
	{
		while (bahncardType < 1 || bahncardType > 2)
		{
			printf("Which type?");
			printf("[1] Type 25\n");
			printf("[2] Type 50\n");
			scanf(" %d", &bahncardType);
		}
	}
	
	int age = -1;
	printf("Are you a senior?\n");
	
	if (getYesNoInput())
	{
		// senior handling
		while (age < MIN_SENIOR_AGE)
		{
			printf("Please enter your age > ");
			scanf(" %d", &age);
		}
		
		char seniorCode[MAX_LEN] = {0};
		while (seniorCode[4] != 0)
		{
			seniorCode[MAX_LEN] = {0};
			printf("Please enter your ID > ");
			scanf(" %s", seniorCode);
		}
	}
	
	int hasGutschein = -1;
	char gutscheinCode[7] = {0};
	
	printf("Do you have a coupon?\n");
	
	if (getYesNoInput())
	{
		// gutschein handling
	}
	
	return 0;
}

void initializeArrays(int city_dist[CITIES], char city_name[CITIES][MAX_LEN])
{
	city_dist[0] = 530;
	city_dist[1] = 141;
	city_dist[2] = 558;
	city_dist[3] = 322;
	city_dist[4] = 288;
	
	strcpy(city_name[0], "Berlin");
	strcpy(city_name[1], "Frankfurt");
	strcpy(city_name[2], "Hamburg");
	strcpy(city_name[3], "Koeln");
	strcpy(city_name[4], "Muenchen");
}

int getYesNoInput()
{
	char yninput[MAX_LEN] = {0};
	while (strcmp(yninput, "ja") != 0 || strcmp(yninput, "nein") != 0)
	{
		printf("ja/nein > ");
		scanf(" %s", yninput);
	}
	
	if(strcmp(yninput, "ja") == 0)
		return 1;
	else
		return 0;
}
