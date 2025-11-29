#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	int n , length ;
	int i,j;
	printf("Enter number of strings you want to enter: ");
	scanf("%d",&n);
	printf("Enter length of string: ");
	scanf("%d",&length);
	getchar();
	char **array = (char**)malloc(n*sizeof(char*));
	for (i=0 ; i<n ; i++){
		array[i] = (char*)malloc((length+1)*sizeof(char));
	}
	for (i=0 ; i<n ; i++){
	   	printf("Enter string %d: " , i+1);
	   	fgets(array[i],length+1,stdin);
	   	array[i][strcspn(array[i],"\n")] = '\0';
	}
	printf("\nEntered strings are: \n");
	for (i=0 ; i<n ;i++){
		printf(" %s " ,array[i]);
	}
	for (i=0 ; i<n-1 ; i++){
		for (j=i+1 ; j<n ; j++){
			if(strcmp(array[i],array[j]) > 0){
				char temp[length+1];
				strcpy(temp,array[i]);
				strcpy(array[i],array[j]);
				strcpy(array[j],temp);
			}
		}
	}
	printf("\nSorted strings: \n");
	for (i=0 ; i<n ; i++){
		printf(" %s " , array[i]);
	}
	for(i=0;i<n;i++){
		free(array[i]);
	}
	free(array);
	return 0;
}

