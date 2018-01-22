//C Implementation of Merge sort Algorithm

#include<stdio.h>

void merge(int a[], int start, int middle, int end){
	int size1= (middle-start)+1;
	int size2= (end-middle);
	int i, j,k;
	//Create Temporary array and copy data to them
	int Start[size1], End[size2];
	for(i=0; i<size1; i++)
			Start[i]= a[start+i];
	for(j=0; j<size2; j++)
		End[j]=a[middle+1+j];

	i=0;
	j=0;
	k=start;
	//Merge everything back to one array
	while(i<size1 && j<size2){
		if(Start[i]<=End[j]){
			a[k]=Start[i];
			i++;
			k++;
		}
		else{
			a[k]=End[j];
			j++;
			k++;
		}
	}

	//Rest elements in array
	while(i<size1){
		a[k]=Start[i];
		i++;
		k++;
	}
	while(j<size2){
		a[k]=End[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int start, int end){
	int middle;
	if(start<end){
		//Divide and Conquer
		middle= start+(end-start)/2;
		mergesort(a,start,middle);	//First Half
		mergesort(a,middle+1,end);  //Second Half
		merge(a,start,middle,end);	//Merge Together

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
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Unsorted Array is: ");
	printarray(a, n);
	mergesort(a,0,n-1);
	printf("Sorted Array is: ");
	printarray(a,n);
}
