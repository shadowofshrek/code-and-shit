#include<iostream>
#include<fstream>
using namespace std;

int vowels(string name) {
    int count = 0;
    for (int i = 0; i < name.length(); i++)
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')//this is for makeing the pin using the amount of vowels in the users name
            count++;
    return count;
}

int reverse(int n) {

    int reversedNumber = 0, remainder;// bruv

    while (n != 0) {
        remainder = n % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
    }

    return reversedNumber;
}


int dayofweek(int d, int m, int y)// this is for finding out the day the user was born, i used Tomohiko Sakamoto’s Algorithm to be able to do this
{
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int passwordcheck(string pass) { //this is for the password strengh, i used "https://www.geeksforgeeks.org/count-uppercase-lowercase-special-character-numeric-values/" to help me do this  

    if (pass.length() < 14)
        return 0;

    int cap = 0, num = 0, symb = 0;

    for (int i = 0; i < pass.length(); i++) {

        if (pass[i] >= 'A' && pass[i] <= 'Z')
            cap++;
        else if (pass[i] >= '0' && pass[i] <= '9')
            num++;
        else
            symb++;
    }

    if (pass.length() >= 18 && cap >= 4 && num >= 3 && symb >= 3)
        return 3;
    else if (pass.length() >= 16 && cap >= 2 && num >= 2 && symb >= 2)
        return 2;
    else if (pass.length() >= 14 && cap >= 1 && num >= 1 && symb >= 1)
        return 1;

}
int main()// the start of the app
{
    cout << "Welcome to USW Cyber App \n";
    cout << "enter your date of birth \n";
    int day, month, year;
    cout << "day: ";
    cin >> day;
    cout << "month: ";
    cin >> month;
    cout << "year: ";
    cin >> year;

    day = dayofweek(day, month, year);

    if (day == 0)
        cout << "Sunday";
    else if (day == 1)
        cout << "Monday";
    else if (day == 2)
        cout << "Tusday";
    else if (day == 3)
        cout << "Wednesday";
    else if (day == 4)
        cout << "Thursday";
    else if (day == 5)
        cout << "Friday";
    else
        cout << "Saturday";

    cout << endl;

    string name;
    int enrolement_number, age;

    cout << "Enter full name: ";
    cin >> name;
    fflush(stdin);
    cout << "Enter your Enrollment number: ";
    cin >> enrolement_number;
    cout << "Enter your age: ";
    cin >> age;

    int count = vowels(name);
    int reverse_age = reverse(age);

    int pin = count * reverse_age;// this is to generate your pin
    cout << "your pin is: ";
    printf("%04d\n", pin);
    
    int account, i = 3, check = 1;
    cout << "Enter Enrollment number:";
    cin >> account;
    cout << "Enter pin:";
    cin >> pin;

    while (i--) {

        if (pin == pin && account == enrolement_number)
            break;

        cout << "Error!\n";
        cout << "Enter Enrollment number:";
        cin >> account;
        cout << "Enter pin:";
        cin >> pin;
    }

    if (i + 1 == 0) {

        cout << "Session ended 3 trials done";
        return 0;
    }
    string username, temp;
    cout << "Enter username:";
    cin >> username;

    string password;
    cout << "Please Make a Password:";
    cin >> password;
    check = passwordcheck(password);
    while (check != 3) {

        if (check == 0){
            cout << "Invalid password try again \n";
            
        }else if (check == 1){
            cout << "Weak password try again \n";
            
        }else{
            cout << "Medium password try again\n";
            
        }
        cout << "your password needs to be atleast 18 characters long \n";
        cout << "you need atleast 4 upper case letters \n";
        cout << "you need atleast 3 numbers \n";
        cout << "you need atleast 3 symbols \n";

        cout << "Enter password:";
        cin >> password;
        check = passwordcheck(password);
    }
    cout << "Strong password";
    cout << "";

    ofstream file;
    file.open("2FA_users.txt", ios::app);
    file << account << " " << pin << " " << username << " " << password << endl;
    
    return 0;
    
}