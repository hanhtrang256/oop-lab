#include "Theater.h"
#include <iostream> 
#include <algorithm>
#include <string> 
#include <vector> 
#include <fstream>
/**
* @note opt1: add group of tickets (can be 1) 
*       TODO: remember to check for valid seats
* @note opt2: display all purchased tickets
* @note opt3: display all available seats
* @note opt4: display all purchased seats
* @note opt5: display seat charts
* @note opt6: display user options
* @note opt7: display available seats of a specific row
* @note opt8: exit
**/
void printUserOptions() {
  std::cout << "---        [User Options]      ---\n";
  std::cout << "1. Add group of tickets (can be 1)\n"; 
  std::cout << "2. Display all purchased tickets  \n";
  std::cout << "3. Display all available seats    \n";
  std::cout << "4. Display all purchased seats    \n";
  std::cout << "5. Display seat charts            \n";
  std::cout << "6. Display user options           \n";
  std::cout << "7. Display available seats of row \n";
  std::cout << "8. Exit                           \n";
}

/**
* @brief Receive user input
* @note Check for valid input 
* @note Allow re-type when invalid input
* @return user option
**/
int checkValidInput() {
  int userOpt;
  while (true) {
    std::cout << "Enter option: ";
    std::cin >> userOpt;
    if (userOpt < 1 || userOpt > 8) {
      std::cout << "Invalid option. Please type again!!!\n";
      continue;
    }
    break;
  }
  return userOpt;
}

void addTicketsInfo(Theater &theater, const int& numTicket, const std::vector<int>& seatPrices) {
  for (int ticketID = 0; ticketID < numTicket; ++ticketID) {
    std::cout << "[Enter Information Of Ticket " << ticketID << "]\n";
    Ticket ticket;
    ticket.input(theater.getMap()); // <-- allow user to enter information for ticket
    ticket.setPrice(seatPrices);
    theater.addTicket(ticket);
    std::cout << ticket << '\n';
    std::cout << "Seat " << ticket.getSeatName() << " is update!\n";
  }
}

int main() {
	/** 
	* @brief Asks user to input numRow, numSeat, seatPrices
	**/
	int numRow, numSeat;
	std::vector<int> seatPrices;
	std::cout << "Enter number of rows: "; 
	std::cin >> numRow;
	std::cout << "Enter number of seats each row: ";
	std::cin >> numSeat; 
	std::cout << "Enter prices for each seat row: File(enter 1) or Input by hands(enter 2): ";
	int enterPriceOpt; 
	std::cin >> enterPriceOpt;
	if (enterPriceOpt == 2) {
    for (int i = 0; i < numRow; ++i) {
      int x;
      std::cin >> x;
      seatPrices.push_back(x);
    }
	}
  else {
    std::ifstream fin("price.txt"); 
    if (!fin.is_open()) {
      std::cout << "Cannot open file!!!\n"; 
      return 0;
    }
    for (int i = 0; i < numRow; ++i) {
      seatPrices.push_back(0);
      fin >> seatPrices[(int)seatPrices.size() - 1];
    }
    fin.close();
  }

	/**
	* @brief Initialize a theater
	* @brief Display auditorium
	**/
	Theater theater(numRow, numSeat, seatPrices); 
	theater.printMap();
   
  
  /**
  * @brief The program loop
  * @note seat chart will always be displayed
  * @note print user options
  * @note handle user input
  * TODO: remember to check for valid seats
  **/
  bool programLoop = true;
  while (programLoop) {
    printUserOptions();
    int userOpt = checkValidInput();
    switch (userOpt) {
      case 8:
        std::cout << "[PROGRAM IS CLOSED]\n";
        programLoop = false;
        break;
      case 7: 
        char x;
        std::cout << "Enter row to check: "; 
        std::cin >> x;
        theater.printValidSeatsOfRow(x - 'A'); 
        break;
      case 6: 
        // do nothing otherwise will print user options twice
        break;
      case 5:
        theater.printMap(); 
        break;
      case 4:
        theater.printInvalidSeats();
        break;
      case 3: 
        theater.printValidSeats();
        break;
      case 2: 
        theater.printTickets();
        break;
      case 1: 
        std::cout << "Number of sold tickets: ";
        int numTickets; 
        std::cin >> numTickets;
        addTicketsInfo(theater, numTickets, seatPrices);
        break;
      default:
        break;
    }
    std::cout << '\n';
  }
	return 0;
}
