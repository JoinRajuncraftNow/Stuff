function clear(){}
function info_map()
{
  console.log("H - Help");
  console.log("W - North");
  console.log("A - West");
  console.log("S - South");
  console.log("D - East");
  console.log("Q - Up");
  console.log("Z - Down");
  console.log("M - Medkit");
}
function info_bottle()
{
  console.log("B-Big Slash: 15-50 + `pow` damage, 25% chance of missing");
  console.log("Q-Quick Slash: 5-12 + `pow` damage, 10% chance of missing");
  console.log("D-Dodge: 75% chance of dodging all damage");
  console.log("M-Medkit: Restores you to full health");
  console.log("H-Help: Display this help message");
}
function gen(num)
{
  return Math.floor(Math.random()*num);
}
