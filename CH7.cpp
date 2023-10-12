//Mauricio Zurita
//3-17-23
//CIS 251 9:10AM - 10:25AM
//Chapter 7 Programming Assignment
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;
//Global variables
const double taxRate = 0.10; // The tax rate is 10%
const string REST_NAME = "Mo's BEVERAGES"; // The restaurant name
const int ITEMS = 8; // Used for the menu items and prices
const int SIZE = 4; // Used for the tip percentage

void specialMenu(int& dailySpecial, char& dailyOption, char& menuOption)   {
    do   {
        string dailyLines[] = { "+~~~~~~~~~~~~~~~~~+\n", "|  DAILY SPECIALS |\n", "| 1.) Sunday      |\n", "| 2.) Monday      |\n", "| 3.) Tuesday     |\n"   // The strings for the daily
                              , "| 4.) Wednesday   |\n", "| 5.) Thursday    |\n", "| 6.) Friday      |\n", "| 7.) Saturday    |\n", "+~~~~~~~~~~~~~~~~~+\n"}; // special menu
        // Below is menu of the days and each day has a special discount
        cout << "\nPlease Choose what day it is\n";
        cout << "To know the special discount!!!\n";
        for (string printDaily : dailyLines)   { // Prints out the daily special
            cout << printDaily;                  // option menu with a loop
        }
        cout << "Enter options 1-7: ";
        cin >> dailySpecial;
        cout << endl;
        while (cin.fail() || dailySpecial <= 0 || dailySpecial >= 8)   {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!!! Please try again and enter a valid input: ";
            cin >> dailySpecial;
        }
        if ((dailySpecial == 1 || dailySpecial == 4))   { // If its these days then tells you there is no special
            cout << "No special today.\n";
        }
        else if (dailySpecial == 2 || dailySpecial == 3 || dailySpecial == 5 || dailySpecial == 6 || dailySpecial == 7)   { // Tells you there is a special
            cout << "There is special today.\n";
        }
        cout << "Would you like to choose daily special again?\n";
        cout << "Choose Y for Yes or N for No: ";
        cin >> dailyOption;
    }while(dailyOption == 'Y' || dailyOption == 'y');
    
    if ((dailyOption == 'N' || dailyOption == 'n') && (dailySpecial >= 1 || dailySpecial <= 7))   { // If these days and if its N to not repeat it will make
        menuOption = 'N';                                                                           // menuOption = N which will make the program start over
        cout << endl;
        
    }
    
}
void tipMenu(double(&tipPercentage)[SIZE], double& tipPercent, int& e)   {
    char tipOptions; // Used for input in thr tip options which is A - D or a - d
    cout << "\nChoose from the following options below.\n";
    string menuTip[] = {"+~~~~~~~~~~~~~+", "| TIP OPTIONS |", "| A.) 15%     |", "| B.) 18%     |", // The string for each line of the tip option
                        "| C.) 20%     |", "| D.) Other   |", "+~~~~~~~~~~~~~+" };
    for (string val : menuTip)   { // Every line of string well print out in the order it is
        cout << val << endl;
    }
    cout << "Enter options A - D or a - d: ";
    cin >> tipOptions;
    // Error checking for the menu
    while ((tipOptions >= 'E' && tipOptions <= 'Z') || (tipOptions >= 'e' && tipOptions <= 'z') || cin.fail() || cin.get() != '\n')   {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!!! Please enter A - D or a - d: ";
        cin >> tipOptions;
    }
    cout << endl;
    switch (tipOptions) {
        case 'A':
        case 'a':
            e = 0;
            tipPercentage[e] = 15;
            tipPercent = tipPercentage[e]; // Variable that will keep tipPercentage as a whole number to be used later
            tipPercentage[e] *= 0.01;   // tipPercentage multiply by 0.01 so it can be used as a percentage
            break;
        case 'B':
        case 'b':
            e = 1;
            tipPercentage[e] = 18;
            tipPercent = tipPercentage[e]; // Variable that will keep tipPercentage as a whole number to be used later
            tipPercentage[e] *= 0.01;  // tipPercentage multiply by 0.01 so it can be used as a percentage
            break;
        case 'C':
        case 'c':
            e = 2;
            tipPercentage[e] = 20;
            tipPercent = tipPercentage[e]; // Variable that will keep tipPercentage as a whole number to be used later
            tipPercentage[e] *= 0.01;  // tipPercentage multiply by 0.01 so it can be used as a percentage
            break;
        case 'D':
        case 'd':
            e = 3;
            cout << "Enter tip percentage(As whole number): ";
            cin >> tipPercentage[e]; // How much tip to give based on amounnt
            while (cin.fail() ) { // Error checking for the tip percentage
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input!!! Please enter a tip percentage as a whole number: ";
                cin >> tipPercentage[e];
            }
            
            tipPercent = tipPercentage[e]; // Variable that will keep tipPercentage as a whole number to be used later
            tipPercentage[e] *= 0.01; // tipPercentage multiply by 0.01 so it can be used as a percentage
            break;
            
    }
}
double calcBill(double num1, double num2)   {
    double finalAmount;
    
    finalAmount = num1 + num2; // The total amount plus the tip amount equals the final amount
    return finalAmount;        // And returns the final amount
}
void calcAmount(double& taxAmount, double& totalAmount, double& tipAmount, double (&tipPercentage)[SIZE], int &e)   {
    taxAmount = totalAmount * taxRate; // How much to pay in taxes
    totalAmount += taxAmount; // The amount of taxes added to total amount to make it equal to totalAmount variable
    tipAmount = totalAmount * tipPercentage[e]; // Bill amount times tip percentage equals tip amount
    
}
bool finalDiscount(double& tipPercent, double& totalAmount, double& discountSpecial)   {
    bool isDiscount;
    
    isDiscount = (totalAmount >= 10.00) && (tipPercent >= 18);
    if(isDiscount)   {
        
        discountSpecial = 0.05; // Special is 5% off
        discountSpecial *= totalAmount;
        totalAmount -= discountSpecial;
        
        cout << "\nYou get a 5% discount!!\n";
        cout << "Your subtotal now: $" << setprecision(2) << fixed << totalAmount;
        isDiscount = true;
    }
    else   {
        isDiscount = false;
    }
    return isDiscount;
}

