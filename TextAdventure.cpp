#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string vowel(string arg) //Little helper function for grammar, just tells if an 'n' should be added dependending on the next word, arg
{
		return ( arg[0]=='A' || arg[0]=='E' || arg[0]=='I' || arg[0]=='O' || arg[0]=='U' ) ? "n" : "";
}
int gen(int x, int y) //Generates a random number between x and y.
{
	return (rand() % y + x);
}

void death() //Outputs "You have died!" then stops.
{
	cout << "You have died!";
	while(true)
	{
		
	}
}

void boss(int& health, int def, int& m) //Boss Battle
{
	int g, c=0, chance, damage, charge=0, t=0, whealth=1000, f=0, stun=0;
	while(health>0,whealth>0)
	{
		string att;
		if(stun==0)
		{
			cout << "-------Combat-------" << endl << "B-Big slash: 15-50 damage, 25% chance of missing." << endl << "Q-Quick Slash: 5-12 damage, 10% chance of missing." << endl << "D-Dodge: 75% chance of dodging all damage." << endl << "M-Medkit: Restores you to full health." << endl << "--------------------" << endl << "Health: " << health << endl << "def: " << def << endl << "Medkits: " << m << endl << "Enemy Health: " << whealth << endl << "Command: ";
			if(t==0)
			{
				getline(cin, att);
				if(att=="b"||att=="B")
				{
					cout << endl << "Big Slash!" << endl;
					chance=gen(1,4);
					f=0;
					if(chance==1)
					{
						cout << "Dodged!" << endl;
					}else{
						whealth-=gen(15,50);
					}
				}else{
					if(att=="q"||att=="Q")
					{
						cout << endl << "Quick Slash!" << endl;
						chance=gen(1,20);
						f=0;
						if(chance==1)
						{
							cout << "Dodged!" << endl;
						}else{
							whealth-=gen(5,15);
						}
					}else{
						if(att=="d"||att=="D")
						{
							cout << endl << "Dodge!" << endl;
							chance=gen(1,4);
							f=0;
							if(chance==1||chance==2||chance==3)
							{
								f=1;
								cout << "Success" << endl;
							}else{
								cout << "Failed." << endl;
							}
						}else{
							if(att=="m"||att=="M")
							{
								cout << endl << "Used a medkit." << endl;
								m--;
								health=1000;
								f=1;
							}else{
								cout << "Not a valid command!" << endl;
								f=1;
							}
						}
					}
				}
			}
				cout << endl;
			}			
		stun=0;
		damage=0;
		if(charge==0)
		{
			cout << "The Destroyer Attacks!" <<  endl;
			damage=gen(20,100)-def;
			if(def>damage||def==damage)
			{
				if(f==1)
				{
					cout << "Your armor blocked the damage!" << endl;
				}
				damage=0;
			}
			health-=damage;
			chance=gen(1,4);
			if(chance==1)
			{
				charge++;
			}else{
				charge=0;
			}
		}else{
			if(charge==1)
			{
				cout << "The Destroyer is charging up for a heavy attack!" << endl;
				charge++;
			}else{
				stun=1;
				cout << "The Destroyer Charges!" <<  endl << "You have been stunned!" << endl;
				damage=gen(25, 200)-def;
				if(def>damage||def==damage)
				{
					if(f==1)
					{
						cout << "Your armor blocked the damage!" << endl;
					}
					damage=0;
				}
					health-=damage;
					charge=0;
				}
			}
			g=0;
			cout << "You took " << damage << " damage!" << endl;
			f=0;
			charge=0;
		if(health<1)
		{
			death();
		}
		while(whealth<1)
		{
			cout << "#Congrats! You won!";
		}
	}
}

