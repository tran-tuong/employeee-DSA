#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;
//spinach//
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

void predisplay();
void readCSVFile();
bool check_email();
int validEmailCheck();
bool caseCheck(int n);
void addPhoneNo();
bool checkValidIntegerArray(string n);
bool checkIDDuplicate(int ID);
bool checkPNDuplicate(int pn);
void add();
void displayEmployees();
void deleteEmployee(int id);
void addID();
void addSalary();
void update_input();

void predisplay(){
    cout << " ______ __  __ _____  _      ______     ________ ______   __  __          _   _          _____ ______ __  __ ______ _   _ _______    _______     _______ _______ ______ __  __ " << endl;
    cout << "|  ____|  \\/  |  __ \\| |    / __ \\ \\   / /  ____|  ____| |  \\/  |   /\\   | \\ | |   /\\   / ____|  ____|  \\/  |  ____| \\ | |__   __|  / ____\\ \\   / / ____|__   __|  ____|  \\/  |" << endl;
    cout << "| |__  | \\  / | |__) | |   | |  | \\ \\_/ /| |__  | |__    | \\  / |  /  \\  |  \\| |  /  \\ | |  __| |__  | \\  / | |__  |  \\| |  | |    | (___  \\ \\_/ / (___    | |  | |__  | \\  / |" << endl;
    cout << "|  __| | |\\/| |  ___/| |   | |  | |\\   / |  __| |  __|   | |\\/| | / /\\ \\ | . ` | / /\\ \\| | |_ |  __| | |\\/| |  __| | . ` |  | |     \\___ \\  \\   / \\___ \\   | |  |  __| | |\\/| |" << endl;
    cout << "| |____| |  | | |    | |___| |__| | | |  | |____| |____  | |  | |/ ____ \\| |\\  |/ ____ \\ |__| | |____| |  | | |____| |\\  |  | |     ____) |  | |  ____) |  | |  | |____| |  | |" << endl;
    cout << "|______|_|  |_|_|    |______\\____/  |_|  |______|______| |_|  |_/_/    \\_\\_| \\_/_/    \\_\\_____|______|_|  |_|______|_| \\_|  |_|    |_____/   |_| |_____/   |_|  |______|_|  |_|" << endl;

}

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

void addGender(){
    bool parse_correct;
    do{
        parse_correct = true;
        cout << "Gender: \nMale(1)\t\tFemale(2)\t\tHomo(3)\nYour choice: " ;
        int gender;
        cin >> gender;
        switch (gender)
        {
        case 1:
            info.gender = "Male";
            break;
        case 2:
            info.gender = "Female";
            break;
        case 3:
            info.gender = "Homo";
            
            break;
        
        default:
            cout << "Invalid input!";
            parse_correct = false;
            break;
        }
    } while(!parse_correct);
}

bool check_email(string email){
    int i, j, k = 0, count = 0;
    bool atFlag = true;
    bool dotFlag = true;
    char two_words[3] = "@.";
    
    while (email[k] != '\0')
    {
        if(email[k] == ' '){
            count++;
        }
        k++;
    }
    
    if (count > 0) return false;
    for(i = 0; i < email.length(); i++){
        if(email[i] == '@'){
            atFlag = false;
        }
        for (j = 0; j < email.length(); j++)
        {
            if(email[j] == '.'){
                dotFlag = false;
            }
        }
    }

    
    //if (info.email.compare(two_words) != NULL) return false;
    if (atFlag == false && dotFlag == false) return true;
    if (atFlag == true && dotFlag == true) return false;
}

int validEmailCheck() {
    getline(cin, info.email);
    bool x = true;
    do
    {
        printf("Email: ");
        x = check_email(info.email);
        if (x == false) printf("Invalid email!\n");
    } while (x == false); 
    return 0;
}


bool caseCheck(int n){
    if(n < 1 || n > 6){
        return false;
    }
    return true;
}

