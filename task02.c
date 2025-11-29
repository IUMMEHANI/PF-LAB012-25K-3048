#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	int i;
	printf("Enter array's size: ");
	scanf("%d" , &n);
	int *array = (int*)malloc(n*sizeof(int));
	printf("Enter array's elements.\n");
	for (i=0 ; i<n ; i++){
		scanf("%d" , &array[i]);
	}
	printf("\nEntered array is:\n");
	for (i=0 ; i<n ; i++){
		printf(" %d " , array[i]);
	}
	int m = 2*n;
	array = (int*)realloc(array,m*sizeof(int));
	printf("\nEnter another elements of updated array: \n");
	for (i=n ; i<m ; i++){
		scanf("%d",&array[i]);
	}
	printf("Updated array is:\n");
	for (i=0 ; i<m ; i++){
		printf(" %d " , array[i]);
	}
	free(array);
	return 0;
}
