#include <iostream>
#include <set>

using namespace std;

class Parquet
{
	int width, length;

	public:
		Parquet(int w, int l){ this->width = w; this->length = l; };
		~Parquet();
		void setWidth(int w){ this->width = w; };
		void setLength(int l){ this->length = l; };
		void setWidthLength(int w, int l){ this->width = w; this->length = l; };
		int getWidth(){ return this->width; };
		int getLength(){ return this->length; };
};

class Window
{

	int width, height;

	public:
		Window(int w, int h){ this->width = w; this->height = h; };
		~Window();
		void setWidth(int w){ this->width = w; };
		void setHeight(int h){ this->height = h; };
		void setWidthHeight(int w, int h){ this->width = w; this->height = h; };
		int getWidth(){ return this->width; };
		int getHeight(){ return this->height; };
};

class Color
{

	int red, green, blue;

	public:
		Color(int r, int g, int b){ this->red = r; this->green = g; this->blue = b; };
		~Color();
		void setRed(int r){ this->red = r; };
		void setGreen(int g){ this->green = g; };
		void setBlue(int b){ this->blue = b; };
		int getRed(){ return this->red; };
		int getGreen(){ return this->green; };
		int getBlue(){ return this->blue; };

};

class Room
{

	int length, height, width;
	Color* color;
	double liters;
	set<Parquet*> parquets;
	set<Window*> windows;

	public:
		Room(int l, int h, int w, Color* c, double lit){ this->length = l; this->height = h; this->width = w; this->color = c; this->liters = lit; };
		Room(int l, int h, int w){ this->length = l; this->height = h; this->width = w; };
		~Room();
		void setLength(int l){ this->length = l; };
		void setHeight(int h){ this->height = h; };
		void setWidth(int w){ this->width = w; };
		void setColor(Color* c){ this->color = c; };
		void setLiters(double l){ this->liters = l; };

		void addParquet(Parquet* p){ this->parquets.insert(p); };
		void addWindow(Window* w){ this->windows.insert(w); };
		void delParquet(Parquet* p){ this->parquets.erase(p); };
		void delWindow(Window* w){ this->windows.erase(w); };

		int getLength(){ return this->length; };
		int getHeight(){ return this->height; };
		int getWidth(){ return this->width; };
		Color* getColor(){ return this->color; };
		double getLiters(){ return this->liters; };
		Parquet* getParquet(int i){ set<Parquet*>::iterator it = this->parquets.begin(); for(; i!=0; i--)it++; return *it; };
		Window* getWindow(int i){ set<Window*>::iterator it = this->windows.begin(); for(; i!=0; i--)it++; return *it; };
};

class Flat
{
	int numberOfRooms;
	set<Room*> rooms;

	public:
		Flat(){ this->numberOfRooms = 0; };
		~Flat();

		void addRoom(Room* r){ this->rooms.insert(r); this->numberOfRooms++; };
		void delRoom(Room* r){ this->rooms.erase(r); this->numberOfRooms--; };

		int getNumberOfRooms(){ return this->numberOfRooms; };
		Room* getRoom(int i){ set<Room*>::iterator it = this->rooms.begin(); for(; i!=0; i--)it++; return *it; };
};

class House
{

	int numbersOfFloors, numberOfFlats;
	set<Flat*> flats;

	public:
		House(int numOfFloors, int numOfFlats){ this->numbersOfFloors = numOfFloors; this->numberOfFlats = numOfFlats; };
		~House();

		void setNumOfFloors(int n){ this->numbersOfFloors = n; };
		void setNumOfFlats(int n){ this->numberOfFlats = n; };
		int getNumOfFloors(){ return this->numbersOfFloors; };
		int getNumOfFlats(){ return this->numberOfFlats; };

		void addFlat(Flat* f){ this->flats.insert(f); };
		void delFlat(Flat* f){ this->flats.erase(f); };
		Flat* getFlat(int i){ set<Flat*>::iterator it = this->flats.begin(); for(; i!=0; i--)it++; return *it; };
};

class Street
{

	double volumeOfHouses;
	double liters;
	int parquets;
	int glass;
	set<House*> houses;

	public:
		Street(double v, double l, int p, int g){ this->volumeOfHouses = v; this->liters = l; this->parquets = p; this->glass = g; };
		~Street();
		void setVolumeOfHouses(double v){ this->volumeOfHouses = v; };
		void setLiters(double l){ this->liters = l; };
		void setParquets(int p){ this->parquets = p; };
		void setGlasses(int g){ this->glass = g; };
		double getVolumeOfHouses(){ return this->volumeOfHouses; };
		double getLiters(){ return this->liters; };
		int getParquets(){ return this->parquets; };
		int getGlasses(){ return this->glass; };

		void addHouse(House* h){ this->houses.insert(h); };
		void delHouse(House* h){ this->houses.erase(h); };
		House* getHouse(int i){ set<House*>::iterator it = this->houses.begin(); for(; i!=0; i--)it++; return *it; };

};

