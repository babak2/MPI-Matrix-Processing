/*
 * MPI Matix Processing program
 * 
 * Description:
 *   This program demonstrates the use of MPI (Message Passing Interface) to parallelize
 *   a computationally heavy task, specifically the computation of the sum of elements
 *   in a matrix. The program is designed to compare the execution time of the task
 *   with and without MPI, showcasing the potential speedup achieved through parallelization.
 *   Additionally, it calculates and prints the speedup factor and percentage improvement.
 * 
 * Compilation (MPI):
 *   mpic++ -g mpi-matrix-processing.cpp -o mpi-matrix-processing
 *   Or: 
 *   mpic++ -DUSE_MPI -g mpi-matrix-processing.cpp -o mpi-matrix-processing
 *
 * Execution (MPI):
 *   mpirun --oversubscribe -np <number_of_processes> ./mpi-matrix-processing
 *   Example: 
 *   mpirun --oversubscribe -np 4 ./mpi-matrix-processing
 * 
 * Compilation (Non-MPI):
 *   g++ -g mpi-matrix-processing.cpp -o matrix-processing-no-mpi
 * 
 * Execution (Non-MPI):
 *   ./mpi-matrix-processing
 * 
 * Author: Babak Mahdavi Ardestani
 * Date: 8 November 2023
 * 
 * Notes:
 *   - The program generates a random matrix for demonstration purposes, and the matrix
 *     size is reduced for debugging. You can modify the 'matrix_size' constant to
 *     adjust the size of the matrix.
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iomanip>  // Add this line for setprecision

#ifdef USE_MPI
#include <mpi.h>
#endif

const int matrix_size = 10;  // Reduced matrix size for debugging

void fillMatrix(double matrix[matrix_size][matrix_size]) {
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

double computeSum(const double matrix[matrix_size][matrix_size], int start, int end) {
    double sum = 0.0;
    for (int i = start; i < end; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main(int argc, char** argv) {

#ifdef USE_MPI
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double matrix[matrix_size][matrix_size];
    fillMatrix(matrix);

    MPI_Barrier(MPI_COMM_WORLD);
    double start_time_mpi = MPI_Wtime();

    // MPI code...

    double end_time_mpi = MPI_Wtime();
    double execution_time_mpi = end_time_mpi - start_time_mpi;

    std::cout << "\n";
    std::cout << "Execution Time (MPI): " << execution_time_mpi << " seconds" << std::endl;
    //std::cout << "Execution Time (MPI): " << execution_time_mpi << " seconds";

    MPI_Finalize();

#else
    // Non-MPI code...
    double start_time_non_mpi = std::clock();

    double matrix[matrix_size][matrix_size];
    fillMatrix(matrix);

    // Print matrix for debugging
    /*std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    } */

    double end_time_non_mpi = std::clock();
    double execution_time_non_mpi = (end_time_non_mpi - start_time_non_mpi) / CLOCKS_PER_SEC;

    std::cout << "Execution Time (Non-MPI): " << execution_time_non_mpi << " seconds" << std::endl;
#endif

    return 0;
}
