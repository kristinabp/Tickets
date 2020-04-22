#ifndef SYSTEM_H
#define SYSTEM_H

#include "Event.h"

class System
{
private:
	std::vector <Event*> events;

public:
	System();
	System(std::vector<Event*> events);

	System& addEvent(Event* event);
	void freeSeats(const std::string name, const Date& date);
	bool book(const std::string name, const Date& date, int row, int seat, const std::string note);
	bool unbook(const std::string name, const Date& date, int row, int seat);

	void print()const;

};
#endif // !SYSTEM_H

