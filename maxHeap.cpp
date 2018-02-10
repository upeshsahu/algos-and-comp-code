#include<bits/stdc++.h>
using namespace std;

#define N 1000002

int arr[N],heap_size=0;

void maxHeapify(int i){
	
   int l=2*i;
   int r=2*i+1;

   int largest=i;

   if(l<=heap_size && arr[l]>arr[i])
      largest=l;

   if(r<=heap_size && arr[r]>arr[largest])
      largest=r;

   if(largest!=i){

      swap(arr[i],arr[largest]);
      maxHeapify(largest);

   }


}

void buildMaxHeap(){
	
   printf("Enter number of items to be entered in max heap\n");

   scanf("%d",&heap_size);

   printf("Enter items to be inserted in max heap\n");

   for(int i=1;i<=heap_size;++i)
      scanf("%d",&arr[i]);

   for(int i=heap_size/2;i>=1;--i){

      maxHeapify(i);

   }
   
   printf("Max Heap succesfully built\n");

}

void insert(){
	
   printf("Enter element to be inserted in maxHeap\n");

   int x;

   scanf("%d",&x);

   heap_size++;

   arr[heap_size]=x;

   int i=heap_size;

   while(i>1){

      if(arr[i/2]<arr[i]){

          swap(arr[i/2],arr[i]);
          i=i/2;

      }
      else
        break;
      

   }

   printf("Element inserted in heap\n");

}

void extractMax(){
	 
   if(heap_size>0)
     printf("Maximum element of heap is %d\n",arr[1]);

   else
     printf("Heap currently empty\n");


}

void deleteMax(){
	
    if(heap_size>0){

       swap(arr[1],arr[heap_size]);
       heap_size--;
       maxHeapify(1);

      // printf("Max element of heap is %d\n",arr[heap_size+1]);

      // printf("Max element successfully deleted\n");

    }
    else
      printf("Heap is currently empty\n");


}

void increaseKey(){

   int i,key;
   printf("Enter index at which you want to decrease key\n");
   cin>>i;

   printf("Enter new key\n");
   cin>>key;

   if(i<=heap_size){

      if(key<arr[i]){

        printf("Enter an key greater than current value\n");

      }

      else{

         arr[i]=key;
         
         while(i>1 && arr[i/2]<arr[i]){

            swap(arr[i],arr[i/2]);
            i=i/2;

         }

         printf("Key correctly increased\n");
 
      }
   }
   else{

      printf("No such index currently in the heap\n");

   }


}

void decreaseKey(){
	int i,key;
	printf("Enter index at which you want to decrease key\n");
    cin>>i;

    printf("Enter new key\n");
    cin>>key;


   if(i<=heap_size){

      if(key>arr[i]){

         printf("Enter a key less than current element\n");

 
      }

      else{

        arr[i]=key;

        maxHeapify(i);


      }



   }

   else{

      printf("No such index currently in the heap\n");

   }


}

void heapSort(){
 
   int n=heap_size;

   while(heap_size!=0){

      deleteMax();
   }

   printf("Elements in increasing order\n");

   heap_size=n;

   for(int i=1;i<=heap_size;++i){

      cout<<arr[i]<<" ";

   }

   cout<<"\n";

   // Rebuild heap in order for next queries to succesfully happen

   heap_size=n;

   for(int i=heap_size/2;i>=1;--i){

      maxHeapify(i);

   }

   

}

int main(){
 
   int choice=0;

   while(choice!=8){

      printf("Enter your choice\n");
      printf("1-Build MaxHeap\n");
      printf("2-Insert in MaxHeap\n");
      printf("3-Extract-Max in MaxHeap\n");
      printf("4-Delete-Max in MaxHeap\n");
      printf("5-Increase-Key in MaxHeap\n");
      printf("6-Decrease-Key in MaxHeap\n");
 
      printf("7-Heapsort\n");
      printf("8-Exit\n");

      cin>>choice;

      switch(choice){

         case 1:
           buildMaxHeap();
           break;
         case 2:
           insert();
           break;
         case 3:
           extractMax();
           break;
         case 4:
           deleteMax();
           break;
         case 5:
           increaseKey();
           break;
         case 6:
           decreaseKey();
           break;
         case 7:
           heapSort();
           break;
         case 8:
           exit(0);
         default:
           printf("Invalid choice\n");
           break;
      }

      printf("\n\n");

   }

   return 0;
}
