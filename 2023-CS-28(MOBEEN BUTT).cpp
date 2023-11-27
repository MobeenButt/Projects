#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

void User();
void services();
void rate();
void dashboard();
void header();
void eticket();
void feedback();
void rating();
void helpline();
void Menu(string submenu);
void subMenu(string submenu);
void addTicketInformation();
void clearScreen();
int loginMenu();
void Exit();
void displayMenu();
void displayInformation(string names[], int cnics[], string locations[], int nums[], int totalAmounts[], int numTickets);
string Signin(string name, string password, string users[], string passwords[], string roles[], int count);
bool Signup(string name, string password, string role, string users[], string passwords[], string roles[], int &usersCount, int userArrSize);
void manageTrains(string names[], string destinations[], int departureTimes[], int &numTrains, const int MAX_TRAINS);
void removeTrain(string names[], string destinations[], int departureTimes[], int &numTrains);
void addTrain(string names[], string destinations[], int departureTimes[], int &numTrains, const int MAX_TRAINS);
void viewTrains(const string names[], const string destinations[], const int departureTimes[], int numTrains);

int main()
{

    const int userArrSize = 100;
    string users[userArrSize];
    string passwords[userArrSize];
    string roles[userArrSize];
    int count = 0;
    int option = 0;
    while (option != 3)
    {
        header();
        Menu("Login");
        option = loginMenu();
        if (option == 1)
        {
            system("cls");

            string name;
            string password;
            string role;
            header();
            Menu("Signin");
            cout << "Enter your Name: ";
            cin>>name;
            cout << "Enter your Password: ";
            cin >> password;
            role = Signin(name, password, users, passwords, roles, count);
            system("cls");
            if (role == "Admin")
            {
                clearScreen();
                const int MAX_TRAINS = 10; // Maximum number of trains
                header();
                string names[MAX_TRAINS];
                string destinations[MAX_TRAINS];
                int departureTimes[MAX_TRAINS];
                int numTrains = 0;

                int choice = 0;
                while (choice != 9)
                {
                    system("cls");
                    header();
                    cout << "\n\n\t\t\tPress 1 Add New Train" << endl;
                    cout << "\n\n\t\t\tPress 2 View added Trains " << endl;
                    cout << "\n\n\t\t\tPress 3 Available Trains" << endl;
                    cout << "\n\n\t\t\tPress 4 Info" << endl;
                    cout << "\n\n\t\t\tPress 5 Ticket Information" << endl;
                    cout << "\n\n\t\t\tPress 6 Helpline" << endl;
                    cout << "\n\n\t\t\tPress 7 E-Ticket" << endl;
                    cout << "\n\n\t\t\tPress 8 Remove Added Trains" << endl;
                    cout << "\n\n\t\t\tPress 9 Logout" << endl;
                    cout << "\n\n\t\t\tPress 10 Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    if (choice == 1)
                    {
                        system("cls");
                        manageTrains(names, destinations, departureTimes, numTrains, MAX_TRAINS);
                        system("cls");
                    }
                    if (choice == 3)
                    {
                        system("cls");
                        dashboard();
                        system("cls");
                    }
                    if (choice == 4)
                    {
                        system("cls");
                        Sleep(800);
                        header();
                        cout << "Pakistan Railways is the national, state-owned railway company of Pakistan in Lahore. Founded in 1861 as the North Western State Railway and headquartered in Lahore, it owns 7,490 kilometres of operational track across Pakistan, stretching from Torkham to Karachi, offering both freight and passenger services." << endl;
                        clearScreen();
                    }
                    if (choice == 5)
                    {
                        system("cls");
                        rate();
                        system("cls");
                    }
                    if (choice == 6)
                    {
                        system("cls");
                        helpline();
                        system("cls");
                    }
                    if (choice == 7)
                    {
                        system("cls");
                        eticket();
                        system("cls");
                    }
                    if (choice == 8)
                    {
                        system("cls");
                        removeTrain(names, destinations, departureTimes, numTrains);
                        system("cls");
                    }
                    if (choice == 2)
                    {
                        system("cls");
                        viewTrains(names, destinations, departureTimes, numTrains);
                        clearScreen();
                    }
                    if (choice == 9)
                    {

                        system("cls");
                        clearScreen();
                        system("cls");

                        Menu("Login");
                        system("cls");
                    }
                    if (choice == 10)
                    {
                        system("cls");
                        Exit();
                    }

                    else
                    {
                        system("cls");
                        cout << "Invalid choice. Please try again.\n";
                        system("cls");
                    }
                }
            }
            else if (role == "User")
            {
                clearScreen();
                User();
            }
            else if (role == "undefined")
            {
                system("cls");
                cout << "UnIdentifed! " << endl;
            }
        }
        else if (option == 2)
        {
            system("cls");
            string name;
            string password;
            string role;
            header();
            Menu("Signup");
            cout << "\t\t\t\t\tEnter your Name (Spaces Not Allowed): ";
        cin>>name;
            cout << "\t\t\t\t\tEnter your Password: ";
            cin >> password;
            cout << "\t\t\t\t\tEnter your Role (Admin or User): ";
            cin >> role;
            bool isValid = Signup(name, password, role, users, passwords, roles, count, userArrSize);
            if (isValid)
            {
                cout << "\t\t\tCongratulation Signup Succeessfully as " << role << endl;
            }
            if (!isValid)
            {
                cout << "\t\t\tInvalid ! Username or Password" << endl;
            }
        }
        clearScreen();
    }

    return 0;
}

