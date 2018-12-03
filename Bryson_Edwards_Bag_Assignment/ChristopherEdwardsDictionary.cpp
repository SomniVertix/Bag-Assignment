// ChristopherEdwardsDictionary.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

using namespace std;
int main()
{
	int userInput, intHolder;
	string stringTemplate;
	cout << "How many inputs would you like?" << endl;
	cin >> userInput;
	cout << endl;

	BDictionary<int, string> dictCallIntString(userInput);
	cout << "Testing dictionary with <int,string> KV Pair" << endl;
	cout << "-----------------------------------------------" << endl;
	for(int i = 0; i < userInput; i++)
	{
		// Loops through inserting KVPairs to BDictionary until user input is complete
		stringTemplate = "String" + to_string(i);
		dictCallIntString.insert(i, stringTemplate);
		cout << i << "  " << stringTemplate << endl;
		intHolder = i;
	}
	cout << "Insert: " << intHolder +1 << " values to make Dictionary " << dictCallIntString.size() << " KV Pairs big" << endl;

	dictCallIntString.removeAny(stringTemplate);
	cout << "RemoveAny: Removed int data " << stringTemplate << endl;

	dictCallIntString.find(intHolder, stringTemplate);
	cout << "Find: Data at key " << intHolder << " is " << stringTemplate << endl;
	

	dictCallIntString.remove(intHolder, stringTemplate);
	cout << "Remove: Data at key " << intHolder << " with value " << stringTemplate << " has been removed" << endl;

	dictCallIntString.clear();
	cout << "Clear: Dictionary cleared" << endl;
	cout << endl;






	BDictionary<string, int> dictCallStringInt(userInput);
	cout << "Testing dictionary with <string, int> KV Pair" << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i <= userInput; i++)
	{
		// Loops through inserting KVPairs to BDictionary until user input is complete
		stringTemplate = "String" + to_string(i );
		dictCallStringInt.insert(stringTemplate, i);
		intHolder = i;
	}
	cout << "Insert: " << intHolder << " values to make Dictionary " << dictCallStringInt.size() << " KV Pairs big" << endl;

	dictCallStringInt.find(stringTemplate, intHolder);
	cout << "Find: Data at key " << intHolder << " is " << stringTemplate << endl;
	cout << endl;

	system("pause");
    return 0;
}