
/***********************************************************************
 *
 * output.h
 *
 * purpose: output simulation result
 *
 **********************************************************************/


int BinaryOutput(int n)
{
  int i, j;
  char filename[64];
  FILE *fo;
  
  // set file name of output
  sprintf(filename, "./2d_spin_%d.dat", n);
  
  // open file
  fo = fopen(filename, "wb");
  if(fo==NULL){
    printf("I can't open %s.\n", filename);
    exit(1);
  }
  
  // write spin to file
  fwrite(S, sizeof S, 1, fo);
  
  // close file
  fclose(fo);
  
  return 0;
}