void addPhoneNo(){
    bool parse_correct = true;
    int addPhoneNoTemp;
    do{
        cout << "Phone number: ";
        getline(cin, info.phoneNo);
        addPhoneNoTemp = stoi(info.phoneNo);
        if(info.phoneNo.length() != 10){
            parse_correct = false;
            cout << "Phone number must have 10 digits!\n";
            continue;
        } else if(!checkValidIntegerArray(info.phoneNo) || !checkPNDuplicate(addPhoneNoTemp)){
            parse_correct = false;
        } else {
            parse_correct = true;
        }

    } while(!parse_correct);
}

void addID(){
    bool parse_correct = true;
    int addIDTemp;
    do{
        cout << "ID: ";
        getline(cin, info.ID);
        addIDTemp = stoi(info.ID);
        if(!checkIDDuplicate(addIDTemp)){
            parse_correct = false;
        } else{
            parse_correct = true;
        }
    }while(!parse_correct);
}

void addSalary(){
    bool parse_correct = true;
    int addSalaryTemp;
    do{
        cout << "Salary: ";
        getline(cin, info.salary);
        if(!checkValidIntegerArray(info.salary)){
            parse_correct = false;
        } else {
            parse_correct = true;
        }

    } while(!parse_correct);
}

bool checkValidIntegerArray(string n){
    for(auto i : n){
        if(!isdigit(i)){
            cout << "Invalid Input!";
            return false;
        }
    }
    return true;
}

bool checkIDDuplicate(int id){
    stack<Employee> tempStack = employees;
    bool found = false;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        if (stoi(temp.ID) == id) {
            cout << "ID already appeared in the database! Please check again\n";
            return false;
        }
    }
    fflush(stdin);
    return true;
}

bool checkPNDuplicate(int pn){
    stack<Employee> tempStack = employees;
    bool found = false;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        temp.phoneNo.insert(0, zero);
        if (stoi(temp.phoneNo) == pn) {
            cout << "Phone number already appeared in the database! Please check again\n";
            temp.phoneNo.erase(0,1);
            return false;
        }
        temp.phoneNo.erase(0,1);
    }
    fflush(stdin);
    return true;
}


