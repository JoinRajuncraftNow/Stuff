import std.stdio,std.random,std.conv;
string vowel(string arg)
{
	return arg[0]=='A' || arg[0]=='E' || arg[0] == 'I' || arg[0]=='O' || arg[0]=='U'  ? "n" : "";
}
int gen(int x,int y)
{
	return uniform(x,y + 1);
}
void death()
{
	write("You have died!");
	while(true)
	{
	}
}
string getline()
{
	return readln[0..$-1];
}
void info(int health,int def,int m,int whealth)
{
	writeln("-------Combat-------");
	writeln("B-Big slash: 15-50 damage, 25% chance of missing.");
	writeln("D-Dodge: 75% chance of dodging all damage.");
	writeln("M-Medkit: Restores you to full health.");
	writeln("--------------------");
	write("Health: ");
	writeln(health);
	write("def: ");
	writeln(def);
	write("Medkits: ");
	writeln(m);
	write("Enemy Health: ");
	writeln(whealth);
	write("Command: ");
}
void boss(ref int health,int def,ref int m)
{
	int g,c,chance,damage,charge,t,whealth=1000,f,stun;
	while(health>0 && whealth>0)
	{
		string att;
		if(stun==0)
		{
			info(health,def,m,whealth);
			att=getline;
			if(att=="b"||att=="B")
			{
				writeln;
				writeln("Big Slash!");
				chance=gen(1,4);
				f=0;
				if(chance==1)
					writeln("Dodged!");
				else
					whealth-=gen(15,50);
			}
			else if(att=="q"||att=="Q")
			{
				writeln;
				writeln("Quick Slash!");
				chance=gen(1,20);
				f=0;
				if(chance==1)
					writeln("Dodged!");
				else
					whealth-=gen(5,15);
			}
			else if(att=="d"||att=="D")
			{
				writeln;
				writeln("Dodge!");
				chance=gen(1,4);
				f=0;
				if(chance==1||chance==2||chance==3)
				{
					f=1;
					writeln("Success");
					charge++;
				}
				else
					writeln("Failed.");
			}
			else if(att=="m"||att=="M")
			{
				writeln;
				writeln("Used a medkit.");
				m--;
				health=1000;
				f=0;
			}
			else
			{
				writeln("Not a valid command!");
				f=1;
			}
			writeln;
		}
		else
		{
			info(health,def,m,whealth);
			att=getline;
			writeln("###############");
			writeln("You are stunned!");
			writeln("###############"); //Line 90
		}
		stun=0;
		damage=0;
		if(f==0)
		{
			if(charge==0)
			{
				writeln("The Destroyer Attacks!"); //97
				damage=gen(20,100)-def;
				if(def>=damage)
				{
					if(f==1) writeln("Your armor blocked the damage!");
					damage=0; //useless, LOL
				}
				health-=damage;
				chance=gen(1,3);
				if(chance==2)
					charge++;
			}
			else if(charge==1)
			{
				writeln("The Destroyer is charging up for a heavy attack!");
				charge++;
			}
			else
			{
				stun=1;
				writeln("The Destroyer Charges!");
				writeln("You have been stunned!");
				damage=gen(25,200)-def;
				if(def>=damage)
				{
					if (f==1) writeln("Your armor blocked the damage!");
					damage=0;
				}
				else
				{
					health-=damage;
					charge=0;
				}
			}
		}
		g=0;
		write("You took ");
		write(damage);
		writeln(" damage!");
		f=0;
		if(health<1)
			death;
		while(whealth<1)
			write("#Congrats! You won!");
	}
}
//Line 152, combat function
void combat(int z,ref int num,ref int health,ref int def,ref int m)
{
	int j=gen(1,3);
	string monster;
	if(z==4)
	{
		if(j==3)
			monster="Bandit";
		else if(j==2)
			monster="Wyvern";
		else
			monster="Giant Snake";
		int g,c,chance,damage,charge,whealth=gen(100,200),t,f; //Line 169
		writeln("Something approaches");
		writeln("A" ~ vowel(monster) ~ " " ~ monster ~ " jumps out!"); //Line 170
		while(c==0)
		{
			string att;
			info(health,def,m,whealth);
			if(t==0)
			{
				att=getline; //Line 179
				if(att=="b"||att=="B")
				{
					writeln;
					writeln("Big Slash!");
					chance=gen(1,4);
					f=0;
					if(chance==1)
						writeln("Dodged!");
					else
						whealth-=gen(15,50);
				}
				else if(att=="q"||att=="Q")
				{
					writeln;
					writeln("Quick Slash!");
					chance=gen(1,20);
					f=0;
					if(chance==1)
						writeln("Dodged!");
					else
						whealth-=gen(5,15); //Line 201
					
				}
				else if(att=="d"||att=="D")
				{
					writeln;
					writeln("Dodge!");
					chance=gen(1,4);
					f=0;
					if(chance==1||chance==2||chance==3)
					{
						f=1;
						writeln("Success");
					}
					else
						writeln("Failed."); //Line 214
				}
				else if(att=="m"||att=="M")
				{
					f=1;
					if(m>0)
					{
						writeln;
						writeln("Used a medkit.");
						m--;
						health=1000;
					}
					else
						writeln("You have no medkits!");
				}
				else
				{
					writeln("Not a valid command!");
					f=1; //Line 231
				}
			}
			writeln;
			damage=0;
			if(charge==0)
			{
				writeln(monster ~ " Attacks!");
				damage=gen(5,25)-def;
				if(def>=damage&&f==0)
				{
					writeln("Your armor blocked the damage!");
					damage=0;
				}
				health-=damage;
				chance=gen(1,4);
				if(chance==1)
					charge++;
				else
					charge=0;
			}
			else if(charge==1)
			{
				writeln("The "~monster~" is charging up for a heavy attack");
				charge++;
			}
			else
			{
				writeln(monster~" Charges!");
				damage=gen(10,25)-def;
				if(def>=damage&&f==0)
				{
					writeln("Your armor blocked the damage!");
					damage=0;
				}
				health-=damage;
				charge=0;
			}
			g=0;
			write("You took ");
			write(damage);
			writeln(" damage!");
			if(health<1)
				death;
			if(whealth<1)
			{
				writeln("#############");
				writeln(monster ~ " Slain!");
				writeln("#############");
				chance=gen(1,3);
				if(chance==1)
				{
					def++;
					writeln("You loot some armor off of thhe corpse... Defence +1");
				}
				else
				{
					m++;
					writeln("You loot a medkit off of the corpse...");
				}
				t=1;
				c=1; //294
			}
		}
	}
	if(z==2||z==3)
	{
		if(j==3)
			monster="Giant Spider";
		else if(j==2)
			monster="Giant Scorpion";
		else
			monster="Insane Bandit";
		int g,c,chance,damage,charge,t,f,whealth=gen(200,300);
		writeln("Something approaches...");
		writeln("A" ~ vowel(monster) ~ " " ~ monster ~ " jumps out!");
		c=0;
		while(c==0)
		{
			string att;
			info(health,def,m,whealth);
			if(t==0)
			{
				att=getline; //320
				if(att=="b"||att=="B")
				{
					writeln;
					writeln("Big Slash!");
					chance=gen(1,4);
					f=0;
					if(chance==1)
						writeln("Dodged!");
					else
						whealth-=gen(15,50);
				}
				else if(att=="q"||att=="Q")
				{
					writeln;
					writeln("Quick Slash");
					chance=gen(1,20);
					f=0;
					if(chance==1)
						writeln("Dodged!");
					else
						whealth-=gen(5,15);
				}
				else if(att=="d"||att=="D")
				{
					writeln;
					writeln("Dodge!");
					chance=gen(1,4);
					f=0;
					if(chance==1||chance==2||chance==3)
					{
						f=1;
						writeln("Success");
					}
					else
						writeln("Failed.");
				}
				else if(att=="m"||att=="M")
				{
					f=1;
					if(m>0)
					{
						writeln;
						writeln("Used a medkit.");
						m--;
						health=1000;
					}
					else
						writeln("You have no medkits!");
				}
				else
				{
					writeln("Not a valid command!");
					f=1; //371
				}
			}
			writeln;
			damage=0;
			if(charge==0)
			{
				writeln(monster~" Attacks!");
				damage=gen(7,25)-def;
				if(def>=damage&&f==0)
				{
					writeln("Your armor blocked the damage!");
					damage=0;
				}
				health-=damage;
				chance=gen(1,4);
				if(chance==1)
					charge++;
				else
					charge=0;
			}
			else if(charge==1)
			{
				writeln("The "~monster~" is charging up for a heavy attack!");
				charge++;
			}
			else
			{
				writeln(monster ~ " Charges!");
				damage=gen(15,135)-def;
				if(def>=damage&&f==0)
				{
					writeln("Your armor blocked the damage");
					damage=0;
				}
				health-=damage;
				charge=0;
			}
			g=0;
			write("You took ");
			write(damage);
			writeln(" damage!");
			if(health<1)
				death;
			if(whealth<1)
			{
				writeln("#############");
				writeln(monster ~ " Slain!");
				writeln("#############"); //421
				chance=gen(1,3);
				if(chance==1)
				{
					def++;
					writeln("You loot some armor off of the corpse...");
				}
				else if(chance==2||chance==3)
				{
					m++;
					writeln("You loot a medkit off of the corpse...");
				}
				t=1;
				c=1; //435
			}
		}
	}
	if(z==1||z==0)
	{
		if(j==3)
			monster="Earth Elemental";
		else if(j==2)
			monster="Undead Bandit";
		else
			monster="Giant Mole";
		int g,c,chance,damage,charge,t,f,whealth=gen(200,300);
		writeln("Something approaches...");
		writeln("A"~vowel(monster)~" "~monster~" jumps out!");
		c=0;
		while(c==0)
		{
			string att;
			info(health,def,m,whealth);
			if(t==0)
			{
				att=getline;
				if(att=="b"||att=="B")
				{
					writeln;
					writeln("Big Slash!");
					chance=gen(1,4);
					f=0;
					if(chance==1)
						writeln("Dodged!");
					else
						whealth-=gen(15,50);
				}
				else if(att=="q"||att=="Q")
				{
					writeln;
					writeln("Quick Slash!");
					chance=gen(1,20);
					f=0;
					if(chance==1)
						writeln("Dodged!");
					else
						whealth-=gen(5,15);
				}
				else if(att=="d"||att=="D")
				{
					writeln;
					writeln("Dodge!");
					chance=gen(1,4);
					f=0;
					if(chance==1||chance==2||chance==3)
					{
						f=1;
						writeln("Success");
					}
					else
						writeln("Failed.");
				}
				else if(att=="m"||att=="M")
				{
					f=1;
					if(m>0)
					{
						writeln;
						writeln("Used a medkit.");
						m--;
						health=1000;
					}
					else
						writeln("You have no medkits!");
				}
				else
				{
					writeln("Not a valid command!");
					f=1;
				}
			}
			writeln;
			damage=0;
			if(charge==0)
			{
				writeln(monster ~ " Attacks!");
				damage=gen(7,25)-def;
				if(def>=damage&&f==0)
				{
					writeln("Your armor blocked the damage!");
					damage=0;
				}
				health-=damage;
				chance=gen(1,4);
				if(chance==1)
					charge++;
				else
					charge=0;
			}
			else if(charge==1)
			{
				writeln("The "~monster~" is charging up for a heavy attack!");
				charge++;
			}
			else
			{
				writeln(monster ~ " Charges!");
				damage=gen(15,135)-def;
				if(def>=damage&&f==0)
				{
					writeln("Your armor blocked the damage!");
					damage=0;
				}
				health-=damage;
				charge=0;
			}
			g=0;
			write("You took ");
			write(damage);
			writeln(" damage!");
			if(health<1)
				death;
			if(whealth<1)
			{
				writeln("#############");
				writeln(monster ~ " Slain!");
				writeln("#############");
				chance=gen(1,3);
				if(chance==1)
				{
					def++;
					writeln("You loot some armor off of the corpse... Defence +1");
				}
				if(chance==2||chance==3)
				{
					m++;
					writeln("You loot a medkit off of the corpse...");
				}
				t=1;
				c=1;
			}
		}
	}
}
//At line 584!!!!! Heck Yeah!

