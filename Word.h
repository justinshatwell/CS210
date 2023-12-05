#pragma once
#include <string>;

using namespace std;

class Word {
	int count;
	string name;
	Word* nextWord;

public:
	
	Word();
	~Word();
	Word(const Word&);
	void PrintNum();
	void PrintHist();
	string GetName();
	void SetName(string);
	int GetCount();
	void SetCount(int);
	Word* GetNext();
	void SetNext(Word*);
	void InsertAfter(Word&);
	bool operator>(Word&);
	bool operator<(Word&);
	bool operator==(Word&);
	void operator++();
	void operator=(const Word&);
};