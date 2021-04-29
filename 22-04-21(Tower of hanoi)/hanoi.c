#include <stdio.h>

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("\n Move disk %d from rod %c to rod %c", n, from, to);
    hanoi(n-1, aux, to, from);
}
 
int main()
{
    int n;
	printf("Enter the number of disks\n");
	scanf("%d",&n);
    hanoi(n, 'A', 'C', 'B');  //names of the rods
    return 0;
}
