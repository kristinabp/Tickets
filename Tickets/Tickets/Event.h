#ifndef EVENT_H
#define EVENT_H

#include "Date.h"
#include "Hall.h"
#include <vector>
#include <string>

enum SeatStatus
{
	NOTRESERVED = 0, RESERVED = 1, PAID = 2
};

class Event
{
private:
	std::string name;
	Date date;
	Hall hall;
	std::vector<std::vector<std::string>> note;
    std::vector<std::vector<std::string>> id;
	std::vector<std::vector<SeatStatus>> seats;
	int freeSeats;
	int soldSeats;

	void copy(const Event& other);
	void createId(int row, int seat);
	std::string takeIdNote(std::string note);
	void initalize();

public:
	Event();
	Event(const std::string name, const Date& date, const Hall& hall);
	Event(const std::string name, int day, int month, int year, int num, int rows, int seats);
	Event(const Event& other);
	~Event();

	Event& operator=(const Event& other);
	bool operator==(const Event& other)const;

	Event* clone()const;

	std::string getName()const;
	Date getDate()const;
	Hall getHall()const;
	int getRows()const;
	int getSeats()const;
	std::string getId(int row, int seat)const;
	int getFreeSeats()const;
	int getSoldSeats()const;

	void setNote(const std::string note, int row, int seat);

	void printBooked()const;
	void printPaid() const;
	bool checkPaid(int row, int seat)const;

	void bookSeat(int row, int seat, std::string name);
	void unbookSeat(int row, int seat);
	void buy(int row, int seat, std::string name);

	void printSeats()const;
	void print() const;
	void save(std::ostream& os);
};

#endif // !EVENT_H


