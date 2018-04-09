#include <fstream>
#include <iomanip>
#include <iostream>
// Структура Дата DD.MM.YYYY
struct Date
{
	int Day, Month, Year;

	Date() : Day(1), Month(1), Year(1700) {}
	Date(int d, int m, int y) : Day(d), Month(m), Year(y)
	{
		if ((d<1)||(d>31)) throw ("Incorrect day");
		if ((m<1)||(m>12)) throw ("Incorrect month");
		if ((y<1700)||(y>2200)) throw ("Incorrect year");
	}

	bool operator==(const Date &d) const
	{ // для поиска по дате
		return (Day == d.Day)
			&& (Month == d.Month)
			&& (Year == d.Year);
	}
};
// ----------------------------------------------------------------------------
// Операторы ввода/вывода Даты в поток
std::istream & operator>>(std::istream &is, Date &d)
{
	char dot; // между числами сюда считывается точка (любой разделитель)
	try
	{
		is >> d.Day >> dot >> d.Month >> dot >> d.Year;

		if ((d.Day<1)||(d.Day>31))
			throw ("Incorrect day");
		if ((d.Month<1)||(d.Month>12))
			throw ("Incorrect month");
		if ((d.Year<1700)||(d.Year>2200))
			throw ("Incorrect year");
	}
	catch (char * err)
	{ std::cout << err << std::endl; }

	return is;
}
std::ostream & operator<<(std::ostream &os, const Date &d)
{
	return os << std::setfill('0') << std::setw(2) << d.Day
		<< '.' << std::setfill('0') << std::setw(2) << d.Month
		<< '.' << d.Year;
}
//-----------------------------------------------------------------------------

struct Razmery
{
	float length;
	float height;
	float weight;

	Razmery() {}
	Razmery(float l, float h, float w) : length(l), height(h), weight(w){}

};