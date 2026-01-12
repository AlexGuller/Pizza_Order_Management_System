# Name: Alexander Guller
# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO THIS ASSIGNMENT.

# Compiler options
gcc_opt = -std=c99 -pedantic -Wimplicit-function-declaration -Wreturn-type -Wformat -g -c

# required target
all: project3.zip project3

# mandatory executable
project3: project3main.o get_ingredients.o get_item.o get_thispizza.o save_info.o free_dmem.o
	gcc project3main.o get_ingredients.o get_item.o get_thispizza.o save_info.o free_dmem.o -o project3

# compile object files
project3main.o: project3main.c project3.h
	gcc $(gcc_opt) project3main.c -o project3main.o

get_ingredients.o: get_ingredients.c project3.h
	gcc $(gcc_opt) get_ingredients.c -o get_ingredients.o

get_item.o: get_item.c project3.h
	gcc $(gcc_opt) get_item.c -o get_item.o

get_thispizza.o: get_thispizza.c project3.h
	gcc $(gcc_opt) get_thispizza.c -o get_thispizza.o

save_info.o: save_info.c project3.h
	gcc $(gcc_opt) save_info.c -o save_info.o

free_dmem.o: free_dmem.c project3.h
	gcc $(gcc_opt) free_dmem.c -o free_dmem.o

# zip file for submission
project3.zip: Makefile project3main.c get_ingredients.c get_item.c get_thispizza.c save_info.c free_dmem.c project3.h PROJECT3README
	zip project3.zip Makefile project3main.c get_ingredients.c get_item.c get_thispizza.c save_info.c free_dmem.c project3.h PROJECT3README

# clean up build artifacts
clean:
	rm -rf *.o project3 project3.zip

# test build in fresh directory
test:
	echo "files in project3 directory:"
	ls
	mkdir testdir
	cp project3.zip testdir
	unzip project3.zip -d testdir
	make -C testdir project3
	echo "files in testdir directory:"
	ls testdir
	rm -rf testdir/*
