#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "DynamicArrays.h"

#define InitialCapacity 20

int main(int argc, char *argv[]){

	/* Initialize double values X and Y that will store the point values
	returned from the call to Data Points */
	double X, Y;

	/* Initialize variable for Dynamic Array */
	DArray array;

	/* Call CreateDArray to initialize array */
	CreateDArray(&array, InitialCapacity);

	/* output from CreateDArray */
	printf("Entries Used: %d\n", array.EntriesUsed);
	printf("Capacity: %d\n", array.Capacity);


	while (DataPoints(&X, &Y)==1){
		/* printf("Data Points\nX: %f\nY: %f\n", X, Y);*/

		/* Initialize Data Object */
		Data point;
		point.X=X;
		point.Y=Y;
		printf("Point Created\n");
		PushToDArray(&array, &point);



		/* Add data point to Array */


	}

	/* Return 1 to the operating system */
	return 1;
}
