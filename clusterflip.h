
/***********************************************************************
 *
 * clusterflip.h
 *
 * purpose: reversing spins in clusters
 *
 **********************************************************************/


int ClusterFlip(void)
{
  int i, j;
  int i1, j1, i2, j2;
  int rank, myrank;
  int clusterflip[ixmax*jymax];
  double p;
  
  // set rank of Union-Find cluster
#pragma omp parallel for private(rank)
  for(rank=0; rank<ixmax*jymax; rank++){
    CLUSTER[rank] = rank;
  }
  
  // compute probability of making bond
  p = 1.0 - exp(-2.0*J*ONEOKBT);

  // random array (-1 or 1)
#pragma omp parallel for private(rank)
  for(rank=0; rank<ixmax*jymax; rank++){
    clusterflip[rank] = 2 * (rand()%2) - 1;
  }
  
  // make bond
#pragma omp parallel for private(i1, j1, i2, j2)
  for(i1=0; i1<ixmax; i1++){
    for(j1=0; j1<jymax; j1++){
      for(i2=0; i2<ixmax+1; i2++){
        for(j2=0; j2<jymax+1; j2++){
          if(i1!= i2 && j1!=j2){
            // make bond between (i1, j1) & (i2, j2)
            ConnectBond(i1, j1, i2, j2, p);
          }
        }
      }
    }
  }

  // update spin
#pragma omp parallel for private(i, j)
  for(i=0; i<ixmax; i++){
    for(j=0; j<jymax; j++){
      myrank = GetClusterRank(i, j);
      S[i][j] *= clusterflip[myrank];
    }
  }
  
  return 0;
}
