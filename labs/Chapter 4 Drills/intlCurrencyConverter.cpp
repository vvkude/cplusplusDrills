/* Stroustrup's C++ Programming Chapter 4 Drill 1
Write a program that prompts a person for an amount of money in yen, kroner 
or pounds, convert it in to the dollar amount for them and display it
*/

#include "../../headers/headerTemplate.h"

int main()
{
	/* We will declare constexrp doubles to ensure conversion amounts are not 
	   inadvertently updated. In the future, these should be consts that are 
	   updated through some API with up-to-date values according to market data */
	constexpr double yen_per_dollar = 109.66;
	constexpr double kroner_per_dollar = .11;
	constexpr double pounds_per_dollar = 0.78;

	double monies = 1.0;
	string unit = " "; // a space is not a unit
	cout << "Please enter the amount of money you have followed by a currency symbol:\n"
	     << "Available currencies are 'yen(y)', 'kroner(k)', and 'pounds(p)'\n";
	cin >> monies >> unit;

	// Now use if clauses to select the currect operation depending on the person's input
	double dollars = 0;
    cout << "\nAt the current market rate, 1 " << unit << " is worth $";

    // Recognize that we cannot use `switch' statements on strings
    // So, we will use nested if statements to make a selection based on user input
	if (unit == "y" || unit == "yen") {
		dollars = monies*yen_per_dollar;
		cout << yen_per_dollar <<'\n';
	}
	else if (unit == "k" || unit == "kroner") {
		dollars = monies*kroner_per_dollar;
		cout << kroner_per_dollar <<'\n'; 
	}
	else if (unit == "p" || unit == "pounds") {
		dollars = monies*pounds_per_dollar;
		cout << pounds_per_dollar <<'\n';
	}
	else { // Crude error handling
		cout << "\nSorry, I do not know about that type of currency.\n"
	         << "Will you try y, k or p?:\n";
	    cin >> monies >> unit;
	}

	// Read back what the person entered and display their converted value
    cout << "\nYou entered that you have " << monies << " " << unit
         <<  ", which is $" << dollars 
         << '\n';

}