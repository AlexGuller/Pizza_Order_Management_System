#include <stdio.h>
#include <stdlib.h>
#include "project3.h"

char **get_ingredients(int count){
  // Allocate memory for the ingredients.
  char **ingred_arr = malloc(count * sizeof(char *));
  if(ingred_arr == NULL){
    printf("Memory allocation failed...");
    exit(1);
  }

  // Loop through the ingredient array and populate it with ingredients.
  for(int i = 0; i < count; i++){
    *(ingred_arr + i) = get_item();
  }

  // Return the ingredients.
  return ingred_arr;
}
