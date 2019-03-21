#include "person.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

//both functions pass by REFERENCE

void readData(vector<Person> &employeeN);
void getCompanies(vector<Person> &employeeN, vector<string> &companyN);
void printHighestPaid(vector<Person> &employeeN);
void separateAndSave(vector<Person> &employeeN, vector<string> &companyN);

void readData(vector<Person> &employeeN){

  //Declared some variables to be able to pass it to the employee vector.
  fstream file;
  string fiName;
  string laName;
  int employID;
  string compName;
  float hoursW;
  float pay;

  //Create a temporary Person class pointer to push_back into the employee vector.
  Person *employeePtr = new Person;

  //Input the data
  file.open("input.txt");
  if(file.is_open()){
    while(!file.eof()){
      file >> fiName >> laName >> employID;
      file >> compName >> hoursW >> pay;

      //Probably inefficient
      employeePtr->setFirstName(fiName);
      employeePtr->setLastName(laName);
      employeePtr->setEmployeeId(employID);
      employeePtr->setCompanyName(compName);
      employeePtr->setHoursWorked(hoursW);
      employeePtr->setPayRate(pay);

      //push_back every employee one by one in the file.
      employeeN.emplace_back(*employeePtr);

    }
  }
  //If file wasn't opened, come to this else.
  else{
    cout << "Error: Could not open file!" << endl;
  }
  //Deallocate the employeePtr.
  delete employeePtr;
  file.close();
}

void getCompanies(vector<Person> &employeeN, vector<string> &companyN){

  //Pushed all 16 of the employee companies. Must be a better way to
  //uniquely get the companies.
  for(int i = 0; i < employeeN.size(); i++){
       companyN.push_back(employeeN[i].getCompanyName());
    }
/*    for(int j = 0; j < 4; j++){
    companyN.push_back(employeeN[j].getCompanyName());
  }
    companyN.push_back(employeeN[8].getCompanyName());

    cout << "This vector contains: \n";

      for(int i = 0; i < companyN.size(); i++){
      cout << companyN[i] << endl;
    } */
}
void printHighestPaid(vector<Person> &employeeN){
  //Created a temporary variable that will hold the largest amount.
  float tmp = 0;
  //For loop will check every single employees wage, and add the
  //biggest amount found to the temporary variable.
  for(int i = 0; i < employeeN.size(); i++){
    if(tmp < employeeN[i].totalPay()){
      tmp = employeeN[i].totalPay();
    }
  }
  //This loop will check which employee got paid the highest and print
  //out their information.
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
  string companyName;
  fstream file;
  string name;
  int id;
  string company;
  float total;

  float intelTotal;
  float raytheonTotal;
  float healthtechTotal;
  float douglasTotal;
  float boeingTotal;

  //Since the company name vector isn't what I wanted, there probably is
  //a more efficent way to write this part of the code.
  for(int i = 0; i < employeeN.size(); i++){
    companyName = companyN[i] + ".txt";
    file.open(companyName, fstream::app);
  //  cout << companyName << endl;
        if(file.is_open()){
          name = employeeN[i].fullName();
          id = employeeN[i].getEmployeeId();
          company = employeeN[i].getCompanyName();
          total = employeeN[i].totalPay();

        //  cout << name << " " << id << " " << company << " " << total << endl;
         file << name << " " << id << " " << company << " $" << total << endl;
        }
        else{
          cout << "Error: Could not open file!" << endl;
        }
        if(company == "Intel"){
          intelTotal += total;
        }
        if(company == "Raytheon"){
          raytheonTotal += total;
        }
        if(company == "HealthTech"){
          healthtechTotal += total;
        }
        if(company == "Douglas"){
          douglasTotal += total;
        }
        if(company == "Boeing"){
          boeingTotal += total;
        }
          file.close();
        }
    file.open("Intel.txt", fstream::app);
    file << "Total $" << intelTotal << endl;
    file.close();

    file.open("Raytheon.txt", fstream::app);
    file << "Total $" << raytheonTotal << endl;
    file.close();

    file.open("HealthTech.txt", fstream::app);
    file << "Total $" << healthtechTotal << endl;
    file.close();

    file.open("Douglas.txt", fstream::app);
    file << "Total $" << douglasTotal << endl;
    file.close();

    file.open("Boeing.txt", fstream::app);
    file << "Total $" << boeingTotal << endl;
    file.close();
}

int main(){

  //Vector that holds all employees of the class type
  vector<Person> employees;

  //Vector that only holds strings. All company names.
  vector<string> companyNames;

  //Function that reads in data from a file.
  readData(employees);

  //Function that adds company names from employees vector to companyNames vector.
  //Should take a look at how to check if it's already in the vector because
  //I added all 16 of the companies in the vector instead of just 5 unique companies.
  getCompanies(employees, companyNames);

  //Function that prints the highest paid employee. Should be correct.
  printHighestPaid(employees);

  //Separates the employees by company name and puts them in their respective
  //file.
  separateAndSave(employees, companyNames);
}
