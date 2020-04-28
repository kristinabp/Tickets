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
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 2, "book");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 2,"");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 1, "");
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
	theatre.book("The Avengers", Date(26, 4, 2020), 1, 1, "Kristina Popova");
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 3, "Desislava Radkova");
	theatre.book("The Wizard of Oz", Date(25, 4, 2020), 2, 2, "Hristo Kostov");
	theatre.book("The Wizard of Oz", Date(25, 4, 2020), 2, 4, "Borislav Popov");
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
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 1,"");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 3, "");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 2, "");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 4,"");
	theatre.check("1-1-T-24-4");
	theatre.check("1-1-T-26-4");
}

void Test5()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 5, 5))).
		addEvent(new Event("The Avengers", Date(26, 4, 2020), Hall(2, 5, 5))).
		addEvent(new Event("The Wizard of Oz", Date(25, 4, 2020), Hall(3, 5, 5)));
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 1,"");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 3, "");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 2,"");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 4, "");
	theatre.report(Date(25, 4, 2020), Date(27, 4, 2020), Hall(2, 5, 5));
	theatre.report(Date(25, 4, 2020), Date(27, 4, 2020));
}

void Test6()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 1, 5))).
		addEvent(new Event("The Avengers", Date(26, 4, 2020), Hall(2, 2, 5))).
		addEvent(new Event("The Wizard of Oz", Date(25, 4, 2020), Hall(1, 2, 5)));
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 1, "Desislava");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 2, "Mariq");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 3, "Petar");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 4, "Georgi");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 5, "Ivan");

	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 1, "Kristina");
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 2, "Bobi");
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 3, "Nikolai");
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 4, "Ivan");
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 5, "Teodora");
	theatre.buy("The Avengers", Date(26, 4, 2020), 2, 1, "Lucho");
	theatre.buy("The Avengers", Date(26, 4, 2020), 2, 2, "Nataliq");
	theatre.buy("The Avengers", Date(26, 4, 2020), 2, 3, "Sofiq");
	theatre.buy("The Avengers", Date(26, 4, 2020), 2, 4, "Dani");

	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 1, "Hristo");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 2, "Borislav Popov");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 3, "Moni");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 4, "Kaloqn");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 1, "Sasho");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 2, "Sisi");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 3, "Mirela");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 4, "Qnica");

	theatre.mostWatched();
}

void Test7()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 1, 5))).
		addEvent(new Event("The Avengers", Date(26, 4, 2020), Hall(2, 2, 5))).
		addEvent(new Event("The Wizard of Oz", Date(25, 4, 2020), Hall(1, 2, 5)));
	
	theatre.buy("The Avengers", Date(26, 4, 2020), 1, 1, "Kristina");
	
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 1, "Hristo");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 2, "Borislav Popov");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 3, "Moni");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 1, 4, "Kaloqn");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 1, "Sasho");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 2, "Sisi");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 3, "Mirela");
	theatre.buy("The Wizard of Oz", Date(25, 4, 2020), 2, 4, "Qnica");

	theatre.underTen(Date(25, 4, 2020), Date(28, 4, 2020));
}

void Test8()
{
	System theatre;
	theatre.addEvent(new Event("The Avengers", Date(25, 4, 2020), Hall(2, 1, 5)));
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 1, "Desislava");
	theatre.book("The Avengers", Date(25, 4, 2020), 1, 2, "Ivan");

	theatre.freeSeats("The Avengers", Date(25, 4, 2020));

	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 2, "Petrana");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 1, "Desislava");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 5, "Mariq");
	theatre.buy("The Avengers", Date(25, 4, 2020), 1, 3, "Petar");
	
	theatre.freeSeats("The Avengers", Date(25, 4, 2020));
	
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	//Test7();
	//Test8();

	return system("pause");
}