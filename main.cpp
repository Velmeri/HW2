#include <iostream>
#include <fstream>

using namespace std;

void Note(const char* str1, char* str2);

class Student {
	char* FullName;
	char* date;
	char* phone;
	char* city;
	char* country;
	char* inst;
	char* InstCity;
	char* InstCountry;
	char* grup;
public:
	Student();
	Student(const char* FN, const char* d, const char* p, const char* c, const char* co, const char* i, const char* ic, const char* ico, const char* g);
	~Student();
	void Print();
	void SetFullName(const char* str);
	void SetDate(const char* str);
	void SetPhone(const char* str);
	void SetCity(const char* str);
	void SetCountry(const char* str);
	void SetInst(const char* str);
	void SetInstCity(const char* str);
	void SetInstCountry(const char* str);
	void SetGrup(const char* str);
	char* GetFullName();
	char* GetDate();
	char* GetPhone();
	char* GetCity();
	char* GetInst();
	char* GetInstCity();
	char* GetInstCountry();
	char* GetGrup();
};

class Point {
	int x, y, z;
public:
	Point();
	Point(int x, int y, int z);
	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);
	int GetX();
	int GetY();
	int GetZ();
	void Save(const char* path);
	void Load(const char* path);
};

int main() {
	setlocale(LC_ALL, "ru");
	Point p1(1, 2, 3);
	p1.Save("MyFile");
	Point p2;
	p2.Load("MyFile");
	cout << p2.GetX() << endl << p2.GetY() << endl << p2.GetZ();

	Student me; ("Mykhailiuchenko D. E.", "03.05.2004", "0685774520,", "Bergen", "Norway", "Odessa", "Ukraine", "КН-П-211");
	me.Print();

	return 0;
}

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

void Point::SetZ(int z) {
	this->z = z;
}

int Point::GetX()
{
	return x;
}

int Point::GetY()
{
	return y;
}

int Point::GetZ()
{
	return z;
}

void Point::Save(const char* path)
{
	ofstream file;
	file.open(path);
	if (!file.is_open()) {
		cout << "ERROR";
	}
	else {
		file << (char)x << (char)y << (char)z;
	}
	file.close();
}

void Point::Load(const char* path)
{
	ifstream file;
	file.open(path);
	if (!file.is_open()) {
		cout << "ERROR";
	}
	else {
		char str[4] = { 0, 0, 0 };
		file >> str;
		x = str[0];
		y = str[1];
		z = str[2];
	}
	file.close();
}

void Note(const char* StrL, char* StrR)
{
	int size = 0;
	for (int i = 0; StrL[i] == '\0'; i++)
		size++;
	StrR = new char[size];
	for (int i = 0; i < size; i++)
		StrR[i] = StrL[i];
}


Student::Student()
{
	FullName = nullptr;
	date = nullptr;
	city = nullptr;
	country = nullptr;
	inst = nullptr;
	InstCity = nullptr;
	InstCountry = nullptr;
	grup = nullptr;

}

Student::Student(const char* FN, const char* d, const char* p, const char* c, const char* co, const char* i, const char* ic, const char* ico, const char* g)
{
	Note (FN, FullName);
	Note(d, date);
	Note(p, phone);
	Note(c, city);
	Note(co, country);
	Note(i, inst);
	Note(ic, InstCity);
	Note(ico, InstCountry);
	Note(g, grup);
}

Student::~Student()
{
	delete FullName;
	delete[] FullName;
	delete date;
	delete[] date;
	delete phone;
	delete[] phone;
	delete city;
	delete[] city;
	delete country;
	delete[] country;
	delete inst;
	delete[] inst;
	delete InstCity;
	delete[] InstCity;
	delete InstCountry;
	delete[] InstCountry;
	delete grup;
	delete[] grup;
}

void Student::Print()
{
	cout << "Name: " << FullName << endl;
	cout << "Date: " << date << endl;
	cout << "Phone: " << phone << endl;
	cout << "City: " << city << endl;
	cout << "Country: " << country << endl;
	cout << "Inst city: " << InstCity << endl;
	cout << "Inst country" << country << endl;
	cout << "Grupe: " << grup;
}

void Student::SetFullName(const char* str)
{
	Note(str, FullName);
}

void Student::SetDate(const char* str)
{
	Note(str, date);
}

void Student::SetPhone(const char* str)
{
	Note(str, phone);
}

void Student::SetCity(const char* str)
{
	Note(str, city);
}

void Student::SetCountry(const char* str)
{
	Note(str, country);
}

void Student::SetInst(const char* str)
{
	Note(str, inst);
}

void Student::SetInstCity(const char* str)
{
	Note(str, InstCity);
}

void Student::SetInstCountry(const char* str)
{
	Note(str, InstCountry);
}

void Student::SetGrup(const char* str)
{
	Note(str, grup);
}

char* Student::GetFullName()
{
	return FullName;
}

char* Student::GetDate()
{
	return date;
}

char* Student::GetPhone()
{
	return phone;
}

char* Student::GetCity()
{
	return city;
}

char* Student::GetInst()
{
	return inst;
}

char* Student::GetInstCity()
{
	return InstCity;
}

char* Student::GetInstCountry()
{
	return InstCountry;
}

char* Student::GetGrup()
{
	return grup;
}
