#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#define par health,m,def,x,y,z,qx,qy,qz,map,quest
using namespace std;
/*
A Text Adventure by Alex Trahan and Zachary Taylor. 
A few notes:
I am only working on this version, and not the older one.
I use endl because it is neater than /n in my opinion. Lol, it's \n, not /n!
I tried to simplify it so others who don't code could understand for a school presentation.
Everyone is free to spot bugs and such. After all, it is on github.
Check out the planned features.
If you have any suggestions, or just want to contact me. My email is thecajunthatrages@gmail.com
*/
bool exists (string name) {
    ifstream f(name.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }   
}
void save_others(int health, int m, int def, int x, int y, int z, int qx, int qy, int qz,int quest)
{
	ofstream outf;
	outf.open("save_file.txt",::std::ofstream::trunc | ::std::ofstream::out);
	outf << health << endl << m << endl << def << endl << x << endl << y << endl << z << endl << qx << endl << qy << endl << qz << endl << quest << endl;
	outf.close();
}
void load_others(int& health, int& m, int& def, int& x, int& y, int& z, int& qx, int& qy, int& qz,int& quest)
{
	if(!exists("save_file.txt"))
	{
		return; //File doesn't exist, do nothing
	}
	ifstream inf;
	inf.open("save_file.txt");
	inf >> health;
	inf >> m;
	inf >> def;
	inf >> x;
	inf >> y;
	inf >> z;
	inf >> qx;
	inf >> qy;
	inf >> qz;
	inf >> quest;
	inf.close();
}
void save_board(int board[100][100][5]) //Reference passed by default for arrays
{
	int i=0,j=0,k=0;
	ofstream outf;
	outf.open("board_file.txt",::std::ofstream::trunc | ::std::ofstream::out);
	while(i!=100)
	{
		j=0;
		while(j!=100)
		{
			k=0;
			while(k!=5)
			{
				outf << board[i][j][k] << endl;
				k++; //Derp!
			}
			j++;
		}
		i++;
	}
	outf.close();
}
void load_board(int board[100][100][5])
{
	if(!exists("board_file.txt")){ return; }
	int i=0,j=0,k=0;
	ifstream inf;
	inf.open("board_file.txt");
	while(i!=100)
	{
		inf >> board[i][j][k];
		k++;
		if(k==5)
		{
			k=0;
			j++;
			if(j==100)
			{
				j=0;
				i++;
			}
		}
	}
	inf.close();
}
void save(int health, int m, int def, int x, int y, int z, int qx, int qy, int qz,int board[100][100][5],int quest)
{
	save_others(health,m,def,x,y,z,qx,qy,qz,quest);
	save_board(board);
}
void load(int& health, int& m, int& def, int& x, int& y, int& z, int& qx, int& qy, int& qz,int board[100][100][5],int& quest)
{
	load_others(health,m,def,x,y,z,qx,qy,qz,quest);
	load_board(board);
}
string vowel(string arg) //Little helper function for grammar, just tells if an 'n' should be added depending on the next word, arg
{
		return ( arg[0]=='A' || arg[0]=='E' || arg[0]=='I' || arg[0]=='O' || arg[0]=='U' ) ? "n" : "";
}
int gen(int x, int y) //Generates a random number between x and y.
{
	return rand()%(y-x+1)+x; //This is mathematically sound!
	//Thats the same thing I put, but more organized!
}

void death() //Outputs "You have died!" then stops.
{
	cout << "You have died!";
	while(true)
	{
		
	}
}

