#include "person.h"

using namespace std;

Person::Person(string firstName, string lastName, float  payRate, float
hoursWorked){
  
}
Person::Person(){
  firstName = "John";
  lastName = "Smith";
  employeeID = 200;
  companyName = "Unaffiliated";
  hoursWorked = 0.00;
  payRate = 0.00;
}
void  Person::setFirstName(string fName){
  firstName = fName;
}
string Person::getFirstName(){
  return firstName;
}
void   Person::setLastName(string lName){
  lastName = lName;
}
string Person::getLastName(){
  return lastName;
}
void   Person::setEmployeeId(int id){
  employeeID = id;
}
int    Person::getEmployeeId(){
  return employeeID;
}
void   Person::setCompanyName(string coName){
  companyName = coName;
}
string Person::getCompanyName(){
  return companyName;
}
void   Person::setPayRate(float rate){
  payRate = rate;
}
float  Person::getPayRate(){
  return payRate;
}
void   Person::setHoursWorked(float hours){
  hoursWorked = hours;
}
float  Person::getHoursWorked(){
  return hoursWorked;
}
float  Person::totalPay(){
  return payRate * hoursWorked;
}
string Person::fullName(){
  return firstName + " " + lastName;
}
