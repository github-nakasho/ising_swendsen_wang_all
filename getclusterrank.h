
/***********************************************************************
 *
 * getclusterrank.h
 *
 * purpose: return cluster rank of (i, j)
 *
 **********************************************************************/


int GetClusterRank(i, j)
{
  int rank;
  
  // set rank of (i, j)
  rank = i * jymax + j;
  
  // find rank
  while(rank!=CLUSTER[rank]){
    rank = CLUSTER[rank];
  }
  
  return rank;
}