void combat(int z, int& num, int& health, int& def, int& m) //Main combat
{
	int j=gen(1,3);
	string monster;
	if(z==4)
	{
		if(j==3)
		{
			monster="Bandit";
		}else{
			if(j==2)
			{
				monster="Wyvern";
			}else{
				monster="Giant Snake";
			}
		}
		int g, c=0, chance, damage, charge=0, whealth=gen(100,200), t=0, f=0;
		cout << "Something approaches..." << endl << "A" << vowel(monster) << " " << monster << " jumps out!" << endl;
		while(c==0)
			{
			string att;
			cout << "-------Combat-------" << endl << "B-Big slash: 15-50 damage, 25% chance of missing." << endl << "Q-Quick Slash: 5-12 damage, 10% chance of missing." << endl << "D-Dodge: 75% chance of dodging all damage." << endl << "M-Medkit: Restores you to full health." << endl << "--------------------" << endl;
			cout << "Health: " << health << endl << "def: " << def << endl << "Medkits: " << m << endl << "Enemy Health: " << whealth << endl;
			cout << "Command: ";
			if(t==0)
			{
				getline(cin, att);
				if(att=="b"||att=="B")
				{
					cout << endl << "Big Slash!" << endl;
					chance=gen(1,4);
					f=0;
					if(chance==1)
					{
						cout << "Dodged!" << endl;
					}else{
						whealth-=gen(15,50);
					}
				}else{
					if(att=="q"||att=="Q")
					{
						cout << endl << "Quick Slash!" << endl;
						chance=gen(1,20);
						f=0;
						if(chance==1)
						{
							cout << "Dodged!" << endl;
						}else{
							whealth-=gen(5,15);
						}
					}else{
						if(att=="d"||att=="D")
						{
							cout << endl << "Dodge!" << endl;
							chance=gen(1,4);
							f=0;
							if(chance==1||chance==2||chance==3)
                            {
                                f=1;
                                cout << "Success" << endl;
                            }else{
                                cout << "Failed." << endl;
                            }
                        }else{
                            if(att=="m"||att=="M")
                            {
                                f=1;
                                if(m>0)
                                {
                                    cout << endl << "Used a medkit." << endl;
                                    m--;
                                    health=1000;
                                }else{
                                    cout << "You have no medkits!" << endl;
                                }
                            }else{
                                cout << "Not a valid command!" << endl;
                                f=1;
                            }
						}
					}
				}
			}
			cout << endl;
			damage=0;
			if(charge==0)
			{
				cout << monster << " Attacks!" <<  endl;
				damage=gen(5,25)-def;
				if(def>damage||def==damage&&f==0)
				{
					cout << "Your armor blocked the damage!" << endl;
					damage=0;
				}
				health-=damage;
				chance=gen(1,4);
				if(chance==1)
				{
					charge++;
				}else{
					charge=0;
				}
			}else{
				if(charge==1)
				{
					cout << "The " << monster << " is charging up for a heavy attack!" << endl;
					charge++;
				}else{
					cout << monster << " Charges!" <<  endl;
					damage=gen(10,25)-def;
					if(def>damage||def==damage&&f==0)
					{
						cout << "Your armor blocked the damage!" << endl;
						damage=0;
					}
					health-=damage;
					charge=0;
				}
			}
			g=0;
			cout << "You took " << damage << " damage!" << endl;
			if(health<1)
			{
				death();
			}
			if(whealth<1)
			{
				cout << "#############" << endl << monster << " Slain!" << endl << "#############" << endl;
				chance=gen(1,3);
				if(chance==1)
				{
					def++;
					cout << "You loot some armor off of the corpse... Defence +1" << endl;
				}else{
                    if(chance==2||chance==3)
                    {
                        m++;
                        cout << "You loot a medkit off of the corpse..." << endl;
                    }
                }
				t=1;
				c=1;
			}
		}
	}
	if(z==2||z==3)
	{
		if(j==3)
		{
			monster="Giant Spider";
		}else{
			if(j==2)
			{
				monster="Giant Scorpion";
			}else{
				monster="Insane Bandit";
			}
		}
		int g, c, chance, damage, charge=0, t=0, f=0, whealth=gen(200,300);
		cout << "Something approaches..." << endl << "A" << vowel(monster) << " " << monster << " jumps out!" << endl;
		c=0;
		while(c==0)
			{
			string att;
			cout << "-------Combat-------" << endl << "B-Big slash: 15-50 damage, 25% chance of missing." << endl << "Q-Quick Slash: 5-12 damage, 10% chance of missing." << endl << "D-Dodge: 75% chance of dodging all damage." << endl << "M-Medkit: Restores you to full health." << endl << "--------------------" << endl << "Health: " << health << endl << "Defence: " << def << endl << "Medkits: " << m << endl << "Enemy Health: " << whealth << endl << "Command: ";
			if(t==0)
			{
				getline(cin, att);
				if(att=="b"||att=="B")
				{
					cout << endl << "Big Slash!" << endl;
					chance=gen(1,4);
					f=0;
					if(chance==1)
					{
						cout << "Dodged!" << endl;
					}else{
						whealth-=gen(15,50);
					}
				}else{
					if(att=="q"||att=="Q")
					{
						cout << endl << "Quick Slash!" << endl;
						chance=gen(1,20);
						f=0;
						if(chance==1)
						{
							cout << "Dodged!" << endl;
						}else{
							whealth-=gen(5,15);
						}
					}else{
						if(att=="d"||att=="D")
						{
							cout << endl << "Dodge!" << endl;
							chance=gen(1,4);
							f=0;
							if(chance==1||chance==2||chance==3)
                            {
                                f=1;
                                cout << "Success" << endl;
                            }else{
                                cout << "Failed." << endl;
                            }
                        }else{
                            if(att=="m"||att=="M")
                            {
                                f=1;
                                if(m>0)
                                {
                                    cout << endl << "Used a medkit." << endl;
                                    m--;
                                    health=1000;
                                }else{
                                    cout << "You have no medkits!" << endl;
                                }
                            }else{
                                cout << "Not a valid command!" << endl;
                                f=1;
                            }
						}
					}
				}
			}
			cout << endl; 
			damage=0;
			if(charge==0)
			{
				cout << monster << " Attacks!" <<  endl;
				damage=gen(7,25)-def;
				if(def>damage||def==damage&&f==0)
				{
					cout << "Your armor blocked the damage!" << endl;
					damage=0;
				}
				health-=damage;
				chance=gen(1,4);
				if(chance==1)
				{
					charge++;
				}else{
					charge=0;
				}
			}else{
				if(charge==1)
				{
					cout << "The " << monster << " is charging up for a heavy attack!" << endl;
					charge++;
				}else{
					cout << monster << " Charges!" <<  endl;
					damage=gen(15,135)-def;
					if(def>damage||def==damage&&f==0)
					{
						cout << "Your armor blocked the damage!" << endl;
						damage=0;
					}
					health-=damage;
					charge=0;
				}
			}
			g=0;
			cout << "You took " << damage << " damage!" << endl;
			if(health<1)
			{
				death();
			}
			if(whealth<1)
			{
				cout << "#############" << endl << monster << " Slain!" << endl << "#############" << endl;
				chance=gen(1,3);
				if(chance==1)
				{
					def++;
					cout << "You loot some armor off of the corpse... Defence +1" << endl;
				}else{
                    if(chance==2||chance==3)
                    {
                        m++;
                        cout << "You loot a medkit off of the corpse..." << endl;
                    }
                }
				t=1;
				c=1;
			}
		}
	}
	if(z==1||z==0)
	{
		if(j==3)
		{
			monster="Earth Elemental";
		}else{
			if(j==2)
			{
				monster="Undead Bandit";
			}else{
				monster="Giant Mole";
			}
		}
		int g, c, chance, damage, charge=0, t=0, f=0,whealth = gen(200,300); //I assume this is what you meant, because integer overflows cause the enemy to be HARD (30000+ health!)
		cout << "Something approaches..." << endl << "A" << vowel(monster) << " " << monster << " jumps out!" << endl;
		c=0;
		while(c==0)
			{
			string att;
			cout << "-------Combat-------" << endl << "B-Big slash: 15-50 damage, 25% chance of missing." << endl << "Q-Quick Slash: 5-12 damage, 10% chance of missing." << endl << "D-Dodge: 75% chance of dodging all damage." << endl << "M-Medkit: Restores you to full health." << endl << "--------------------" << endl;
			cout << "Health: " << health << endl << "Defence: " << def << endl << "Medkits: " << m << endl << "Enemy Health: " << whealth << endl; //problems occur here, no reason why!
			cout << "Command: ";
			if(t==0)
			{
				getline(cin, att);
				if(att=="b"||att=="B")
				{
					cout << endl << "Big Slash!" << endl;
					chance=gen(1,4);
					f=0;
					if(chance==1)
					{
						cout << "Dodged!" << endl;
					}else{
						whealth-=gen(15,50);
					}
				}else{
					if(att=="q"||att=="Q")
					{
						cout << endl << "Quick Slash!" << endl;
						chance=gen(1,20);
						f=0;
						if(chance==1)
						{
							cout << "Dodged!" << endl;
						}else{
							whealth-=gen(5,15);
						}
					}else{
						if(att=="d"||att=="D")
						{
							cout << endl << "Dodge!" << endl;
							chance=gen(1,4);
							f=0;
							if(chance==1||chance==2||chance==3)
                            {
                                f=1;
                                cout << "Success" << endl;
                            }else{
                                cout << "Failed." << endl;
                            }
                        }else{
                            if(att=="m"||att=="M")
                            {
                                f=1;
                                if(m>0)
                                {
                                    cout << endl << "Used a medkit." << endl;
                                    m--;
                                    health=1000;
                                }else{
                                    cout << "You have no medkits!" << endl;
                                }
                            }else{
                                cout << "Not a valid command!" << endl;
                                f=1;
                            }
						}
					}
				}
			}
			cout << endl; 
			damage=0;
			if(charge==0)
			{
				cout << monster << " Attacks!" <<  endl;
				damage=gen(7,25)-def;
				if(def>damage||def==damage&&f==0)
				{
					cout << "Your armor blocked the damage!" << endl;
					damage=0;
				}
				health-=damage;
				chance=gen(1,4);
				if(chance==1)
				{
					charge++;
				}else{
					charge=0;
				}
			}else{
				if(charge==1)
				{
					cout << "The " << monster << " is charging up for a heavy attack!" << endl;
					charge++;
				}else{
					cout << monster << " Charges!" <<  endl;
					damage=gen(15,135)-def;
					if(def>damage||def==damage&&f==0)
					{
						cout << "Your armor blocked the damage!" << endl;
						damage=0;
					}
					health-=damage;
					charge=0;
				}
			}
			g=0;
			cout << "You took " << damage << " damage!" << endl;
			if(health<1)
			{
				death();
			}
			if(whealth<1)
			{
				cout << "#############" << endl << monster << " Slain!" << endl << "#############" << endl;
				chance=gen(1,3);
				if(chance==1)
				{
					def++;
					cout << "You loot some armor off of the corpse... Defence +1" << endl;
				}else{
                    if(chance==2||chance==3)
                    {
                        m++;
                        cout << "You loot a medkit off of the corpse..." << endl;
                    }
                }
				t=1;
				c=1;
			}
		}
	}
}

