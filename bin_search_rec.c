#include<stdio.h>

void bsr(int a[], int low, int high, int item)
{
  if(low<=high)
  {
    int mid = (low+high)/2;

    if(a[mid] == item)
    {
      printf("Item found at position %d", mid+1);
      return;
    }

    else if(a[mid] > item)
    {
      bsr(a, low, mid-1, item);
    }

    else
    {
      bsr(a, mid+1, high, item);
    }
  }

  else
  {
    printf("Item not found");
  }
}

int main()
{
  int item, a[20], n;
  scanf("%d", &n);

  for(int i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }

  scanf("%d", &item);
  bsr(a, 0, n-1, item);

  return 0;
}
