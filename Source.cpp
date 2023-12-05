#include <iostream>
#include "Word.h"
#include "ListOfWords.h"
#include <fstream>

using namespace std;

int main() {
	
	//Initialize List
	ListOfWords list(100);
	
	//////////////////////////////////////////////////
	//Open file and copy to list ////////////////////
	////////////////////////////////////////////////
	ifstream fromFile;
	fromFile.open("GroceryTestFile.txt");

	//Check if it opened
	if (!fromFile.is_open()) {
		cout << "Failed to open file." << endl;
		cin.clear();
		cout << "PRESS ENTER" << endl;
		cin.get();
		return 1;
	}
	//If open, process words till end of file.
	else {
		cout << "File opened..." << endl;
		int count = 0;

		while (!fromFile.fail()) {
			fromFile >> list;
			++count;
		}
		
		cout << "Processed " << count << " items..." << endl;
	}
	//Quit if not all data uploaded.
	if (!fromFile.eof()) {
		cout << "Failure occured during upload." << endl;
		cin.clear();
		cout << "PRESS ENTER" << endl;
		cin.get();
		return 1;
	}
	
	fromFile.close(); //Close file

	////////////////////////////////////////////////////
	////////////WRITE TO BACK UP FILE//////////////////
	//////////////////////////////////////////////////
	
	//Open back up
	ofstream toBackUp;
	toBackUp.open("frequency.dat");

	//Quit program if it did not open
	if (!toBackUp.is_open()) {
		cout << "Back up file failed to open." << endl;
		cin.clear();
		cout << "PRESS ENTER" << endl;
		cin.get();
		return 1;
	}
	//Once open, copy list to backup file
	else {
		toBackUp << list; 
		cout << "Back up created..." << endl;
		cin.clear();
		cout << "PRESS ENTER" << endl;
		cin.get();
	}
	toBackUp.close(); //close file

	//////////////////////////////////////////////
	////////////////// MENU /////////////////////
	////////////////////////////////////////////

	string input = "0"; //Sentinal
	
	//input validation done through string recognition. Anything other than 1, 2, 3, or 4 is ignored
	while (input != "4") {

		system("CLS"); //clear screen

		//PRINT MENU
		cout << "===================" << endl;
		cout << "GROCERY LIST READER" << endl;
		cout << "===================" << endl << endl;
		cout << "1) SEARCH FOR ITEM" << endl;
		cout << "2) PRINT ALL (NUM)" << endl;
		cout << "3) PRINT ALL (HIST)" << endl;
		cout << "4) EXIT" << endl;

		cin >> input;

		//Option 1: Search

		if (input == "1") {
			system("CLS");
			
			//Get input
			cout << "ENTER ITEM: ";
			string item;
			cin >> item;
			cout << endl;
			
			//Find word. Returns nullptr if not found
			Word* word = list.FindWord(item);

			//Display result
			if (word != nullptr) {
				word->PrintNum();
				cout << endl << "PRESS ENTER" << endl;
				cin.get();
				cin.get();
			}
			else {
				cout << "Item not found." << endl << endl;
				cout << "PRESS ENTER" << endl;
				cin.get();
				cin.get();
			}
		}

		//Option 2: Print num

		else if (input == "2") {
			system("CLS");
			cout << endl;
			cout << "ALL ITEMS:" << endl;
			list.PrintAll(false);
			cout << endl << "PRESS ENTER" << endl;
			cin.get();
			cin.get();
		}

		//Option 3: Print hist
		else if (input == "3") {
			system("CLS");
			cout << endl;
			cout << "ALL ITEMS:" << endl;
			list.PrintAll(true);
			cout << endl << "PRESS ENTER" << endl;
			cin.get();
			cin.get();
		}
		else if (input == "4") {
			cout << endl << "GOODBYE...";
		}

	}
	

	return 0;
}
