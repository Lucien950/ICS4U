#include <vector>
#include <iostream>
#include <typeinfo>
#include <bits/stdc++.h>


#include "Flight.h"
#include "Seat.h"
#include "User.h"

#include "Employee.h"
#include "Customer.h"


using namespace std;

static vector<Flight> FlightList;
static auto * USER = new User("unknown user");

bool inRange(int flightnum, int seatnum);
void printFlight(Flight *thisFlight, int flightnum);
bool notEnoughArguments(istringstream * ss);

int main(){
    cout << "Flight Scheduler" << endl
        << "Copyright (C) The Edwin Corporation. All rights reserved." << endl
        << "Type \"help\" for more information" << endl << endl;

    while(true){
        cout << endl;
        cout << '[' << USER->getName() << ']' << endl << ">>";

        //INPUT PROCESSING
        string input;
        getline(cin, input);
        istringstream commandss(input);

        string command;
        commandss >> command;

        if(command == "exit"){
            return 1;
        }
        else if(command == "help"){
            cout << "Commands" << endl << "-------------------------------------------------" << endl;
            cout << "WARNING: EXTRA ARGUMENTS WILL NOT BE HANDLED" << endl << endl;
            cout << "\"help\": Brings up this menu" << endl;
            cout << "\"exit\": Ends the Program" << endl;
            cout << "\"setuser [employeeType] [userName] ([userAddress] [userPhoneNumer] if customer)\": Creates user with name userName, address userAddress, phone number userPhoneNumber" << endl;
            cout << "\"getticket [flightnumber] [seatnumber]\": Gets the seatnumber seat on flight flightnumber";
            cout << "\"getFlight [flightNumber]\": Gets the flightNumberth flight" << endl;
            cout << "\"getAllFlights\": Gets all the flights" << endl;
            cout << "\"newFlight [seatCount]\": Creates a new flight with seatCount seats." << endl;
        }
        //set the user using the system
        else if(command == "setuser"){
            string newUserType;
            string newUserName;
            commandss >> newUserType >> newUserName;

            if(newUserName.empty() || newUserType.empty()){cout << "Username or UserType is empty, try again" << endl; continue;}
            if(newUserType == "customer") {
                string newAddress;
                string newPhoneNumber;
                commandss >> newAddress >> newPhoneNumber;
                if (newAddress.empty() || newPhoneNumber.empty()) {
                    cout << "Address or Phone Number is Empty, try again" << endl;
                    continue;
                }

                USER = new Customer(newUserName, newAddress, newPhoneNumber);
                auto * thisUser = dynamic_cast<Customer *>(USER);
                //FEEDBACK
                cout << "Customer Successfully Created" << endl <<
                     "Name: " << thisUser->getName() << endl <<
                     "Address: " << thisUser->getAddress() << endl <<
                     "Phone Number: " << thisUser->getPhone() << endl;
            }else if(newUserType == "employee"){
                USER = new Employee(newUserName);
                auto * thisUser = dynamic_cast<Employee *>(USER);
                cout << "Employee Successfully Created" << endl <<
                "Name: " << thisUser->getName() << endl;
            }else{
                cout << R"(User type must be "employee" or "customer")" << endl;
            }
        }
        //Identify user, for user convenience
        else if(command == "whoami"){
            if(USER->getUserType() == "customer"){
                auto* thisUser = dynamic_cast<Customer *>(USER);
                cout << "This User" << endl <<
                     "Name: " << thisUser->getName() << endl <<
                     "Address: " << thisUser->getAddress() << endl <<
                     "Phone Number: " << thisUser->getPhone() << endl;
            }else if(USER->getUserType() == "employee"){
                auto* thisUser = dynamic_cast<Employee *>(USER);
                cout << "This User" << endl <<
                    "Name: " << thisUser->getName() << endl;
            }
            else{
                cout << "User type is invalid" << endl;
            }
        }
        //3. Requesting tickets from customer
        else if(command == "getticket"){
            int flightnum;
            int seatnum;
            if(commandss.eof()){
                cout << "Flight Number not Provided" << endl;
                continue;
            }
            commandss >> flightnum;
            if(commandss.eof()){
                cout << "Seat Number not Provided" << endl;
                continue;
            }
            commandss >> seatnum;


            //check user
            if(USER->getUserType() != "customer") {cout << "You can only place orders as \"customer\" user" << endl;continue;}

            //INRANGE
            if(!inRange(flightnum, seatnum)) continue;
            Flight* thisFlight = &FlightList[flightnum - 1];

            if (thisFlight->fullyBooked()){
                cout << "Flight is fully booked, try again" << endl;
                continue;
            }
            else if (!thisFlight->checkSeatAvailable(seatnum - 1)){
                cout << "Seat is already occupied" << endl;
                cout << "Seat availability" << endl << "---------------" << endl;
                printFlight(thisFlight, flightnum);
                continue;
            }

            thisFlight->setSeat(seatnum - 1, Seat(seatnum - 1, dynamic_cast<Customer *>(USER)));
            //display airplane
            cout << "Seat availability" << endl << "---------------" << endl;
            printFlight(thisFlight, flightnum);
        }
        else if(command == "newFlight"){
            if(USER->getUserType() != "employee"){
                cout << "Only Employees can create flights" << endl;
                continue;
            }
            int seatCount;
            cout << commandss.eof() << endl;
            if(notEnoughArguments(&commandss)){
                continue;
            }
            commandss >> seatCount;
            FlightList.emplace_back(seatCount);
            cout << "New flight created" << endl;
            printFlight(&FlightList[FlightList.size()-1], FlightList.size());
        }
        //4. Cancel Reservation
        else if(command == "cancelreservation"){
            int flightnum, seatnum;
            if(commandss.eof()){
                cout << "Flight Number not Provided" << endl;
                continue;
            }
            commandss >> flightnum;
            if(commandss.eof()){
                cout << "Seat Number not Provided" << endl;
                continue;
            }
            commandss >> seatnum;

            if(!inRange(flightnum, seatnum)) continue;
            Flight* thisFlight = &FlightList[flightnum - 1];

            if(thisFlight->checkSeatAvailable(seatnum - 1)){
                cout << "Seat is already available. Cannot be cancelled" << endl;
                continue;
            }

            auto thisUser = *dynamic_cast<Customer *>(USER);
            Customer otherUser = thisFlight->customerAtSeat(seatnum - 1);
            if(thisUser.getUserType() == "customer" && !(otherUser == thisUser)){
                cout << "You are a different user, you don't have permission to cancel this reservation" << endl;
                continue;
            }

            FlightList[flightnum - 1].setSeat(seatnum - 1, Seat());
            cout << "Seat at " << seatnum << " has been cancelled" << endl;
            cout << "New seat arrangement" << endl;
            printFlight(thisFlight, flightnum);
        }
        //5. Cancel flight
        else if(command == "cancelflight"){
            int flightNumber;

            if(commandss.eof()){
                cout << "Flight Number not Provided" << endl;
                continue;
            }
            commandss >> flightNumber;

            if(flightNumber <= 0 || flightNumber > FlightList.size()){
                cout << "Flight number is out of range" << endl;
                continue;
            }
            Flight * thisFlight = &FlightList[flightNumber - 1];
            for(int i = 0; i < thisFlight->getSeatCount(); i++){
                if(!thisFlight->checkSeatAvailable(i)){
                    cout << "Seat number " << i << " is occupied by this passenger" << endl;
                    cout << thisFlight->customerAtSeat(i).toString() << endl;
                }
            }

            FlightList.erase(FlightList.begin()+(flightNumber - 1));
            cout << "Flight " << flightNumber << " has been removed" << endl;
        }
        else if(command == "getAllFlights"){
            for(int i = 0; i < FlightList.size(); i++){
                printFlight(&FlightList[i], i + 1);
            }
        }
        else if(command == "getFlight"){
            int flightNum;
            if(commandss.eof()){
                cout << "Not enough arguments" << endl;
                continue;
            }

            commandss >> flightNum;

            if(flightNum <= 0 || flightNum > FlightList.size()){
                cout << "Flight Num is Out Of Range" << endl;
                continue;
            }

            printFlight(&FlightList[flightNum - 1], flightNum);
        }

        //CATCH FINALLY
        else cout << "Command \"" << command << "\" is invalid, please try again" << endl;
    }
    return 0;
}

bool inRange(int flightNum, int seatNum){
    if (flightNum <= 0 || flightNum > FlightList.size()){
        cout << "Flight Number is out of range, try again" << endl;
        return false;
    }
    Flight* thisFlight = &FlightList[flightNum - 1];
    if(seatNum <= 0 || seatNum > thisFlight->getSeatCount()){
        cout << "Seat number is out of range" << endl;
        return false;
    }

    return true;
}

void printFlight(Flight *thisFlight, int flightNum){
    cout << "Flight " << flightNum << endl;
    for(int i = 0; i < thisFlight->getSeatCount(); i++){
        cout << (thisFlight->checkSeatAvailable(i) ? "O" : "X") << " ";
    }
    cout << endl;
}

bool notEnoughArguments(istringstream * ss){
    if(ss->eof()){
        cout << "Not enough arguments" << endl;
        return true;
    }
    return false;
}