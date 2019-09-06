
/***********************************************************************
 *
 * initial.h
 *
 * purpose: set initial condition
 *
 **********************************************************************/


/*******************************
 * 2D random +1 or -1 spin
 ******************************/

int RandomSpin(void)
{
  int i, j;
  
  srand((unsigned int)time(NULL));
  
#pragma omp parallel for private(i, j)
  for(i=0; i<ixmax; i++){
    for(j=0; j<jymax; j++){
      S[i][j] = 2 * (rand()%2) - 1;
    }
  }
    
  return 0;
}
