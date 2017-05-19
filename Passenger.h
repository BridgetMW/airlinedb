#ifndef __PASSENGER_H__
#define __PASSENGER_H__


class Passenger {
protected:
     std::string firstname;
     std::string lastname;
     std::string address;
     std::string phone;

public:
     Passenger() {
     };

     ~Passenger() {
     };

     // set firstname
     std::string FirstName(std::string name) {
          firstname = name;
          return firstname;
     };
     // get firstname
     std::string FirstName() {
          return firstname;
     };
     // set lastname
     std::string LastName(std::string name) {
         lastname = name;
         return lastname;
     };
     // get lastname
     std::string LastName() {
         return lastname;
     };
     // set address
     std::string Address(std::string addr) {
         address = addr;
         return address;
     };
     // get address
     std::string Address() {
         return address;
     };
     // set phone
     std::string Phone(std::string phnum) {
         phone = phnum;
         return phone;
     };
     // get phone
     std::string Phone() {
         return phone;
     };

     bool operator<( class Passenger &other) {  return lastname.compare(other.lastname) < 0; };
     bool operator==( class Passenger &other) {  return lastname.compare(other.lastname) == 0; };
     bool operator!=( class Passenger &other) {  return lastname.compare(other.lastname) != 0; };
     bool operator>( class Passenger &other) {  return lastname.compare(other.lastname) > 0; };

     std::string toString() {  return "name: "+lastname+","+firstname; };
};

#endif // __PASSENGER_H__


