#ifndef _THEATER_H_
#define _THEATER_H_

#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm>
#include "Ticket.h"

class Theater {
private:
	int numRow, numSeat;
	std::vector<std::vector<char>> map; 
	std::vector<Ticket> tickets;
	std::vector<int> seatPrices;
	void printSpace(int x);
public:
	Theater(); 
	Theater(int numRow, int numSeat, const std::vector<int>& seatPrices); 
	std::vector<std::vector<char>> getMap();
  int getPriceSeat(int row);
	void addTicket(const Ticket& t);
	void printMap(); 
	void printTickets(); 
	void printSeatPrices();
	void printValidSeats();
	void printInvalidSeats();
  void printValidSeatsOfRow(const int& x) const;
};

#endif // _THEATER_H_

