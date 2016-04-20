function clear
{
  cls;
}
function info_map
{
  Write-Host "H - Help";
  Write-Host "W - North";
  Write-Host "A - West";
  Write-Host "S - South";
  Write-Host "D - East";
  Write-Host "Q - Up";
  Write-Host "Z - Down";
  Write-Host "M - Medkit";
}
function info_battle
{
  Write-Host "B-Big Slash: 15-50 + ``pow`` damage, 25% chance of missing";
  Write-Host "Q-Quick Slash: 5-12 + ``pow`` damage, 10% chance of missing";
  Write-Host "D-Dodge: 75% chance of dodging all damage";
  Write-Host "M-Medkit: Restores you to full health";
  Write-Host "H-Help: Display this help message";
}
