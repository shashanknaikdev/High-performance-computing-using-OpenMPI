#include<stdio.h>
#include "mpi.h"

 void compute(int size, int rank, int start , int range, int pwd);

int main (int argc,char *argv[])
{
  int rank, size,range,start,end;
  
  MPI_Init(&argc, &argv);
  
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  

  
   int no;
    int tran_array[10000];
   
    long l_limit=0, u_limit=999999, pwd;
   
   
  if(rank==0)
  {
      printf("%d compute nodes detected... \n \n ", size);
  
  printf("rank %d of %d currently active... \n", rank, size);
  
  printf("\n \n");
    
    printf("\n");
    printf("ENTER THE PASSWORD .. ??\n");
   scanf("%d",&pwd);  
  
   
    int a, b,c,d,e ;
  float z;
  
  range=u_limit/size;
             
  
  /******** READ
  
  shall have an array of nodes, with size=np_of_nodes.
  array will hold the value of cpu utilization
  apply function to return k elements of smallest value (k=no of sub-transactions)
  call mPI_SEND , in a loop woth dynamic value of reciever address
  
  
  
  */
  
  int i1;
  for ( i1=0 ; i1<size ; i1++)
  {
  start=i1*range;
  end=start+range;
  MPI_Send(&pwd,1,MPI_INT,i1,0, MPI_COMM_WORLD);
   MPI_Send(&start,1,MPI_INT,i1,0, MPI_COMM_WORLD);
   MPI_Send(&end,1,MPI_INT,i1,0, MPI_COMM_WORLD);
   
  // printf("sent start =%d to %d\n\n",start, i1);
  }
  /*
  
  //for (a=-3200;a<3200;a++)
    for (b=-32000;b<32000;b++) 
      for (c=0;c<3200;c++)
  	for(d=range*rank;d<=range*rank+range;d++)
{
      z=123.32/2342.543*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342;    
  
}
    */  
      
 
  
  
  
  
  
   // printf("rank %d of %d currently active... \n", rank, size);
  
  MPI_Recv(&pwd,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  MPI_Recv(&start,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  MPI_Recv(&end,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   
 // printf(" recieved rank = %d start=%d \n",rank, start);
  // printf(" recieved rank = %d end=%d \n\n",rank, end);
   
   compute(size, rank, start, end, pwd);
   
   
   printf("DONE !!! %d of %d \n", rank, size);
  MPI_Finalize();
  return 0;
}

else
{
  printf("rank %d of %d currently active... \n", rank, size);
  
  MPI_Recv(&pwd,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  MPI_Recv(&start,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  MPI_Recv(&end,1,MPI_INT,0,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  
   //printf(" recieved rank = %d start=%d \n",rank, start);
 //  printf(" recieved rank = %d end=%d \n\n",rank, end);
   
   
   
   compute(size, rank, start, end, pwd);
   
   
 printf("DONE !!! %d of %d \n", rank, size);
  MPI_Finalize();
  return 0;
}
  
}






void compute(int size, int rank, int start , int end, int pwd)
{
  if(rank==size-1)
    end=999999;
  
 printf(" OPERATING RANK= %d \n",rank);
 printf("Trying combinations from %d to %d \n \n \n", start, end);
 //printf("size=%d    pwd=%d   \n", size, pwd);
 
 
 long a,b,c,i2;
 float z;
 
 for( i2=start; i2<=end; i2++)
 {
  //////   printf("     i2 = %d      ",i2);
   if(i2==pwd) 
   {
     printf("FOUND THE PASSWORD in rank=%d, IT IS %d \n",rank,i2);
     MPI_Abort(MPI_COMM_WORLD, 1);
   }
 
 
 else
 //for (a=-0;a<320;a++)
    for (b=-320;b<32000;b++) 
	//for (c=0;c<3200;c++)
	// 	for(d=range*rank;d<=range*rank+range;d++)
	{
	//printf("for loop of rank = %d", rank);
	//z=123.32/2342.543*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342*2343.43/123.43*890.123/623.342;    
  
	}
 
 
 {
 
 
}
 }
printf("Rank %d operation ends\n\n\n",rank);}