#include <iostream>
#include <vector>
#include "System.h"

void Test1()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 5, 5))).
		    addEvent(new Event("The Wizard of Oz", Date(24, 4, 2020), Hall(1, 10, 10))).
		    addEvent(new Event("Kink Kong", Date(25, 4, 2020), Hall(4, 5, 5)));
	theatre.print();
}

void Test2()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 5, 5)));
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 1, "book");
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 1, "book");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 2);
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 1);
	theatre.freeSeats("The Avengers", Date(25, 4, 2020));
	theatre.unbook("The Avengers", Date(25, 4, 2020), 1, 1);
	theatre.freeSeats("The Avengers", Date(25, 4, 2020));
}

void Test3()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 5, 5))).
		    addEvent(new Event("The Avengers", Date(26, 4, 2020), Hall(2, 5, 5))).
		    addEvent(new Event("The Wizard of Oz", Date(25, 4, 2020), Hall(1, 10, 10)));
	theatre.book("The Avengers", Date(26, 4, 2020), 1, 1, "book");
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 3, "book");
	theatre.book("The Wizard of Oz", Date(25, 4, 2020), 2, 2, "book");
	theatre.book("The Wizard of Oz", Date(25, 4, 2020), 2, 4, "book");
	theatre.bookings("The Avengers", Date(25, 4, 2020));
	theatre.bookings(Date(25, 4, 2020));
	theatre.bookings("The Avengers");

}

void Test4()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 5, 5))).
		addEvent(new Event("The Avengers", Date(26, 4, 2020), Hall(2, 5, 5))).
		addEvent(new Event("The Wizard of Oz", Date(25, 4, 2020), Hall(3, 5, 5)));
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 1);
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 3);
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 2);
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 4);
	theatre.check("1-1-T-24-4");
	theatre.check("1-1-T-26-4");
}

void Test5()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 5, 5))).
		addEvent(new Event("The Avengers", Date(26, 4, 2020), Hall(2, 5, 5))).
		addEvent(new Event("The Wizard of Oz", Date(25, 4, 2020), Hall(3, 5, 5)));
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 1);
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 3);
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 2);
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 4);
	theatre.report(Date(25, 4, 2020), Date(27, 4, 2020), Hall(2, 5, 5));
	theatre.report(Date(25, 4, 2020), Date(27, 4, 2020));
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();

	/*std::vector<std::vector<std::string>> id(5);
	id[0].push_back("1XX-XXX");
	id[0].push_back("1XX-XXX");
	id[1].push_back("1XX-XXX");
	for (size_t i = 0; i < id[0].size(); i++) { 
		std:: cout << id[0][i] << " ";
	}*/

	
	return system("pause");
}