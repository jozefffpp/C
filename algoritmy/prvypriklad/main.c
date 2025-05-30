#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  int i, n = 10;
  #pragma omp parallel default(none) shared(n) private(i)
  {
    #pragma omp for
    for(i = 0; i < n; i++) {
      printf("Vlakno %d z %d iteracia %d\n", omp_get_thread_num(), omp_get_num_threads(), i);
    }
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _OPENMP
  #include <omp.h>
#endif

int main(int argc, char* argv[])
{
  long i, n;
  double x, y, dx, pi = 0;

  //zistenie hodnoty n
  n = atol(argv[1]);

  //v�po�et hodnoty ��rky pl��ky
  dx = 1.0 / n;

  //paraleln� v�po�et iter�ci� cyklu
  #pragma omp parallel for default(none) private(i, x, y) shared(dx, n) reduction(+:pi)
  for(i = 0; i < n; i++) {
    x = dx * i;
    y = sqrt(1-x*x);
    pi += dx * y;
  }

  printf("Hodnota PI: %.16f\n", 4*pi);

  return 0;
}

#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  #pragma omp parallel
  {	//za�iatok paralelnej oblasti
    #pragma omp sections
    {	//za�iatok sekci�
      #pragma omp section	//sekcia A
      {
      	printf("sekciu A vykonava vlakno %d z %d\n", omp_get_thread_num(), omp_get_num_threads());
      }
      #pragma omp section	//sekcia B
      {
      	printf("sekciu B vykonava vlakno %d z %d\n", omp_get_thread_num(), omp_get_num_threads());
      }
      #pragma omp section	//sekcia C
      {
      	printf("sekciu C vykonava vlakno %d z %d\n", omp_get_thread_num(), omp_get_num_threads());
      }
      #pragma omp section	//sekcia D
      {
      	printf("sekciu D vykonava vlakno %d z %d\n", omp_get_thread_num(), omp_get_num_threads());
      }
    }	//koniec sekci�
  }	//koniec paralelnej oblasti

  return 0;
}


#include <stdio.h>
#include <omp.h>

//rekurz�vna funkcia
int F(int n)
{
  int i, j;
  if(n < 2) return(1);
  else {
    //vytvorenie novej pod�lohy
    #pragma omp task shared(i)
    {
      i = F(n-1);
      printf("%d-ty clen: vlakno %d\n",                             n-1, omp_get_thread_num());
    }
    //vytvorenie novej pod�lohy
    #pragma omp task shared(j)
    {
      j = F(n-2);
      printf("%d-ty clen: vlakno %d\n",                             n-2, omp_get_thread_num());
    }
    //explicitn� synchroniz�cia vl�kien
    #pragma omp taskwait
    return(i + j);
  }
}

int main(int argc, char* argv[])
{
  int i;

  #pragma omp parallel
  {     //za�iatok paralelnej oblasti
    #pragma omp single nowait
    for(i = 0; i < 6; i++)
      printf("F(%d) = %d\n", i, F(i));
  }     //koniec paralelnej oblasti

  return 0;
}

#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  #pragma omp parallel
  {	//za�iatok paralelnej oblasti
    #pragma omp single
    {	//za�iatok bloku vykon�van�ho 1 vl�knom
      printf("blok single vykonava vlakno %d\n", omp_get_thread_num());
    }	//koniec bloku vykon�van�ho 1 vl�knom

    printf("paralelnu oblast vykonava vlakno %d\n", omp_get_thread_num());
  }	//koniec paralelnej oblasti

  return 0;
}

#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  int i, n = 10;
  #pragma omp parallel default(none) shared(n) private(i)
  {
    #pragma omp for
    for(i = 0; i < n; i++) {
    #pragma omp master
      printf("Vlakno %d z %d iteracia %d\n", omp_get_thread_num(), omp_get_num_threads(), i);
    }
  }

  return 0;
}

#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  int i, n = 10;
  int a[n][n];
  #pragma omp parallel private(i, step)
  {
    i = omp_get_thread_num();
    step = omp_get_num_threads();
    while (i < n) {
      //sort(a[i][0];
      i += step;
    }
    #pragma omp barrier
    //�al�ie v�po�ty s maticou a
  }

  return 0;
}

#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
  int i, n = 10;
  #pragma omp parallel for ordered default(none) shared(n) private(i)
  for(i = 0; i < n; i++) {
    printf("Vlakno %d z %d iteracia %d\n", omp_get_thread_num(), omp_get_num_threads(), i);
    #pragma omp ordered
    { //za�iatok bloku ordered
      //pr�kazy bud� vykonan� v porad� iter�ci� cyklu
      printf("Iteracia v poradi %d\n", i);
    } //koniec bloku ordered
  }

  return 0;
}

#include <stdio.h>
#ifdef _OPENMP
  #include <omp.h>
#endif

//po�et prvkov po�a
#define MAX 10

int main(int argc, char* argv[])
{
  float a[MAX] = {1.4, 1.2, 1.1, 1.1, 0.47, 0.99, 7.86, 2.3, 9.0, 6.7};
  float b[MAX];
  int idx[MAX];
  int i, j;
  double start, stop;

  #pragma omp parallel
  {	//za�iatok paralelnej oblasti
#ifdef _OPENMP
    //za�iatok merania �asu
    start = omp_get_wtime();
#endif
    //paralelne vykon�van� iter�cie cyklu
    #pragma omp for
    for(i = 0; i < MAX; i++) {
      idx[i] = 0;
    }
    //paralelne vykon�van� iter�cie 2 vnoren�ch cyklov
    #pragma omp for collapse(2) private(i, j)
    for(i = 0; i < MAX; i++) {
      for(j = 0; j < MAX; j++) {
        if((a[i] > a[j]) || ((a[i] == a[j]) && (i > j))) {
	  //v kritickej oblasti sa m��e nach�dza� len 1 vl�kno
	  #pragma omp critical
	  idx[i]++;
	}
      }
    }
    //paralelne vykon�van� iter�cie cyklu
    #pragma omp for
    for(i = 0; i < MAX; i++) {
      b[idx[i]] = a[i];
    }
#ifdef _OPENMP
    //koniec merania �asu
    stop = omp_get_wtime();
#endif
    //paralelne vykon�van� iter�cie cyklu v porad� iter�ci�
    #pragma omp for ordered
    for(i = 0; i < MAX; i++) {
      #pragma omp ordered
      printf("%6.2f", b[i]);
    }

    //oblas� single vykon� len 1 vl�kno
    #pragma omp single
    printf("\n");
  }	//koniec paralelnej oblasti
#ifdef _OPENMP
  printf("Cas: %.9f s\nPresnost: %e s\n", stop - start, omp_get_wtick());
#endif

  return 0;
}
