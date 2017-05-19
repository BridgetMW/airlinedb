
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;


OrderedLinkedList<Passenger> flight100, flight200, flight300, flight400; 


OrderedLinkedList<Passenger> *SelectFlight(int flightNum)

{


    switch(fltNum) 
    {
    case 100:
        return flight100;
    case 200:
        return flight200;
    case 300:
        return flight300;
    case 400:
        return flight400;

    default:
        return NULL;
    }
}


void PrintPassenger( Passenger &p)

{

}



OrderedLinkedList<Passenger> *SelectFlight(std::string flightStr)

{ int flt_num = strtol(flightStr);

   return SelectFlight(flight_num);
}


int main(){
    // create lists

    // variables for getting user input
    string flightNum = NULL;
    string firstName = NAME;
    string lastName = NAME;
    string address = ADDRESS;
    string phoneNum = PHONE;
    string userInput = input;


    // prompt user until Quit
    cout << "Please choose an operation: << endl;
    while (userInput != Q) {
        cout << "Please choose an operation: " << endl;
        cout << "A (Add) | S (search) | D (Delete) | L (list) | Q (quit) : " endl;
        cin >> userInput
        
        if (userInput == 'A')
        {
            Passenger p;
            OrderedLinkedList *flt = NULL;

            // A -- add a passenger
            cout << "Enter flight number: ";
            cin >> flightNum
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter address: ";
            cin >> address;
            cout << "Enter phone number: ";
            cin >> phoneNum;
          
            // adding passenger info 
            p.FirstName(firstName);
            p.LastName(LastName);
            p.Address(address);
            p.Phone(phoneNum);

            flt = SelectFlight(flightNum);
            if (!flt) // flight not found
            {
                cerr << "flight " << flightNum << "is not valid" << endl;
                continue;
            }

            
            // add to LinkedList
            flt->insert_node(p);
        }
        else if (userInput == 'S')
        {
            bool done = false;
            int flt_num = 100;
            Passenger p;
            Passenger search_rslt;
            OrderedLinkedList *flt = NULL;

            // S -- search
            cout << "Enter a last name: ";
            cin >> lastName;
            cout << "Enter a first name: ";
            cin >> firstName;

            p.FirstName(firstName);
            p.LastName(LastName);
            
            
            // display flight, first & last name, address, phone
            //
            //
            for (bool done = false; flt_num <= 400 && !done; flt_num+=100) 
            {
                flt = SelectFlight(flt_num);
              
                search_rslt = flt->search(p);
                
                if (serch_rslt) 
                {
                     // Print

                    cout << "flight: " << flt_num << endl;
                    PrintPassenger(search_rslt);
                    done = true;
                    continue;
                }

            }
            if (done)
            {
                continue;
            }
        }

        else if (userInput == 'D')
        {
            // D -- delete a passenger
            cout << "Enter flight number: ";
            cin >> flightNum;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;

            // find and remove the passenger
            //
            p.FirstName(firstName);
            p.LastName(LastName);

            flt = SelectFlight(flightNum);
            flt->delete_node(p);

            //
            cout << "The passenger is deleted.";
        }
        else if (userInput == 'L')
        {
            OrderedLinkedList *flt = NULL;

            // L -- list passengers by flight
            cout << "Enter flight number: ";
            cin >> flightNum;
            flt = SelectFlight(flightNum);

            // print info for all passengers in requested list
            //
            //
            flt->apply(PrintPassenger);
        }
        else
        {
            cout << "Command not found. Please select from the following." << endl;
        }
         
    }  
}
