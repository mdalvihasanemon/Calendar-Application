#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class calendar_2024;

class Calendar {
private:
    static const int MAX_ACCOUNTS = 1000;
    struct Account
    {
        string AcNumber;
        string password;
        string name;
    };
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 3;

    int changeACnumber = 0;
    int month;
    int year;

public:
    string Month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    Calendar()
    {
        initializeAccounts();
    }

    void initializeAccounts()
    {
        accounts[0] = {"01406501", "Rafi014", "Tahamid hasan rafi"};
        accounts[1] = {"01795561", "Alvi017", "Alvi hasan"};
        accounts[2] = {"016", "016", "Kamrul Hasan"};
    }

    void getData()
    {
        string response;
        cout << "\t\t----WELCOME TO ABS() CALENDAR----\n\n\tDo you have any Account in this Calendar ....?\n"
        << "\t\t 'yes'..... or .....'no'\n";
        cin >> response;

        if (response == "yes" || response == "YES" || response == "Yes")
        {
            getExistingAccountData();
        }
        else if (response == "no" || response == "No" || response == "NO")
        {
            createNewAccount();
        }
        else
        {
            cout << "Type 'yes' or 'no'\n:";
            getData();
        }
    }

    void OpenCalendar()
    {
        cout << "Calendar is open!" << endl;
        int month, year;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
        Calendar cal(month, year);
        cout << endl;
        if (month == 1)
        {
            cout << "    Calendar: " << Month[0] << "/" << year << endl;
        }
        else if (month == 2)
        {
            cout << "    Calendar: " << Month[1] << "/" << year << endl;
        }
        else if (month == 3)
        {
            cout << "    Calendar: " << Month[2] << "/" << year << endl;
        }
        else if (month == 4)
        {
            cout << "    Calendar: " << Month[3] << "/" << year << endl;
        }
        else if (month == 5)
        {
            cout << "    Calendar: " << Month[4] << "/" << year << endl;
        }
        else if (month == 6)
        {
            cout << "    Calendar: " << Month[5] << "/" << year << endl;
        }
        else if (month == 7)
        {
            cout << "    Calendar: " << Month[6] << "/" << year << endl;
        }
        else if (month == 8)
        {
            cout << "    Calendar: " << Month[7] << "/" << year << endl;
        }
        else if (month == 9)
        {
            cout << "    Calendar: " << Month[8] << "/" << year << endl;
        }
        else if (month == 10)
        {
            cout << "    Calendar: " << Month[9] << "/" << year << endl;
        }
        else if (month == 11)
        {
            cout << "    Calendar: " << Month[10] << "/" << year << endl;
        }
        else if (month == 12)
        {
            cout << "    Calendar: " << Month[11] << "/" << year << endl;
        }

        cal.print();
    }

    void getExistingAccountData()
    {
        string EnteredNumber, enteredPassword;
        cout << "Enter your AC number:";
        cin >> EnteredNumber;
        cout << "Enter your Password:";
        cin >> enteredPassword;
        matchData(EnteredNumber, enteredPassword);
    }

    void matchData(string EnteredNumber, string enteredPassword);

    void createNewAccount()
    {
        changeACnumber = changeACnumber + 188;
        accountCount++;
        if (accountCount < MAX_ACCOUNTS)
        {
            int Username;
            int index = accountCount;

            cout << "\t\tCreate a ABS( ) Calendar Account.....\n\nEnter your name:";
            cin >> ws;
            getline(cin, accounts[index].name);
            cout << "Enter your Username :";
            cin >> Username;

            cout << "Enter your password:";
            cin >> accounts[index].password;

            accounts[index].AcNumber = generateAccountNumber();

            cout << "\n-After creating a new account-\n"
                 << "AC number: " << accounts[index].AcNumber << "\n"
                 << "AC name: " << accounts[index].name << "\n"
                 << "AC password: " << accounts[index].password << "\n";
            cout << "-----THANK YOU!-----\n\n";

            getData();
        }
        else
        {
            cout << "Can't create a new account. Maximum limit you have reached.\n";
        }
    }

