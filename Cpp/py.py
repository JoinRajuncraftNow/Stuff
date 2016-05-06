try:
  import readchar
  has_r = True
except:
  import os
  has_r = False
def key():
  if has_r:
    f=open("c.txt","w")
    u=readchar.readkey()
    i=0
    while i!=len(u):
      f.write(str(ord(u[i]))+" ")
      i+=1
    f.close()
  else:
    os.system("read -n 1 c; echo $c>temp.txt;echo -e -n '\\b'")
    f=open("temp.txt","r")
    u=ord(f.read()[0])
    f.close()
    f=open("c.txt","w")
    f.write(str(u))
    f.close()
key()
