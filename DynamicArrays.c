#include <stdlib.h>
#include <stdio.h>
#include "DynamicArrays.h"

/* This function will initialize the state of the dynamic array
header, and will allocate memory if necessary (dependant on InitialSize) */
void CreateDArray(DArray *DArrayPtr, unsigned int InitialSize){
	printf("initialize called\n");

	/* Set Capacity equal to Initial Size */
	DArrayPtr->Capacity=InitialSize;

	/* Set Entries Used to zero (There is no data currently stored) */
	DArrayPtr->EntriesUsed=0;
}
