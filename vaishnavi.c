#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define NUM_NUMBERS 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int numbers[NUM_NUMBERS];
    int local_min, local_max;
    int global_min, global_max;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Seed random number generator differently for each process
    srand(time(NULL) + rank);

    // Generate random numbers (only for rank 0 for simplicity)
    if (rank == 0) {
        for (int i = 0; i < NUM_NUMBERS; i++) {
            numbers[i] = rand() % 1000;  // Random numbers between 0 and 999
        }
    }

    // Distribute nu

