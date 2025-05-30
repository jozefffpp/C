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

  //vıpoèet hodnoty šírky plôšky
  dx = 1.0 / n;

  //paralelnı vıpoèet iterácií cyklu
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
  {	//zaèiatok paralelnej oblasti
    #pragma omp sections
    {	//zaèiatok sekcií
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
    }	//koniec sekcií
  }	//koniec paralelnej oblasti

  return 0;
}


#include <stdio.h>
#include <omp.h>

//rekurzívna funkcia
int F(int n)
{
  int i, j;
  if(n < 2) return(1);
  else {
    //vytvorenie novej podúlohy
    #pragma omp task shared(i)
    {
      i = F(n-1);
      printf("%d-ty clen: vlakno %d\n",                             n-1, omp_get_thread_num());
    }
    //vytvorenie novej podúlohy
    #pragma omp task shared(j)
    {
      j = F(n-2);
      printf("%d-ty clen: vlakno %d\n",                             n-2, omp_get_thread_num());
    }
    //explicitná synchronizácia vlákien
    #pragma omp taskwait
    return(i + j);
  }
}

int main(int argc, char* argv[])
{
  int i;

  #pragma omp parallel
  {     //zaèiatok paralelnej oblasti
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
  {	//zaèiatok paralelnej oblasti
    #pragma omp single
    {	//zaèiatok bloku vykonávaného 1 vláknom
      printf("blok single vykonava vlakno %d\n", omp_get_thread_num());
    }	//koniec bloku vykonávaného 1 vláknom

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
    //ïalšie vıpoèty s maticou a
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
    { //zaèiatok bloku ordered
      //príkazy budú vykonané v poradí iterácií cyklu
      printf("Iteracia v poradi %d\n", i);
    } //koniec bloku ordered
  }

  return 0;
}

#include <stdio.h>
#ifdef _OPENMP
  #include <omp.h>
#endif

//poèet prvkov po¾a
#define MAX 10

int main(int argc, char* argv[])
{
  float a[MAX] = {1.4, 1.2, 1.1, 1.1, 0.47, 0.99, 7.86, 2.3, 9.0, 6.7};
  float b[MAX];
  int idx[MAX];
  int i, j;
  double start, stop;

  #pragma omp parallel
  {	//zaèiatok paralelnej oblasti
#ifdef _OPENMP
    //zaèiatok merania èasu
    start = omp_get_wtime();
#endif
    //paralelne vykonávané iterácie cyklu
    #pragma omp for
    for(i = 0; i < MAX; i++) {
      idx[i] = 0;
    }
    //paralelne vykonávané iterácie 2 vnorenıch cyklov
    #pragma omp for collapse(2) private(i, j)
    for(i = 0; i < MAX; i++) {
      for(j = 0; j < MAX; j++) {
        if((a[i] > a[j]) || ((a[i] == a[j]) && (i > j))) {
	  //v kritickej oblasti sa môe nachádza len 1 vlákno
	  #pragma omp critical
	  idx[i]++;
	}
      }
    }
    //paralelne vykonávané iterácie cyklu
    #pragma omp for
    for(i = 0; i < MAX; i++) {
      b[idx[i]] = a[i];
    }
#ifdef _OPENMP
    //koniec merania èasu
    stop = omp_get_wtime();
#endif
    //paralelne vykonávané iterácie cyklu v poradí iterácií
    #pragma omp for ordered
    for(i = 0; i < MAX; i++) {
      #pragma omp ordered
      printf("%6.2f", b[i]);
    }

    //oblas single vykoná len 1 vlákno
    #pragma omp single
    printf("\n");
  }	//koniec paralelnej oblasti
#ifdef _OPENMP
  printf("Cas: %.9f s\nPresnost: %e s\n", stop - start, omp_get_wtick());
#endif

  return 0;
}
