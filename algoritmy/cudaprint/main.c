#include <stdio.h>
#include <cuda.h>

__global__ void identify()
{
  printf("blok: x=%d y=%d z=%d\tvlakno: x=%d y=%d z=%d\n", blockIdx.x, blockIdx.y, blockIdx.z, threadIdx.x, threadIdx.y, threadIdx.z);
  printf("griddim: x=%d y=%d z=%d\tblokdim: x=%d y=%d z=%d\n", gridDim.x, gridDim.y, gridDim.z, blockDim.x, blockDim.y, blockDim.z);
}

int main(int argc, char* argv[])
{
  //definícia dimenzie gridu
  dim3 gs(2,2);
  //definícia dimenzie bloku
  dim3 bs(32);
  //volanie kernelu
  identify<<<gs, bs>>>();
  //synchronizácia - dokonèenie kernelu
  cudaDeviceSynchronize();

  return(0);
}
