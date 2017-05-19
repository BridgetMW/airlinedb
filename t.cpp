#include <string>
#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"

using namespace std;

int main(int argc, char *argv[])

{
     class Passenger p1;
     class Passenger p2;
     class Passenger p3;

     class LinkedList<Passenger> passengerlist;
     class OrderedLinkedList<Passenger> orderedpassengerlist;

     (void) p1.FirstName("Bob");
     (void) p1.LastName("Dinosaur");
     (void) p1.Address("Under The Refrigerator");
     (void) p1.Phone("1-800-ByteMe");

     (void) p2.FirstName("Turkey");
     (void) p2.LastName("Lurkey");
     (void) p2.Address("Under The Refrigerator");
     (void) p2.Phone("1-800-ByteMe");

     (void) p3.FirstName("zoot");
     (void) p3.LastName("Dinosaur");
     (void) p3.Address("Under The Refrigerator");
     (void) p3.Phone("1-800-ByteMe");

     if (p1 < p2)
     {
         cerr << p1.toString() << " is less than " << p2.toString() << endl;
     }
     else 
     {
         cerr << p1.toString() << " is not less than " << p2.toString() << endl;
     }

     if (p1 == p3)
     {
         cerr << p1.toString() << " is equal to " << p2.toString() << endl;
     }
     else 
     {
         cerr << p1.toString() << " is not equal to " << p2.toString() << endl;
     }
     
     passengerlist.insert_first(p1);
     return 0;
}






