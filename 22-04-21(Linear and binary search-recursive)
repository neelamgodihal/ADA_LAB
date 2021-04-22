#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int lin_rec(int ele,int n,int index,int arr[]){
	int pos=0;
	
	if(index==n)
		return -1;
	else if(arr[index]==ele){
		pos=index+1;
		return pos;
	}
	else{
		return lin_rec(ele,n,index+1,arr);
	}
	//return pos;
}

int bin_rec(int l, int r, int ele,int arr[])
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
  
        if (arr[mid] == ele)  return mid;
		
        if (arr[mid] > ele) return bin_rec( l, mid-1, ele,arr);
  
        return bin_rec( mid+1,r,ele,arr);
   }
   return -1;
}

int main(){
	int n,ele,pos;
	clock_t start_t,end_t;
	double total_t;
	
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		arr[i]=rand()%50;
	}
	
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
	printf("\nEnter the element to be searched\n");
	scanf("%d",&ele);
	
	start_t=clock();
	pos=lin_rec(ele,n,0,arr);
	end_t=clock();
	total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
	
	printf("------LINEAR SEARCH------\n");
	if(pos==-1)
		printf("Linear search unsuccessful!No such element found!\n");
	else
		printf("Element is found at %d\n",pos);

	printf("The total time taken for linear search is %fs\n",total_t);
	
	//printf("Binary search\n");
	
	printf("------BINARY SEARCH------\n");
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	start_t=clock();
	printf("%lu\n",start_t);
	pos=bin_rec(0,n-1,ele,arr);
	end_t=clock();
	printf("%lu\n",end_t);
	total_t=(end_t-start_t)/CLOCKS_PER_SEC;
	
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
	if(pos==-1)
		printf("\nBinary search unsuccessful!No such element found!\n");
	else
		printf("\nElement is found at %d\n",pos+1);

	printf("The total time taken for binary search is %fs\n",total_t);	
}
