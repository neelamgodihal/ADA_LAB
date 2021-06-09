#include<stdio.h>
#include <stdlib.h>
#include<time.h>

void quicksort(int arr[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);

   }
}

int main(){
    int n;
	clock_t start_t,end_t;
	double total_t;
	
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		arr[i]=rand()%50;
	}
	
	printf("The array is:");
	for(int i=0;i<n;i++)
      printf(" %d",arr[i]);

	start_t=clock();
   quicksort(arr,0,n-1);
   end_t=clock();
	total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
	
	printf("\nThe time taken is %f\n",total_t);

   printf("Order of Sorted elements: ");
   for(int i=0;i<n;i++)
      printf(" %d",arr[i]);

   return 0;
}