void boss(int& health, int def, int& m, int num) //Boss Battle, I liked destroyer better!
{
	int chance, damage, charge=0, whealth=1000, f=0, stun=0;
	string boss_name="Dragon";
	if(num==11)
	{
		whealth=2000; //For final boss. You used boss twice
		boss_name="Destroyer";
	}
	while(health>0&&whealth>0) //By the way, comma means throw something out!
	{
		string att;
		if(stun==0)
		{
			cout << "-------Combat-------" << endl << "B-Big slash: 15-50 damage, 25% chance of missing." << endl << "Q-Quick Slash: 5-12 damage, 10% chance of missing." << endl << "D-Dodge: 75% chance of dodging all damage." << endl << "M-Medkit: Restores you to full health." << endl << "--------------------" << endl << "Health: " << health << endl << "def: " << def << endl << "Medkits: " << m << endl << "Enemy Health: " << whealth << endl << "Command: ";
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
							charge++;
						}else{
							cout << "Failed." << endl;
						}
					}else{
						if(att=="m"||att=="M")
						{
							if(m>0)
							{
								cout << endl << "Used a medkit." << endl;
								m--;
								health=1000;
							}
							else
							{
								cout << endl << "You have no medkits!" << endl;
							}
							f=1;
						}else{
							cout << "Not a valid command!" << endl;
							f=1;
						}
					}
				}
			}
			cout << endl;
		}else{
			cout << "-------Combat-------" << endl << "B-Big slash: 15-50 damage, 25% chance of missing." << endl << "Q-Quick Slash: 5-12 damage, 10% chance of missing." << endl << "D-Dodge: 75% chance of dodging all damage." << endl << "M-Medkit: Restores you to full health." << endl << "--------------------" << endl << "Health: " << health << endl << "def: " << def << endl << "Medkits: " << m << endl << "Enemy Health: " << whealth << endl << "Command: ";
			getline(cin, att);
			cout << "###############" << endl << "You are stunned!" << endl << "###############" << endl; //To make it easier to read.
		}		
		stun=0;
		damage=0;
		if(f==0)
		{
			if(charge==0)
			{
				cout << "The " << boss_name << " Attacks!" <<  endl;
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
				chance=gen(1,3);
				if(chance==2)
				{
					charge++;
				}else{
					charge=0;
				}
			}else{
				if(charge==1)
				{
					cout << "The " << boss_name << " is charging up for a heavy attack!" << endl;
					charge++;
				}else{
					stun=1;
					cout << "The " << boss_name << " Charges!" <<  endl << "You have been stunned!" << endl;
					damage=gen(25, 200)-def;
					if(def>damage||def==damage)
					{
						if(f==1)
						{
							cout << "Your armor blocked the damage!" << endl;
						}
						damage=0;
					}else{
						health-=damage;
					}
					charge = 0;
				}
			}
		}

			cout << "You took " << damage << " damage!" << endl;
			f=0; 
		if(health<1)
		{
			death();
		}
		if(whealth<1)
		{
			while(num==11)
			{
			 	cout << "YOU WIN!" << endl;	
			}
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
		int c=0, chance, damage, charge=0, whealth=gen(100,200), t=0, f=0;
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
			if((def>damage||def==damage)&&f==0)
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
				if((def>damage||def==damage)&&f==0)
				{
					cout << "Your armor blocked the damage!" << endl;
					damage=0;
				}
				health-=damage;
				charge=0;
			}
		}

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
		int c, chance, damage, charge=0, t=0, f=0, whealth=gen(200,300);
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
				if((def>damage||def==damage)&&f==0)
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
					if((def>damage||def==damage)&&f==0)
					{
						cout << "Your armor blocked the damage!" << endl;
						damage=0;
					}
					health-=damage;
					charge=0;
				}
			}

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
		int  c, chance, damage, charge=0, t=0, f=0,whealth = gen(200,300); //I assume this is what you meant, because integer overflows cause the enemy to be HARD (30000+ health!)
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
				if((def>damage||def==damage)&&f==0)
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
					if((def>damage||def==damage)&&f==0)
					{
						cout << "Your armor blocked the damage!" << endl;
						damage=0;
					}
					health-=damage;
					charge=0;
				}
			}

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
	unsigned int x=0, output=0;
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

