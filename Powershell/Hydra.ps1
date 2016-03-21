#turn echo off
$host.UI.RawUI.WindowTitle="Hydra";
lbegin while(1)
{
    $n=$n+1;
    #See if data.txt exist, if not: create it
    findstr /m `"$n`" data.txt;
    if($?==$true)
    {
      continue;
    }
    break;
}
