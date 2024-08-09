#include <stdio.h>
#include <stdlib.h>    /* exit, malloc, calloc, etc. */
#include <string.h>
#include <getopt.h>    /* getopt */
#include <time.h>

#include "matriz.h"
#include "utils.h"
#include "likwid.h"

/**
 * Exibe mensagem de erro indicando forma de uso do programa e termina
 * o programa.
 */

static void usage(char *progname)
{
  fprintf(stderr, "Forma de uso: %s [ <ordem> ] \n", progname);
  exit(1);
}



/**
 * Programa principal
 * Forma de uso: matmult [ -n <ordem> ]
 * -n <ordem>: ordem da matriz quadrada e dos vetores
 *
 */

int main (int argc, char *argv[]) 
{
  int n=DEF_SIZE;
  
  MatRow mRow_1, mRow_2, resMat, resMatOtimizado;
  Vetor vet, res, resOtimizado;
  double timeMatVet, timeMatVetOtimizado, timeMatMat, timeMatMatOtimizado;
  
  /* =============== TRATAMENTO DE LINHA DE COMANDO =============== */

  if (argc < 2)
    usage(argv[0]);

  n = atoi(argv[1]);
  
  /* ================ FIM DO TRATAMENTO DE LINHA DE COMANDO ========= */
 
  srandom(20232);
      
  res = geraVetor (n, 0); // (real_t *) malloc (n*sizeof(real_t));
  resOtimizado = geraVetor (n, 0);
  resMat = geraMatRow(n, n, 1);
  resMatOtimizado = geraMatRow(n, n, 1);
    
  mRow_1 = geraMatRow (n, n, 0);
  mRow_2 = geraMatRow (n, n, 0);

  vet = geraVetor (n, 0);

  if (!res || !resMat || !mRow_1 || !mRow_2 || !vet || !resOtimizado || !resMatOtimizado) {
    fprintf(stderr, "Falha em alocação de memória !!\n");
    liberaVetor ((void*) mRow_1);
    liberaVetor ((void*) mRow_2);
    liberaVetor ((void*) resMat);
    liberaVetor ((void*) resMatOtimizado);
    liberaVetor ((void*) vet);
    liberaVetor ((void*) res);
    liberaVetor ((void*) resOtimizado);
    exit(2);
  }
    

#ifdef _DEBUG_
    //prnMat (mRow_1, n, n);
    //prnMat (mRow_2, n, n);
    //prnVetor (vet, n);
    printf ("===============================================================================\n\n");
#endif /* _DEBUG_ */

  LIKWID_MARKER_INIT;

  LIKWID_MARKER_START("MatVet");
  timeMatVet = timestamp();
  multMatVet (mRow_1, vet, n, n, res);
  timeMatVet = timestamp() - timeMatVet;
  LIKWID_MARKER_STOP("MatVet");

  LIKWID_MARKER_START("MatVetOtimizado");
  timeMatVetOtimizado = timestamp();
  multMatVetOtimizado (mRow_1, vet, n, n, resOtimizado);
  timeMatVetOtimizado = timestamp() - timeMatVetOtimizado;
  LIKWID_MARKER_STOP("MatVetOtimizado");
    
  LIKWID_MARKER_START("MatMat");
  timeMatMat = timestamp();
  multMatMat (mRow_1, mRow_2, n, resMat);
  timeMatMat = timestamp() - timeMatMat;
  LIKWID_MARKER_STOP("MatMat");

  LIKWID_MARKER_START("MatMatOtimizado");
  timeMatMatOtimizado = timestamp();
  multMatMatOtimizado (mRow_1, mRow_2, n, resMatOtimizado);
  timeMatMatOtimizado = timestamp() - timeMatMatOtimizado;
  LIKWID_MARKER_STOP("MatMatOtimizado");

  printf ("Tempo do MatVet %.8lf ms\n", timeMatVet);
  printf ("Tempo do MatVetOtimizado %.8lf ms\n", timeMatVetOtimizado);
  printf ("Tempo do MatMat %.8lf ms\n", timeMatMat);
  printf ("Tempo do MatMatOtimizado %.8lf ms\n", timeMatMatOtimizado);

#ifdef _DEBUG_
    //prnVetor (res, n);
    //prnVetor (resOtimizado, n);
    prnMat (resMat, n, n);
    prnMat (resMatOtimizado, n, n);
#endif /* _DEBUG_ */

  liberaVetor ((void*) mRow_1);
  liberaVetor ((void*) mRow_2);
  liberaVetor ((void*) resMat);
  liberaVetor ((void*) resMatOtimizado);
  liberaVetor ((void*) vet);
  liberaVetor ((void*) res);
  liberaVetor ((void*) resOtimizado);

  LIKWID_MARKER_CLOSE;

  return 0;
}