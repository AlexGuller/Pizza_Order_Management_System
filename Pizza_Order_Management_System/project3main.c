#include <stdio.h>
#include <stdlib.h>
#include "project3.h"

int main(){
	//EMPLOYEE INPUT

	// Get number of ingredients
	int num_ingr;
	printf("How many available pizza ingredients do we have today? ");
	scanf("%i", &num_ingr);
	getchar();
	
	// Get the specific ingredients
	printf("Enter the %i ingredients one to a line:\n", num_ingr);
	
	// Store ingredients
	char **ingredients = get_ingredients(num_ingr);

	// Print available ingredients
	printf("\nAvailable ingredients today are: \n");
	for(int i = 0; i < num_ingr; i++){
		printf(" %i. %s\n", i + 1, *(ingredients + i));
	}

	// USER INPUT

	// Greet
	printf("\nWelcome to our Pizza ordering system!");

	// Give user options
	printf("\nToday we have the following fresh ingredients available:\n");
	for(int i = 0; i < num_ingr; i++){
	  printf(" %i. %s\n", i + 1, *(ingredients + i));
	}
	
	// Initialize thispizza.
	int user_num;
	char *thispizza_size;
	// Populate thispizza
	char ***thispizza = get_thispizza(ingredients, num_ingr, &user_num, &thispizza_size);

	// RECEIPT
	
	// Initialize var to track if they want receipt.
	int receipt_check;
	printf("\nDo you want to save this receipt? (1=yes, 2=no): ");
	scanf("%i", &receipt_check);
	getchar();

	// If they want to save the recipt.
	if(receipt_check == 1){
	  // Get the receipt file name.
	  char receipt_file[100];
	  printf("What file name do you want to use? ");
	  scanf("%99s", receipt_file);

	  // Save receipt.
	  save_info(user_num, thispizza, thispizza_size, receipt_file);
	}
       
	// Free Memory
	free_dmem(ingredients, num_ingr, thispizza, user_num);
}
