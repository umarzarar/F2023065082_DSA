#include "header.h"

	Seat::Seat(int num, string nam) {
		status = "Available";
		seatNum = num;
		name = nam;
		next = nullptr;
	}



	ReservationList::ReservationList() {
		head = nullptr;
	}

	void ReservationList::printAll() {
		Seat* temp = head;
		while (temp != nullptr) {
			cout << "Seat Number: " << temp->seatNum << "\n"
				<< "Name: " << temp->name << "\n"
				<< "Status: " << temp->status << endl << endl;
			temp = temp->next;
		}

	}

	//seat booking
	void ReservationList::bookTicket(int num, string stat, string nam) {
		Seat* newSeat = new Seat(num, nam);
		newSeat->status = stat;
		//either booked or avialable
		if (head == nullptr) {
			head = newSeat;
			return;
		}

		Seat* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newSeat;
	}
	//seat cancelation
	void ReservationList::cancelSeat(int key) {
		if (head == nullptr) {
			cout << "There is no seat booked yet. :) " << endl;
			return;
		}
		if (head->seatNum == key) {
			Seat* temp = head;
			head = head->next;
			cout << "Seat " << key << " (Passenger: " << temp->name << ") has been canceled." << endl;
			delete temp;
			return;
		}
		Seat* temp = head;
		while (temp->next != nullptr && temp->next->seatNum != key) {
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			cout << "\nSeat not found. It might not be booked by any passenger yet. :)" << endl;
			return;
		}
		Seat* toDelete = temp->next;
		temp->next = temp->next->next;
		cout << "\nSeat " << key << " (Passenger: " << toDelete->name << ") has been canceled." << endl;
		delete toDelete;
	}
	//search for Seat
	void ReservationList::SearchSeat(int key) {
		Seat* temp = head;
		while (temp != nullptr) {
			if (temp->seatNum == key) {
				cout << "\nSeat Number: " << temp->seatNum << "\n"
					<< "Name: " << temp->name << "\n"
					<< "Status: " << temp->status << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Seat not found.\n";
	}

	//Update Seat info:
	void ReservationList::updateInfo(int key, string nam) {
		Seat* temp = head;
		while (temp != nullptr) {
			if (temp->seatNum == key) {
				temp->name = nam;
				cout << "\nSeat Information Updated Successfully:\n";
				cout << "Seat Number: " << temp->seatNum << "\n"
					<< "updated Name: " << temp->name << "\n"
					<< " Status: " << temp->status << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Seat not found.\n";
	}
