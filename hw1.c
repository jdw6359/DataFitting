#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "DynamicArrays.h"

#define INITIAL_CAPACITY 0

void ComputeCoefficients(double *A, double *B, DArray *DArrayPtr){

	/* Initialize variables to hold computations */
	double S_XX = 0.0;
	double S_XY = 0.0;
	double S_X = 0.0;
	double S_Y = 0.0;


	/* Variable to keep track of index while looping */
	int counter;

	for(counter=0;counter < DArrayPtr->EntriesUsed; counter++){

		/* Increment temporary sums of X Y combonations */
		S_XX += DArrayPtr -> Payload[counter].X * DArrayPtr -> Payload[counter].X;
		S_XY += DArrayPtr -> Payload[counter].X * DArrayPtr -> Payload[counter].Y;
		S_X += DArrayPtr -> Payload[counter].X;
		S_Y += DArrayPtr -> Payload[counter].X;

		/* Compute the coefficients */
		/* Compute the constant */
		*B = (((S_XX * S_Y) - (S_XY * S_X)) / ((DArrayPtr->EntriesUsed * S_XX) - (S_X * S_X)));

		/* Compute the linear coefficient */
		*A = (((DArrayPtr->EntriesUsed * S_XY) - (S_X * S_Y)) / ((DArrayPtr->EntriesUsed * S_XX) - (S_X * S_X)));



	}





}





int main(int argc, char *argv[]){

	/* Initialize double values X and Y that will store the point values
	returned from the call to Data Points */
	double X, Y;

	/* Initialize double values A and B that represent the coefficients for
	the line of best fit. Passed into ComputeCoefficients by refence */
	double A, B;

	/* Variable that represents the index of the last element added to Payload */
	unsigned int Index;

	/* Initialize variable for Dynamic Array */
	DArray array;

	/* Call CreateDArray to initialize array */
	CreateDArray(&array, INITIAL_CAPACITY);

	while (DataPoints(&X, &Y)==1){

		/* Initialize Data Object With values from DataPoints function */
		Data point;
		point.X=X;
		point.Y=Y;

		/* Send the data point to the dynamic array */
		Index=PushToDArray(&array, &point);

		/* Add data point to Array */
	}

	printf("Index is %d!\n", Index);
	printf("Values at index!!!!!!\nX: %f\nY: %f\n", array.Payload[Index].X, array.Payload[Index].Y);

	/* Compute the coefficients (Stores both A AND B) */
	ComputeCoefficients(&A, &B, &array);

	printf("The line is: Y= %f * X + %f\n", A, B);
	printf("There were %d points in the data set\n", array.EntriesUsed);




	DestroyDArray(&array);

	/* Return 1 to the operating system */
	return 1;
}
