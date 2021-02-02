#include <stdio.h>

#define WARE_NUM  12
#define WARE_NAME "wasabi"
#define WARE_PRICE 9.20

int main(void)
{
	int running = 1;
	int stock = 0;
	
	while (running)
	{
		int input = 0;
		char mainMenuInput = 0;
		
		printf("[1] [D]elivery\n[2] [S]hipment\n[3] E[x]it\n");
		scanf(" %c", &mainMenuInput);
		printf("\n");
		switch (mainMenuInput)
		{
			case '1':
			case 'D':
			case 'd': // start of Delivery menu
				input = 0;
				while (input < 1 || input > 5)
				{
					printf("How many packages were delivered? ");
					scanf(" %d", &input);
					
					if (input < 1 || input > 5)
					{
						printf("Invalid number of packages, valid range between 1 and 5\n");
					}
				}
				
				printf("\n");
				
				int amountOfPackages = input;
				for (int i = 1; i <= amountOfPackages; i++)
				{
					do 
					{
						printf("package %d | ", i);
						scanf(" %d", &input);
					} 
					while (input < 1 || input > 100);
					
					stock += input;
					printf("%d | %s | old stock: %d | new stock: %d\n\n", WARE_NUM, WARE_NAME, stock - input, stock);
				}
				
			break; // end of Delivery menu
			
			case '2':
			case 'S':
			case 's': // start of Shipment menu
				if (stock > 0)
				{
					char premiumClientInput;
					printf("Is the shipment for a premium client?\n");
					printf("Y/N ");
					scanf(" %c", &premiumClientInput);
					
					input = 0;
					printf("\nHow many goods will be sent?\n");
					while (input < 1 || input > 5 || input > stock)
					{
						printf("[shipment] | %d | %s | current stock: %d > ", WARE_NUM, WARE_NAME, stock);
						scanf(" %d", &input);
						
						if (input < 1 || input > 5 || input > stock)
						{
							printf("Invalid number of goods, valid range between 1 and 5 and cannot be more than stock\n");
						}
					}
					
					stock -= input;
					printf("%d | %s | old stock: %d | new stock: %d\n", WARE_NUM, WARE_NAME, stock + input, stock);
					
					if (premiumClientInput == 'y' || premiumClientInput == 'Y')
					{
						int discountRate;
						
						if (input == 1)
							discountRate = 5;
						else if (input == 2 || stock == 3)
							discountRate = 10;
						else if (input > 3)
							discountRate = 15;
							
						float totalPriceNetto = WARE_PRICE * input;
						float discount = (WARE_PRICE * input) * (discountRate / 100.0f);
						float totalPriceBrutto = totalPriceNetto - discount;
						
						printf("[shipment to premium customer] %d | %s | %d | %.2f | %.2f | %d%% discount = %.2f | %.2f\n", WARE_NUM, WARE_NAME, input, WARE_PRICE, totalPriceNetto, discountRate, discount, totalPriceBrutto);	
					}
					
					
				}
				else
				{
					printf("You do not have any stock to send.\n");
				}
				
				printf("\n");
				
			break; // end of Shipment menu
			
			case '3':
			case 'X':
			case 'x': // exit
				printf("%s", "Goodbye");
				running = 0;
			break;
			
			default:
				printf("Please enter a valid option\n");
			break;
		}
	}
	
	return 0;
}

