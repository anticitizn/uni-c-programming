#define MAX_COUNTRIES 10
#define MAX_BRANCHES  10
#define MAX_REGIONS	  10
#define COL_LEN		 -12
#define NAME_LEN	  20

#include <stdio.h>
#include <string.h>

void initializeCountryBranches(int country_b[MAX_COUNTRIES][MAX_BRANCHES]);
void initializeCountryRegions(int country_r[MAX_COUNTRIES][MAX_REGIONS]);
void initializeRegionManagers(char region_m[MAX_REGIONS][NAME_LEN]);
void printCountryBranchesRevenue(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int *validCountries);
void printCountryRegions(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], int validCountries, int *validRegions);
void printRegionManagers(char region_m[MAX_REGIONS][NAME_LEN], int validRegions);
void addRevenueMenu(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int validCountries);
int getRevenueByRegion(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], int choice);
int getRevenueByBranch(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int choice);
int getRevenueByCountry(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int choice);
int getRevenueByManager(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], char region_m[MAX_REGIONS][NAME_LEN], char stringInput[NAME_LEN]);
void changeRegionManager(char region_m[MAX_REGIONS][NAME_LEN]);
void addNewCountry(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], char region_m[MAX_REGIONS][NAME_LEN], int validCountries);

int main()
{
	int country_b[MAX_COUNTRIES][MAX_BRANCHES] = {0};
	int country_r[MAX_COUNTRIES][MAX_REGIONS] = {0};
	char region_m[MAX_REGIONS][NAME_LEN];
	
	int validCountries = MAX_COUNTRIES;
	int validRegions = MAX_REGIONS;
	
	initializeCountryBranches(country_b);
	initializeCountryRegions(country_r);
	initializeRegionManagers(region_m);
	
	int running = 1;
	while (running)
	{
		putchar('\n');
		printCountryBranchesRevenue(country_b, &validCountries);
		printCountryRegions(country_b, country_r, validCountries, &validRegions);
		printRegionManagers(region_m, validRegions);
		
		printf("\n[A]add revenue\n");
		printf("Report total revenue by [b]ranch\n");
		printf("Report total revenue by [r]egion\n");
		printf("Report total revenue by [m]anager\n");
		printf("[C]hange region manager\n");
		printf("Add [n]ew country\n");
		printf("E[x]it\n");
		
		int input = 0;
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
				while (input < 1 || input > MAX_BRANCHES)
				{
					printf("branch > B");
					scanf("%d", &input);
				}
				
				printf("revenue for branch B%d | %d", input, getRevenueByBranch(country_b, input - 1));
			break;
			
			case 'R':
			case 'r':
				// report total revenue by region
				while (input < 1 || input > MAX_REGIONS)
				{
					printf("region > R");
					scanf("%d", &input);
				}
				
				printf("revenue for region R%d | %d", input, getRevenueByRegion(country_b, country_r, input - 1));
			break;
			
			case 'M':
			case 'm':
				// report total revenue by manager
				printf("Exact manager name: ");
				
				char stringInput[NAME_LEN] = {0};
				scanf("%s", stringInput);
				
				int revenue = getRevenueByManager(country_b, country_r, region_m, stringInput);
				
				if (revenue > 0)
				{
					printf("revenue for manager %s | %d\n", stringInput, revenue);
				}
				else
				{
					printf("no such manager found");
				}
				
			break;
			
			case 'C':
			case 'c':
				// change region manager
				changeRegionManager(region_m);
			break;
			
			case 'N':
			case 'n':
				addNewCountry(country_b, country_r, region_m, validCountries);
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

void initializeCountryBranches(int country_b[MAX_COUNTRIES][MAX_BRANCHES])
{
	//initialize2dArray(MAX_COUNTRIES, MAX_BRANCHES, country_b, 0);
	country_b[0][0] = 125900;
	country_b[0][1] = 1640050;
	country_b[1][0] = 7210050;
	country_b[2][2] = 8009005;
	country_b[2][4] = 70010050;
	country_b[3][3] = 10020050;
	country_b[4][3] = 8710050;
}

void initializeCountryRegions(int country_r[MAX_COUNTRIES][MAX_REGIONS])
{
	//initialize2dArray(MAX_COUNTRIES, MAX_BRANCHES, country_r, 0);
	country_r[0][0] = 1;
	country_r[1][3] = 1;
	country_r[2][4] = 1;
	country_r[3][1] = 1;
	country_r[4][2] = 1;
}

void initializeRegionManagers(char region_m[MAX_REGIONS][NAME_LEN])
{
	strncpy(region_m[0], "Susan", NAME_LEN);
	strncpy(region_m[1], "Charlotte", NAME_LEN);
	strncpy(region_m[2], "Charlotte", NAME_LEN);
	strncpy(region_m[3], "Bob", NAME_LEN);
	strncpy(region_m[4], "Simon", NAME_LEN);
}

void printCountryBranchesRevenue(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int *validCountries)
{
	printf("Revenue per country per branch:\n");
	// print empty space at the start of first row
	for (int i = 0; i >= COL_LEN; i--)
	{
		putchar(' ');
	}
	
	// print branch numeration on first row
	for (int i = 0; i < MAX_BRANCHES; i++)
	{
		if (getRevenueByBranch(country_b, i) > 0)
		{
			printf("B%*d", COL_LEN + 1, i + 1);
		}
	}
	
	putchar('\n');
	int emptyCountries = 0;
	
	// print each country's revenue per branch
	for (int i = 0; i < MAX_COUNTRIES; i++)
	{
		// first check if the total revenue of the country across all branches is 0
		// if so, ignore the country
		int sumRevenue = 0;
		for (int j = 0; j < MAX_BRANCHES; j++)
		{
			sumRevenue += country_b[i][j];
		}
		
		if (sumRevenue > 0)
		{
			printf("C%*d", COL_LEN, i + 1 - emptyCountries);
			for (int j = 0; j < MAX_BRANCHES; j++)
			{
				if (getRevenueByBranch(country_b, j) > 0)
				{
					printf("%*d", COL_LEN, country_b[i][j]);
				}
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

void printCountryRegions(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], int validCountries, int *validRegions)
{
	
	
	printf("Regions per countries:\n");
	// print empty space at the start of first row
	for (int i = 0; i >= COL_LEN; i--)
	{
		putchar(' ');
	}
	
	int emptyRegions = 0;
	// print branch numeration on first row
	for (int i = 0; i < MAX_REGIONS; i++)
	{
		if (getRevenueByRegion(country_b, country_r, i) > 0)
		{
			printf("R%*d", COL_LEN + 1, i + 1);
		}
		else
		{
			emptyRegions++;
		}
	}
	
	putchar('\n');
	
	for (int i = 0; i < validCountries; i++)
	{
		printf("C%*d", COL_LEN, i + 1);
		for (int j = 0; j < MAX_REGIONS; j++)
		{
			if (getRevenueByRegion(country_b, country_r, j))
			{
				printf("%*c", COL_LEN, (country_r[i][j]) ? 'X' : ' ');
			}
		}
		putchar('\n');
		
	}
	
	*validRegions = MAX_REGIONS - emptyRegions;
	putchar('\n');
}

void printRegionManagers(char region_m[MAX_REGIONS][NAME_LEN], int validRegions)
{
	printf("Managers per region:\n");
	for (int i = 0; i < validRegions; i++)
	{
		printf("R%*d %s\n", COL_LEN, i + 1, region_m[i]);
	}
}

void addRevenueMenu(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int validCountries)
{
	int countryChoice = 0;
	while (countryChoice < 1 || countryChoice > validCountries)
	{
		printf("country > C");
		scanf("%d", &countryChoice);
	}
	
	int branchChoice = 0;
	while (branchChoice < 1 || branchChoice > MAX_BRANCHES)
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

int getRevenueByBranch(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int choice)
{
	int revenue = 0;
	for (int i = 0; i < MAX_COUNTRIES; i++)
	{
		revenue += country_b[i][choice];
	}
	return revenue;
}

int getRevenueByRegion(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], int choice)
{
	int revenue = 0;
	
	for (int i = 0; i < MAX_COUNTRIES; i++)
	{
		if (country_r[i][choice] != 0)
		{
			revenue += getRevenueByCountry(country_b, i);
		}
	}
	return revenue;
}

int getRevenueByCountry(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int choice)
{
	int revenue = 0;
	for (int i = 0; i < MAX_BRANCHES; i++)
	{
		revenue += country_b[choice][i];
	}
	return revenue;
}

int getRevenueByManager(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], char region_m[MAX_REGIONS][NAME_LEN], char stringInput[NAME_LEN])
{
	int revenue = 0;
	for (int i = 0; i < MAX_REGIONS; i++)
	{
		if (strcmp(stringInput, region_m[i]) == 0)
		{
			revenue += getRevenueByRegion(country_b, country_r, i);
		}
	}
	
	return revenue;
}

void changeRegionManager(char region_m[MAX_REGIONS][NAME_LEN])
{
	int input = 0;
	while (input < 1 || input > MAX_REGIONS)
	{
		printf("Region > R");
		scanf(" %d", &input);
	}
	
	input--;
	printf("current manager for region R%d | %s\n", input, region_m[input]);
	printf("please enter new name for manager %s of region R%d > ", region_m[input], input);
	
	char newManager[NAME_LEN];
	scanf(" %s", newManager);
	
	if (strcmp(newManager, region_m[input]) == 0)
	{
		printf("no record updated");
	}
	else
	{
		strncpy(region_m[input], newManager, NAME_LEN);
	}
	
}

void addNewCountry(int country_b[MAX_COUNTRIES][MAX_BRANCHES], int country_r[MAX_COUNTRIES][MAX_REGIONS], char region_m[MAX_REGIONS][NAME_LEN], int validCountries)
{
	if (validCountries > MAX_COUNTRIES)
	{
		printf("Maximum amount of countries reached\n");
		return;
	}
	
	printf("Adding country > C%d\n", validCountries + 1);
	
	int branchInput = 0;
	while (branchInput < 1 || branchInput > MAX_BRANCHES)
	{
		printf("Branch > B");
		scanf(" %d", &branchInput);
	}
	
	int revenueInput = 0;
	while (revenueInput < 1)
	{
		printf("Revenue > ");
		scanf(" %d", &revenueInput);
	}
	
	country_b[validCountries][branchInput - 1] = revenueInput;
	
	int regionInput = 0;
	while (regionInput < 1)
	{
		printf("Region > R");
		scanf(" %d", &regionInput);
	}
	
	country_r[validCountries][regionInput - 1] = 1;
}
