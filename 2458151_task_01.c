#include <stdio.h>

#define MAX_CHAR_LIMIT 25
#define VAT_RATE       19 // vat rate percentage

int main(void)
{
	int number;
	char name[MAX_CHAR_LIMIT];
	float nettoPrice;
	char category;
	
	printf("Enter number: ");
	scanf(" %d", &number);
	
	printf("Enter name: ");
	scanf(" %s", &name[0]);
	
	printf("Enter netto price: ");
	scanf(" %f", &nettoPrice);
	
	printf("Enter category: ");
	scanf(" %c", &category);
	
	float tax = nettoPrice * (VAT_RATE / 100.0f);
	float bruttoPrice = nettoPrice + tax;
	
	printf("%d | %s | %c | (netto) %.2f | (tax) %.2f | (brutto) %.2f \n", number, name, category, nettoPrice, tax, bruttoPrice);
	
	int bytesTaken = sizeof(number) + sizeof(name) + sizeof(nettoPrice) + sizeof(category) + sizeof(tax) + sizeof(bruttoPrice);
	
	printf("%d | %s | %c | (netto) %.2f | (tax) %.2f | (brutto) %.2f | (memory) %d bytes", number, name, category, nettoPrice, tax, bruttoPrice, bytesTaken);
	
	return 0;
}
