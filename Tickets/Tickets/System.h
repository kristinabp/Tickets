#ifndef SYSTEM_H
#define SYSTEM_H

#include "Event.h"
#include <algorithm>   

class System
{
private:
	std::vector <Event*> events;
	
	void sort();

public:
	System();
	System(std::vector<Event*> events);

	System& addEvent(Event* event);
	void freeSeats(const std::string name, const Date& date);
	bool book(const std::string name, const Date& date, int row, int seat, const std::string note);
	bool unbook(const std::string name, const Date& date, int row, int seat);
	bool buy(const std::string name, const Date& date, int row, int seat, const std::string note);
	void bookings(const std::string name, const Date& date)const;
	void bookings(const std::string name)const;
	void bookings(const Date& date)const;
	void check(std::string id);
	void report(const Date& from, const Date& to, const Hall& hall);
	void report(const Date& from, const Date& to);
	void mostWatched();
	void underTen(const Date& from, const Date& to);

	void print()const;

};
#endif // !SYSTEM_H

