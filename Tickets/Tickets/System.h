#ifndef SYSTEM_H
#define SYSTEM_H

#include "Event.h"
#include <algorithm>   
#include <fstream>
#include <sstream> 
#include <cstring>
#include <iostream>

class System
{
private:
	std::vector <Event*> events;
	std::vector <Hall*> availableHalls;
	std::string fileName;
	bool isOpen;

public:
	System();
	System(std::vector<Event*> events);

	void open(const std::string fileName);
	void save();
	void saveAs(const std::string fileName);
	void close();
	void help();
	void exit();

	void addEvent(Event* event);
	void addHall(Hall* hall);
	void freeSeats(const std::string name, const Date& date);
	void book(const std::string name, const Date& date, int row, int seat, const std::string note);
	void unbook(const std::string name, const Date& date, int row, int seat);
	void buy(const std::string name, const Date& date, int row, int seat, const std::string note);
	void bookings(const std::string name, const Date& date)const;
	void bookings(const std::string name)const;
	void bookings(const Date& date)const;
	void check(std::string id);
	void report(const Date& from, const Date& to,int hall);
	void report(const Date& from, const Date& to);
	void mostWatched();
	void underTen(const Date& from, const Date& to, std::ostream& os);
	
	void print()const;
};
#endif // !SYSTEM_H

