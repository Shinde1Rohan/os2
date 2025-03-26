#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <limits.h>
#define ARRAY_SIZE 1000
int main(int argc, char** argv)
{
int rank, size, i;
int local_max = INT_MIN;
int global_max;
int array[ARRAY_SIZE];
MPI_Init(NULL, NULL);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
for (i = 0; i < ARRAY_SIZE; i++)
{
array[i] = rand();
}
for (i = 0; i < ARRAY_SIZE / size; i++)
{
if (array[i] > local_max)
{
local_max = array[i];
}
}
MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
if (rank == 0)
{
printf("Global maximum value = %d\n", global_max);
}
MPI_Finalize();
return 0;
}
