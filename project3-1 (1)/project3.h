#ifndef PROJECT3_H
#define PROJECT3_H

#include <stdio.h>
#include <stdlib.h>

// Prototypes for all functions in this program
char **get_ingredients(int count);

char *get_item(void);

char ***get_thispizza(char **ingredients, int num_ingredients, int *user_num, char **thispizza_size);

void save_info(int num_ingredients, char ***thispizza, char *thispizza_size, char *receipt_file);

void free_dmem(char **ingredients, int num_ingredients, char ***thispizza, int pizza_size);

#endif
