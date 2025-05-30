
#define   TOTALELEMS   147
#define   MAXPROC      32

#include <stdio.h>
#include <math.h>
#include "ga.h"
#include <mpi.h>

int main(int argc, char **argv)
{
    int me, nprocs;

    int dims[1], chunk[1], ld[1], lo, hi;
    int lo1, hi1, lo2, hi2;
    int g_a, g_b, a[MAXPROC*TOTALELEMS],b[MAXPROC*TOTALELEMS];
    int nelem, i;

    // Inicializ�cia MPI
    MPI_Init(&argc, &argv);

    // Inicializ�cia GA
    GA_Initialize();

    // Priradenie ID lok�lneho ranku a celkov�ho po�tu rankov
    me = GA_Nodeid();
    nprocs = GA_Nnodes();

    // Konfigur�cia rozmerov pol�
    dims[0]  = nprocs*TOTALELEMS + nprocs/2;
    ld[0]    = dims[0];
    chunk[0] = TOTALELEMS;

    // Vytvor Global Array g_a a duplikuj do g_b
    g_a = NGA_Create(C_INT, 1, dims, "array A", chunk);
    g_b = GA_Duplicate(g_a, "array B");
    // Inicializuj �daje v g_a
    if (me==0) {
       for(i=0; i<dims[0]; i++) a[i] = i;
       lo = 0;
       hi = dims[0]-1;
       NGA_Put(g_a, lo, hi, a, ld);
    }

    // Synchronizuj v�etky procesy pred �al��m pokra�ovan�m
    GA_Sync();

    // Zisti, ktor� �daje s� na lok�lnom ranku
    NGA_Distribution(g_a, me, lo1, hi1);

    // Kop�ruj lok�lne �daje z g_a do lok�lneho z�sobn�ka a
    NGA_Get(g_a, lo1, hi1, a, ld);

    // Invertuj �daje lok�lne
    nelem = hi1 - lo1 + 1;
    for (i=0; i<nelem; i++) b[i] = a[nelem-1-i];

    // Invertuj �daje glob�lnym ulo�en�m invertovan�ch blokov na spr�vne miesto v global array g_b
    lo2 = dims[0] - hi1 -1;
    hi2 = dims[0] - lo1 -1;
    NGA_Put(g_b, lo2, hi2, b, ld);

    // Synchronizuj v�etky procesy
    GA_Sync();

    // Dealokuj polia
    GA_Destroy(g_a);
    GA_Destroy(g_b);

    GA_Terminate();
    MPI_Finalize();
    return(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <GASPI.h>

#define TOTALELEMS 147

int main(int argc,char *argv[])
{
    gaspi_rank_t rank, size;
    gaspi_proc_init(GASPI_BLOCK);
    gaspi_proc_rank(&rank);
    gaspi_proc_num(&size);
    gaspi_segment_id_t seg_id_a = 0, seg_id_b = 1;
    gaspi_pointer_t seg_ptr_array, seg_ptr_value;
    gaspi_size_t seg_length;
    gaspi_offset_t l_p = 0, r_p = 0;

    int i, n, n_part, s = 0, shift = 0;
    int *a, *b;

    n = TOTALELEMS;

    // V�po�et dl�ky segmentov
    if( n%size == 0 )
        n_part = n/size;
    else
    {
        shift = size-n%size;
        n_part = (n+shift)/size;
        s = 1;

        if ( rank == size-1 )
        {
            n_part = n-n_part*(size-1);
            shift = 0;
        }
    }

    // Alok�cia GASPI segmentov
    seg_length = sizeof (int);

    gaspi_segment_create ( seg_id_a, n_part*seg_length, GASPI_GROUP_ALL,GASPI_BLOCK, GASPI_MEM_INITIALIZED );
    gaspi_segment_create ( seg_id_b, n_part*seg_length, GASPI_GROUP_ALL,GASPI_BLOCK, GASPI_MEM_INITIALIZED );
    // Z�skanie lok�lnych ukazovate�ov
    gaspi_segment_ptr ( seg_id_a, & seg_ptr_array );
    a = (int *) seg_ptr_array ;

    gaspi_segment_ptr ( seg_id_b, & seg_ptr_array );
    b = (int *) seg_ptr_array ;

    // Inicializ�cia �dajov
    for (i = 0; i < n_part; i++)
    {
        a[i] = rank*(n+s*size-n%size)/size + i;
        b[i] = a[i];
    }

    // Invertovanie lok�lnych �dajov
    for (i = 0; i < n_part; i++)
    {
        a[i] = b[n_part-i-1];
    }

    // Invertovanie glob�lnych �dajov
    if( shift > 0 )
    {
        l_p = 0;
        r_p = (n_part-shift)*sizeof(int);
        gaspi_write( seg_id_a, l_p, size-2-rank, seg_id_b, r_p, shift*sizeof(int), 0, GASPI_BLOCK);
    }

    l_p = shift*sizeof(int);
    r_p = 0;
    gaspi_write( seg_id_a, l_p, size-1-rank, seg_id_b, r_p, (n_part-shift)*sizeof(int), 0, GASPI_BLOCK);

    // Synchronizuj v�etky procesy //
    gaspi_barrier ( GASPI_GROUP_ALL, GASPI_BLOCK );

    // Ukon�enie GASPI
    gaspi_proc_term ( GASPI_BLOCK );
    return 0;
}
