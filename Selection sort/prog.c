#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int min(int arr[],int l,int r){
  int minval = pow(2,31)-1;
  int minindex = -1;
  for(int i=l; i<=r; i++){
    if(arr[i] < minval){
      minval = arr[i];
      minindex = i;
    }
  }
  return minindex;
}

void selectionsort(int arr[],int l,int r){
	  int temp,k;
	  if(l == r)
		return;
	  k = min(arr,l,r);
	  if(l != k){
		temp = arr[l];
		arr[l] = arr[k];
		arr[k] = temp;
  }
  selectionsort(arr,l+1,r);
}

int main(int argc,char **argv){
	  int n,i;
	  clock_t starttime,endtime;
	  printf("Enter the size\n");
	  scanf("%d",&n);
	  int arr[n];
	  
	  for(i=0; i<n; i++)
		arr[i] = (rand()%50)+1;
		
	  starttime = clock();
	  selectionsort(arr,0,n-1);
	  endtime = clock();
	  
	  double time = ((double)(endtime-starttime)/CLOCKS_PER_SEC);
	  
	  for(i=0; i<n; i++)
		printf("%d\t",arr[i]);
	  printf("\nTime complexity of selectionsort:%f\n",time);
	  return 0;
}