void header()
{
    system("Color 0A");
    cout << R"(
             ______     ______     __     __         __     __     ______     __  __        __    __     ______     __   __     ______     ______     ______     __    __     ______     __   __     ______     
            /\  == \   /\  __ \   /\ \   /\ \       /\ \  _ \ \   /\  __ \   /\ \_\ \      /\ "-./  \   /\  __ \   /\ "-.\ \   /\  __ \   /\  ___\   /\  ___\   /\ "-./  \   /\  ___\   /\ "-.\ \   /\__  _\    
             \ \  __<   \ \  __ \  \ \ \  \ \ \____  \ \ \/ ".\ \  \ \  __ \  \ \____ \     \ \ \-./\ \  \ \  __ \  \ \ \-.  \  \ \  __ \  \ \ \__ \  \ \  __\   \ \ \-./\ \  \ \  __\   \ \ \-.  \  \/_/\ \/    
              \ \_\ \_\  \ \_\ \_\  \ \_\  \ \_____\  \ \__/".~\_\  \ \_\ \_\  \/\_____\     \ \_\ \ \_\  \ \_\ \_\  \ \_\\"\_\  \ \_\ \_\  \ \_____\  \ \_____\  \ \_\ \ \_\  \ \_____\  \ \_\\"\_\    \ \_\    
               \/_/ /_/   \/_/\/_/   \/_/   \/_____/   \/_/   \/_/   \/_/\/_/   \/_____/      \/_/  \/_/   \/_/\/_/   \/_/ \/_/   \/_/\/_/   \/_____/   \/_____/   \/_/  \/_/   \/_____/   \/_/ \/_/     \/_/    
                                                                                                                                                                                                    
)";
}

void addTrain(string names[], string destinations[], int departureTimes[], int &numTrains, const int MAX_TRAINS)
{

    header();
    if (numTrains < MAX_TRAINS)
    {
        cout << "\nEnter Train Details:\n";
        cout << "Train Name: ";
        cin.ignore(); // Ignore newline character in the input buffer
        getline(cin, names[numTrains]);

        cout << "Destination: ";
        getline(cin, destinations[numTrains]);

        cout << "Departure Time (24-hour format, e.g., 1400): ";
        cin >> departureTimes[numTrains];

        cout << "Train added successfully!\n";
        numTrains++;
    }

    else
    {
        cout << "Maximum number of trains reached. Cannot add more trains.\n";
    }
}