int count(string count, char test) //Tests for # of times char is in string. Useless unless I add an inventory system.
{
	int x=0, output=0;
	while(x<count.size())
	{
		if(count[x]==test)
		{
			output++;
		}
		x++;
	}
	return output;
}

void up(int& x, int& y, int& z, int h) //Move the player up if you can
{
	if(h==10)
	{
		if(z!=4)
		{
			z++;
			cout << "You climb up the stairs, but a doorway closes behind you... You are locked out!" << endl;
		} else {
			cout << "You jump as high as you can, but sadly you cannot fly." << endl;	
		}
	}else{
	cout << "You can't go up from here" << endl;
	}
}

void down(int& x, int& y, int& z, int h) //Move the player down if you can
{
	if(h==10)
	{
		if(z!=0)
		{
			z--;
			cout << "You start to climb down, then the ground collapses underneath you!" << endl;
		} else {
			cout << "There are no tunnels leading down from here..." << endl;	
		}
	}else{
	cout << "You can't go down from here" << endl;
	}
}

void north(int& x, int& y, int& z) //Move north if you can
{
	if(x!=99)
	{
        cout << "You trek north" << endl;
		x++;
	} else {
		cout << "Something tells you that you can't leave the area..." << endl;	
	}
}

void south(int& x, int& y, int& z) //Move south if you can
{
	if(x!=0)
	{
        cout << "You trek south" << endl;
		x--;
	} else {
		cout << "Something tells you that you can't leave the area..." << endl;	
	}
}

