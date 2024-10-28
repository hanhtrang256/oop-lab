#ifndef _TICKET_H_
#define _TICKET_H_

#include <iostream>
#include <string>
#include <vector>

class Ticket {
private:
	std::string movieName;
	std::string date; // <-- format: dd/mm/yy
	std::string time; // <-- format: hh/mm/ss
	std::string food; // <-- format: food1 food2 ... food3, all food same price :v 
	std::string seatName; // <-- format: row column
	int priceSeat; // <-- depends on input
	int priceFood; // <-- depends on number of food or drinks
public:
	Ticket(); 
	Ticket(std::string movieName, std::string date, std::string time, std::string food, std::string seatName, int priceSeat, int priceFood); 
	Ticket(const Ticket& other); 
	/**
  * @brief Set the seat and food price for the ticket
  * @param a seat price vector given by user
  **/
  void setPrice(const std::vector<int>& seatPrice);
	friend std::ostream& operator << (std::ostream& out, const Ticket& t);
  /**
  * @brief Enter information of the ticket
  * @param map The seat chart to make sure the ticket's seat is available
  **/
  void input(const std::vector<std::vector<char>>& map); 
  /**
  * @brief Get row number
  **/
  int getRow() const;
  /**
  * @brief Get column number
  **/
  int getCol() const;
  /**
  * @brief Get seat name
  * @return seat name
  **/
  std::string getSeatName() const;
  /**
  * @brief get food
  **/
  std::string getFood() const; 
  /**
  * @brief get date
  **/
  std::string getDate() const;
  /**
  * @brief get movie name
  **/
  std::string getMovieName() const; 
  /**
  * @brief get time 
  **/
  std::string getTime() const;
  /**
  * @brief Check if the string is a valid seat type
  * @return boolean
  **/
  bool isSeat(const std::string& s);
  /**
  * @brief Get total price
  * @return priceFood + priceSeat
  **/
  int getTotalPrice(); 
};

#endif // _TICKET_H_
