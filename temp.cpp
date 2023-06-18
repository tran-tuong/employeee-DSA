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
bool checkValidIntergerArray(string n);
bool checkIDDuplicate(string id);
bool checkPNDuplicate(string pn);
void add();
void displayEmployees();
void searchEmployee(int id);
void deleteEmployee(int id);
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
    file.open("Book2.csv", ios::in);
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
        if(info.phoneNo.length() != 10){
            parse_correct = false;
            cout << "Phone number must have 10 digits!\n";
            continue;
        } else if(!checkValidIntergerArray(info.phoneNo) || !checkPNDuplicate(info.phoneNo)){
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
        if(!checkValidIntergerArray(info.salary)){
            parse_correct = false;
        } else {
            parse_correct = true;
        }

    } while(!parse_correct);
}

bool checkValidIntergerArray(string n){
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
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        if (info.ID.compare(id)) {
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
        if (!pn.compare(temp.phoneNo)) {
            cout << "Phone number already appeared in the database! Please check again\n";
            return false;
        }
    }

    return true;
}


void add(){
    fstream fout;

    fout.open("Book2.csv", ios::out | ios::app);
    string exit = " ";

    cout << "Adding element: \n(Enter *Blankspace* to exit)" << endl;
    cin.ignore();
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
    info.phoneNo.insert(0, "'");
    fout << info.name << ", " << info.gender << ", " << info.email << ", " << info.ID << ", " << info.phoneNo << ", " << info.salary << endl;
    cout << info.phoneNo;
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
            cout << "| " << setw(9) << temp.ID << " | " << setw(24) << temp.name << " | " << setw(7) 
                         << temp.gender << " | " << setw(24) << temp.email << " | " << setw(11) 
                         << temp.phoneNo << " | " << setw(9) << temp.salary << " | " << endl; 
            }
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void searchEmployee(int id) {
    stack<Employee> tempStack = employees;
    bool found = false;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        if (stoi(temp.ID) == id) {
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

void deleteEmployee(int id) {
    stack<Employee> tempStack, tempStack2;
    Employee temp;
    bool found = false;
    fstream fin("Book1.csv", ios::in | ios::out);
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

//--------------------------------test----------------------------



int main(){
    readCSVFile();
    main:
    system("cls");
    predisplay();
    int yn, choice;
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

            break;
        
        case 3:
            int temp3;

            cout << "Enter the ID of the employee you want to find: ";
            cin >> temp3;
            searchEmployee(temp3);
            break;
        
        case 4:
            int temp4;
            
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