
#include <string>
#include <iostream>
using namespace std;

class Seat {
public:
	int seatNum;
	string status;
	string name;
	Seat* next;

	Seat(int num, string nam);

};
class ReservationList {
public:
	Seat* head;

	ReservationList();

	void printAll();

	//seat booking
	void bookTicket(int num, string stat, string nam);
	//seat cancelation
	void cancelSeat(int key);
	//search for Seat
	void SearchSeat(int key);

	//Update Seat info:
	void updateInfo(int key, string nam);
};
