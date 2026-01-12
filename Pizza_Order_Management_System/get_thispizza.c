#include <stdio.h>
#include <stdlib.h>
#include "project3.h"

char ***get_thispizza(char **ingredients, int num_ingredients, int *user_num, char **thispizza_size){
  // Prompt and get size of pizza
  int size;
  printf("\nWhat size pizza would you like to order:\n");
  printf(" 1) Small\n 2) Medium\n 3) Large\n");
  scanf("%i", &size);
  getchar();

  // Get number of ingredients user wants on their pizza
  int user_ingr_num;
  printf("Of our %i available ingredients, how many do you plan to put on your pizza? ", num_ingredients);
  scanf("%i", &user_ingr_num); // Scan the number.
  *user_num = user_ingr_num; // Initialize the pointer we passed through so we can use this number in main.
  getchar();

  // Allocate memory for pizza
  char ***thispizza = malloc(user_ingr_num * sizeof(char **));
  if(thispizza == NULL){
    printf("Memory allocation failed...");
    exit(1);
  }

  // Get specific ingredients they want on their pizza
  printf("Enter the number next to each ingredient you want on your pizza: ");

  // Process their choices
  for(int i = 0; i < user_ingr_num; i++){
    int choice; 
    scanf("%i", &choice);
    *(thispizza + i) = (ingredients + choice - 1);
  }
  getchar();

  // Receipt
  
  printf("\nHere is your receipt:\n");
  // Initialize variables based on size of pizza.
  double topping_price;
  double base_price;
  double total = 0;
  if(size == 1){
    topping_price = 1.00;
    base_price = 5.00;
    *thispizza_size = "Small";
  }else if(size == 2){
    topping_price = 1.25;
    base_price = 7.50;
    *thispizza_size = "Medium";
  }else{
    topping_price = 1.50;
    base_price = 10.00;
    *thispizza_size = "Large";
  }

  printf(" %s Pizza\t$%.2f\n", *thispizza_size, base_price);
  total += base_price;
  
  // Add each ingredients price.
  for(int i = 0; i < user_ingr_num; i++){
    printf(" %i. %s\t$%.2f\n", i + 1, **(thispizza + i), topping_price);
  }
  total += (user_ingr_num * topping_price);

  printf("\nTotal Due: \t$%.2f\n", total);

  return thispizza;
}