void viewTrains(const string names[], const string destinations[], const int departureTimes[], int numTrains)
{

    header();
    if (numTrains > 0)
    {
        cout << "\n===== List of Added Trains =====\n";
        cout << setw(15) << "Train Name" << setw(15) << "Destination" << setw(20) << "Departure Time\n";
        for (int i = 0; i < numTrains; ++i)
        {
            cout << setw(15) << names[i] << setw(15) << destinations[i] << setw(20) << departureTimes[i] << "\n";
        }
        getch();
    }
    else
    {
        cout << "No trains added yet.\n";
    }
}
void eticket()
{
    system("cls");
    const int MAX_PASSENGERS = 10;
    header();

    int numTickets;
    cout << "Enter number of tickets: ";
    cin >> numTickets;

    string names[MAX_PASSENGERS];
    int cnics[MAX_PASSENGERS];
    string locations[MAX_PASSENGERS];
    int nums[MAX_PASSENGERS];
    int totalAmounts[MAX_PASSENGERS];

    cout << "\t\t\t\t\t\tPASSENGERS DETAILS" << endl;

    
    for (int i = 0; i < numTickets; ++i)
    {
        cout << "Enter Name for Passenger " << i + 1 << ": ";
        cin >> names[i];

        cout << "Enter CNIC for Passenger " << i + 1 << ": ";
        cin >> cnics[i];

        bool validLocation = false;
        while (!validLocation)
        {
            cout << "Enter Location for Passenger " << i + 1 << ": ";
            cin >> locations[i];

            if (locations[i] != "Lahore" && locations[i] != "Gujranwala" && locations[i] != "Peshawar" && locations[i] != "Karachi" && locations[i] != "Multan")
            {
                cout << "Invalid Location. Please enter a valid location (Lahore, Gujranwala, Peshawar, Karachi, Multan).\n";
            }
            else
            {
                validLocation = true;
            }
        }

        nums[i] = 1; 

        if (locations[i] == "Lahore")
        {
            totalAmounts[i] = nums[i] * 4500;
        }
        else if (locations[i] == "Karachi")
        {
            totalAmounts[i] = nums[i] * 4200;
        }
        else if (locations[i] == "Peshawar")
        {
            totalAmounts[i] = nums[i] * 4500;
        }
        else if (locations[i] == "Multan")
        {
            totalAmounts[i] = nums[i] * 4000;
        }
        else if (locations[i] == "Gujranwala")
        {
            totalAmounts[i] = nums[i] * 4500;
        }
    }

    displayInformation(names, cnics, locations, nums, totalAmounts, numTickets);
    clearScreen();
}
void displayInformation(string names[], int cnics[], string locations[], int nums[], int totalAmounts[], int numTickets)
{
    clearScreen();
    header();

    cout << "\n\n\n\n\t\t\t\t\t\tTicket Details\n\n\n\n"
         << endl;

    for (int i = 0; i < numTickets; ++i)
    {
        cout << "Passenger " << i + 1 << " Name: " << names[i] << endl;
        cout << "Passenger " << i + 1 << " CNIC: " << cnics[i] << endl;
        cout << "Passenger " << i + 1 << " Location: " << locations[i] << endl;
        cout << "Passenger " << i + 1 << " Number of Tickets: " << nums[i] << endl;
        cout << "Passenger " << i + 1 << " Total Amount: " << totalAmounts[i] << endl;
        cout << "-----------------------------------------" << endl;
    }
}

void User()
{
    header();
    int option;

    cout << "\n\n\t\t\tPress 1 Home" << endl;
    cout << "\n\n\t\t\tPress 2 Train Timings" << endl;
    cout << "\n\n\t\t\tPress 3 Rates" << endl;
    cout << "\n\n\t\t\tPress 4 Info" << endl;
    cout << "\n\n\t\t\tPress 5 EBooking" << endl;
    cout << "\n\n\t\t\tPress 6 Feedback" << endl;
    cout << "\n\n\t\t\tPress 7 Ratings" << endl;
    cout << "\n\n\t\t\tPress 8 Ticket Information" << endl;
    cout << "\n\n\t\t\tPress 9 Helpline" << endl;
    cout << "\n\n\t\t\tPress 10 Logout" << endl;
    cout << "Chose an option..  ";
    cin >> option;
    system("cls");
    if (option == 4)
    {
        header();
        cout << "Pakistan Railways is the national, state-owned railway company of Pakistan in Lahore. Founded in 1861 as the North Western State Railway and headquartered in Lahore, it owns 7,490 kilometres of operational track across Pakistan, stretching from Torkham to Karachi, offering both freight and passenger services." << endl;

        cout << endl;
        clearScreen();
        User();
    }

    if (option == 10)
    {
        system("cls");
    }
    if (option == 3)
    {
        rate();
        User();
    }
    if (option == 1)
    {
        services();
        User();
    }
    if (option == 2)
    {
        dashboard();
        User();
    }
    if (option == 5)
    {
        eticket();
        User(); 
    }
    if (option == 7)
    {
        rating();
        User();
    }
    if (option == 8)
    {
        system("cls");
        addTicketInformation();
        clearScreen();
        User();
    }

    if (option == 6)
    {
        feedback();
        User();
    }
    if (option == 9)
    {
        helpline();
        User();
    }
}
void helpline()
{
    clearScreen();
    header();
    cout << "Call us at following numbers: " << endl;
    cout << "xxxx-xxx-xxxx" << endl;
    cout << "0000-000-0000\n";
    clearScreen();
}

