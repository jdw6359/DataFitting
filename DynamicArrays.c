#include <stdlib.h>
#include <stdio.h>
#include "DynamicArrays.h"

/* This function will initialize the state of the dynamic array
header, and will allocate memory if necessary (dependant on InitialSize) */
void CreateDArray(DArray *DArrayPtr, unsigned int InitialSize){
	printf("initialize called\n");

	/* Set Entries Used to zero (There is no data currently stored) */
	DArrayPtr->EntriesUsed=0;

	/* Set Capacity equal to Initial Size */
	DArrayPtr->Capacity=InitialSize;


	/* Check to see if memory needs to be allocated for the array */
	if(DArrayPtr->Capacity==0){

		printf("Dont need to allocate memory!\n");


		/* Initial Size of Array will be 0, no memory needs to be allocated */
		DArrayPtr->Payload=NULL;

		printf("Payload set to null!\n");

	}else{
		printf("Need to allocate memory!\n");


		/* Allocate space to store payload according to Data struct */
		DArrayPtr->Payload=(Data *)malloc(DArrayPtr->Capacity * sizeof(Data));

		printf("Memory allocated!\n");
	}
}



/* This function will add the given Data struct to the Dynamic Array */
unsigned int PushToDArray(DArray *DArrayPtr, Data *PayloadPtr){

	printf("Payload Values******\nX: %f\nY: %f\n", PayloadPtr->X, PayloadPtr->Y);

}
