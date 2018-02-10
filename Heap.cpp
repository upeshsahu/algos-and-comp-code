/* Menu Driven Program to visualise Binary Heap Procedures 
  
   1) Build Min-Heap 
   2) Insert
   3) Extract-min
   4) Delete-min
   5) Heapsort
   6) Exit

*/

#include<bits/stdc++.h>
using namespace std;

#define N 1000002

int arr[N],heap_size=0;

void heapify(int i){

    int left=2*i;
    int right=2*i+1;

    int smallest;

    if(left<=heap_size && arr[left]<arr[i])
    	 smallest=left;

    else
         smallest=i;

    if(right<=heap_size && arr[right]<arr[smallest])
         smallest=right;

    if(smallest!=i){

         
         swap(arr[i],arr[smallest]);
         heapify(smallest);

    }          	

}

void buildMinHeap(){

    printf("Enter number of items to be entered in min heap\n");
    int i;

    scanf("%d",&heap_size);

    printf("Enter items to be inserted in minHeap\n");

    for(i=1;i<=heap_size;++i){
 
        scanf("%d",&arr[i]);

    }

    for(i=heap_size/2;i>=1;--i){

         heapify(i);
    }

    printf("Heap successfully built\n");

}

void insert(){

    printf("Enter element to insert in minHeap\n");

    int x;

    scanf("%d",&x);

    heap_size++;

    arr[heap_size]=x;

    int i=heap_size;

    int parent;

    while(i>=1){

        parent=i/2;
 
        if(arr[parent]>arr[i]){
 
            swap(arr[parent],arr[i]);
            i=parent;
        }

        else{
           break;
        }
        
    }

    printf("Element inserted in heap\n");

}

void extractMin(){

    if(heap_size>0){

         printf("Minimum element of heap is %d\n",arr[1]);

    }

    else{

         printf("Heap currently empty\n");
    }


}

void deleteMin(){

    if(heap_size>0){
         
        swap(arr[1],arr[heap_size]);
        heap_size--;
        heapify(1);

        printf("Minimum element of heap is %d\n",arr[heap_size+1]);
        printf("Minimum element of successfully deleted\n");

    }

    else 
       printf("Heap is currently empty\n");

}

int main(){

     int choice=0;


     while(choice!=6){

	     printf("Enter your choice\n");
	     printf("1-Build Min Heap\n");
	     printf("2-Insert in MinHeap\n");
	     printf("3-Extract-Min in MinHeap\n");
	     printf("4-Delete-Min in MinHeap\n");
	     printf("5-Heapsort\n");
	     printf("6-Exit\n");

	     scanf("%d",&choice);

	     switch(choice){

             case 1:
                buildMinHeap();
                break;
             case 2:
                insert();
                break;
             case 3:
                extractMin();
                break;
             case 4:
                deleteMin();
                break;
             case 5:
               // heapSort();
                break;           
             case 6:
                exit(0);                 
             case 7:
                printf("Invalid choice\n");

	      }

	      printf("\n\n");

     }

	return 0;
}
