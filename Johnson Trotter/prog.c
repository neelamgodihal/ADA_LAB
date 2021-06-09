#include <stdio.h>
#include <time.h>

void display(int arr[],int n){
  int i;
  for(i=0; i<n; i++)
    printf("%d ",arr[i]);
  printf("\n");
}

void swap(int *p, int *q){
  int temp = *p;
  *p = *q;
  *q = temp;
}

void swapdir(char *p, char *q){
  char temp = *p;
  *p = *q;
  *q = temp;
}

int largestmobilenumber(int n,int arr[],char dir[],int max){
  int i;
  if(arr[0] == max && dir[0] == 'l'){
    dir[0] = 'r';
    return largestmobilenumber(n,arr,dir,max-1);
  }
  else if(arr[n-1] == max && dir[n-1] == 'r'){
    dir[n-1] = 'l';
    return largestmobilenumber(n,arr,dir,max-1);
  }
  for(i=0; i<n; i++){
    if(arr[i] == max){
      if((dir[i]=='l' && arr[i]>arr[i-1]) || (dir[i]=='r' && arr[i]>arr[i+1]))
        return i;
      else{
        if(dir[i] == 'l') 
          dir[i] = 'r';
        else
          dir[i] = 'l';
        return largestmobilenumber(n,arr,dir,max-1);
      }
    }
  }
  return -1;
}

void permutations(int n){
  int i,arr[n];
  char dir[n];
  for(i=0; i<n; i++){
    arr[i] = i+1;
    dir[i] = 'l';
  }
  while(i != -1){
    display(arr,n);
    i = largestmobilenumber(n,arr,dir,n);
    if(i != -1){
      if(dir[i] == 'r'){
        swap(&arr[i],&arr[i+1]);
        swapdir(&dir[i],&dir[i+1]);
      }
      else{
        swap(&arr[i],&arr[i-1]);
        swapdir(&dir[i],&dir[i-1]);
      }
    }
  }
}

int main(void){
  int n;
  clock_t starttime,endtime;
  double efftime;
  scanf("%d",&n);
  starttime = clock();
  permutations(n);
  endtime = clock();
  efftime = ((double)(endtime - starttime))/CLOCKS_PER_SEC;
  printf("Time taken : %lf\n",efftime);
  return 0;
}
