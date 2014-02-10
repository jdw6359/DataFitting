#include <stdlib.h>
#include <stdio.h>
#include "DynamicArrays.h"

/* Implementation of CreateDArray */
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

		/* Check to ensure that memory for Payload was allocated */
		if(DArrayPtr->Payload == NULL){

			/* Write to standard error */
			fprintf(stderr, "CreateDArray(): malloc() failed!\n");

			/* Flush Standard Error */
			fflush(stderr);

		}

		printf("Memory allocated!\n");
	}
}


/* Implementation of PushToDArray */
unsigned int PushToDArray(DArray *DArrayPtr, Data *PayloadPtr){


	/* Does the array need to be made larger? */
	if(DArrayPtr->EntriesUsed==DArrayPtr->Capacity){

		/* Increase the size of the dynamic array */
		DArrayPtr->Capacity += GROWTH_AMOUNT;

		printf("Capacity Increased to %d\n", DArrayPtr->Capacity);

		/* Reallocate storage for the array elements using a larger size */
		DArrayPtr->Payload=realloc(DArrayPtr->Payload, DArrayPtr->Capacity * sizeof(Data));

		/* Check to make sure that memory was propertly reallocated */
		if(DArrayPtr->Payload == NULL){

			/* Write to standard error */
			fprintf(stderr, "PushToDArray(): realloc() failed!\n");

			/* Flush Standard Error */
			fflush(stderr);
		}


	}

	/* Copy the point value into the array where the insertion index is pointing */
	memcpy(&(DArrayPtr->Payload[DArrayPtr->EntriesUsed]), PayloadPtr, sizeof(Data));

	printf("Payload Values******\nX: %f\nY: %f\n\n\n", PayloadPtr->X, PayloadPtr->Y);


	/* Increment the number of elements used in the array */
	DArrayPtr->EntriesUsed++;

	/* return the index of the last element inserted */
	return (DArrayPtr->EntriesUsed-1);

}

/* Implementation of DestroyDArray */
void DestroyDArray(DArray *DArrayPtr){

	/* Set Entries Used to zero */
	DArrayPtr->EntriesUsed=0;

	/* Set Capacity to zero */
	DArrayPtr->Capacity=0;

	/* De-Allocate the storage for the array elements */
	free(DArrayPtr->Payload);

	/* Set Payload to NULL */
	DArrayPtr->Payload=NULL;

	printf("DArray destroyed and memory freed!");

}
