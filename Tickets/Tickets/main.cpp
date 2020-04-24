#include <iostream>
#include <vector>
#include "System.h"

int main()
{
	System s;
	s.addEvent(new Event("Notebook",Date(24,4,2020),Hall(2,5,5))).
	  addEvent(new Event("Avengers", Date(25, 4, 2020), Hall(2, 5, 5)));
	s.buy("Avengers", Date(25, 4, 2020), 2, 2);
	s.buy("Notebook", Date(24, 4, 2020), 1, 3);
	s.buy("Notebook", Date(24, 4, 2020), 2, 3);
	//s.bookings(Date(24, 4, 2020));
	s.report(Date(24,4,2020),Date(29,4,2020),Hall(2,5,5));
	
	return system("pause");
}