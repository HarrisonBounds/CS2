//Harrison Bounds
//Lab4Out
//Postage Addressing System for mailed letters in the US

#include<iostream>
#include<string>
#include<cctype>
#include"graph1.h"
#include<iomanip>


using namespace std;

string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
bool validateWeight(string weight);
string convertToUpper(string state);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, string weight);

const double stamp_cost = 0.47;

int main()
{
	string fn;
	string ln;
	string street_Address;
	string city;
	string state;
	string zip;
	string phone_num;
	string weight;
	bool val;

	displayGraphics();

	do
	{
		fn = getString("Enter First Name: ");

		val = validateName(fn);

		if (!val)
			cout << "Invalid Name --- Please Try Again" << endl;

	} while (!val);

	do
	{
		ln = getString("Enter Last Name: ");

		val = validateName(ln);

		if (!val)
			cout << "Invalid Name --- Please Try Again" << endl;

	} while (!val);

	do
	{
		street_Address = getString("Enter Street Address: ");

		val = validateAddress(street_Address);

		if (!val)
			cout << "Invalid Address --- Please Try Again" << endl;

	} while (!val);

	do
	{
		city = getString("Enter City: ");

		val = validateCity(city);

		if (!val)
			cout << "Invalid City --- First Letter Must Be Capitilized" << endl;

	} while (!val);

	do
	{
		state = getString("Enter State: ");

		val = validateState(state);

		if (!val)
			cout << "Invalid State --- May Only Contain 2 Letters" << endl;

	} while (!val);

	do
	{
		zip = getString("Enter Zip Code: ");

		val = validateZip(zip);

		if (!val)
			cout << "Invalid Zip Code --- Must be 5 Digits" << endl;

	} while (!val);

	do
	{
		weight = getString("Enter weight in ounces: ");

		val = validateWeight(weight);

		if (!val)
			cout << "Invalid Weight --- Must be an integer" << endl;

	} while (!val);

	state = convertToUpper(state);

	displayLetter(fn, ln, street_Address, city, state, zip, weight);
}

string getString(string prompt)
{
	string info = "";

	cout << prompt;
	getline(cin, info);

	return info;
}

bool validateName(string name)
{
	bool val = true;

	for (int i = 0; name[i] != NULL; i++)
	{
		if ((isalpha(name[i]) == 0))
		{
			val = false;
		}
	}

	return val;
}

bool validateAddress(string address)
{
	bool val = true;

	for (int i = 0; address[i] != NULL; i++)
	{
		if ((isalpha(address[i]) == 0))
		{
			if ((isspace(address[i]) == 0))
			{
				if ((isdigit(address[i]) == 0))
				{
					val = false;
				}
			}
		}
	}

	return val;
}

bool validateCity(string city)
{
	bool val = true;

	for (int i = 0; city[i] != NULL; i++)
	{
		if ((isalpha(city[i]) == 0) || (isupper(city[0]) == 0))
		{
			val = false;
		}
	}

	return val;
}

bool validateState(string state)
{
	bool val = true;

	for (int i = 0; state[i] != NULL; i++)
	{
		if (isalpha(state[i]) == 0)
		{
			val = false;
		}
		if (state.length() > 2)
		{
			val = false;
		}
	}

	return val;
}

bool validateZip(string zip)
{
	bool val = true;

	for (int i = 0; zip[i] != NULL; i++)
	{
		if (zip.length() != 5)
		{
			val = false;
		}
		if ((isdigit(zip[i]) == 0)) 
		{
			val = false;
		}
		
	}

	return val;
}

bool validateWeight(string weight)
{
	bool val = true;

	for (int i = 0; weight[i] != NULL; i++)
	{
		if ((isdigit(weight[i]) == 0))
		{
			val = false;
		}
		if (stoi(weight) < 1 || stoi(weight) > 6)
		{
			val = false;
		}
	}

	return val;
}

string convertToUpper(string state)
{
	for (int i = 0; state[i] != NULL; i++)
	{
		state[i] = toupper(state[i]);
	}

	return state;
}

void displayLetter(string fn, string ln, string addr, string city, string state, string zip, string weight)
{
	int x = 525;
	int y = 20;
	int x2 = 525;
	int y2 = 99;

	displayBMP("envelope.bmp", 0, 0);

	displayBMP("returnAddress.bmp", 43, 26);

	for (int i = 0; i < 3; i++)
	{
		displayBMP("stamp.bmp", x, y);
		x -= 75;
	}

	for (int i = 3; i < 6; i++)
	{
		displayBMP("stamp.bmp", x2, y2);
		x2 -= 75;
	}

	gout << setPos(315, 210) << fn << " " << ln << endg;

	gout << setPos(315, 220) << addr << endg;

	gout << setPos(315, 230) << city << ", " << state << " " << zip << endg;

	drawLine(200, 385, 490, 385, 1);
	drawLine(200, 385, 200, 470, 1);
	drawLine(200, 470, 490, 470, 1);
	drawLine(490, 385, 490, 470, 1);

	gout << setPos(215, 400) << "Weight: " << weight << " ounces" << endg;

	gout << setPos(215, 430) << "Cost of First Class Stamp: " << setPrecision(0) << (100 * stamp_cost) << " Cents" << endg;

	gout << setPos(215, 460) << "Total Mailing Cost $" << setPrecision(2) << stoi(weight) * stamp_cost << endg;

	
}