    string generateAccountNumber()
    {
        return "1" + to_string(changeACnumber) + "000";
    }

    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getDaysInMonth(int month, int year)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return -1;
        }
    }

    int getStartingDay(int month, int year)
    {
        if (month < 3)
        {
            month += 12;
            year--;
        }
        int k = year % 100;
        int j = year / 100;
        return (1 + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    }

    Calendar(int m, int y) : month(m), year(y) {}

   void print()
{
    cout << "  " << setw(5) << "SAT" << setw(5) << "SUN" << setw(5) << "MON" << setw(5)
         << "TUE" << setw(5) << "WED" << setw(5) << "THU" << setw(5) << "FRI" << endl;

    int daysInMonth = getDaysInMonth(month, year);
    int startingDay = getStartingDay(month, year);

    // Adjust starting position
    for (int i = 0; i < startingDay; ++i)
    {
        cout << setw(5) << "";
    }

    // Print days sequentially
    for (int day = 1; day <= daysInMonth; ++day)
    {
        cout << setw(5) << day;

        // If it's the last day of the week, start a new line
        if ((startingDay + day) % 7 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
    string Event_Title;
    cout<<"ADD YOUR EVENT:"<< endl;
    cout << "Enter event Title:... ";
    cin >> ws;

    getline(cin, Event_Title);

    Add_NewEvent();
}

    bool isDateValid(string date)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        int currentMonth = 1 + ltm->tm_mon;
        int currentDay = ltm->tm_mday;

        int enteredDay, enteredMonth, enteredYear, enteredHour, enteredMinute;
        sscanf(date.c_str(), "%d/%d/%d %d:%d", &enteredDay, &enteredMonth, &enteredYear, &enteredHour, &enteredMinute);

        if (enteredYear < currentYear || (enteredYear == currentYear && enteredMonth < currentMonth) || (enteredYear == currentYear && enteredMonth == currentMonth && enteredDay < currentDay))
            return false;
        else
            return true;
    }

    void Add_NewEvent()
    {
        string date, time, Event_Title;



        cout << "Enter Event date and time (format: DD/MM/YYYY HH:MM): ";
        cin >> date;
        if (!isDateValid(date))
        {
            cout << "Invalid date and time. Please enter date and time based on current date and time." << endl;

            Add_NewEvent();
        }
        else
        {
            cout << "Event added successfully!" << endl;
        }
    }
};

class calendar_2024 : public Calendar
{
public:


    bool isLeapyear242024(int year24)
    {
        if ((year24 % 4 == 0 && year24 % 100 != 0) || (year24 % 400 == 0))
            return true;
        else
            return false;
    }

    int daysInmonth242024(int month24, int year24)
    {
        if (month24 == 2)
        {
            if (isLeapyear242024(year24))
                return 29;
            else
                return 28;
        }
        else if (month24 == 4 || month24 == 6 || month24 == 9 || month24 == 11)
            return 30;
        else
            return 31;
    }
void printCalendar2024()
{
    int year = 2024;
    cout << "CALENDAR FOR YEAR " << year << endl;
    cout << "===================" << endl;

    string months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};

    int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int startDay = 1; // January 1, 2024 is a Tuesday (0 for Sunday, 1 for Monday, ..., 6 for Saturday)

    for (int month = 0; month < 12; ++month)
    {
        cout << endl << months[month] << endl;
        cout << "---------------------" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

        // Print leading spaces for the first week
        for (int i = 0; i < startDay; ++i)
            cout << "    ";

        // Print days
        for (int day = 1; day <= daysInMonth[month]; ++day)
        {
            printf("%3d ", day);
            startDay++;
            if (startDay % 7 == 0)
                cout << endl;
        }

        if (startDay % 7 != 0)
            cout << endl;

        startDay %= 7;
    }
}

};

void Calendar::matchData(string EnteredNumber, string enteredPassword)
{
    for (int i = 0; i <= accountCount; i++)
    {
        if (EnteredNumber == accounts[i].AcNumber && enteredPassword == accounts[i].password)
        {
            calendar_2024 calendar2024;
            calendar2024.printCalendar2024();
            OpenCalendar();
            return;
        }
    }

    cout << "Account number and password do not match !!" << endl;
    cout << "Enter valid AC number and password:\n";
    getExistingAccountData();
}

int main()
{
    Calendar c;
    c.getData();

    return 0;
}
