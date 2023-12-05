#include <iostream>
#include "Word.h"

using namespace std;

Word::Word() {
	name = "";
	count = 1;
	nextWord = nullptr;
}

Word::Word(const Word& otherWord) {
	name = otherWord.name;
	count = otherWord.count;
	nextWord = otherWord.nextWord;
}

Word::~Word() {
	//cout << "Word Deleted" << endl;
}
void Word::InsertAfter(Word& otherWord) {
	otherWord.SetNext(nextWord);
	nextWord = &otherWord;

}

void Word::PrintNum() {
	cout << name << ": " << count << endl;
}

void Word::PrintHist() {
	cout << name;
	for (int i = 0; i < count; ++i) {
		cout << "*";
	}
	cout << endl;
}

//////////////////////////////////////////////////////////////////
//Getters and Setters/////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
int Word::GetCount() { return count; }
string Word::GetName() { return name; }
Word* Word::GetNext() { return nextWord; }
void Word::SetCount(int newCount) { count = newCount; }
void Word::SetName(string newName) { name = newName; }
void Word::SetNext(Word* newNext) { nextWord = newNext; }

//////////////////////////////////////////////////////////////////
//Operators///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
bool Word::operator > (Word& otherWord) {
	string otherName = otherWord.GetName();


	//First determine length of shorter word
	int length;

	if (name.size() <= otherName.size()) {
		length = name.size();
	}
	else {
		length = otherName.size();
	}

	//Use shorter word length to avoid out of range error
	for (int i = 0; i < length; ++i) {
		if (tolower(name.at(i)) > tolower(otherName.at(i))) {
			return true;
		}
		else if (tolower(name.at(i)) < tolower(otherName.at(i))) {
			return false;
		}
	}

	//If both words match up until the end of the shorter word and they're not the same word,
	//then the longer word is greater than the shorter.
	if (name.size() < otherName.size()) {
		return false;
	}
	else {
		return true;
	}
}

bool Word::operator < (Word& otherWord) {
	return !(*this > otherWord);
}

bool Word::operator == (Word& otherWord) {
	string otherName = otherWord.GetName();

	//First check if they're the same size. If not, can't be same word.
	if (name.size() != otherName.size()) {
		return false;
	}

	for (int i = 0; i < name.size(); ++i) {
		if (tolower(name.at(i)) != tolower(otherName.at(i))) {
			return false;
		}
	}

	return true;
}

void Word::operator++ () {
	++count;
}

void Word::operator= (const Word& otherWord) {
	name = otherWord.name;
	count = otherWord.count;
	nextWord = otherWord.nextWord;
}