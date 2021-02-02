#define MAX_COUNTRIES 20
#define BRANCHES	  5
#define REGIONS		  5
#define COL_LEN		 -12

#include <stdio.h>

void initializeCountryBranches(int country_b[MAX_COUNTRIES][BRANCHES]);
void initializeCountryRegions(int country_r[MAX_COUNTRIES][REGIONS]);
void printCountryBranchesRevenue(int country_b[MAX_COUNTRIES][BRANCHES], int *validCountries);
void addRevenueMenu(int country_b[MAX_COUNTRIES][BRANCHES], int validCountries);
void reportRevenueBranches(int country_b[MAX_COUNTRIES][BRANCHES]);
void reportRevenueRegions(int country_b[MAX_COUNTRIES][BRANCHES], int country_r[MAX_COUNTRIES][REGIONS]);

int main()
{
	int country_b[MAX_COUNTRIES][BRANCHES] = {0};
	int country_r[MAX_COUNTRIES][REGIONS] = {0};
	int validCountries;
	
	initializeCountryBranches(country_b);
	initializeCountryRegions(country_r);
	
	
	
	int running = 1;
	while (running)
	{
		printf("\n");
		printCountryBranchesRevenue(country_b, &validCountries);
		
		printf("[A]add revenue\n");
		printf("Report total revenue by [b]ranch\n");
		printf("Report total revenue by [r]egion\n");
		printf("Report total revenue by [m]anager\n");
		printf("[C]hange region manager\n");
		printf("E[x]it\n");
		
		char mainMenuInput;
		scanf(" %c", &mainMenuInput);
		
		switch(mainMenuInput)
		{
			case 'A':
			case 'a':
				// add revenue
				addRevenueMenu(country_b, validCountries);
			break;
			
			case 'B':
			case 'b':
				// report total revenue by branch
				reportRevenueBranches(country_b);
			break;
			
			case 'R':
			case 'r':
				reportRevenueRegions(country_b, country_r);
				// report total revenue by region
			break;
			
			case 'M':
			case 'm':
				// report total revenue by manager
			break;
			
			case 'C':
			case 'c':
				// change region manager
			break;
			
			case 'X':
			case 'x':
				// exit
				running = 0;
			break;
			
			default:
				printf("unknown option | please repeat\n");
			break;
		}
	}
	return 0;
}

void initializeCountryBranches(int country[MAX_COUNTRIES][BRANCHES])
{
	country[0][0] = 125900;
	country[0][1] = 1640050;
	country[1][0] = 7210050;
	country[2][2] = 8009005;
	country[2][4] = 70010050;
	country[3][3] = 10020050;
	country[4][3] = 8710050;
}

void initializeCountryRegions(int country_r[MAX_COUNTRIES][REGIONS])
{
	country_r[0][0] = 1;
	country_r[1][3] = 1;
	country_r[2][4] = 1;
	country_r[3][1] = 1;
	country_r[4][2] = 1;
}

void printCountryBranchesRevenue(int country_b[MAX_COUNTRIES][BRANCHES], int *validCountries)
{
	// print empty space at the start of first row
	for (int i = 0; i >= COL_LEN; i--) 
	{
		putchar(' ');
	}
	
	// print branch numeration on first row
	for (int i = 0; i < BRANCHES; i++)
	{
		printf("B%*d", COL_LEN + 1, i + 1);
	}
	
	putchar('\n');
	int emptyCountries = 0;
	
	// print each country's revenue per branch
	for (int i = 0; i < MAX_COUNTRIES; i++)
	{
		// first check if the total revenue of the country across all branches is 0
		// if so, ignore the country
		int sumRevenue = 0;
		for (int j = 0; j < BRANCHES; j++)
		{
			sumRevenue += country_b[i][j];
		}
		
		if (sumRevenue > 0)
		{
			printf("C%*d", COL_LEN, i + 1 - emptyCountries);
			for (int j = 0; j < BRANCHES; j++)
			{
				printf("%*d", COL_LEN, country_b[i][j]);
			}
			
			printf("\n");
		}
		else
		{
			emptyCountries++;
		}
		
	}
	
	*validCountries = MAX_COUNTRIES - emptyCountries;
	putchar('\n');
}

void addRevenueMenu(int country_b[MAX_COUNTRIES][BRANCHES], int validCountries)
{
	int countryChoice = 0;
	while (countryChoice < 1 || countryChoice > validCountries)
	{
		printf("country > C");
		scanf("%d", &countryChoice);
	}
	
	int branchChoice = 0;
	while (branchChoice < 1 || branchChoice > BRANCHES)
	{
		printf("branch > B");
		scanf("%d", &branchChoice);
	}
	
	int revenue = 0;
	while (revenue < 1)
	{
		printf("revenue > ");
		scanf("%d", &revenue);
	}
	
	country_b[countryChoice - 1][branchChoice - 1] = revenue;
}

void reportRevenueBranches(int country_b[MAX_COUNTRIES][BRANCHES])
{
	int branchChoice = 0;
	while (branchChoice < 1 || branchChoice > BRANCHES)
	{
		printf("branch > B");
		scanf("%d", &branchChoice);
	}
	
	int revenue = 0;
	for (int i = 0; i < MAX_COUNTRIES; i++)
	{
		revenue += country_b[i][branchChoice - 1];
	}
	printf("revenue for branch B%d | %d", branchChoice, revenue);
}

void reportRevenueRegions(int country_b[MAX_COUNTRIES][BRANCHES], int country_r[MAX_COUNTRIES][REGIONS])
{
	int revenue = 0;
	
	int regionChoice = 0;
	while (regionChoice < 1 || regionChoice > REGIONS)
	{
		printf("region > R");
		scanf("%d", &regionChoice);
	}
	
	for (int i = 0; i < MAX_COUNTRIES; i++)
	{
		if (country_r[i][regionChoice - 1] != 0)
		{
			for (int j = 0; j < BRANCHES; j++)
			{
				revenue += country_b[i][j];
			}
		}
	}
	printf("revenue for region R%d | %d", regionChoice, revenue);
}

void reportRevenuemanager();
