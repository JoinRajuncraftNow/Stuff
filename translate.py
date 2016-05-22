#Ask a question, please, I don't know how to encode ?
if True:
  temp_str="qwertyuiop[]\\"
  to_alex={}
  from_alex={}
  i=0
  while i!=len(temp_str)-1:
    to_alex[temp_str[i]]=temp_str[i+1]
    i+=1
  while i!=0:
    from_alex[temp_str[i]]=temp_str[i-1]
    i-=1
  temp_str="QWERTYUIOP{}|"
  while i!=len(temp_str)-1:
    to_alex[temp_str[i]]=temp_str[i+1]
    i+=1
  while i!=0:
    from_alex[temp_str[i]]=temp_str[i-1]
    i-=1
  temp_str="asdfghjkl;'"
  while i!=len(temp_str)-1:
    to_alex[temp_str[i]]=temp_str[i+1]
    i+=1
  while i!=0:
    from_alex[temp_str[i]]=temp_str[i-1]
    i-=1
  temp_str="ASDFGHJKL:\""
  while i!=len(temp_str)-1:
    to_alex[temp_str[i]]=temp_str[i+1]
    i+=1
  while i!=0:
    from_alex[temp_str[i]]=temp_str[i-1]
    i-=1
  temp_str="zxcvbnm,./"
  while i!=len(temp_str)-1:
    to_alex[temp_str[i]]=temp_str[i+1]
    i+=1
  while i!=0:
    from_alex[temp_str[i]]=temp_str[i-1]
    i-=1
  temp_str="ZXCVBNM<>?"
  while i!=len(temp_str)-1:
    to_alex[temp_str[i]]=temp_str[i+1]
    i+=1
  while i!=0:
    from_alex[temp_str[i]]=temp_str[i-1]
    i-=1
def word_to_alex(word):
  r=""
  j=0
  for i in word:
    if j==0 or j==len(word)-1:
      r+=to_alex[i]
    else:
      r+=i
    j+=1
 return r
def word_from_alex(word):
  r=""
  j=0
  for i in word:
    if j==0 or j==len(word)-1:
      r+=from_alex[i]
    else:
      r+=i
    j+=1
  return r
def phrase_to_alex(phrase):
  t=phrase.split(' ')
  r=[word_to_alex(word) for word in t]
  return " ".join(r)
def phrase_from_alex(phrase):
  t=phrase.split(' ')
  r=[word_from_alex(word) for word in t]
  return " ".join(r)
