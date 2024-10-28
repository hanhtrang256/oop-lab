#include "Theater.h"

Theater::Theater() : numRow(0), numSeat(0), map({}), tickets({}), seatPrices({}) {}

Theater::Theater(int numRow, int numSeat, const std::vector<int>& seatPrices) : numRow(numRow), numSeat(numSeat), seatPrices(seatPrices) {
	map.resize(numRow);
	for (int i = 0; i < numRow; ++i) map[i].assign(numSeat, '#');
}

void Theater::printSpace(int x) {
	for (int i = 0; i < x; ++i) 
		std::cout << " ";
}

std::vector<std::vector<char>> Theater::getMap() {
  return map;
}

int Theater::getPriceSeat(int row) {
	return seatPrices[row];
}

/**
* @brief Add a ticket 
* @note TODO: update the seat chart
**/
void Theater::addTicket(const Ticket& t) {
	tickets.push_back(t);
  map[t.getRow()][t.getCol()] = '*';
}

/**
* @format Row A   [*] [*] [*] [#] [#] ...
**/

void Theater::printMap() {
  int offset = 1;
	/** 
	* @brief Print header for auditorium
	**/ 
	printSpace(5 + offset + 3 * numSeat / 2 - 6); 
	std::cout << "[SEAT CHART]"; 
	printSpace(3 * numSeat / 2 - 6); 
	std::cout << '\n'; 
  	
	/**
	* @brief Print column number
	**/
	printSpace(5 + offset);
	for (int i = 0; i < numSeat; ++i) {
		if (i < 10) {
			std::cout << " " << i << " ";
			printSpace(0);
		} else {
			std::cout << i;
			printSpace(1);
		}
	}
	std::cout << '\n';

	/**
	* @brief Now print all the rows
	**/
	for (int i = 0; i < numRow; ++i) {
		std::cout << "Row " << (char)(i + 'A');
		printSpace(offset);
		for (int j = 0; j < numSeat; ++j) {
			std::cout << "[" << map[i][j] << "]"; 
			printSpace(0);
		}
		std::cout << '\n';
	}
}

void Theater::printTickets() {
	std::cout << "[Information Of Sold Tickets]\n";
  if (tickets.empty()) {
    std::cout << "No tickets have been sold yet!!!\n";
    return;
  }
	for (int i = 0; i < (int)tickets.size(); ++i) 
		std::cout << tickets[i]	<< '\n';
}

void Theater::printSeatPrices() {
	std::cout << "Price of seat rows are ";
	for (int i = 0; i < numRow; ++i) {
		std::cout << "[Row " << (char)(i + 'A') << ": " << seatPrices[i] << "]";
		if (i + 1 < numRow) std::cout << ", ";
	}
}

void Theater::printValidSeats() {
	std::cout << "Number of available seats are "; 
	int cnt = 0; 
  for (int i = 0; i < numRow; ++i) 
    for (int j = 0; j < numSeat; ++j) 
      cnt += (map[i][j] == '#'); 
  std::cout << cnt << '\n';
  if (cnt == 0) return;

  int format = 0;
  for (int i = 0; i < numRow; ++i) {
    for (int j = 0; j < numSeat; ++j) {
      if (map[i][j] == '#') {
        std::cout << "[" << (char)(i + 'A') << j << "]"; 
        ++format;
        if (format < cnt) {
          if (format % 12 == 0) std::cout << ",\n"; 
          else std::cout << ", ";
          if (j < 10 && format % 12 != 0) std::cout << " ";
        }
      }
    }
  }
}

void Theater::printInvalidSeats() {
	std::cout << "Number of purchased seats are "; 
	int cnt = 0; 
  for (int i = 0; i < numRow; ++i) 
    for (int j = 0; j < numSeat; ++j) 
      cnt += (map[i][j] == '*'); 
  std::cout << cnt << '\n';
  if (cnt == 0) return;

  int format = 0;
  for (int i = 0; i < numRow; ++i) {
    for (int j = 0; j < numSeat; ++j) {
      if (map[i][j] == '*') {
        std::cout << "[" << (char)(i + 'A') << j << "]"; 
        ++format;
        if (format < cnt) {
          if (format % 12 == 0) std::cout << ",\n"; 
          else std::cout << ", ";
          if (j < 10 && format % 12 != 0) std::cout << " ";
        }
      }
    }
  }
}

void Theater::printValidSeatsOfRow(const int& x) const {
  if (x < 0 || x >= numRow) {
    std::cout << "Invalid row!!!\n"; 
    return;
  }
  int cnt = 0;
  for (int i = 0; i < (int)map[x].size(); ++i) 
    if (map[x][i] == '#') ++cnt;
  std::cout << "There are " << cnt << " seats available in row " << (char)(x + 'A') << '\n';
  int format = 0;
  for (int i = 0; i < (int)map[x].size(); ++i) {
    if (map[x][i] == '#') {
      std::cout << "[" << (char)(x + 'A') << i << "]";
      ++format;
      if (format < cnt) {
        if (format % 12 == 0) std::cout << ",\n"; 
        else std::cout << ", ";
        if (i < 10) std::cout << " ";
      }
    }
  }
}
