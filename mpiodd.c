#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define SIZE 1000
int main(int argc, char** argv) 
{
int rank, size, i;
double sum = 0.0, local_sum = 0.0;
double data[SIZE];
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
for (i = 0; i < SIZE; i++)
{
data[i] = (double) 2*rand()+1 / RAND_MAX;
}
for (i = 0; i < SIZE/size; i++)
{
local_sum += data[i];
}
MPI_Reduce(&local_sum,&sum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if (rank == 0) {
printf("Sum = %d\n", (int)sum);
}
MPI_Finalize();
return 0;
}
