#include <iostream>
using namespace std;
int arr[20]={0};
int maxi=20;
int current=0;

int swap(int * a,int * b){
	int c= * a;
	* a = * b;
	* b=c;
}

void bubble(){
  int i=current;

  while(i){
  int part=(i-1)/2;
  int partEle=arr[part];
  	if(partEle<=arr[i]){
      swap(&arr[part],&arr[i]);
      i=part;
  	}
  	else{
  		break;
  	}
  }
}
int insert_heap(int val){
	if(current>=maxi-1){
		return maxi-1;
	}
	else{
		arr[current]=val;
		bubble();
				current++;
	}
}
void make_heap(int root){
   int left=2*root+1;
   int right=2*root+2;
   if(current>left&&current>right){
   if(arr[root]>arr[left]&&arr[root]>arr[right]){
   	return;
   }
   else if(arr[left]>arr[right]){
   	swap(&arr[left],&arr[root]);
   	make_heap(left);
   }
   else if(arr[right]>arr[left]){
   	swap(&arr[right],&arr[root]);
   	make_heap(right);
   }
   }
   else if(current<left&&current>right){
   	swap(&arr[right],&arr[root]);
   	make_heap(right);
   }
   else if(current<right&&current>left){
   	swap(&arr[left],&arr[root]);
   	make_heap(left);
   }
   else if(current<left&&current<right){
   	return;
   }
}
int get_max(){
	int max=arr[0];
	arr[0]=arr[current];
	arr[current]=0;
	current--;
	make_heap(0);
	return max;
}

void heap_sort(){
	int new_array[current]={0};
	int size=current;
	for(int i=0;i<=size;i++){
		new_array[i]=get_max();
	}
	for(int i=0;i<=size;i++){
       arr[i]=new_array[i];
	}
}
int main(){
 insert_heap(7);
 insert_heap(8);
 insert_heap(9);
 insert_heap(2);
 insert_heap(11);
 insert_heap(1);
 insert_heap(2);
 insert_heap(3);
 insert_heap(4);
 insert_heap(5);
 insert_heap(6);
 heap_sort();
 int t=0;
 while(t<11){
 	cout<<arr[t]<<" ";
 	t++;
 }
}