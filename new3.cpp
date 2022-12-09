#include <iostream>
#include <string>
#include <climits>
#include<fstream>
using namespace std;

void choose(double currency)//function to print a message after user enters which currency he would like to convert from or to.
{
	if (currency == 1)
		cout << "You have choosen AED." << endl;
	else if (currency == 2)
		cout << "you have choosen INR." << endl;
	else if (currency == 3)
		cout << "you have choosen USD." << endl;
	else if (currency == 4)
		cout << "you have choosen GBP." << endl;
	else if (currency == 5)
		cout << "you have choosen EUR." << endl;
	else if (currency == 6)
		cout << "you have choosen AUD." << endl;
	else if (currency == 7)
		cout << "you have choosen JOD." << endl;
	else if (currency == 8)
		cout << "you have choosen TRY." << endl;
	else if (currency == 9)
		cout << "you have choosen PHP." << endl;
	else if (currency == 10)
		cout << "you have choosen KWD." << endl;
	else
		cout << "error!! value must be a number between 1-10" << endl; //error massage if user enter invalid input.
}


double convert_to_usd(int currency,double money, double a1,double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9, double a10)//convert the amount of money the user enters to USD.
{
	switch (currency)
	{
	case 1: return money * a1; break; //AED TO USD
	case 2: return money * a2; break; //INR TO USD
	case 3: return money * a3; break; //USD TO USD
	case 4: return money * a4; break; //GBP TO USD
	case 5: return money * a5; break; //EUR TO USD
	case 6: return money * a6; break; //AUD TO USD
	case 7: return money * a7; break; //JOD TO USD
	case 8: return money * a8; break; //TRY TO USD
	case 9: return money * a9; break; //PHP TO USD
	case 10: return money * a10; break; //KWD TO USD
	default: return 1; break;
	}
}


double convert_from_usd(int currency, double money, double a1,double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9,double a10)//convert the amount of money the user enters from USD to the currency he has chosen.
{
	switch (currency)
	{
	case 1: return money / a1; break; //USD TO AED
	case 2: return money / a2; break; //USD TO INR
	case 3: return money / a3; break; //USD TO USD
	case 4: return money / a4; break; //USD TO GBP
	case 5: return money / a5; break; //USD TO EUR
	case 6: return money / a6; break; //USD TO AUD
	case 7: return money / a7; break; //USD TO JOD
	case 8: return money / a8; break; //USD TO TRY
	case 9: return money / a9; break; //USD TO PHP
	case 10: return money / a10; break; //USD TO KWD
	default: return 1; break;
	}
}


int main()
{ 
  ifstream fil;
  ifstream mf1;
  ifstream mf2;
  ifstream mf3;
  ifstream mf4;
  ifstream mf5;
  ifstream mf6;
  ifstream mf7;
  ifstream mf8;
  ifstream mf9;
  ifstream mf10;
  mf1.open("r1.txt");
  mf2.open("r2.txt");
  mf3.open("r3.txt");
  mf4.open("r4.txt");
  mf5.open("r5.txt");
  mf6.open("r6.txt");
  mf7.open("r7.txt");
  mf8.open("r8.txt");
  mf9.open("r9.txt");
  mf10.open("r10.txt");// To open the files using ifstream functionality.
		//declaration.
		int convert_from, convert_to;
		double money;
    double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    mf1 >> a1;
     mf2 >> a2;
     mf3 >> a3;
     mf4 >> a4;
     mf5 >> a5;
     mf6 >> a6;
     mf7 >> a7;
     mf8 >> a8;
     mf9>> a9;
     mf10 >> a10;//reading values from files
    
		//program header.
		cout << "********************************************************************************************************" << endl;
		cout << "						Convert Currency											 " << endl;
		cout << "********************************************************************************************************" << endl;

		//currency list.
		cout << "1. AED: Emeriti Dirham\n2. INR: Indian Rupee.\n3. USD : US Dollar.\n4. GBP : Britsih Pound.\n5. EUR : Euro" << endl;
		cout << "6. AUD : Australian Dollar.\n7. JOD : Jordanian Dinar\n8. TRY : Turkish Lira\n9. PHP : Philippine Peso.\n10. KWD : Kuwaiti Dinar " << endl;
		
		do { //Do-while to repeat the code until the user enter a valid input.
			cout << "\nWhat currency would you like to convert from? ";
			cin >> convert_from;
			while (cin.fail())//to stop the user from entering a character or a string.
			{
				cin.clear();//clears the value entered so that its not consistant.
				cin.ignore(INT_MAX, '\n');//how many characters do you want to ignore.
				cout << "error!! value must be a number between 1-10" << endl;
				cin >> convert_from;
			}
			choose(convert_from);//function call.
		} while (convert_from < 1 || convert_from > 10);

		do { //Do-while to repeat the code until the user enter a valid input.
			cout << "\nWhat currency would you like to convert to? ";
			cin >> convert_to;
			while (cin.fail())//to stop the user from entering a character or a string
			{
				cin.clear();//clears the value entered so that its not consistant.
				cin.ignore(INT_MAX, '\n');//how many characters do you want to ignore.
				cout << "\nerror!! value must be a number between 1-10 !" << endl;
				cin >> convert_to;
			}
			choose(convert_to);//function call.
		} while (convert_to < 1 || convert_to > 10);

		cout << "\nHow much money do you want to convert? ";
		cin >> money;
		while (cin.fail())//to stop the user from entering a character or a string
		{
			cin.clear();//clears the value entered so that its not consistant.
			cin.ignore(INT_MAX, '\n');//how many characters do you want to ignore.
			cout << "\nerror!! value must be a number !" << endl;
			cin >> money;
		}

		double usd = convert_to_usd(convert_from, money, a1,a2, a3, a4, a5, a6, a7, a8, a9, a10); //Converted to USD then save it in (usd).

		cout << "\nAmount of money after convert = " << convert_from_usd(convert_to, usd, a1,a2, a3, a4, a5, a6, a7, a8, a9, a10);//Converted from USD to the curreny user has chosen.

  cout << endl;
	return 0;
}
