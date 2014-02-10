#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "DynamicArrays.h"

#define INITIAL_CAPACITY 0

int main(int argc, char *argv[]){

	/* Initialize double values X and Y that will store the point values
	returned from the call to Data Points */
	double X, Y;

	int counter=0;

	unsigned int Index;

	/* Initialize variable for Dynamic Array */
	DArray array;

	/* Call CreateDArray to initialize array */
	CreateDArray(&array, INITIAL_CAPACITY);

	/* output from CreateDArray */
	printf("Entries Used: %d\n", array.EntriesUsed);
	printf("Capacity: %d\n", array.Capacity);

	while (DataPoints(&X, &Y)==1){

		/* Initialize Data Object With values from DataPoints function */
		Data point;
		point.X=X;
		point.Y=Y;

		/* Send the data point to the dynamic array */
		Index=PushToDArray(&array, &point);
		counter++;



		/* Add data point to Array */


	}
	printf("values at index 0\nX: %f\nY: %f\n",array.Payload[0].X, array.Payload[0].Y);
	printf("counter: %d\n", counter);

	printf("Index is %d!\n", Index);
	printf("Values at index!!!!!!\nX: %f\nY: %f\n", array.Payload[Index].X, array.Payload[Index].Y);



	DestroyDArray(&array);

	/* Return 1 to the operating system */
	return 1;
}
