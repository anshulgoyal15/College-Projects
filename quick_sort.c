#include<stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partiton(int a[], int low, int high)
{
  int pivot = a[low], i = low, j = high;

  while(i<j)
  {
    while(a[i]<=pivot && i<=high)
      i++;

    while(a[j]>pivot && j>=low)
      j--;

    if(i<j)
      swap(&a[i], &a[j]);
  }
  swap(&a[low], &a[j]);
  return j;
}

void quickSort(int a[], int low, int high)
{
  if(low<=high)
  {
    int q = partiton(a, low, high);

    quickSort(a, low, q-1);
    quickSort(a, q+1, high);
  }
}

int main()
{
  int a[30], n, i;
  printf("\nEnter the number of elements: ");
  scanf("%d", &n);

  printf("\nEnter the elements: \n");
  for(i=0; i<n; i++)
    scanf("%d", &a[i]);

  quickSort(a, 0, n-1);

  printf("\nThe sorted array is: \n");
  for(i=0; i<n; i++)
    printf("%d\t", a[i]);

  printf("\n");

  return 0;
}
