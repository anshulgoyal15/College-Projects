#include<iostream>
using namespace std;

void sort(int arr[],int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0&&key<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}


int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d",arr[i]);
	}
}