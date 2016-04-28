the TYPED VERSION OF DOM - D

class Window
{
	public:
	bool closed;
	string defaultStatus;
	Document document;
	ElementIFRAME frameElement;
	ElementIFRAME[] frames;
	History history;
	int innerHeight;
	int innerWidth;
	int length;
	//LocalStorage localStorage
	Location location;
	string name;
	Navigator navigator;
	Window opener;
	int outerHeight;
	int outerWidth;
	int pageXOffset
	int pageYOffset;
	Window parent;
	Screen screen;
	int screenLeft;
	int screenTop;
	int scrollX;
	int scrollY;
	Window self;
	string status;
	Window top;
	void alert(string);
	string atob(string);
	void blur();
	string btoa(string);
	void clearInterval(int);
	void clearTimeout(int);
	void close(void);
	bool confirm();
	bool confirm(string);
	void focus();
	CSSStyleDeclaration getComputedStyle(string);
	CSSStyleDeclaration getComputedStyle(string,string);
	void moveBy(int,int);
	void moveTo(int,int);
	Window open();
	Window open(string);
	Window open(string,string);
	Window open(string,string,string);
	Window open(string,string,string,bool);
	void print();
	string prompt(string);
	string prompt(string,string);
	void resizeBy(int,int);
	void resizeTo(int,int);
	deprecated void scroll(int,int);
	void scrollBy(int,int);
	void scrollTo(int,int);
	int setInterval(void function(),float); //Don't know how to get the arguments for this to work!
	int setTimeout(void function(),float);
	void stop();
}
class Navigator
{
	public:
	string appCodeName;
	string appName;
	string appVersion;
	bool cookieEnabled;
	//Geolocation geolocation
	string language;
	bool onLine;
	string platform;
	string product;
	string userAgent;
	bool javaEnabled();
	deprecated bool taintEnabled();
}
class Screen
{
	public:
	int availHeight;
	int availWidth;
	int colorDepth;
	int height;
	int pixelDepth;
	int width;
}
class History
{
	public:
	int length;
	void back();
	void forward();
	void go(int);
	void go(string);
}
class Location
{
	public:
	string hash;
	string host;
	string hostname;
	string href;
	string origin;
	string pathname;
	string port;
	string protocol;
	string search;
	void assign(string);
	void reload();
	void reload(bool);
	void replace(string);
}
