#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *NAME[] = { "meat", "milk", "eggs", "salt", "fish" };
char *BARCODE[] = { "1010", "1313", "1435", "2456", "1198" };
float Sale[5];
float PRICE[5] = { 150.0f, 75.0f, 40.0f, 250.0f, 60.0f };
float FULLPRICE = 0;
float SALE = 0;

struct PProduct
{
	char *Name;
	float Price;
	int Quantity;
	float FullPrice;
	char *BarCode;
};
typedef struct PProduct Product;

void create(Product *_p) {
	int i;
	for (i = 0; i < 5; i++) {
		Product p;
		p.Name = NAME[i];
		p.BarCode = BARCODE[i];
		p.Price = PRICE[i];
		p.Quantity = 0;
		p.FullPrice = 0;
		_p[i] = p;
	}
}

void addout(char *bc, Product *_p) {
	int i;
	for (i = 0; i < 5; i++) {
		if (!(strcmp(bc, _p[i].BarCode))) {
			_p[i].Quantity++;
			_p[i].FullPrice = _p[i].FullPrice + (_p[i].Price*(1 - Sale[i]));
			FULLPRICE += _p[i].FullPrice;
			SALE += (_p[i].Price * Sale[i]);
			printf("%s", _p[i].Name);
			printf(" - %.2f - %d - %.2f\n", _p[i].Price, _p[i].Quantity, _p[i].FullPrice);
		}
	}
}

void main() {
	int i;
	char bc[4];
	Product p[5];
	srand((unsigned int)time(0));
	for (i = 0; i < 5; i++) Sale[i] = ((rand() * (49) / RAND_MAX + 1) / 100.0f);
	create(p);
	printf("Start\n");
	while (i != 0) {
		printf("Enter Barcode Product Code\n");
		scanf("%s", &bc);
		addout(bc, p);
		printf("Enter one to add a new product\n");
		printf("If you want to exit, enter 0\n");
		scanf("%d", &i);
	}
	printf("Full Sale - %.2f\n", SALE);
	printf("Full Price - %.2f", FULLPRICE);
}