int count(string count,char test)
{
	int x,output;
	while(x<count.length)
	{
		if(count[x]==test)
			output++;
		x++;
	}
	return output;
}

void up(ref int x,ref int y,ref int z,int h)
{
	if(h==10)
	{
		if(z!=4)
		{
			z++;
			writeln("You climb up the stairs, but a doorway closes behind you... You are locked out!");
		}
		else
			writeln("You jump as high as you can, but sadly you cannot fly.");
	}
	else
		writeln("You can't go up from here");
}

void down(ref int x,ref int y,ref int z,int h)
{
	if(h==10)
	{
		if(z!=0)
		{
			z--;
			writeln("You start to climb down, then the ground collapses underneath you!");
		}
		else
			writeln("There are no tunnels leading down from here...");
	}
	else
		writeln("You can't go down frrom here");
}

void north(ref int x,ref int y,ref int z)
{
	if(x!=99)
	{
		x++;
		writeln("You trek north");
	}
	else
		writeln("Something tells you that you can't leave the area...");
}
void south(ref int x,ref int y,ref int z)
{
	if(x!=0)
	{
		writeln("You trek south");
		x--;
	}
	else
		writeln("Something tells you that you can't leave the area...");
}

void east(ref int x,ref int y,ref int z)
{
	if(y!=99)
	{
		writeln("You trek east");
		y++;
	}
	else
		writeln("Something tells you that you can't leave the area...");
}

