#include <stdio.h>
#include "project3.h"

void save_info(int num_ingredients, char ***thispizza, char *thispizza_size, char *receipt_file) {
  // Initialize file and open it
    FILE *fptr = fopen(receipt_file, "w");
    if(!fptr){
        printf("Error opening file \n");
        return;
    }

    fprintf(fptr, "Available Pizza Ingredients today:\n");
    
    // Print available ingredients
    for(int i = 0; i < num_ingredients; i++){
        fprintf(fptr, " %i. %s\n", i + 1, *(*(thispizza + i)));
    }

    fprintf(fptr, "\nHere is your receipt:\n");
    // Initialize variables for prices and total.
    double base_price;
    double topping_price;
    double total;
    if(*thispizza_size == 'S'){
      base_price = 5.00;

      topping_price = 1.00;
    }else if(*thispizza_size == 'M'){
      base_price = 7.50;
      topping_price = 1.25;
    }else{
      base_price = 10.00;
      topping_price = 1.50;
    }
    fprintf(fptr, " %s Pizza \t$%.2f\n", thispizza_size, base_price);

    // Loop through ingredients in thispizza and orint them with their prices
    for(int i = 0; i < num_ingredients; i++){
        fprintf(fptr, " %i. %s \t$%.2f\n", i + 1, **(thispizza + i), topping_price);
    }
    fprintf(fptr, " \nTotal Due: \t$%.2f\n", total);

    // Close File
    fclose(fptr);

    printf("Today's Receipt has been saved to the file %s.\n", receipt_file);
}
