#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main(){
	int n;
	clock_t start_t,end_t;
	double total_t;
	
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		arr[i]=rand()%50;
	}
	
	printf("The array elements are:\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
	start_t=clock();
	insertSort(arr, n);
	end_t=clock();
	total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
	
	printf("\nThe time taken is %f\n",total_t);
	
	printf("The array elements are:\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

