#pragma once

#include "Word.h"
#include <iostream>

class ListOfWords {
private:
	int initSize;
	int currSize;
	int numEntries;
	Word* wordHash;
	Word* head;
	void Expand();
	int Hash(string);
	void AddToList(Word&);
	int AddToHash(Word&, int);
	
public:
	
	void InsertWord(Word&);
	Word* FindWord(string);
	void PrintAll(bool);
	ListOfWords(int);
	~ListOfWords();

	friend istream& operator >> (istream& in, ListOfWords& list) {
		//Get next string from file
		string input;
		in >> input;

		if (input != "") {

			//Create a Word object with that input
			Word newWord;
			newWord.SetName(input);

			//Insert it into list
			list.InsertWord(newWord);
		}

		return in;
	}

	friend ostream& operator << (ostream& out, ListOfWords& list) {
		Word* currWord = list.head;
		while (currWord != nullptr) {
			out << currWord->GetName() << ": " << currWord->GetCount() << endl;
			currWord = currWord->GetNext();
		}

		return out;
	}
};
