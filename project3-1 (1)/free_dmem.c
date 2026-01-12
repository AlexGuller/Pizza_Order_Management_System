#include <stdlib.h>
#include "project3.h"

void free_dmem(char **ingredients, int num_ingredients, char ***thispizza, int user_ingr_num){
  // Loop through each ingredient and free the memory allocated.
  for(int i = 0; i < num_ingredients; i++){
    free(*(ingredients + i));
  }

  // Free the memory allocated to the ingredient list.
  free(ingredients);

  // Free the memory allocated to the list of thispizza ingredients.
  free(thispizza);
}
