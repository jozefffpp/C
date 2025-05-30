#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <time.h>

#define MAT_SIZE 4	//rozmer matice
#define BLOCK_SIZE 2	//rozmer bloku

//matice sú uložené v row-major formáte
//M(row, col) = *(M.elements + row * M.stride + col)
typedef struct {
  int width;
  int height;
  int stride; 
  float* elements;
} Matrix;

//prečítaj hodnotu prvku matice
__device__ float GetElement(const Matrix A, int row, int col)
{
  return A.elements[row * A.stride + col];
}

//zapíš hodnotu prvku matice
__device__ void SetElement(Matrix A, int row, int col,
                           float value)
{
  A.elements[row * A.stride + col] = value;
}

//načítaj blok matice
 __device__ Matrix GetSubMatrix(Matrix A, int row, int col) 
{
  Matrix Asub;
  Asub.width    = BLOCK_SIZE;
  Asub.height   = BLOCK_SIZE;
  Asub.stride   = A.stride;
  Asub.elements = &A.elements[A.stride * BLOCK_SIZE * row + BLOCK_SIZE * col];
  return Asub;
}

//kernel pre násobenie matíc
 __global__ void MatMulKernel(Matrix A, Matrix B, Matrix C)
{
  //identifikácia bloku
  int blockRow = blockIdx.y;
  int blockCol = blockIdx.x;

  //podmatica počitana v bloku
  Matrix Csub = GetSubMatrix(C, blockRow, blockCol);

  //hodnota prvku matice C počítaná vláknom
  float Cvalue = 0;

  //identifikácia vlákna
  int row = threadIdx.y;
  int col = threadIdx.x;

  //cyklus cez všetky podmatice 
  for (int m = 0; m < (A.width / BLOCK_SIZE); ++m) {

    //získanie parametrov podmatíc A a B
    Matrix Asub = GetSubMatrix(A, blockRow, m);
    Matrix Bsub = GetSubMatrix(B, m, blockCol);

    //zdieľaná pamäť na uloženie blokov Asub a Bsub
    __shared__ float As[BLOCK_SIZE][BLOCK_SIZE];
    __shared__ float Bs[BLOCK_SIZE][BLOCK_SIZE];

    //prenos podmatíc z globálnej do zdieľanej pamäte
    As[row][col] = GetElement(Asub, row, col);
    Bs[row][col] = GetElement(Bsub, row, col);

    //synchronizácia vlákien
    __syncthreads();

    //násobenie Asub a Bsub
    for (int e = 0; e < BLOCK_SIZE; ++e)
      Cvalue += As[row][e] * Bs[e][col];

    //synchronizácia vlákien
    __syncthreads();
  }

  //zápis výslednej hodnoty prvku
  SetElement(Csub, row, col, Cvalue);
}

//hostiteľská časť programu
void MatMul(const Matrix A, const Matrix B, Matrix C)
{
  //alokácia pamäte zariadenia GPGPU
  Matrix d_A;
  d_A.width = d_A.stride = A.width; d_A.height = A.height;
  size_t size = A.width * A.height * sizeof(float);
  cudaMalloc(&d_A.elements, size);
  //kopírovanie údajov do GPGPU pamäte
  cudaMemcpy(d_A.elements, A.elements, size, cudaMemcpyHostToDevice);

  //alokácia pamäte zariadenia GPGPU
  Matrix d_B;
  d_B.width = d_B.stride = B.width; d_B.height = B.height;
  size = B.width * B.height * sizeof(float);
  cudaMalloc(&d_B.elements, size);
  //kopírovanie údajov do GPGPU pamäte
  cudaMemcpy(d_B.elements, B.elements, size, cudaMemcpyHostToDevice);

  //alokácia pamäte zariadenia GPGPU
  Matrix d_C;
  d_C.width = d_C.stride = C.width; d_C.height = C.height;
  size = C.width * C.height * sizeof(float);
  cudaMalloc(&d_C.elements, size);

  //volanie kernelu
  dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
  dim3 dimGrid(B.width / dimBlock.x, A.height / dimBlock.y);
  MatMulKernel<<<dimGrid, dimBlock>>>(d_A, d_B, d_C);

  //synchronizácia - dokončenie kernelu
  cudaDeviceSynchronize();

  //kopírovanie údajov z GPGPU pamäte
  cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);

  //uvoľnenie pamäte zariadenia GPGPU
  cudaFree(d_A.elements);
  cudaFree(d_B.elements);
  cudaFree(d_C.elements);
}

int main()
{
  srand(time(NULL));
  //alokácia pamäte pre matice A, B, C
  Matrix A, B, C;
  A.width = A.height = A.stride = MAT_SIZE;
  B.width = B.height = B.stride = MAT_SIZE;
  C.width = C.height = C.stride = MAT_SIZE;
  A.elements = (float*) malloc(A.height * A.width * sizeof(float));
  B.elements = (float*) malloc(B.height * B.width * sizeof(float));
  C.elements = (float*) malloc(C.height * C.width * sizeof(float));

  //inicializácia matíc A, B a nulovanie C
  int i,j;
  for(i = 0; i < MAT_SIZE; i++){
    for(j = 0; j < MAT_SIZE; j++){
      A.elements[i * A.stride + j] = rand() % 10;
      B.elements[i * B.stride + j] = rand() % 10;
      C.elements[i * C.stride + j] = 0;
    }
  }
  
  //volanie násobenia matíc
  MatMul(A, B, C);

  for(i = 0; i < MAT_SIZE; i++){
    for(j = 0; j < MAT_SIZE; j++){
      printf("%f\t", A.elements[i * A.stride + j]);
    }
    printf("\n");
  }
  printf("\n");
  for(i = 0; i < MAT_SIZE; i++){
    for(j = 0; j < MAT_SIZE; j++){
      printf("%f\t", B.elements[i * A.stride + j]);
    }
    printf("\n");
  }
  printf("\n");
  for(i = 0; i < MAT_SIZE; i++){
    for(j = 0; j < MAT_SIZE; j++){
      printf("%f\t", C.elements[i * A.stride + j]);
    }
    printf("\n");
  }


  //uvolnenie pamäte
  free((void*) A.elements);
  free((void*) B.elements);
  free((void*) C.elements);
  
  return(0);
}
