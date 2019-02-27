#include "person.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//both functions pass by REFERENCE

void readData(vector<Person> &employeeN);
void getCompanies(vector<Person> &employeeN, vector<string> &companyN);
void printHighestPaid(vector<Person> &employeeN);
void separateAndSave(vector<Person> &employeeN, vector<string> &companyN);

void readData(vector<Person> &employeeN){
  fstream file;
  string fiName;
  string laName;
  int employID;
  string compName;
  float hoursW;
  float pay;

  Person *employeePtr = new Person;

  file.open("input.txt");
  if(file.is_open()){
    while(!file.eof()){
      file >> fiName >> laName >> employID;
      file >> compName >> hoursW >> pay;

      employeePtr->setFirstName(fiName);
      employeePtr->setLastName(laName);
      employeePtr->setEmployeeId(employID);
      employeePtr->setCompanyName(compName);
      employeePtr->setHoursWorked(hoursW);
      employeePtr->setPayRate(pay);

      employeeN.push_back(*employeePtr);
    //  cout << employeePtr->getFirstName() << endl;
    }
  }
  else{
    cout << "Error: Could not open file!" << endl;
  }
  file.close();
}

void getCompanies(vector<Person> &employeeN, vector<string> &companyN){
  for(int i = 0; i < employeeN.size(); i++){
       companyN.push_back(employeeN[i].getCompanyName());
 }
}
void printHighestPaid(vector<Person> &employeeN){
  float tmp = 0;
  for(int i = 0; i < employeeN.size(); i++){
    if(tmp < employeeN[i].totalPay()){
      tmp = employeeN[i].totalPay();
    }
  }
  for(int j = 0; j < employeeN.size(); j++){
    if(tmp == employeeN[j].totalPay()){
      cout << "Highest paid: " << employeeN[j].fullName();
      cout << endl;
      cout << "Employee ID: " << employeeN[j].getEmployeeId();
      cout << endl;
      cout << "Employer: " << employeeN[j].getCompanyName();
      cout << endl;
      cout << "Total pay: " << tmp << endl;
    }
  }
}
void separateAndSave(vector<Person> &employeeN, vector<string> &companyN){
  
}

int main(){
  Person employiis;
  vector<Person> employees;
  vector<string> companyNames;

  readData(employees);
  getCompanies(employees, companyNames);
  printHighestPaid(employees);
}