void add(){
    fstream fout;

    fout.open("Book1.csv", ios::out | ios::app);
    string exit = " ";

    cout << "Adding element: \n(Enter *Blankspace* to exit)" << endl;
    getline(cin, info.name);            //dunno why but it works ?!
    cout << "Name: ";
    getline(cin, info.name);
    int checkIfExit = info.name.compare(exit);
    if(checkIfExit == 0){
        return;

    }
    fflush(stdin);

    addGender();
    fflush(stdin);

    //cout << "Email: ";
    validEmailCheck();
    fflush(stdin);

    addID();
    fflush(stdin);

    addPhoneNo();
    fflush(stdin);

    addSalary();
    fflush(stdin);
    employees.push(info);

    fout << info.name << ", " << info.gender << ", " << info.email << ", " << info.ID << ", " << info.phoneNo << ", " << info.salary << endl;
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

void deleteEmployee(int id) {
    stack<Employee> tempStack;
    bool found = false;
    while (!employees.empty()) {
        Employee temp = employees.top();
        employees.pop();

        if (stoi(temp.ID) == id) {
            found = true;
            break;
        }
        tempStack.push(temp);
    }
    while (!tempStack.empty()) {
        employees.push(tempStack.top());
        tempStack.pop();
    }
    if (found) {
        cout << "Employee with ID " << id << " has been deleted!\n";
    } else {
        cout << "Employee not found!\n";
    }
}
//---------------------------update-----------------------//

void addID(Employee& emp) {
    bool parse_correct = true;
    int addIDTemp;
    do {
        cout << "ID: ";
        cin >> emp.ID;
        addIDTemp = stoi(emp.ID);
        if (!checkIDDuplicate(addIDTemp)) {
            parse_correct = false;
            cout << "ID already exists. Please enter a different ID." << endl;
        } else {
            parse_correct = true;
        }
    } while (!parse_correct);
}

void addGender(Employee& emp) {
    bool parse_correct;
    do {
        parse_correct = true;
        cout << "Gender:\n";
        cout << "Male(1)\t\tFemale(2)\t\tHomo(3)\n";
        cout << "Your choice: ";
        int gender;
        cin >> gender;
        switch (gender) {
            case 1:
                emp.gender = "Male";
                break;
            case 2:
                emp.gender = "Female";
                break;
            case 3:
                emp.gender = "Homo";
                break;
            default:
                cout << "Invalid input!" << endl;
                parse_correct = false;
                break;
        }
    } while (!parse_correct);
}

void addPhoneNo(Employee& emp) {
    bool parse_correct = true;
    int addPhoneNoTemp;
    do {
        cout << "Phone number: ";
        cin >> emp.phoneNo;
        addPhoneNoTemp = stoi(emp.phoneNo);
        if (emp.phoneNo.length() != 10) {
            parse_correct = false;
            cout << "Phone number must have 10 digits!" << endl;
        } else if (!checkValidIntegerArray(emp.phoneNo) || !checkPNDuplicate(addPhoneNoTemp)) {
            parse_correct = false;
        } else {
            parse_correct = true;
        }
    } while (!parse_correct);
}

void addSalary(Employee& emp) {
    bool parse_correct = true;
    do {
        cout << "Salary: ";
        cin >> emp.salary;
        if (!checkValidIntegerArray(emp.salary)) {
            parse_correct = false;
        } else {
            parse_correct = true;
        }
    } while (!parse_correct);
}


// int validEmailCheck() {
//     bool x = true;
//     do
//     {
//         printf("Email: ");
//         x = check_email();
//         if (x == false) printf("Invalid email!\n");
//     } while (x == false); 
//     return 0;
// }

void addEmail(Employee& emp) {
    bool valid = true;
    do {
        cout << "Email: ";
        cin >> emp.email;
        valid = check_email(emp.email);
        if (!valid) {
            cout << "Invalid email!" << endl;
        }
    } while (!valid);
}



void updateEmployees() {
    stack<Employee> tempStack;
    int id;
    bool found = false;

    cout << "Enter employee's ID to update: ";
    cin >> id;

    while (!employees.empty()) {
        Employee emp = employees.top();
        employees.pop();

        if (emp.ID == to_string(id)) {
            found = true;
            addGender(emp);
            addEmail(emp);

            cout << "Name: ";
            cin.ignore();
            getline(cin, emp.name);

            addID(emp);
            addPhoneNo(emp);
            addSalary(emp);
        }

        tempStack.push(emp);
    }

    if (found) {
        ofstream outputFile("employees.csv");
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
        } else {
            cout << "Unable to open employees.csv for writing." << endl;
        }
    } else {
        cout << "Employee with the specified ID not found." << endl;
    }
}




//-------------------------------------------------------//

int main(){
    readCSVFile();
    main:
    system("cls");
    predisplay();
    int choice, yn;
    string name, email;
    int ID;
    bool parsed_correct = true;
    do{
        cout << ("\n\n========== MENU ==========\n\n");
        cout << "1. Add a new info\n"; 
        cout << "2. Update an existing info\n";
        cout << "3. Search for a info\n";   
        cout << "4. Remove a info\n";
        cout << "5. List all contacts\n";
        cout << "6. Exit\n\n";
        cout << "==========================\n\n";
        cout << "Your option: ";
        cin >> choice;
        parsed_correct = caseCheck(choice);
        if(!parsed_correct){
            cout << "Invalid option. Try again.\n";
        }
    } while(!parsed_correct);
    switch (choice){
        case 1:

            add();

            break;
        
        case 2:
            updateEmployees();
            break;
        
        case 3:
            
            break;
        
        case 4:
            int temp;
            
            cout << "Enter the ID of the employee you want to delete: ";
            cin >> temp;
            fflush(stdin);

            deleteEmployee(temp);
            break;
        
        case 5:
            displayEmployees();
            break;
        
        case 6:
            cout << "Are you sure you want to exit?\n";
            break;
        
        default:
            cout << "Invalid option. Try again.\n";
            break;
    }    
    cout << "Press (1) to return to the main menu!\nPress any other key to exit the program!\n";
    cin >> yn;
    switch (yn)
    {
    case 1:
        goto main;
        break;
    

    default:

        cout << "Exitting the program!";
        break;
    }
    
}