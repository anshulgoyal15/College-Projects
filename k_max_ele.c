#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partiton(int *a, int low, int high)
{
  int pivot = a[low], i = low, j = high;

  while(i<j)
  {
    while(a[i]<=pivot && i<=high)
      i++;

    while(a[j]>pivot && j>=low)
      j--;

    if(i<j)
      swap(&*(a+i), &*(a+j));
  }
  swap(&*(a+low), &*(a+j));
  return j;
}

int k_max(int *a, int low, int high, int k)
{
  if(k>high)
    return -1;

  else if(low<=high)
  {
    int q = partiton(a, low, high);

    if(k==q)
      return *(a+k);

    else if(k<q)
    {
      k_max(a, low, q-1, k);
      return *(a+k);
    }

    else
    {
      k_max(a, q+1, high, k);
      return *(a+k);
    }
  }
  else
    return -1;
}

int main()
{
  int *arr, n, i, k;
  printf("\nEnter the number of elements: ");
  scanf("%d", &n);

  arr = calloc(n, sizeof(int));

  printf("\nEnter the elements: \n");
  for(i=0; i<n; i++)
    scanf("%d", &*(arr+i));

  printf("\nWhat max element? : ");
  scanf("%d", &k);

  printf("\nAns = %d \n", k_max(arr, 0, n-1, (n-1)-(k-1)));

  return 0;
}
