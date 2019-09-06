
/***********************************************************************
 *
 * connectbond.h
 *
 * purpose: make bond between 2 spins
 *
 **********************************************************************/


int ConnectBond(int i1, int j1, int i2, int j2, double p)
{
  int rank1, rank2;
 
  // set periodic boundary condition
  if(i2==ixmax){
    i2 = 0;
  }
  if(j2==jymax){
    j2 = 0;
  }
  
  // if two spins are parallel & rand < p, add cluster
  if(S[i1][j1]*S[i2][j2]>0){
    if((double)(rand()/(1.0+RAND_MAX))<p){
      
      rank1 = GetClusterRank(i1, j1);
      rank2 = GetClusterRank(i2, j2);
      
      if(rank1<rank2){
        CLUSTER[rank2] = rank1;
      }
      else{
        CLUSTER[rank1] = rank2;
      }
      
    }
  }
  
  return 0;
}
