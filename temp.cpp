#include <iostream>
#include <fstream>
#include <vector>
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

void predisplay();
void readCSVFile();
bool check_email();
int valid_email_check();
bool caseCheck(int n);
void addPhoneNo();
bool checkValidIntergerArray(string n);
bool checkIDDuplicate(int ID);
bool checkPNDuplicate(int pn);
void add();
void displayEmployees();
void deleteEmployee(int id);


void predisplay(){
    cout << " ______ __  __ _____  _      ______     ________ ______   __  __          _   _          _____ ______ __  __ ______ _   _ _______    _______     _______ _______ ______ __  __ " << endl;
    cout << "|  ____|  \\/  |  __ \\| |    / __ \\ \\   / /  ____|  ____| |  \\/  |   /\\   | \\ | |   /\\   / ____|  ____|  \\/  |  ____| \\ | |__   __|  / ____\\ \\   / / ____|__   __|  ____|  \\/  |" << endl;
    cout << "| |__  | \\  / | |__) | |   | |  | \\ \\_/ /| |__  | |__    | \\  / |  /  \\  |  \\| |  /  \\ | |  __| |__  | \\  / | |__  |  \\| |  | |    | (___  \\ \\_/ / (___    | |  | |__  | \\  / |" << endl;
    cout << "|  __| | |\\/| |  ___/| |   | |  | |\\   / |  __| |  __|   | |\\/| | / /\\ \\ | . ` | / /\\ \\| | |_ |  __| | |\\/| |  __| | . ` |  | |     \\___ \\  \\   / \\___ \\   | |  |  __| | |\\/| |" << endl;
    cout << "| |____| |  | | |    | |___| |__| | | |  | |____| |____  | |  | |/ ____ \\| |\\  |/ ____ \\ |__| | |____| |  | | |____| |\\  |  | |     ____) |  | |  ____) |  | |  | |____| |  | |" << endl;
    cout << "|______|_|  |_|_|    |______\\____/  |_|  |______|______| |_|  |_/_/    \\_\\_| \\_/_/    \\_\\_____|______|_|  |_|______|_| \\_|  |_|    |_____/   |_| |_____/   |_|  |______|_|  |_|" << endl;

}

void readCSVFile() {
    ifstream file; //ifstream Đại diện cho stream đầu vào, được dùng để đọc thông tin từ file dữ liệu
    file.open("Book1.csv", ios::in); //iso::in mở file
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
        employees.push(e);
    }
    file.close();
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
    
    if (count > 0) return false;
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

int valid_email_check() {
    bool x = true;
    do
    {
        printf("Email: ");
        x = check_email();
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
        }
        if(!checkValidIntergerArray(info.phoneNo) || !checkPNDuplicate(addPhoneNoTemp)){
            parse_correct = false;
        }
        parse_correct = true;


    
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

bool checkIDDuplicate(int ID){
    stack<Employee> tempStack = employees;
    bool found = false;
    while (!tempStack.empty()) {
        Employee temp = tempStack.top();
        tempStack.pop();
        if (stoi(temp.ID) == ID) {
            cout << "ID already appeared in the database! Please check again\n";
            return false;
        }
    }
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
    fflush(stdin);

    cout << "Gender: ";
    getline(cin, info.gender);
    fflush(stdin);

    //cout << "Email: ";
    valid_email_check();
    fflush(stdin);

    cout << "ID: ";
    getline(cin, info.ID);
    fflush(stdin);

    addPhoneNo();
    fflush(stdin);

    cout << "Salary: ";
    getline(cin, info.salary);
    fflush(stdin);

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
        temp.phoneNo.insert(0, zero);       //do trong file csv mat so 0 nen add them vao de display
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
// void searchByID(string id)
// {
//     bool found = false;
//     for (auto e : employees) {
//         if (e.ID == id) {
//             found = true;
//             cout << "Name: " << e.name << endl;
//             cout << "Gender: " << e.gender << endl;
//             cout << "Email: " << e.email << endl;
//             cout << "ID: " << e.ID << endl;
//             cout << "Phone number: " << e.phoneNo << endl;
//             cout << "Salary: " << e.salary << endl;
//             cout << endl;
//         }
//     }
//     if (!found) {
//         cout << "Employee with ID " << id << " not found." << endl;
//     }
// }


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
    cout << "Press (1) to return to the main menu!\n";
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