int main()
{

	Parquet* p1 = new Parquet(10, 10);
	Parquet* p2 = new Parquet(20, 20);

	Window* w1 = new Window(10, 10);
	Window* w2 = new Window(20, 20);

	Color* red = new Color(255, 0, 0);
	Color* green = new Color(0, 255, 0);
	Color* blue = new Color(0, 0, 255);

	Room* r1 = new Room(10, 10, 10, red, 10.0);
	Room* r2 = new Room(20, 20, 20, green, 20.0);
	Room* r3 = new Room(30, 30, 30, blue, 30.0);

	r1->addParquet(p1);
	r2->addParquet(p2);
	r3->addParquet(p1);
	r3->addParquet(p2);

	r1->addWindow(w1);
	r2->addWindow(w2);
	r3->addWindow(w1);
	r3->addWindow(w2);

	Flat* f1 = new Flat();
	Flat* f2 = new Flat();

	f1->addRoom(r1);
	f2->addRoom(r2);
	f2->addRoom(r3);



	House* h1 = new House(2, 1);
	House* h2 = new House(1, 2);

	h1->addFlat(f1);
	h1->addFlat(f2);

	h2->addFlat(f1);
	
	Street* s = new Street(10.0, 10.0, 10, 10);
	s->addHouse(h1);
	s->addHouse(h2);

	cout<<"parquet 1:\twidth: "<< p1->getWidth() <<"\tlength: "<< p1->getLength() << endl;
	cout<<"parquet 2:\twidth: "<< p2->getWidth() <<"\tlength: "<< p2->getLength() << endl;

	cout<<"window 1:\twidth: "<< w1->getWidth() <<"\theight: "<< w1->getHeight() << endl;
	cout<<"window 2:\twidth: "<< w2->getWidth() <<"\theight: "<< w2->getHeight() << endl;

	cout<<"color red:\tred: "<< red->getRed() <<"\tgreen: "<< red->getGreen() <<"\tblue: "<< red->getBlue()  << endl;
	cout<<"color green:\tred:"<< green->getRed() <<"\t\tgreen: "<< green->getGreen() <<"\tblue: "<< green->getBlue() << endl;
	cout<<"color blue:\tred:"<< blue->getRed() <<"\t\tgreen: "<< blue->getGreen() <<"\tblue: "<< blue->getBlue() << endl;

	cout<<"room 1:\t\twidth: "<< r1->getWidth() <<"\tlength: "<< r1->getLength() <<"\theight: "<< r1->getHeight() <<"\tcolor point: "<< r1->getColor() <<"\tlites: "<< r1->getLiters() <<"\tparquets point: "<< r1->getParquet(0) <<"\t\twindow point: "<< r1->getWindow(0) <<"\t\tpoint: "<< r1 << endl;
	cout<<"room 2:\t\twidth: "<< r2->getWidth() <<"\tlength: "<< r2->getLength() <<"\theight: "<< r2->getHeight() <<"\tcolor point: "<< r2->getColor() <<"\tlites: "<< r2->getLiters() <<"\tparquets point: "<< r2->getParquet(0) <<"\t\twindow point: "<< r2->getWindow(0) <<"\t\tpoint: "<< r2 << endl;
	cout<<"room 3:\t\twidth: "<< r3->getWidth() <<"\tlength: "<< r3->getLength() <<"\theight: "<< r3->getHeight() <<"\tcolor point: "<< r3->getColor() <<"\tlites: "<< r3->getLiters() <<"\tparquets point: "<< r3->getParquet(0) <<", "<< r3->getParquet(1) <<"\twindow point: "<< r3->getWindow(0) <<", "<< r3->getWindow(1) <<"\tpoint: "<< r3 << endl;
	
	cout<<"flat 1:\tnumber of rooms: "<< f1->getNumberOfRooms() <<"\trooms: "<< f1->getRoom(0) << endl;
	cout<<"flat 2:\tnumber of rooms: "<< f2->getNumberOfRooms() <<"\trooms: "<< f2->getRoom(0) <<", "<< f2->getRoom(1) << endl;
	
	cout<<"house 1:\tnumber of flat: "<< h1->getNumOfFlats() <<"\tnumber of floors: "<< h1->getNumOfFloors() << endl;
	cout<<"house 2:\tnumber of flat: "<< h2->getNumOfFlats() <<"\tnumber of floors: "<< h2->getNumOfFloors() << endl;
	
	cout<<"street:\tvolume of houses: "<< s->getVolumeOfHouses() <<"\tliters of houses: "<< s->getLiters() <<"\tparquets: "<< s->getParquets() <<"\tglasses: "<< s->getGlasses() <<"\thouses: "<< s->getHouse(0) <<", "<< s->getHouse(1) <<"\tpoint: "<< s << endl;
	
	return 0;
}