void feedback()
{
    cin.ignore();
    string res;
    cout << "Enter Your Feedback about our Services: ";
    getline(cin, res);
    cout << "Thanks for your feedback!" << endl;
    Sleep(300);
    clearScreen();
}
void rating()
{
    header();
    cout << "\t\t\t\tGive Your Response" << endl;
    cout << "1. Good \n";
    cout << "2. Average\n";
    cout << "3. Worst\n";
    int op;
    cout << "Chose any option.. ";
    cin >> op;
    if (op > 3)
    {
        cout << "Invalid choice.Chose other option!";
    }
    else
        cout << "Thanks for your opinion! " << endl;
    Sleep(300);
    clearScreen();
}

void dashboard()
{
    int op;
    cout << "\n\n\t\t\tPress 1 Enter Train:" << endl;
    cout << "\n\n\t\t\tPress 2 Location" << endl;
    cout << "\n\n\t\t\tPress 3 Back" << endl;
    cin >> op;

    if (op == 1)
    {
        string name;
        cout << "\n\n\t\t\tName: ";
        cin >> name;
        if (name == "JAFFAR EXPRESS")
        {
            cout << "\n\n\t\t\tTrain Arrive At 10AM";
        }
        if (name == "YAAD-GAR-EXPRESS")
        {
            cout << "\n\n\t\t\tTrain is on time. ";
        }
        if (name == "PAK-TRAIN")
        {
            cout << "\n\n\t\t\tTrain is late due to Rain!";
        }
        if (name == "GREEN TRAIN")
        {
            cout << "\n\n\t\t\tTrain arrives at 2AM";
        }
        else
        {
            cout << "Invalid Name";
        }
    }
    if (op == 2)
    {
        string location;
        cout << "\n\n\t\t\tEnter Location: ";
        cin >> location;
        if (location == "Lahore")
        {
            cout << "\n\n\t\t\tJAFFAR EXPRESS is coming soon! \n";
            Sleep(800);
            system("cls");
            dashboard();
        }
        if (location == "Karachi")
        {
            cout << "\n\n\t\t\tYAAD-GAR-EXPRESS is on its Way!\n";
            Sleep(800);
            system("cls");
            dashboard();
        }
        if (location == "Peshawar")
        {
            cout << "\n\n\t\t\tGREEN TRAIN arrives soon! \n";
            Sleep(800);
            system("cls");
            dashboard();
        }
        if (location == "Multan")
        {
            cout << "\n\n\t\t\tTrain is OUT OF ORDER! \n";
            Sleep(800);
            system("cls");
            dashboard();
        }
    }
    cout << endl;
    clearScreen();
}

void services()
{
    cout << "\n\n\t\t\tOur Services:";
    cout << "\n\n\t\t\tJAFFAR EXPRESS";
    cout << "\n\n\t\t\tYAAD-GAR-EXPRESS";
    cout << "\n\n\t\t\tGREEN TRAIN";
    cout << "\n\n\t\t\tPAK-TRAIN \n\n\n\n";
    clearScreen();
}

void rate()
{

    cout << setw(70) << setfill('-') << "" << setfill(' ') << endl;

    cout << left << setw(30) << "City" << setw(30) << "Train"
         << "Ticket Rate" << endl;
    cout << setw(30) << "Lahore-to-Karachi" << setw(30) << "JAFFAR EXPRESS"
         << "Rs 4500" << endl;
    cout << setw(30) << "Lahore-to-Multan" << setw(30) << "PAK-TRAIN"
         << "Rs 4500" << endl;
    cout << setw(30) << "Karachi-to-Multan" << setw(30) << "YAAD-GAR-EXPRESS"
         << "Rs 4200" << endl;
    cout << setw(30) << "Karachi-to-Lahore" << setw(30) << "JAFFAR EXPRESS"
         << "Rs 4200" << endl;
    cout << setw(30) << "Multan-to-Lahore" << setw(30) << "GREEN TRAIN"
         << "Rs 4000" << endl;
    cout << setw(30) << "Peshawar-to-Karachi" << setw(30) << "JAFFAR EXPRESS"
         << "Rs 4500" << endl;
    cout << setw(30) << "Peshawar-to-Lahore" << setw(30) << "YAAD-GAR-EXPRESS"
         << "Rs 4500" << endl;
    cout << setw(30) << "Gujranwala-to-Lahore" << setw(30) << "PAK-TRAIN"
         << "Rs 4500" << endl;

    clearScreen();
}

