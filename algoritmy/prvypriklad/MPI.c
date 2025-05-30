
#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  //inicializ�cia MPI
  MPI_Init(&argc, &argv);

  printf("Hello world\n");

  //ukon�enie MPI
  MPI_Finalize();

  return 0;
}

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  int rank, size;

  //inicializ�cia MPI
  MPI_Init(&argc, &argv);

  //zistenie poradov�ho ��sla procesu - rank
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //zistenie celkov�ho po�tu procesov - size
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf("Hello world, proces %d z %d\n", rank, size);

  //ukon�enie MPI
  MPI_Finalize();

  return 0;
}

#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAXSTR 100

int main(int argc, char* argv[])
{
  char sprava[MAXSTR];
  int rank, size;

  //inicializ�cia MPI
  MPI_Init(&argc, &argv);

  //zistenie poradov�ho ��sla procesu - rank
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //zistenie celkov�ho po�tu procesov - size
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if(rank != 0) {
    sprintf(sprava, "Hello world, proces %d z %d", rank, size);
    //odoslanie spr�vy
    MPI_Send(sprava, strlen(sprava)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  } else {
    printf("Hello world, proces %d z %d\n", rank, size);
    for(int i=1; i<size; i++) {
      //prijatie spr�vy
      MPI_Recv(sprava, MAXSTR, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("%s\n", sprava);
    }
  }

  //ukon�enie MPI
  MPI_Finalize();

  return 0;
}

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  int rank, size;
  MPI_Status status;

  //inicializ�cia MPI
  MPI_Init(&argc, &argv);
  //zistenie poradov�ho ��sla procesu - rank
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //zistenie celkov�ho po�tu procesov - size
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  double start, stop, sprava=123.456;

  start = MPI_Wtime();  //meranie �asu
  for(int i=0; i<50; i++) {
    if(!rank) {
      //odoslanie spr�vy procesom 0
      MPI_Send(&sprava, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
      //prijatie spr�vy procesom 0
      MPI_Recv(&sprava, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);
    } else {
      //prijatie spr�vy procesom 1
      MPI_Recv(&sprava, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
      //odoslanie spr�vy procesom 1
      MPI_Send(&sprava, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
  }
  stop = MPI_Wtime();  //meranie �asu
  if(!rank) {
    printf("Cas prenosu: %f mikrosekund.\n", (stop-start)/(2*50)*1e6);
    printf("Bandwidth: %f B/s\n", sizeof(sprava)*2*50/(stop-start));
  }

  //ukon�enie MPI
  MPI_Finalize();
  return(0);
}

#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  int rank, size;
  MPI_Status status;
  MPI_Request req;

  //inicializ�cia MPI
  MPI_Init(&argc, &argv);

  //zistenie poradov�ho ��sla procesu - rank
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //zistenie celkov�ho po�tu procesov - size
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int send_buf, recv_buf, sum=0, odosielatel, adresat;

  send_buf = rank;
  //v�po�et rankov odosielate�a a adres�ta
  odosielatel = (rank - 1 + size) % size;
  adresat = (rank + 1) % size;

  for(int i=0; i<size; i++) {
    //odoslanie spr�vy
    MPI_Issend(&send_buf, 1, MPI_INT, adresat, 0, MPI_COMM_WORLD, &req);
    //prijatie spr�vy
    MPI_Recv(&recv_buf, 1, MPI_INT, odosielatel, 0, MPI_COMM_WORLD, &status);
    //�akanie na dokon�enie neblokuj�cej oper�cie
    MPI_Wait(&req, &status);
    sum += recv_buf;
    send_buf = recv_buf;
  }

  printf("Proces %d vypocital sumu %d\n", rank, sum);

  //ukon�enie MPI
  MPI_Finalize();

  return(0);
}

#include <stdio.h>
#include <mpi.h>

#define MAX 100

int main(int argc, char* argv[])
{
  int rank, size;
  MPI_Status status;
  MPI_Request req;

  //inicializ�cia MPI
  MPI_Init(&argc, &argv);

  //zistenie poradov�ho ��sla procesu - rank
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  //zistenie celkov�ho po�tu procesov - size
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  double A[MAX], B[MAX], result;

  //�daje ulo�en� vo vektoroch A, B bude ma� len proces 0
  if(!rank) { 		//t�to �as� vykon� iba proces 0
    for(int i=0; i<MAX; i++) {
      A[i] = i;		//inicializ�cia vektora A
      B[i] = i*i;	//inicializ�cia vektora B
    }
  }

  //po�et polo�iek pridelen�ch ka�d�mu procesu
  const int count = MAX / size;

  double workA[count], workB[count], workResult=0;

  //rozdelenie vektorov na �asti jednotliv�m procesom
  MPI_Scatter(A, count, MPI_DOUBLE, workA, count, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Scatter(B, count, MPI_DOUBLE, workB, count, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  //v�po�et �iastkov�ho v�sledku
  for(int i=0; i<count; i++) {
    workResult += workA[i] * workB[i];
  }

  //kombinovanie poslan�ch �iastkov�ch v�sledkov procesom 0
  MPI_Reduce(&workResult, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if(!rank) {
    printf("Vysledok je: %f\n", result);
  }

  //ukon�enie MPI
  MPI_Finalize();

  return(0);
}
