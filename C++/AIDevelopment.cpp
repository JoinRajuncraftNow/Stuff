//Just a fragment of a file, so it will not work alone
void wait()
{
  system("sleep 1"); //Have to love universal commands
}
string movef_(int x,int y,int z,int qx,int qy,int qz,int num)
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
  if(qy!=y)
  {
    if(qy>y) return "n";
    return "s";
  }
  if(qx!=x)
  {
    if(qx>x) return "e";
    return "w";
  }
  string c[4];
  c[0]="n";c[1]="s";c[2]="w";c[3]="e";
  int j=gen(0,3);
  return c[j];
}
void movef(int& att,int x,int y,int z,int qx,int qy,int qz,int num)
{
  att=movef_(x,y,z,qx,qy,qz,num);
  wait();
}
string movec_(int health,int def,int m,int charge)
{
  int damage=200;
  if(m>0)
  {
    if(health<=damage-def)
    {
      return "m";
    }
    if(charge)
    {
      return "d";
    }
    return "b";
  }
  if(charge) //We're screwed!
  {
    return "d";
  }
  return "b";
}
void movec(int& att,int health,int def,int m,int charge)
{
  att=movec_(health,def,m,charge);
  wait(); //Should wait
}