void printBill(double&);
void printMenu(string(&menuItems)[ITEMS], double(&menuPrice)[ITEMS]);

int main ()
{
    string serverFullName, // Servers name
    menuItem[ITEMS]; // The string use for the item names
    int restOptions, // Use for when choosing your main menu options
    numBeverage = 0,
    // Variables i, u, a, x, z, e are used for loops, while loops, and if\else statements
    i,
    u = 0,
    a,
    x,
    z = 0,
    e = 0,
    count[ITEMS] = {0, 0, 0, 0, 0, 0, 0, 0}, // Used for to count how many beverages are order for each specific bev
    tableNumber, // Your random table number
    dailySpecial;// Variables for the restaurant, tip, and daily speciel options
    char menuOption = '\0', // Used to if you want to go again or not
    payBill = '\0', // Used to recalculate bill
    dailyOption, // Used to go again or not with the daily specials
    temp; // Used for the [Enter] to continue
    // Variables use to hold the total, sub, tax, tip, discount amounts
    double subAmount = 0.0,// Variable used to hold the first subtotal amount
    totalAmount = 0.0,// The variable for the total or final amount
    taxAmount, // The varibale for the total of taxes
    tipAmount,// The variable of the amount of tip you will give based off the tip percentage
    finalTotalAmount, // The final amount
    taxPercent, // Tax percent as a whole number
    discountSpecial, // How much will be discounted
    tipPercent, // The tip percent used to hold the number as a whole number
    tipPercentage[SIZE], // Used as a decimal to find out how much tip to give
    menuPrice[ITEMS], // The prices of the items on the menu
    costList[ITEMS] = {0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00}, // The exact Price amount for each amount ordered from each specific item
    price = 0.0; // Used in a while loop so it could print out the number of items, then the item name, and then the exact price for the amount of items
    
    do   {
  
    cout << "Hello, Welcome to " << REST_NAME << endl; // A welcome greetings with restaurant name variable
  
        cout << "\nTake your to time choose from our options.\n";
        printMenu(menuItem, menuPrice); // Function prints out the main menu
        
        cout << "\nChoose from the following options below\n";
        cout << "+~~~~~~~~~~~~~~~~~~~~+\n";
        cout << "| 1.) Daily Specials |\n";
        cout << "| 2.) Pay Now        |\n";
        cout << "| 3.) Exit Now       |\n";
        cout << "+~~~~~~~~~~~~~~~~~~~~+\n";
        
        cout << "Enter Options 1 - 3: ";
        cin >> restOptions;
        while (cin.fail() || restOptions <= 0 || restOptions >= 4) { // Error checking so if its words or letters it will aska again
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!!! Please try again and enter a valid option: ";
            cin >> restOptions;
        }
        if (restOptions == 3) { // Is there if chosen 3 makes program end
            menuOption = 'Y';
        }
    
            switch (restOptions) {
                case 1:
                    specialMenu(dailySpecial, dailyOption, menuOption); // Prints the daily special menu
                    break;
                case 2:
                  
                    do   {
                        if (payBill == 'y' || payBill == 'Y' || payBill == 'n' || payBill == 'N')   { // Resets every variable back to zero when ever you
                            totalAmount = 0.0;                                                        // choose 'Y' or 'y' so it can be used again
                            subAmount = 0.0;
                            z = 0;
                            a = 0;
                            price = 0.0;
                            x = 0;
                            u = 0;
                            while(u < ITEMS)   {
                                count[u] = 0;
                                costList[u] = 0.00;
                                u +=1;
                            }
                            
                        }

                        if ((restOptions == 2) ||(payBill == 'y'|| payBill == 'Y'))   { // Only used if user has choose option 2 to pay now
                            cout << "\nPlease Enter the amount of Beverages: ";
                            cin >> numBeverage;
                            while (cin.fail() ) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input!!! Please enter the amount of beverages: ";
                                cin >> numBeverage;
                            }
                            
                            cout << "\nLook over the menu and choose item number." << endl;
                            printMenu(menuItem, menuPrice);
                            for (i = 1; i <= numBeverage; i++)   {
                                cout << "Enter an item number from the Menu: ";
                                cin >> a;
                                while (cin.fail() || a >= 9 || a <= 0) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input!!! Please an item number: ";
                                    cin >> a;
                                }
                                a -= 1;                          // When you choose 1 - 8 it well take one away
                                if (a >=0 && a <= 7)   {         // for the array and when its 0 - 7 it will find the
                                    count[a] += 1;               // array and add to the count of how many beverages
                                    costList[a] += menuPrice[a]; // and add to the price
                                    
                                }
                                totalAmount = menuPrice[a];
                                subAmount += totalAmount;
                                z += 1;
                            }
                            totalAmount = subAmount;
                        }
                        
                        tipMenu(tipPercentage, tipPercent, e); // Function prints the tip menu
                        
                        taxPercent = 100 * taxRate; // Making the tax percent a whole number
                        
                        cout << "Enter servers First and Last name(Perferably yours): "; // Print out of your servers name
                        // Please enter your name below
                        getline(cin, serverFullName);
                        
                        random_device tabNum;                        // This part here picks
                        uniform_int_distribution<int>tableNum(1,20); // random number from 1- 20
                        tableNumber = tableNum(tabNum);              // for your table number
                        
                        cout << "\nRecipt\n";
                        cout << "+-------------------------+\n";
                        cout << "Servers Name: " << serverFullName << endl;
                        cout << "Table Number: " << tableNumber << endl << endl;
                        cout << setw(16) << left << "ITEMS:" << setw(10) << right << "PRICE:\n";
                        x = 0;
                        while (price < subAmount)   {
                            if ((x == 0 && count[0] >= 1 && menuPrice[0] == 2.00) || (x == 1 && count[1] >= 1 && menuPrice[1] == 3.00) ||
                                (x == 2 && count[2] >= 1 && menuPrice[2] == 3.00) || (x == 3 && count[3] >= 1 && menuPrice[3] == 2.50) ||
                                (x == 4 && count[4] >= 1 && menuPrice[4] == 2.50) || (x == 5 && count[5] >= 1 && menuPrice[5] == 8.00) ||
                                (x == 6 && count[6] >= 1 && menuPrice[6] == 4.00) || (x == 7 && count[7] >= 1 && menuPrice[7] == 4.00))    {
                                cout << count[x] << " " << setw(14) << left << menuItem[x] << setw(4) << right << "$" << costList[x] << endl;
                                price += costList[x];
                                ++x;
                            }
                            else   {
                                ++x;
                            }
                        }
                                                    
                        cout << "\nSubtotal amount:   $" << setprecision(2) << fixed << subAmount << endl; // The total amount
                        cout << "Tip Percentage:" << setw(7) << static_cast<int>(tipPercent) << "%\n"; // The tip percent
                        cout << "Tax Percentage:" << setw(7) << static_cast<int>(taxPercent) << "%\n"; //  Tax percentage for the State of Alabama
                        
                                    
                        finalDiscount(tipPercent, totalAmount, discountSpecial); // Function calculates if the total amount is higher than 10 &
                                                                                 // and tip amount is higher than 18
                        cout << endl << endl; // line is used to space it out
                        
                        calcAmount(taxAmount, totalAmount, tipAmount, tipPercentage, e);
                        
                        cout << "Tip Amount:" << setw(9) << "$" << setprecision(2) << fixed << tipAmount << "\n"; // Output of the total amount of tip
                        cout << "Sales Tax:" << setw(10) << "$" << setprecision(2) << fixed << taxAmount << "\n"; // Output of the total amount of taxes
                        
                        cout << "+-------------------------+\n";
                                                
                        cout << "\nYour final amount with tax & tip is: $" << setprecision(2) << fixed <<  (finalTotalAmount = calcBill(totalAmount, tipAmount)) << endl; // What the final amount is with function
                        
                        printBill(finalTotalAmount); // Function to print bill on bill.txt
                        
                        cout << "\nWould you like to recalculate bill?\n" << // Asks if you want to
                        "Choose y for Yes or n for No: ";                    // recalculate bill
                        cin >> payBill;
                        cout << endl;
                    } while(payBill == 'y' || payBill == 'Y');
                    if (payBill == 'n' || payBill == 'N')   {
                        menuOption = 'N';
                        break;
                    }

                    // Saying our goodbyes and hoping you comeback
                    cout << "Thank you for dining with us at " << REST_NAME << endl;
                    cout << "Hope you was treated well by " << serverFullName << endl;
                    cout << "And come back to see us soon!!!!\n";
                    cout << "\nPress [Enter] to continue....." << endl;
                    cin.get(temp);
                    cin.get();
                    break;
                case 3:
                    cout << "\nHave a good day!!!\n";
                    cout << "Thanks for stopping by!!!\n";
                    cout << "\nPress [Enter] to continue....." << endl;
                    cin.get(temp);
                    cin.get();
                    break;
                default:
                    cout << "Invalid response!!!\n";
                    break;
            }
    }while(menuOption == 'N' || menuOption == 'n');
        return 0;
    }

void printBill(double& finalTotalAmount)   {
    // The final amount is being printed to the bill.txt file
    ofstream inputFile;
    inputFile.open("bill.txt");
    inputFile << "$" << setprecision(2) << fixed << finalTotalAmount;
    inputFile.close();
}
void printMenu(string (&menuItems)[ITEMS], double(&menuPrice)[ITEMS]) {
    ifstream outputFile; // Used for output in file
    
    outputFile.open("menu.txt");
    if (outputFile) {
        // The menu is only taking the menu item first and then the
        // menu price and putting them in a seperate line with the
        // number it is and dollar sign
        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
        cout << "|       MO's BEVERAGES     |\n";
        for (int i = 0; i < ITEMS; i++)   {
            getline(outputFile, menuItems[i]);
            outputFile >> menuPrice[i];
            outputFile.ignore();
            cout << "|"  << (i + 1) << ".) " << setw(14) << left << menuItems[i] << setprecision(2) << fixed << setw(4) << right << "$" << menuPrice[i] << "|" << endl;
        }
        cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n";
    }
    else    {
        cout << "Error reading file!!!\n";
    }
    
}