void west(ref int x,ref int y,ref int z)
{
	if(y!=0)
	{
		writeln("You trek west");
		y--;
	}
	else
		writeln("Something tells you that you can't leave the area...");
}

void command(string input,ref int x,ref int y,ref int z,ref int h,ref int health)
{
	if(input=="n"||input=="N")
		north(x,y,z);
	else if(input=="s"||input=="S")
		south(x,y,z);
	else if(input=="e"||input=="E")
		east(x,y,z);
	else if(input=="w"||input=="W")
		west(x,y,z);
	else if(input=="h"||input=="H")
	{
		writeln("Commands:");
		writeln("E-east");
		writeln("W-west");
		writeln("N-north");
		writeln("S-South");
		writeln("D-down");
		writeln("U-up");
	}
	else if(input=="d"||input=="D")
		down(x,y,z,h);
	else if(input=="u"||input=="U")
		up(x,y,z,h);
	else if(input=="116728")
	{
		write("X: ");
		x=to!int(getline);
		write("Y: ");
		y=to!int(getline);
		write("Z: ");
		z=to!int(getline);
		write("Health: ");
		health=to!int(getline);
	}
	else
		writeln("That is not a valid command, type H for help.");
}

int tile(int z,ref int num,ref int health,ref int def,ref int m)
{
	if(z==4)
	{
		if(num==1||num==3||num==12)
		{
			writeln("[Forest]");
			return 1;
		}
		if(num==4||num==6)
		{
			writeln("[Swamp]");
			return 4;
		}
		if(num==7||num==8||num==9)
		{
			writeln("[Desert]");
			return 7;
		}
		if(num==10)
		{
			writeln("[Cave Entrance]");
			return 10;
		}
		if(num==2)
		{
			combat(z,num,health,def,m);
			return 12;
		}
		if(num==5||num==15)
		{
			writeln("[Ruins]");
			return 15;
		}
	}
	if(num==1||num==3||num==12)
	{
		writeln("[Cavern]");
		return 1;
	}
	if(num==4||num==5||num==6)
	{
		writeln("[Tunnel]");
		return 4;
	}
	if(num==7||num==8||num==9)
	{
		writeln("[Cave]");
		return 7;
	}
	if(num==10)
	{
		writeln("[Stairway]");
		return 10;
	}
	if(num==2)
	{
		combat(z,num,health,def,m);
		return 12;
	}
	if(num==11)
	{
		writeln("A feeling of hopelessness overwhelms you...");
		writeln("-----BOSS FIGHT-----");
		boss(health,def,m);
	}
	assert(0);
}
void main()
{
	string com,pause;
	int x,y,z,death_,def,num,m;
	int map[100][100][5];
	writeln("Generating Map...");
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
	writeln;
	writeln("This is the translated version of a text adventure by Alex Trahan, translated by Zachary Taylor.");
	writeln("Defeat the Boss at (99,99,0) to win!");
	writeln("Hit any key to continue.");
	pause=getline;
	int health=1000,l;
	while(true)
	{
		num=map[x][y][z];
		map[x][y][z]=tile(z,num,health,def,m);
		write("Coordinates: (");
		write(x);
		write(", ");
		write(y);
		write(", ");
		write(z);
		writeln(")"); //841
		write("Command: ");
		com=getline;
		writeln;
		writeln;
		writeln("---------------------------------------------------------------------------");
		command(com,x,y,z,num,health);
		writeln("---------------------------------------------------------------------------");
	}
}
