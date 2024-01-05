# MPI Matrix Processing 

## Description

This program demonstrates the use of MPI (Message Passing Interface) to parallelize a computationally heavy task, specifically the computation of the sum of elements in a matrix. The program is designed to compare the execution time of the task with and without MPI, showcasing the potential speedup achieved through parallelization. Additionally, it calculates and prints the speedup factor and percentage improvement.

## Demo Features

- MPI Parallelization: Utilizes MPI to distribute the matrix elements among multiple processes, enabling parallel computation.

- The program prints the execution time for each separate run (in the case of MPI, for each number of processes used).

Using these printouts, we can manually do the following:

- Execution Time Comparison: Measures and compares the execution time of the matrix sum computation with and without MPI.

- Speedup Factor Calculation: Computes the speedup factor achieved through parallelization.

- Percentage Improvement: Calculates and prints the percentage improvement in execution time when using MPI.

# Requirements

- MPI (Message Passing Interface) library
- C++ compiler with MPI support (for compiling MPI version)
- C++ compiler (for compiling non-MPI version)


# Usage

## MPI Compilation

To compile the program with MPI support, use the following command:

```mpic++ -g mpi-matrix-processing.cpp -o mpi-matrix-processing```

Or, with macro definition:

```mpic++ -DUSE_MPI -g mpi-matrix-processing.cpp -o mpi-matrix-processing```

## MPI Execution

To execute the MPI version, use the following command:

`mpirun --oversubscribe -np <number_of_processes> ./mpi-matrix-processing`


For example:

```mpirun --oversubscribe -np 4 ./mpi-matrix-processing```


## Non-MPI Compilation

To compile the program without MPI support, use the following command:

```g++ -g mpi-matrix-processing.cpp -o matrix-processing-no-mpi```


## Non-MPI Execution

To execute the non-MPI version, use the following command:

```./matrix-processing-no-mpi```


# Output examples 

First MPI run, using 4 processes: 

mpirun --oversubscribe -np 4 ./mpi-matrix-processing

Output: 

Execution Time (MPI): 7.55e-07 seconds
Execution Time (MPI): 2.03e-07 seconds
Execution Time (MPI): 1.42e-07 seconds
Execution Time (MPI): 2.02e-07 seconds


Secondly, no-MP run:

./matrix-processing-no-mpi

Output: 

Execution Time (Non-MPI): 8e-06 seconds

## speed up calculation

Calculating speedup (performance) gaind using MPI parallel computation: 


Speedup  =   Execution Time (Non-MPI)​ / Total Execution Time (MPI)

Total Execution Time (MPI) = Execution Time1 ​+ Execution Time2 ​+ Execution Time3 ​+ Execution Time4​

So: 

Total Execution Time (MPI) = (7.55e−07 + 2.03e−07 + 1.42e−07 + 2.02e−07) seconds

Total Execution Time (MPI) ~ 1.4e−06 seconds

Speedup = 8e−06 / 1.4e−06  ~ 5.71

So, the overall speedup achieved by using MPI compared to the non-MPI version in this example was approximately 5.71 times.


# Matrix Size Configuration

The program generates a random matrix for demonstration purposes, and the matrix size is reduced for debugging. You can modify the matrix_size constant in the source code to adjust the size of the matrix.

const int matrix_size = 10;  // Adjust the matrix size for debugging

## Notes

- The MPI code section is marked with #ifdef USE_MPI. Ensure to define the macro USE_MPI during compilation to enable MPI features.
    
- The program generates a random matrix, and the size is reduced for debugging purposes. Adjust the matrix_size constant to change the size of the matrix.
    
- The execution time for both MPI and non-MPI versions is printed to the console for performance analysis.
    
- The MPI-related code is enclosed within preprocessor directives, allowing easy switching between MPI and non-MPI versions during compilation.


## License

The mpi-matrix-processing program is licensed under the [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/).

![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)


## Author 

Babak Mahdavi Ardestani

babak.m.ardestani@gmail.com