void command(string input, int& x, int& y, int& z, int& h, int& health, int& def, int& m, int& qx, int& qy, int& qz, int map[100][100][5], int& quest) //Tests for which command you inputted
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
					cout << "Commands:" << endl << "E-east" << endl << "W-west" << endl << "N-north" << endl << "S-south" << endl << "D-down" << endl << "U-up" << endl << "M-medkit" << endl << "V-save";
					} else {
						if(input=="u"||input=="U")
						{	
							up(x, y, z, h);
						} else {
							if(input=="D"||input=="d")
							{
								down(x, y, z, h);
							} else {
								if(input=="116728") //Secret
								{
									cout << "Cheat Activated!" << endl;
									cout << "X: ";
									cin >> x;
									cout << "Y: ";
									cin >> y;
									cout << "Z: ";
									cin >> z;
									cout << "Health: ";
									cin >> health;
									cout << "Defence: ";
									cin >> def;
									cout << "Medkits: ";
									cin >> m;
								}else{
									if(input=="M"||input=="m")
									{
										if(m>0)
										{
											m--;
											health=1000;
										}else{
											cout << "You have no medkits!" << endl;
										}
									}
									else if(input=="V"||input=="v")
									{
										save(par);
									}
									else
									{
										cout << "That is not a valid command, type H for help." << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void questcomplete(int& m, int& def, int& quest, int& qx, int& qy, int& qz)
{ 
	cout << "$$$$$$$$$$$$$$$$$$$$" << endl << "You have completed a quest!" << endl;
	int r=gen(1,10);
	cout << "You recieved " << r << " Medkit" << (r==1 ? "" : "s"); //semicolon
	m+=r; 
	r=gen(1,10);
	cout << " and " << r << " Armor!" << endl << "$$$$$$$$$$$$$$$$$$$$" << endl;
	def+=r; 
	quest=0;
	qx=1000;
	qy=1000;
	qz=1000;
}

void queststuff(int& qx, int& qy, int& qz, int& quest) //Only one quest now. I will add more later.
{
	cout << "A strange man approaches..." << endl;
	if(quest==0)
	{
		qx=gen(1,98);
		qy=gen(1,98);
		qz=gen(1,4);
		quest=1;
		cout << "Please help us! Our village is being terrorized by a fearsome dragon! We believe its lair to be at: " << endl << "( " << qx << ", " << qy << ", " << qz << " )" << endl << "There will be a reward once this creature has been vanquished." <<  endl; //GRAMMAR!
	}
}

int tile(int x, int y, int z, int& num, int& health, int& def, int& m, int& quest, int& qx, int& qy, int& qz) //Tests for what value you are on
{
	if(x==qx&&y==qy&&z==qz)
	{
		boss(health, def, m, num);
		questcomplete(m, def, quest, qx, qy, qz);
		return 15;
	}
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
								cout << "[Glade]" << endl;
								if(num==5)
								{
									queststuff(qx, qy, qz, quest);
									return 15;
								}
								return 5;
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
						}else{
							if(num==15)
							{
								cout << "[Ruins]" << endl; //WHAT IS THE NUMBER FOR RUINS?
								return 5;
							}
						}
					}
				}
			}
		}
	}
    if(num==11)
    {
        cout << "A feeling of hopelessness overwhelms you..." << endl << "-----BOSS FIGHT-----" << endl;
        boss(health, def, m, num);
        return 15;
    }
    else
    {
    	return -1; //This should never happen, but if it does, we want some bad things/runtime errors to occur!
    }
}

void endline() //What is this?
{
	int x=0;
	while(x<50)
	{
		cout << endl; //See, fixed!
		x++;
	}
	//clrscr();
	/*
	Worried about the school's computers reactions
	*/
	//system("CLS || clear");cout << flush;         Lol, why did you put a single-line comment here? Just extend the one above.
	
}

int main()
{
	srand(time(NULL));
	string com, pause;
	int x=0, y=0, z=0, def=0, num, m=0, quest=0, qx=1000, qy=1000, qz=1000,health=1000, menu, done=0;
	int map[100][100][5];
	//Just made this in like 2 mins. Will finish in english class.
	while(done==0)
	{
		
		cout << "1 - New" << endl << "2- Load" << endl;
		cin >> menu;
		if(menu==1)
		{
			done++;
			cout << "Generating Map..." << endl; //Randomly generates map.
			while(x<100)
			{
				while(y<100)
				{
					while(z<5)
					{
						map[x][y][z]=gen(1,10);
						z++;
					}
					y++;
					z=0;
				}
				x++;
				y=0;
			}
			map[99][99][0]=11;
			x=0; //y is already 0!
			z=4;
		    	cout << endl << "This is a text adventure by Alex Trahan and Zachary Taylor." << endl << "Defeat the Boss at (99,99,0) to win!" << endl << "Hit enter to continue." << endl;
			cin.get();
		}else{
			if(menu==2)
			{
				done++;
				load(par);
			}else{
				cout << "Please only input 1 or 2!" << endl;
			}
		}
	}
	while(true) //Never stop looping
	{
		num=map[x][y][z];
		map[x][y][z]=tile(x, y, z, num, health, def, m, quest, qx, qy, qz); //Uses this so that the tile function can easily change the map.
		if(quest==1)
		{
			cout << "Quest Destination: (" << qx << ", " << qy << ", " << qz << ")" << endl;
		}else{
			cout << "Quest Destination: No Quest" << endl;
		}
		cout << "Coordinates: " << "(" << x << ", " << y << ", " << z << ")" << endl << "Health: " << health << endl << "Defence: " << def << endl << "Medkits: " << m << endl;
		cout << "Command: "; 
		getline(cin, com);
		endline();
		cout << "---------------------------------------------------------------------------" << endl;
		command(com, x, y, z, num, health, def, m, qx, qy, qz, map, quest);
		cout << "---------------------------------------------------------------------------" << endl;
	}
} 
