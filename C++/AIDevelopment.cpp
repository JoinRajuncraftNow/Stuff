//Just a fragment of a file, so it will not work alone
string movef(int x,int y,int z,int qx,int qy,int qz,int num)
{
  if(qx==100)
  {
    qx=99;
    qy=99;
    qz=0;
  }
  if(num==10&&qz!=z)
  {
    if(qz>z) return "u";
    return "d";
  }
}

void movec()
{
}
