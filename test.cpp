#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

struct Employee
{
    string gender;
    string email;
    string name;
    string ID;
    string phoneNo;
    string salary;
}info ;

stack<Employee> employees;
string deleteTemp, zero = "0";

void readCSVFile() {
    ifstream file;
    file.open("Book1.csv", ios::in);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee e;
        getline(ss, e.name, ',');
        getline(ss, e.gender, ',');
        getline(ss, e.email, ',');
        getline(ss, e.ID, ',');
        getline(ss, e.phoneNo, ',');
        getline(ss, e.salary, ',');
        e.phoneNo.insert(0, zero);
        employees.push(e);
    }
    file.close();
}

void displayEmployees() {
    system("cls");
    stack<Employee> tempStack = employees;
    if (tempStack.empty()) {
        cout << "No employees in the system!\n";
    }
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        //temp.phoneNo.insert(0, zero);       //do trong file csv mat so 0 nen add them vao de display
        tempStack.pop();
        cout << "Name: " << temp.name << endl;
        cout << "Gender: " << temp.gender << endl;
        cout << "Email: " << temp.email << endl;
        cout << "ID: " << temp.ID << endl;
        cout << "Phone num: " << temp.phoneNo << endl;
        cout << "Salary: " << temp.salary << endl;
        cout << "----------------------\n";
    }
}

void updateEmployees() {
    Employee updatedEmployee = { "Female", "updated@example.com", "Updated Employee", "E002", "+555555555", "8000" };
    stack<Employee> tempStack;
    int id;
    bool checkID = false;
    cout << "Enter employee's ID to update: ";
    cin >> id;

    while (!employees.empty()) {
        Employee temp = employees.top();
        employees.pop();

        if (temp.ID == to_string(id)) {
            checkID = true;
            temp = updatedEmployee;  
        }
        tempStack.push(temp);
    }

    if (checkID) {
        ofstream outputFile("Book1.csv");
        if (outputFile.is_open()) {
            while (!tempStack.empty()) {
                Employee emp = tempStack.top();
                tempStack.pop();

                stringstream ss;
                ss << emp.gender << "," << emp.email << "," << emp.name << "," << emp.ID << ","
                    << emp.phoneNo << "," << emp.salary << endl;

                outputFile << ss.str();
            }

            outputFile.close();
            cout << "Employee information updated and written to employees.csv." << endl;
        }
    }else{
        cout << "Unable to open employees.csv for writing." << endl;
    }


}



int main(){
    readCSVFile();
    int choice;
    cin >> choice;

    switch (choice){
        case 1:
            updateEmployees();
            break;
        
        case 2:
            displayEmployees();
            break;
        
        default:
            cout << "Invalid option. Try again.\n";
            break;
    }
    return 0;
}