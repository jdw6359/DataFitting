#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(int argc, char *argv[]){

	double X, Y;
	while (DataPoints(&X, &Y)==1){
		printf("Data Points\nX: %f\nY: %f\n", X, Y); 
	}
	return 1;
}
