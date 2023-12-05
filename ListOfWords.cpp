#include "ListOfWords.h"
#include <iostream>

using namespace std;

ListOfWords::ListOfWords(int size) {
	initSize = size;
	currSize = initSize;
	numEntries = 0;
	head = nullptr;
	wordHash = new Word[currSize];
}

ListOfWords::~ListOfWords() {
	//Delete hash table
	delete [] wordHash;
}

int ListOfWords::Hash(string word) {
	
	//Count value of chars in the word
	int hash = 0;

	for (int i = 0; i < word.size(); ++i) {
		hash += tolower(word.at(i));
	}

	//Mod by currSize
	hash %= currSize;
	
	return hash;
}

//AddToHash returns -1 if duplicate. Otherwise returns insertion point.
int ListOfWords::AddToHash(Word& wordToAdd, int hashCode) {
	int count = 1;
	string name = wordHash[hashCode].GetName();
	string otherName = wordToAdd.GetName();

	//If ideal location is empty
	if (name == "") {
		wordHash[hashCode] = wordToAdd;
		return hashCode;
	}
	//If ideal location is occupied by matching word, increment that word
	else if (name == otherName) {
		++wordHash[hashCode];
		return -1;
	}
	//If not, add value to hash until an empty slot or duplicate is found
	else {
		while (true) {
			hashCode += (3 * count);
			hashCode %= currSize;
			name = wordHash[hashCode].GetName();

			if (name == "") {
				wordHash[hashCode] = wordToAdd;
				return hashCode;
			}
			else if (name == otherName) {
				++wordHash[hashCode];
				return -1;
			}
			else {
				++count;
			}
		}
	}
}

void ListOfWords::AddToList(Word& wordToAdd)
{
	//If head is null, word is new head
	if (head == nullptr) {
		head = &wordToAdd;
	}
	//If word is less than head, swap them
	else if (wordToAdd < *head) {
		wordToAdd.SetNext(head);
		head = &wordToAdd;
	}
	else {
		//Search list until the position is found or the end of the
		//list is reached.
		Word* prevWord = head;
		Word* currWord = head->GetNext();
		bool done = false;

		while (!done && currWord != nullptr) {  //Increment if equals
			if (wordToAdd < *currWord) { //Insert before currword if less than
				prevWord->InsertAfter(wordToAdd);
				done = true;
			}
			else {  //Reassign preWord and currWord if neither
				prevWord = currWord;
				currWord = currWord->GetNext();
			}
		}
		//At this point, the word has been inserted or we're at the end
		//of the list.
		if (!done) { //If at end of list...
			prevWord->InsertAfter(wordToAdd); //Add to end of list
		}
	}
}

void ListOfWords::InsertWord(Word& wordToAdd) {
	//I want the Word to exist in one place in memory, so I think I 
	// need to add to hash table first.
	
	int location = Hash(wordToAdd.GetName());
	location = AddToHash(wordToAdd, location); //Add to hash. Save final index back to location
	
	if (location > -1) {
		AddToList(wordHash[location]); //Execute this with the copy of word in hash, not the parameter word
		++numEntries; //Keep track of how many words exist.
		Expand();
	}
}

void ListOfWords::Expand() {
	if (numEntries >= (.6 * currSize)) //If hashMap is 60% full
	{
		currSize += initSize;
		Word* temp = wordHash; //Point to existing array
		wordHash = new Word[currSize]; //wordHash now points to larger array
		numEntries = 0; //Reset numEntries

		//Cycle through the linked list to add existing words to new array
		Word* currWord = head;
		head = nullptr;  //We're also making a new linked list, so set to null
		while (currWord != nullptr) {
			cout << "Inserting: " << currWord->GetName() << endl; 

			//In order to be inserted correctly, the next pointer needs to be null or nodes will duplicate in linked list
			//So we copy currWord into tempWord and set the pointer back to null before inserting.
			Word tempWord = *currWord;
			tempWord.SetNext(nullptr);
			InsertWord(tempWord);

			//Then go back to currWord and get the location of the next word in the old array.
			currWord = currWord->GetNext();
		}
		cout << "Array expanded. New size: " << currSize << endl;

		//When this is done, erase original array
		delete[] temp;

	}
}
void ListOfWords::PrintAll(bool hist) {
	Word* currWord = head;
	if (hist) {
		while (currWord != nullptr) {
			currWord->PrintHist();
			currWord = currWord->GetNext();
		}
	}
	else {
		while (currWord != nullptr) {
			currWord->PrintNum();
			currWord = currWord->GetNext();
		}
	}
}

Word* ListOfWords::FindWord(string name) {

	//Hash the word to find the location
	int location = Hash(name);
	int count = 0;
	Word tempWord;
	tempWord.SetName(name);

	//Check location for matching word. If not found, add to location and search again.
	//Loop until word found or program hits an empty word
	while (true) {

		location += (3 * count);
		location %= currSize;

		if (wordHash[location].GetName() == "") {
			return nullptr;
		}

		else if (wordHash[location] == tempWord) {
			return &wordHash[location];
		}

		else {
			++count;
		}
	}
}
