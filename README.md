# CS304ProfessionalNetworkingWriting

#Restaurant Billing System - README

#Introduction

The Restaurant Billing System is a C++ program designed to handle the billing process at “Mos BEVERAGES.” The purpose of this program is to help restaurant staff efficiently calculate bills, apply discounts, and generate receipts for customers. This README document provides an overview of the program, its functions, and how to use it.

#Methodology

-Inputs

	1.	Daily Specials: The program allows users to check if there are any daily specials.
	2.	Menu Selection: Users can select items from the restaurants menu.
	3.	Tip Selection: Users can choose a tip percentage from predefined options (15%, 18%, 20%) or enter a custom tip percentage.
	4.	Servers Name: The program asks for the servers first and last name.
	5.	Number of Beverages: Users need to enter the number of beverages ordered.

-Outputs

	1.	A detailed receipt that includes the server’s name, table number, ordered items, their quantities, individual prices, subtotal, tip amount, tax amount, and final total.
	2.	Optional 5% discount if the total amount is greater than $10 and the tip percentage is 18% or more.
	3.	Option to recalculate the bill.
	4.	Farewell message to the customer.

#Data Flow

The program reads the menu items and their prices from an external file (menu.txt) and stores them in arrays. It uses these arrays to display the menu to the user and to calculate the bill. The program interacts with the user through a series of prompts, input validation, and menu options.

#Methods

	1.	specialMenu(): Allows the user to check if there are any daily specials and select a day.
	2.	tipMenu(): Allows the user to choose a tip percentage from predefined options or enter a custom tip percentage.
	3.	calcBill(): Calculates the final amount by adding the subtotal and tip amount.
	4.	calcAmount(): Calculates tax amount, updates the total amount with taxes, and calculates the tip amount.
	5.	finalDiscount(): Applies a 5% discount to the total amount if specific conditions are met.
	6.	printBill(): Prints the final amount to a file named “bill.txt.”
	7.	printMenu(): Reads the menu items and prices from “menu.txt” and displays them to the user.

#Variables

The program uses various variables for storing user inputs, menu items, their prices, counts of items ordered, and calculated amounts.

#Results

The Restaurant Billing System provides an efficient way to calculate bills, apply tips, and generate detailed receipts. Some key results and features of the program are:

	•	Users can easily check for daily specials.
	•	The program validates user inputs to prevent errors.
	•	It calculates tip percentages, tax amounts, and offers a 5% discount for eligible bills.
	•	The final bill is presented with all details, ensuring transparency.

#Conclusions

From implementing the Restaurant Billing System, we have learned the following:

	•	The program successfully manages the billing process and improves the customer experience.
	•	Pre-defined tip percentages and the ability to enter custom tips to make it flexible.
	•	The 5% discount for specific bill amounts and tip percentages is an attractive feature.
	•	Further improvements could include more extensive menu options, multiple payment methods, and the ability to split bills for larger parties.

This program provides a solid foundation for a restaurant billing system, which can be expanded and customized to meet specific requirements.

#Recommendations

To improve the program:

	1.	Expand the menu with more items and categories.
	2.	Add support for splitting bills for groups.
	3.	Include options for different payment methods (cash, card, etc.).
	4.	Enhance error handling and validation to make the program more strong.
	5.	Implement a feature to save and recall previous orders or receipts.
