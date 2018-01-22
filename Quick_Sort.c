#include<stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
	int pivot= a[high];
	int i=low-1, j;
	for(j=low; j<= high-1; j++){
		if(a[j]<= pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return(i+1);

}

void quicksort(int a[], int low, int high){
	if(low<high)
	{
		int pi= partition(a,low,high);

		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
}
void printarray(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void main()
{
	int i, n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int* a = malloc(sizeof(int)* n);
	for(i=0;i<n;i++){
		printf("Enter Element %d: ", i+1);
		scanf("%d",&a[i]);
	}
	printf("Unsorted Array is: ");
	printarray(a, n);
	quicksort(a,0,n-1);
	printf("Sorted Array is: ");
	printarray(a,n);
}