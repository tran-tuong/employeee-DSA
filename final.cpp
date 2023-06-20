#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <iomanip> // For setw() function

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


void predisplay();
void readCSVFile();
bool check_email();
void validEmailCheck();
bool caseCheck(int n);
void addPhoneNo();
bool checkValidIntegerArray(string n);
bool checkIDDuplicate(string id);
bool checkPNDuplicate(string pn);
void add();
void displayEmployees();
void searchEmployee();
void deleteEmployee(string id);
void addID();
void addSalary();
int partition(vector<int>& arr1, vector<int>& arr2, int low, int high);
void quicksort(vector<int>& arr1, vector<int>& arr2, int low, int high);
void sortData();


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
        if(!ss){
            continue;
        }
        getline(ss, e.name, ',');
        getline(ss, e.gender, ',');
        getline(ss, e.email, ',');
        getline(ss, e.ID, ',');
        getline(ss, e.phoneNo, ',');
        getline(ss, e.salary, ',');
        e.phoneNo.erase(0,2);
        employees.push(e);
    }
    file.close();
}

void addGender(){
    bool parse_correct;
    do{
        parse_correct = true;
        cout << "Gender: \nMale(1)\tFemale(2)\tHomo(3)\nYour choice: " ;
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

bool check_email(){
    int i, j, k = 0, count = 0;
    bool atFlag = true;
    bool dotFlag = true;
    char two_words[3] = "@.";
    getline(cin, info.email);

    while (info.email[k] != '\0')
    {
        if(info.email[k] == ' '){
            count++;
        }
        k++;
    }
    
    if (count > 0){
        return false;
    }
    for(i = 0; i < info.email.length(); i++){
        if(info.email[i] == '@'){
            atFlag = false;
        }
        for (j = 0; j < info.email.length(); j++)
        {
            if(info.email[j] == '.'){
                dotFlag = false;
            }
        }
    }

    
    //if (info.email.compare(two_words) != NULL) return false;
    if (atFlag == false && dotFlag == false) return true;
    if (atFlag == true && dotFlag == true) return false;
}

void validEmailCheck() {
    bool x = true;
    do
    {
        printf("Email: ");
        x = check_email();
        if (x == false) printf("Invalid email!\n");
    } while (x == false); 
    //return 0;
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
        //addPhoneNoTemp = stoi(info.phoneNo);
        if(info.phoneNo.length() != 10){
            parse_correct = false;
            cout << "Phone number must have 10 digits!\n";
            continue;
        } else if(!checkValidIntegerArray(info.phoneNo) || !checkPNDuplicate(info.phoneNo)){
            parse_correct = false;
        } else {
            parse_correct = true;
        }

    } while(!parse_correct);
}

void addID(){
    bool parse_correct = true;
    do{
        cout << "ID: ";
        getline(cin, info.ID);
        if(!checkIDDuplicate(info.ID)){
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

bool checkIDDuplicate(string id){
    stack<Employee> tempStack = employees;
    bool found = false;
    //cout << id << "  " << id.size() << endl;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        //cout << temp.ID << "  " << temp.ID.size() << "\t" <<endl;
        
        if ((temp.ID == id) == 1) {
            cout << "ID already appeared in the database! Please check again\n";
            return false;
        }
    }
    
    return true;
}
bool checkPNDuplicate(string pn){
    stack<Employee> tempStack = employees;
    bool found = false;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        if ((temp.phoneNo == pn) == 1) {
            cout << "Phone number already appeared in the database! Please check again\n";
            return false;
        }
    }

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

    addGender();
    cin.ignore();

    validEmailCheck();

    addID();

    addPhoneNo();
    
    addSalary();
    employees.push(info);
    cout << info.ID.size() << "\t" << info.gender.size() << info.salary.size() << "\t" << endl;
    info.phoneNo.insert(0, "'");
    fout << info.name << "," << info.gender << "," << info.email << "," << info.ID << "," << info.phoneNo << "," << info.salary << endl;
    fout.close();
}

void displayEmployees(){
    system("cls");
    stack<Employee> tempStack = employees;
    if (tempStack.empty()) {
        cout << "No employees in the system!\n";
    } else {
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                               LIST OF EMPOYEES                                               |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|    ID     |            Name          |  Gender |           Email          |" 
                << "     Phone Number     |  Salary   |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;

        while(!tempStack.empty()){
            Employee temp = tempStack.top();
            tempStack.pop();
            cout << "| " << left << setw(9) << temp.ID << " | " << setw(24) << temp.name << " | " << setw(7) 
                         << temp.gender << " | " << setw(24) << temp.email << " | " << setw(20) 
                         << temp.phoneNo << " | " << setw(9) << temp.salary << " | " << endl; 
            }
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void searchEmployee() {
    stack<Employee> tempStack = employees;
    bool found = false;
    string id;
    cout << "Enter the ID of the employee you want to find: ";
    cin >> id;
    cin.ignore();
    //cout << id << endl;

    //cout << id << "  " << id.size() << endl;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        //cout << id << endl;

        //cout << temp.ID << "  " << (id == temp.ID)<< endl;

        if ((id == temp.ID) == 1) {
            cout << "Employee Found!\n";
            cout << "ID: " << temp.ID << endl;
            cout << "Name: " << temp.name << endl;
            cout << "Gender: " << temp.gender << endl;
            cout << "Phone number: " << temp.phoneNo << endl;
            cout << "Email: " << temp.email << endl;
            cout << "Salary: " << temp.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found!\n";
    }
}

//-------------------------------update-----------------------------------

void addID(Employee& emp) {
    bool parse_correct = true;
    do {
        cout << "ID: ";
        cin >> emp.ID;
        if (!checkIDDuplicate(emp.ID)) {
            parse_correct = false;
            //cout << "ID already exists. Please enter a different ID." << endl;
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
    string addPhoneNoTemp;
    do {
        cout << "Phone number: ";
        cin >> emp.phoneNo;
        addPhoneNoTemp = emp.phoneNo;
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
        getline(cin, emp.salary);
        if (!checkValidIntegerArray(emp.salary)) {
            parse_correct = false;
        } else {
            parse_correct = true;
        }
    } while (!parse_correct);
}


bool check_email_update(Employee& emp){
    int i, j, k = 0, count = 0;
    bool atFlag = true;
    bool dotFlag = true;
    char two_words[3] = "@.";
    getline(cin, emp.email);

    while (emp.email[k] != '\0')
    {
        if(emp.email[k] == ' '){
            count++;
        }
        k++;
    }
    
    if (count > 0){
        return false;
    }
    for(i = 0; i < emp.email.length(); i++){
        if(emp.email[i] == '@'){
            atFlag = false;
        }
        for (j = 0; j < emp.email.length(); j++)
        {
            if(emp.email[j] == '.'){
                dotFlag = false;
            }
        }
    }

    
    //if (info.email.compare(two_words) != NULL) return false;
    if (atFlag == false && dotFlag == false) return true;
    if (atFlag == true && dotFlag == true) return false;
}

void validEmailCheck_update(Employee& emp) {
    bool x = true;
    do
    {
        printf("Email: ");
        x = check_email_update(emp);
        if (x == false) printf("Invalid email!\n");
    } while (x == false); 
    //return 0;
}

void addEmail(Employee& emp) {
    bool valid = true;
    do {
        validEmailCheck_update(emp);
        if (!valid) {
            cout << "Invalid email!" << endl;
        }
    } while (!valid);
}



void updateEmployees() {
    stack<Employee> tempStack,tempStack2 = employees;
    Employee temp1, temp2;
    string id;
    char change;
    bool found = false;
    fstream fin("Book1.csv", ios::in | ios::out);
    cin >> id;
    cin.ignore();

    while (!tempStack2.empty()) {
        Employee emp = tempStack2.top();
        tempStack2.pop();

        if ((emp.ID == id) == 1) {
            found = true;

            cout << "Do you want to change the name? (Y/N): "; 
            cin >> change;
            if (change == 'Y' || change == 'y'){
                cin.ignore();
                cout << "Name: ";
                getline(cin, temp1.name);
            }else{
                temp1.name = emp.name;
            }
             
            cout << "Do you want to change the gender? (Y/N): ";
            cin >> change;
            if (change == 'Y' || change == 'y') {
                addGender(temp1);
            } else {
                temp1.gender = emp.gender;  
            }
            
            cout << "Do you want to change the email? (Y/N): ";
            cin >> change;
            cin.ignore();
            if (change == 'Y' || change == 'y') {
                addEmail(temp1);
            } else {
                temp1.email = emp.email;  
            }
        
            cout << "Do you want to change the ID? (Y/N): ";
            cin >> change;
            if (change == 'Y' || change == 'y') {
                addID(temp1);
            } else {
                temp1.ID = emp.ID;  
            }
            
            cout << "Do you want to change the phone number? (Y/N): ";
            cin >> change;
            cin.ignore();
            if (change == 'Y' || change == 'y') {
                addPhoneNo(temp1);
            } else {
                temp1.phoneNo = emp.phoneNo;  
            }
            
            cout << "Do you want to change the salary? (Y/N): ";
            cin >> change;
            cin.ignore();
            if (change == 'Y' || change == 'y') {
                addSalary(temp1);
            } else {
                temp1.salary = emp.salary;  
            }
        
            tempStack.push(temp1);
            break;
        } else {
            tempStack.push(emp);
        }
    }
    
    while (!tempStack.empty()) {
        tempStack2.push(tempStack.top());
        tempStack.pop();
    }    
    employees = tempStack2;
    if (found) {
        fin.close();
        ofstream fout("Book1.csv", ios::trunc); // Open the file in truncate mode to clear the existing data

        while (!tempStack2.empty()) {
            Employee temp2 = tempStack2.top();
            temp2.phoneNo.insert(0, " '");
            fout << temp2.name << "," << temp2.gender << ","
                 << temp2.email << "," << temp2.ID << "," << temp2.phoneNo << ","
                 << temp2.salary << endl;

            tempStack2.pop();
        }

        fout.close();
        cout << "Employee updated successfully!\n";
    } else {
        cout << "Employee not found!\n";
    }
}

void deleteEmployee(string id) {
    stack<Employee> tempStack, tempStack2;
    Employee temp;
    bool found = false;
    fstream fin("Book1.csv", ios::in | ios::out);
    while (!employees.empty()) {
        Employee temp = employees.top();
        employees.pop();

        if ((temp.ID == id) == 1) {
            found = true;
            break;
        }
        tempStack.push(temp);
    }
    while (!tempStack.empty()) {
        employees.push(tempStack.top());
        tempStack.pop();
    }
    tempStack2 = employees;



    if (found) {
        cout << "Employee with ID " << id << " has been deleted!\n";
        fin.seekg(0, ios::beg);
        while(!tempStack2.empty()){
            fin << tempStack2.top().name << ","<< tempStack2.top().gender << ","<< tempStack2.top().email << ","<< tempStack2.top().ID << ","<< tempStack2.top().phoneNo << ","<< tempStack2.top().salary << endl; 
            tempStack2.pop();
        }

    } else {
        cout << "Employee not found!\n";
    }
    fin.close();
}



//--------------------------------sort test----------------------------


int partition(vector<int>& arr, vector<int>& arr1, int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swap(arr1[i], arr1[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    swap(arr1[i + 1], arr1[high]);

    return i + 1;
}

// Function to perform quicksort on the vector
void quicksort(vector<int>& arr, vector<int>& arr1, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, arr1, low, high);

        quicksort(arr, arr1, low, pivot_index - 1);
        quicksort(arr, arr1, pivot_index + 1, high);
    }
}

void sortData(){
    //stack<Employee> tempStack = employees, sortedData;
    Employee temp;
    int i, j, l, a = 0, stemp;
    vector<Employee> tempVector;
    vector<int> salary, index;
    while(!employees.empty()){
        tempVector.push_back(employees.top());
        stemp = stoi(employees.top().salary);
        salary.push_back(stemp);
        index.push_back(a);
        a++;
        employees.pop();
    }
    l = tempVector.size();
    quicksort(salary, index, 0, l-1);

    for(auto ele : index){
        employees.push(tempVector[ele]);
    }
    cout << "Sort succeeded!!\n";

}

int main(){
    readCSVFile();
    main:
    system("cls");
    predisplay();
    int yn, choice;
    string temp2, temp3, temp4;
    bool parsed_correct = true;
    do{
        cout << ("\n\n========== MENU ==========\n\n");
        cout << "1. Add a new info\n"; 
        cout << "2. Update an existing info\n";
        cout << "3. Search for a info\n";   
        cout << "4. Remove a info\n";
        cout << "5. List all datas\n";
        cout << "6. Sort datas\n";
        cout << "7. Exit\n\n";
        cout << "==========================\n\n";
        cout << "Your option: ";

        cin >> choice;

        if(!caseCheck(choice) || choice == 0){
            parsed_correct = false;
            break;
        }
    } while(!parsed_correct);
    switch (choice){
        case 1:

            add();

            break;
        
        case 2:
            cout << "Enter the ID of the employee you want to update: ";

            updateEmployees();
            break;
        
        case 3:


            searchEmployee();
            break;
        
        case 4:
            //int temp4;
            
            cout << "Enter the ID of the employee you want to delete: ";
            cin >> temp4;
            

            deleteEmployee(temp4);
            break;
        
        case 5:
            displayEmployees();
            break;
        
        case 6:

            sortData();
            displayEmployees();

            break;

        case 7:
        
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