void east(int& x, int& y, int& z) //Move east if you can
{
	if(y!=99)
	{
        cout << "You trek east" << endl;
		y++;
	} else {
		cout << "Something tells you that you can't leave the area..." << endl;	
	}
}

void west(int& x, int& y, int& z) //Move west if you can
{
	if(y!=0)
	{
        cout << "You trek west" << endl;
		y--;
	} else {
		cout << "Something tells you that you can't leave the area..." << endl;	
	}
}

void command(string input, int& x, int& y, int& z, int& h) //Tests for which command you inputted
{
	if(input=="n"||input=="N")
	{
		north(x, y, z);
	} else {
		if(input=="s"||input=="S")
		{
			south(x, y, z);
		} else {
			if(input=="e"||input=="E")
			{
				east(x, y, z);
			} else {
				if(input=="w"||input=="W")
				{
					west(x, y, z);
				} else {
					if(input=="h"||input=="H")
					{
					cout << "Commands:" << endl << "E-east" << endl << "W-west" << endl << "N-north" << endl << "S-South" << endl << "D-down" << endl << "U-up" << endl;
					} else {
						if(input=="u"||input=="U")
						{	
							up(x, y, z, h);
						} else {
							if(input=="D"||input=="d")
							{
								down(x, y, z, h);
							} else {
								cout << "That is not a valid command, type H for help." << endl;
							}
						}
					}
				}
			}
		}
	}
}

