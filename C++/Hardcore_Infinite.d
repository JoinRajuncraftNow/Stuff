bool exists(string name)
{
	import std.file : exists;
	return exists(name);
}
void save_others(int health, int m, int def, int x, int y, int z, int qx, int qy, int qz)
{
	import std.stdio : File; //that's odd
	import std.conv : to;
	auto outf = File("save_file.txt","w");
	void write(string arg)
	{
		outf.writeln(arg);
	}
	write(health);write(m);write(def);write(x);write(y);write(z);write(qx);write(qy);write(qz);
	outf.close();
}
void load_others(ref int health,ref int m,ref int health,ref int def,ref int x,ref int y,ref int z,ref int qx,ref int qy,ref int qz)
{
	if(!exists("save_file.txt"))
	{
		return;
	}
}
