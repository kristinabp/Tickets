#ifndef EVENT_H
#define EVENT_H

#include "Date.h"
#include "Hall.h"
#include <vector>
#include <string>

class Event
{
private:
	std::string name;
	Date date;
	Hall hall;
	std::string note;
	std::vector<std::vector<int>> seats;
	int freeSeats;

	void copy(const Event& other);

public:
	Event();
	Event(const std::string name, const Date& date, const Hall& hall);
	Event(const Event& other);
	~Event();

	Event& operator=(const Event& other);
	bool operator==(const Event& other)const;

	Event* clone()const;

	//std::string getName()const;

	std::string getName()const;
	Date getDate()const;
	Hall getHall()const;
	int getRows()const;
	int getSeats()const;

	void bookSeat(int row, int seat);
	void unbookSeat(int row, int seat);
	bool checkSeat(int row, int seat) const;

	void printSeats()const;
	void print() const;
};

#endif // !EVENT_H