int tile(int z, int& num, int& health, int& def, int& m) //Tests for what value you are on
{
	if(z==4)
	{
		if(num==1||num==3||num==12)
		{
			cout << "[Forest]" << endl;
			return 1;
		}else{
			if(num==4||num==6)
			{
				cout << "[Swamp]" << endl;
				return 4;
			}else{
				if(num==7||num==8||num==9)
				{
					cout << "[Desert]" << endl;
					return 7;
				}else{
					if(num==10)
					{
						cout << "[Cave Entrance]" << endl;
						return 10;
					}else{
						if(num==2)
						{
							combat(z, num, health, def, m);
							return 12;
						}else{
							if(num==5||num==15)
							{
								cout << "[Ruins]" << endl;
								return 15;
							}
						}
					}
				}
			}
		}
	}else{
		if(num==1||num==3||num==12)
		{
			cout << "[Cavern]" << endl;
			return 1;
		}else{
			if(num==4||num==5||num==6)
			{
				cout << "[Tunnel]" << endl;
				return 4;
			}else{
				if(num==7||num==8||num==9)
				{
					cout << "[Cave]" << endl;
					return 7;
				}else{
					if(num==10)
					{
						cout << "[Stairway]" << endl;
						return 10;
					}else{
						if(num==2)
						{
							combat(z, num, health, def, m);
							return 12;
						}
					}
				}
			}
		}
	}
    if(num==11)
    {
        cout << "A feeling of hopelessness overwhelms you..." << endl << "-----BOSS FIGHT-----" << endl;
        boss(health, def, m);
    }
}

int main()
{
	string com, pause;
	int x=0, y=0, z=0, death=0, def=0, num, m=0;
	int map[100][100][5];
	cout << "Generating Map..." << endl; //Randomly generates map.
	while(x<100)
	{
		while(y<100)
		{
			while(z<5)
			{
				num=gen(1,10);
				map[x][y][z]=num;
				z++;
			}
			y++;
			z=0;
		}
		x++;
		y=0;
	}
    map[99][99][0]=11;
	x=0;
	y=0;
	z=4;
    cout << endl << "This is a text adventure by Alex Trahan, and very minor contributions by Zachary Taylor." << endl << "Defeat the Boss at (99,99,0) to win!" << endl << "Hit any key to continue." << endl;
    getline(cin, pause);
	int health=1000, l=0;
	while(true) //Never stop looping
	{
		num=map[x][y][z]; //Copies the value so I don't have to pass an array by reference. There is an easier way of doing this, but whatever.
		map[x][y][z]=tile(z, num, health, def, m); //Uses this so that the tile function can easily change the map.
		cout << "Coordinates: " << "(" << x << ", " << y << ", " << z << ")" << endl; //Outputs Coordinates
		cout << "Command: "; 
		getline(cin, com);
		cout << endl << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		command(com, x, y, z, num);
		cout << "---------------------------------------------------------------------------" << endl;
	}
} 
