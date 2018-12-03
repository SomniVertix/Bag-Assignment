// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef BDICTIONARY_H
#define BDICTIONARY_H

#include "dictionaryADT.h"
#include "ABag.h"
#include "KVPair.h"
#include <string>


using namespace std;
template <typename Key, typename E>
class  BDictionary : public Dictionary<Key, E>{
private:
	ABag<KVpair<Key, E>>* bagPtr;
public:
	
	BDictionary(int max = 10); // Default constructor

	virtual ~BDictionary(); // Base destructor

							 // Reinitialize dictionary
	virtual void clear()override; //overrides needed to access these functions and not the derived class' functions

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false otherwise
	virtual bool insert(const Key& k, const E& e) override;

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	virtual bool remove(const Key& k, E& rtnVal)override;

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	virtual bool removeAny(E& returnValue) override;

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	virtual bool find(const Key& k, E& returnValue) const override;

	// Return the number of records in the dictionary.
	virtual int size() override;
};

template <typename Key, typename E>
BDictionary<Key, E>::BDictionary(int max) 
{
	bagPtr = new ABag<KVpair<Key, E>>(max);
}          // Default constructor

template <typename Key, typename E>
 BDictionary<Key, E>::~BDictionary() {
	delete bagPtr;
} // Base destructor



template <typename Key, typename E>
inline void BDictionary<Key, E>::clear()
{
	bagPtr->emptyBag(); // Calls ABag's emptyBag
}


template <typename Key, typename E>
inline bool BDictionary<Key, E>::insert(const Key& k, const E& e)
{
	KVpair<Key, E> fill(k,e); //Needs a KVpair to hold both k and e in order to pass to the function
	return bagPtr->operator+=(fill); // use of +=
}


template <typename Key, typename E>
inline bool BDictionary<Key, E>::remove(const Key& k, E& rtnVal)
{
	KVpair<Key, E> fill(k, rtnVal); // Same as insert, needs a filler KVpair
	if (bagPtr->remove(fill))
	{
		rtnVal = fill.value();
		return true;
	}
	return false;
}

template <typename Key, typename E>
inline bool BDictionary<Key, E>::removeAny(E& returnValue)
{
	Key* k;
	k = new Key();
	KVpair<Key, E> fill(*k, returnValue); 
	if (bagPtr->removeTop(fill)) // Use of removeTop since we can delete ANY arbitrary element
	{
		returnValue = fill.value();
		delete k;
		return true;
	}
	delete k;
	return false;
}


template <typename Key, typename E>
inline bool BDictionary<Key, E>::find(const Key& k, E& returnValue) const
{
	KVpair<Key, E> fill(k, returnValue);
	return bagPtr->find(fill); // fills key and value into a KVpair and then calling the find function
}


template <typename Key, typename E>
inline int BDictionary<Key, E>::size()
{
	return bagPtr->size(); // calls size function from ABag
}

#endif