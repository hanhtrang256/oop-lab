#include "Ticket.h"
#include <string> 
#include <iostream>
#include <vector>

Ticket::Ticket() : movieName(""), date(""), time(""), food(""), seatName(""), priceSeat(0), priceFood(0) {}

Ticket::Ticket(std::string movieName, std::string date, std::string time, std::string food, std::string seatName, int priceSeat, int priceFood) : movieName(movieName), date(date), time(time), food(food), seatName(seatName), priceSeat(priceSeat), priceFood(priceFood) {}

Ticket::Ticket(const Ticket& other) : movieName(other.movieName), date(other.date), time(other.time), food(other.food), seatName(other.seatName), priceSeat(other.priceSeat), priceFood(other.priceFood) {}

void Ticket::setPrice(const std::vector<int>& seatPrice) {
  this->priceSeat = seatPrice[seatName[0] - 'A'];
  for (int i = 0; i < (int)food.size(); ++i) 
    if (food[i] == ' ') 
      ++priceFood;
  ++priceFood;
}

std::ostream& operator << (std::ostream& out, const Ticket& t) {
	out << "{Movie name: " << t.movieName << ", ";
	out << "Date: " << t.date << ", ";
	out << "Time: " << t.time << ", ";
	out << "Food: " << t.food << ", ";
	out << "Seat: " << t.seatName << ", ";
	out << "Price seat: " << t.priceSeat << ", ";
	out << "Price food: " << t.priceFood << ", ";
  out << "Total price: " << t.priceSeat + t.priceFood << "}";
	return out;
}

int Ticket::getRow() const {
  return seatName[0] - 'A';
}

int Ticket::getCol() const {
  int col = 0;
  for (int i = 1; i < (int)seatName.size(); ++i) 
    col = col * 10 + (seatName[i] - '0');
  return col;
}

std::string Ticket::getSeatName() const {
  return seatName;
}
/**
* @brief get food
**/
std::string Ticket::getFood() const {
  return food;
}
/**
* @brief get date
**/
std::string Ticket::getDate() const {
  return date;
}
/**
* @brief get movie name
**/
std::string Ticket::getMovieName() const {
  return movieName;
}
/**
* @brief get time 
**/
std::string Ticket::getTime() const {
  return time;
}

bool Ticket::isSeat(const std::string& s) {
  if ((int)s.size() > 3 || (int)s.size() < 2) return false;
  if (!(s[0] >= 'A' && s[0] <= 'Z')) return false; 
  if (!(s[1] >= '0' && s[1] <= '9')) return false;
  if ((int)s.size() == 3 && !(s[2] >= '0' && s[2] <= '9')) return false;
  return true;
}

void Ticket::input(const std::vector<std::vector<char>>& map) {
  std::cout << "Movie name: ";
  std::cin.ignore();
  std::getline(std::cin, movieName);

  std::cout << "Date: ";
  std::getline(std::cin, date);

  std::cout << "Time: "; 
  std::getline(std::cin, time);

  std::cout << "Food: "; 
  std::getline(std::cin, food);

  while (true) {
    std::cout << "Enter seat (ex: A5): "; 
    std::cin >> seatName;
    if (!isSeat(seatName)) {
      std::cout << "Invalid seat name. Please type again!!!\n"; 
      continue;
    }
    int row = getRow();
    int col = getCol();
    if (row < 0 || row >= 15 || col < 0 || col >= 30) {
      std::cout << "Seat does not exist. Please type again!!!\n"; 
      continue;
    }
    if (map[row][col] == '*') {
      std::cout << "Seat " << seatName << " is occupied. Please type again!!!\n";
      continue;
    }
    break;
  }
}

int Ticket::getTotalPrice() {
  return priceFood + priceSeat;
}

