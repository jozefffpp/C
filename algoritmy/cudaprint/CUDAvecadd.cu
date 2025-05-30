#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#define MAX 1024

__global__ void vecAdd(float* A, float* B, float* C)
{
  C[threadIdx.x] = A[threadIdx.x] + B[threadIdx.x];
}

int main(int argc, char* argv[])
{
  //ukazovatele na vektory v hostiteľskej pamäti
  float *hA, *hB, *hC;
  //ukazovatele na vektory v pamäti zariadenie GPGPU
  float *dA, *dB, *dC;

  //alokácia hostiteľskej pamäte
  hA = (float*) malloc(sizeof(float) * MAX);
  hB = (float*) malloc(sizeof(float) * MAX);
  hC = (float*) malloc(sizeof(float) * MAX);

  //inicializácia vstupných a výstupného vektoru
  for(int i = 0; i < MAX; i++) {
    hA[i] = hB[i] = i;
    hC[i] = 0;
  }

  //alokácaía pamäte zariadenia GPGPU
  cudaMalloc(&dA, sizeof(float) * MAX);
  cudaMalloc(&dB, sizeof(float) * MAX);
  cudaMalloc(&dC, sizeof(float) * MAX);

  //kopírovanie údajov do GPGPU pamäte
  cudaMemcpy(dA, hA, sizeof(float) * MAX, cudaMemcpyHostToDevice);
  cudaMemcpy(dB, hB, sizeof(float) * MAX, cudaMemcpyHostToDevice);

 //definícia dimenzie gridu
  dim3 gs(1);
  //definícia dimenzie bloku
  dim3 bs(MAX);
  //volanie kernelu
  vecAdd<<<gs, bs>>>(dA, dB, dC);
  //synchronizácia - dokončenie kernelu
  cudaDeviceSynchronize();

  //kopírovanie údajov z GPGPU pamäte
  cudaMemcpy(hC, dC, sizeof(float) * MAX, cudaMemcpyDeviceToHost);

  //uvolnenie pamäte zariadenia GPGPU
  cudaFree(dA);
  cudaFree(dB);
  cudaFree(dC);

  //výpis výsledkov
  for(int i = 0; i < MAX; i++) {
    printf("%f ", hC[i]);
  }

  //uvolnenie hostiteľskej pamäte
  free(hA);
  free(hB);
  free(hC);

  return(0);
}

