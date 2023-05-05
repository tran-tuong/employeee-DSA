#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

struct employee
{
    string name;
    string gender;
    string email;
    int ID;
    int phoneNo;
    int salary;
}info ;

void add(){
    fstream fout;

    fout.open("Book1.csv", ios::out | ios::app);

    cout << "Adding element: " << endl;
    cout << "Name: ";
    getline(cin, info.name);

    cout << "Gender: ";
    getline(cin, info.gender);

    cout << "Email: ";
    getline(cin, info.email);

    cout << "ID: ";
    cin >> info.ID;

    cout << "Phone number: ";
    cin >> info.phoneNo;

    cout << "Salary: ";
    cin >> info.salary;

    fout << info.name << ", " << info.gender << ", " << info.email << ", " << info.ID << ", " << info.phoneNo << ", " << info.salary << endl;

}

void show(){
    fstream fin;
    
    fin.open("Book1.csv", ios::in);

    int rollnum, roll2, count;
    cout << "Enter the ID: ";
    cin >> rollnum;

    vector<string> row;
    string line, word, temp;

    while (fin << temp){
        row.clear();

        getline(fin, line);

        stringstream str(line);

        while(getline(str, word)){
            row.push_back(word);
        }

        roll2 = stoi(row[3]);

        if(roll2 == rollnum){
            count = 1;
            cout << "Name" << row[0] << endl;
            cout << "Gender" << row[1] << endl;
            cout << "Email" << row[2] << endl;
            cout << "ID" << row[3] << endl;
            cout << "Phone num" << row[4] << endl;
            cout << "Salary" << row[5] << endl;
            break;
        }


    }

    if (count == 0){
        cout << "Record not found";
    }
}


int main(){
    string name, email;
    int ID;
    cout << " ______ __  __ _____  _      ______     ________ ______   __  __          _   _          _____ ______ __  __ ______ _   _ _______    _______     _______ _______ ______ __  __ " << endl;
    cout << "|  ____|  \\/  |  __ \\| |    / __ \\ \\   / /  ____|  ____| |  \\/  |   /\\   | \\ | |   /\\   / ____|  ____|  \\/  |  ____| \\ | |__   __|  / ____\\ \\   / / ____|__   __|  ____|  \\/  |" << endl;
    cout << "| |__  | \\  / | |__) | |   | |  | \\ \\_/ /| |__  | |__    | \\  / |  /  \\  |  \\| |  /  \\ | |  __| |__  | \\  / | |__  |  \\| |  | |    | (___  \\ \\_/ / (___    | |  | |__  | \\  / |" << endl;
    cout << "|  __| | |\\/| |  ___/| |   | |  | |\\   / |  __| |  __|   | |\\/| | / /\\ \\ | . ` | / /\\ \\| | |_ |  __| | |\\/| |  __| | . ` |  | |     \\___ \\  \\   / \\___ \\   | |  |  __| | |\\/| |" << endl;
    cout << "| |____| |  | | |    | |___| |__| | | |  | |____| |____  | |  | |/ ____ \\| |\\  |/ ____ \\ |__| | |____| |  | | |____| |\\  |  | |     ____) |  | |  ____) |  | |  | |____| |  | |" << endl;
    cout << "|______|_|  |_|_|    |______\\____/  |_|  |______|______| |_|  |_/_/    \\_\\_| \\_/_/    \\_\\_____|______|_|  |_|______|_| \\_|  |_|    |_____/   |_| |_____/   |_|  |______|_|  |_|" << endl;
    cout << ("\n\n========== MENU ==========\n\n");
    cout << "1. Add a new info\n"; 
    cout << "2. Update an existing info\n";
    cout << "3. Search for a info\n";   
    cout << "4. Remove a info\n";
    cout << "5. List all contacts\n";
    cout << "6. Exit\n\n";
    cout << "==========================\n\n";
    cout << "Your option: ";
    int choice;
    cin >> choice;
    switch (choice){
        case 1:

            add();

            break;
        
        case 2:
            
            break;
        
        case 3:
            
            break;
        
        case 4:
            
            break;
        
        case 5:
            show();
            break;
        
        case 6:
            
            break;
        
        default:
            break;
    }
}