#include <iostream>
#include <vector>
#include "System.h"

int main()
{
	Event* a=new Event("Avengers", Date(24, 4, 2020), Hall(2, 5, 5));
	System s;
	s.addEvent(new Event("Notebook",Date(24,4,2020),Hall(2,10,12))).addEvent(a);
	delete a;
	s.book("Avengers", Date(24, 4, 2020), 1, 2, "book");
	s.book("Avengers", Date(24, 4, 2020), 2, 2, "book");
	s.book("Notebook", Date(24, 4, 2020), 5, 8, " ");
	//s.unbook("Avengers", Date(24, 4, 2020), 1, 2);
	//s.buy("Avengers", Date(24, 4, 2020), 2, 2);
	//s.freeSeats("Avengers", Date(24, 4, 2020));
	s.check(1002);
	return system("pause");
}