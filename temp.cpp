#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

struct employee
{
    string gender;
    string email;
    string name;
    int ID;
    int phoneNo;
    int salary;
}info ;

void predisplay(){
    cout << " ______ __  __ _____  _      ______     ________ ______   __  __          _   _          _____ ______ __  __ ______ _   _ _______    _______     _______ _______ ______ __  __ " << endl;
    cout << "|  ____|  \\/  |  __ \\| |    / __ \\ \\   / /  ____|  ____| |  \\/  |   /\\   | \\ | |   /\\   / ____|  ____|  \\/  |  ____| \\ | |__   __|  / ____\\ \\   / / ____|__   __|  ____|  \\/  |" << endl;
    cout << "| |__  | \\  / | |__) | |   | |  | \\ \\_/ /| |__  | |__    | \\  / |  /  \\  |  \\| |  /  \\ | |  __| |__  | \\  / | |__  |  \\| |  | |    | (___  \\ \\_/ / (___    | |  | |__  | \\  / |" << endl;
    cout << "|  __| | |\\/| |  ___/| |   | |  | |\\   / |  __| |  __|   | |\\/| | / /\\ \\ | . ` | / /\\ \\| | |_ |  __| | |\\/| |  __| | . ` |  | |     \\___ \\  \\   / \\___ \\   | |  |  __| | |\\/| |" << endl;
    cout << "| |____| |  | | |    | |___| |__| | | |  | |____| |____  | |  | |/ ____ \\| |\\  |/ ____ \\ |__| | |____| |  | | |____| |\\  |  | |     ____) |  | |  ____) |  | |  | |____| |  | |" << endl;
    cout << "|______|_|  |_|_|    |______\\____/  |_|  |______|______| |_|  |_/_/    \\_\\_| \\_/_/    \\_\\_____|______|_|  |_|______|_| \\_|  |_|    |_____/   |_| |_____/   |_|  |______|_|  |_|" << endl;

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
//        printf("Email: ");
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

    cout << "Email: ";
    valid_email_check();
    fflush(stdin);

    cout << "ID: ";
    cin >> info.ID;
    fflush(stdin);

    cout << "Phone number: ";
    cin >> info.phoneNo;
    fflush(stdin);

    cout << "Salary: ";
    cin >> info.salary;
    fflush(stdin);

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
    main:
    //system("cls");
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
            
            break;
        
        case 5:
            show();
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