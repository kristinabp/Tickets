#include "Validator.h"

bool Validator::validateCommand(ICommand * cmd, std::string input)
{
	std::vector<std::string> words;
	std::string current;
	int i = 0;
	while (i < input.size())
	{
		while (i < input.size() && input[i] != ' ')
		{
			current.push_back(input[i]);
			i++;
		}
		words.push_back(current);
		current = "";
		i++;
	}

	if (words[0] == "open")
	{
		//input --> open "filename"
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "addevent")
	{
		//input --> addevent eventname year month day hallnumber rows seats
		if (words[0] == cmd->toString() && words.size() == 8)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "save")
	{
		//input --> save
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if(words[0] == "saveas")
	{
		//input --> saveas filename
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "close")
	{
		//input --> close
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "help")
	{
		//input --> help
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "exit")
	{
		//input --> exit
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "book")
	{
		//input --> book eventname year month day row seat note
		if (words[0] == cmd->toString() && words.size() == 8)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "unbook")
	{
		//input --> unbook eventname year month day row seat 
		if (words[0] == cmd->toString() && words.size() == 7)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "freeseats")
	{
		//input --> freeseats eventname year month day 
		if (words[0] == cmd->toString() && words.size() == 5)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "bookings")
	{
		if (words.size() == 5)
		{
			//input --> bookings eventname year month day
			if (words[0] == cmd->toString())
			{
				return true;
			}
			else return false;
		}
		else if (words.size() == 2)
		{
			//input --> bookings eventname 
			if (words[0] == cmd->toString())
			{
				return true;
			}
			else return false;
		}
		else if (words.size() == 4)
		{
			//input --> bookings year month day 
			if (words[0] == cmd->toString())
			{
				return true;
			}
			else return false;
		}
	}
	else if (words[0] == "check")
	{
		//input --> check id
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "report")
	{
		if (words.size() == 8)
		{
			//input --> report year1 month1 day1 year2 month2 day2 hallnumber
			if (words[0] == cmd->toString())
			{
				return true;
			}
			else return false;
		}
		else if (words.size() == 7)
		{
			//input --> report year1 month1 day1 year2 month2 day2 
			if (words[0] == cmd->toString())
			{
				return true;
			}
			else return false;
		}
	}
	else if (words[0] == "mostwatched")
	{
		//input --> mostwatched
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "underten")
	{
		//input --> underten year1 month1 day1 year2 month2 day2 
		if (words[0] == cmd->toString() && words.size() == 7)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "buy")
	{
		//input --> buy eventname year month day row seat note
		if (words[0] == cmd->toString() && words.size() == 8)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "addhall")
	{
	    //input --> addhall hallnumber rows seats
		if (words[0] == cmd->toString() && words.size() == 4)
		{
			return true;
		}
		else return false;
	}
	else
	{
		return false;
	}
}
