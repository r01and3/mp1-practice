#include "Allday.h"

Allday::Allday(string _str, Date &_date) : Task(_str, _date) {}

void Allday::print() const{
	cout << task << " ";
	date.out();
}