int loginMenu()
{
    int option;
    cout << "\n\n\t\t\t1. Signin" << endl;
    cout << "\n\n\t\t\t2. Signup" << endl;
    cout << "\n\n\t\t\t3. Exit" << endl;
    cout << endl;
    cout << "\n\n\t\t\tEnter the Option ";
    cin >> option;
    if (option > 3)
    {
        cout << "Invaild Option \n";
    }

    return option;
}
string Signin(string name, string password, string users[], string passwords[], string roles[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (users[i] == name && passwords[i] == password)
        {
            return roles[i];
        }
    }
    return "undefined";
}

bool Signup(string name, string password, string role, string users[], string passwords[], string roles[], int &count, int userArrSize)
{
    bool isPresent = false;

    for (int i = 0; i < count; i++)
    {
        if (users[i] == name && passwords[i] == password)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;
    }
    else if (count < userArrSize)
    {
        users[count] = name;
        passwords[count] = password;
        roles[count] = role;
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

void Menu(string submenu)
{
    string message = submenu + " Menu";
    cout << "\t\t\t\t---------------------" << endl;
    cout << "\t\t\t\t\t" << message << endl;
    cout << "\t\t\t\t---------------------" << endl;
}

void subMenu(string submenu)
{
    string message = "Main Menu > " + submenu;
    cout << message << endl;
    cout << "---------------------" << endl;
}

void clearScreen()
{
    cout << "Press Any Key to Continue.. " << endl;
    getch();
    system("cls");
}
void Exit()
{
    system("cls");
    while (true)
    {
        break;
    }
    exit(0);
}

void displayMenu()
{
    header();
    cout << "1. Add a Train\n";
    cout << "2. View Added Trains\n";
}
void manageTrains(string names[], string destinations[], int departureTimes[], int &numTrains, const int MAX_TRAINS)
{

    addTrain(names, destinations, departureTimes, numTrains, MAX_TRAINS);
}
void removeTrain(string names[], string destinations[], int departureTimes[], int &numTrains)
{
    header();
    if (numTrains > 0)
    {
        viewTrains(names, destinations, departureTimes, numTrains); // Display the list of trains for reference

        string trainName;
        cout << "\nEnter the name of the train to remove: ";
        cin.ignore(); // Ignore newline character in the input buffer
        getline(cin, trainName);

        bool found = false;
        for (int i = 0; i < numTrains; ++i)
        {
            if (names[i] == trainName)
            {
                // Shift elements to remove the train
                for (int j = i; j < numTrains - 1; ++j)
                {
                    names[j] = names[j + 1];
                    destinations[j] = destinations[j + 1];
                    departureTimes[j] = departureTimes[j + 1];
                }

                // Decrement the number of trains
                --numTrains;

                cout << "Train '" << trainName << "' removed successfully!\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Train '" << trainName << "' not found. No changes made.\n";
        }
    }
    else
    {
        cout << "No trains to remove.\n";
    }

    clearScreen();
}
void addTicketInformation()
{
    const int MAX_PASSENGERS = 10;
    header();

    int numTickets;
    cout << "Enter number of tickets: ";
    cin >> numTickets;

    string names[MAX_PASSENGERS];
    int cnics[MAX_PASSENGERS];
    string locations[MAX_PASSENGERS];
    int nums[MAX_PASSENGERS];
    int totalAmounts[MAX_PASSENGERS];

    cout << "\t\t\t\t\t\tPASSENGERS DETAILS" << endl;

    for (int i = 0; i < numTickets; ++i)
    {
        cout << "Enter Name for Passenger " << i + 1 << ": ";
        cin >> names[i];

        cout << "Enter CNIC for Passenger " << i + 1 << ": ";
        cin >> cnics[i];

        cout << "Enter Location for Passenger " << i + 1 << ": ";
        cin >> locations[i];

        nums[i] = 1; // Assuming each passenger gets one ticket by default

        if (locations[i] == "Lahore")
        {
            totalAmounts[i] = nums[i] * 4500;
        }
        else if (locations[i] == "Karachi")
        {
            totalAmounts[i] = nums[i] * 4200;
        }
        else if (locations[i] == "Peshawar")
        {
            totalAmounts[i] = nums[i] * 4500;
        }
        else if (locations[i] == "Multan")
        {
            totalAmounts[i] = nums[i] * 4000;
        }
        else if (locations[i] == "Gujranwala")
        {
            totalAmounts[i] = nums[i] * 4500;
        }
    }

    displayInformation(names, cnics, locations, nums, totalAmounts, numTickets);
}
