#include<iostream>

using namespace std;

int merge(int arr[],int i,int j,int p){
	int arr_size_1=p-i+1;
	int arr_size_2=j-p;
    int arr_1[arr_size_1],arr_2[arr_size_2];

    for(int k=0;k<arr_size_1;k++){
    	arr_1[k]=arr[k+i];
    	cout<<arr_1[k]<<" ";
    }
    cout<<"======";
    for(int k=0;k<arr_size_2;k++){
    	arr_2[k]=arr[p+k+1];
    	cout<<arr_2[k]<<" ";
    }
    cout<<"\n";
    int s_1=0;
    int s_2=0;
    int s=i;
    while(s_1<arr_size_1&&s_2<arr_size_2 ){
    	if(arr_1[s_1]>=arr_2[s_2]){
    		arr[s]=arr_2[s_2];
    		s++;
    		s_2++;
    	}
    	else if(arr_1[s_1]<arr_2[s_2]){
    		arr[s]=arr_1[s_1];
    		s_1++;
    		s++;
    	}
    }
    while (s_1< arr_size_1) 
    { 
        arr[s] = arr_1[s_1]; 
        s_1++; 
        s++; 
    } 
    while (s_2 < arr_size_2) 
    { 
        arr[s] = arr_2[s_2]; 
        s_2++; 
        s++; 
    } 
}

void merge_sort(int arr[],int start,int end){
	if(start<end){
		int middle=start+(end-start)/2;
		cout<<start<<" "<<middle<<" "<<end<<"\n";
		merge_sort(arr,start,middle);
		merge_sort(arr,middle+1,end);
		merge(arr,start,end,middle);
	}
}


int main(){
	int a[]={1,2,3,4,5,0,0};
	merge_sort(a,0,6);
	//merge(a,2,3,2);
	for (int i = 0; i < 7; ++i)
	{
		cout<<a[i]<<"  ";
	}
}