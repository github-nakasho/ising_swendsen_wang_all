
/***********************************************************************
 *
 * IsingSwendsenWangAll
 *
 * purpose: Ising model solver (Swendsen & Wang 1987)
 *
 **********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// for input parameters
#include "input.h"

// for common values
#include "commonfield.h"

// for initial condition
#include "initial.h"

// for main solvers
#include "getclusterrank.h"
#include "connectbond.h"
#include "clusterflip.h"

// for output
#include "output.h"


int main(voie)
{
  // set initial condition
  RandomSpin();
  
  // set time step = 0
  int n = 0;
  
  // output for analysis & visualization
  BinaryOutput(n);
  
  // main loop start
  while(n<NSTEP){
    // proceed one step
    n++;
    printf("n = %d\n", n);
    
    // main solver
    ClusterFlip();
    
    // output per NOUT
    if(n % NOUT == 0){
      BinaryOutput(n/NOUT);
    }
  }
  
  return 0;
}
