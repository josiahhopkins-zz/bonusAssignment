#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 //*******************************************************
	//1 mark
	//write a function "allocate10" that allocates space for 10 integer using the parameter list
	//in other words the function is of VOID type, takes a parameter and allocates and assigns memory to that parameter
	//call the function to allocate and assign memory to a
	//use a loop in the function to assign a[0] to a[9] to integers 0 to 9 
	//print the values out one per line in the main program
	//To be clear - the memory is allocated and assigning values happens in the function
	//in the main function
 //free the memory in a
 //*******************************************************

void allocate10(void **p){
	*p = malloc(10 * sizeof(int));
}
 //*******************************************************
 //1 mark 
 //Write a function "joinStrings" takes as parameters 3 strings. It joins the first 2 together and puts the result in the third string
 //The function allocates memory for the third string using malloc
 //apply the function to strings b,c, and d. After the function is done d should have memory allocated to it and contain "Hello World"
 //the function should not assume the sizes of b or c - it needs to be general enough for any string
 //after calling the function using b,c,d as parameters print out d from the main function
 //free the memory in d
 //*******************************************************
 
void joinStrings(char *b, char *c, char **d){
	*d = malloc((strlen(b) + strlen(c)) * sizeof(char));
	strcpy(*d, b);
	strcat(*d, c);
}

 //*******************************************************
 //1 mark
 //write a function "arrayWrite" that takes as parameters an array of the same type as e, 
 //the size of the first dimension, and a string variables, binaryFilename
 //the function "arrayWrite" writes the values of the the array 
 //(starting from array[0][0] and ending at array[size-1][2]) to the binaryFilename
 //apply the function to array e and file1
 //*******************************************************
 
 void arrayWrite(int a[][3], int size, char *binaryFile){
	int e[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	a = e;
	FILE *f = fopen(binaryFile, "w");
	 for(int i = 0; i < size; i++){
		fwrite(*(a + i), 1, 3, f); 
	 }
	 fclose(f);
 }

 //******************************************************* 
 //1 mark
 //write a function "binaryIO" to take as a parameter two filenames
 //it opens the first file which is binary reads in sizeof(int) bytes at a time
 //it writes value and the value squared separated by a ',' one set of values per line i.e.
 //0,0
 //1,1
 //2,4 
 //etc. to a the second file
 //
 //run the function with parameters e,file1, file2
 //so at the end of this there should be two new files
  //*******************************************************
void binaryIO(char *a, char *b){
	FILE *f1, *f2;
	f1 = fopen(a, "r");
	f2 = fopen(b, "w");
	while(!feof(f1)){
		int j;
		fread(&j, sizeof(int), 1, f1);
		fprintf(f2, "%d, %d\n", j, j * j);
	}
	fclose(f1);
	fclose(f2);
}

 //******************************************************* 
 //2 marks
 //malloc and assign memory for	f as a pointer to pointers to integer style array of the same size as e
 //malloc and assign memory for g as a pointer to pointer to integer where you assign the 
 //pointers to a block of memory the size of e
	//write a function "arrayCopy" that that takes parameters of 
	//the same type as e, f, and g and a sizes array parameter
	//sizes is an array of the dimension sizes
	//use for loops to copy values of e to f and g inside the function
	//in main print out e, f and g
 //in main free the memory for f
 //in main free the memory for g
 //*******************************************************
 
 
 void arrayCopy(int **e, int **f, int **g, int sizes[]){
	 for(int i = 0; i < sizeof(sizes); i++){
			*(f + i) = malloc(sizes[i] * sizeof(e[0]));
			*(g + i) = malloc(sizes[i] * sizeof(e[0]));
			memcpy(*(f + i), &e[i], sizes[i] * sizeof(e[0]));
			memcpy(*(g + i), &e[i], sizes[i] * sizeof(e[0]));
	 }
 }
 
 
int main(){
	
	int *a;
	char *b="Hello ";
	char *c= "World";
	char *d;
	char *file1="e.bin";
	char *file2="e.txt";
	int size;
	int sizes[2];
	int e[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int sizeArray[4] = {3, 3, 3, 3};
	int **f;
    int **g;
	//Part 1
	
	allocate10(&a);
	for(int i = 0; i < 10; i++){
		a[i] = i;
		printf("%d\n", a[i]);
	}
	free(a);
	

	//part 2
	joinStrings(b, c, &d);
	printf("%s\n", d);
	free(d);
	
	//part 3
	arrayWrite(&e, 4, file1);

	//part 5
	 f = malloc(sizeof(int) * sizeof(e));
	 g = malloc(sizeof(int) * sizeof(e));
	 arrayCopy(e, f, g, sizeArray);
	 free(f);
	 free(g);
	return 1;
}
 
	
