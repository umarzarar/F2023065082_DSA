#include "header.h"
int main()
{
    ReservationList list;
    int num, seatnum;
    string name;
    // Book tickets

    cout << "Enter how many tickets you want to book: ";
    cin >> num;

    for (int i = 1; i <= num; i++) {
        cout << "\nEnter the name of Passenger: ";
        cin >> name;
        cout << "Enter the prefferable seat number for " << name << " : ";
        cin >> seatnum;
        list.bookTicket(seatnum, "Booked", name);
    }

    // Print all seats
    cout << "Seat Reservation List:\n\n";
    list.printAll();

    int choice;
    cout << "\nPress 1 to cancel the seat.\nPress 2 to search for a seat.\nPress 3 to update the Passenger info.\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        {
    case 1:
        cout << "\nEnter the seat number you want to cancel : ";
        int nn;
        cin >> nn;
        list.cancelSeat(nn);
        cout << "\nAfter cancelation of seat , the Passenger list is: " << endl;
        list.printAll();
        break;
        }
        {
    case 2:
        cout << "\nEnter the seat number you want to search : ";
        int nm;
        cin >> nm;
        list.SearchSeat(nm);
        break;
        }
        {
    case 3:
        cout << "\nEnter the seat number you want to update : ";
        int nnn;
        cin >> nnn;
        cout << "Enter the name of new Passenger: ";
        string namm;
        cin >> namm;
        list.updateInfo(nnn, namm);
        cout << "\nAfter updation , the Passenger list is: " << endl;
        list.printAll();
        break;
        }
    default:
        cout << "\nPlease enter correct choice :)" << endl;
        break;
    }

    return 0;
}