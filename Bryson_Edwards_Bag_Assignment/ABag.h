#ifndef ABAG_H
#define	ABAG_H

#include "bagADT.h"
#include "kvpair.h"
#include <string>
using namespace std;

template <typename E>
class ABag : public Bag<E> {
	
public:
	E* arr;
	int position;
	int cap = 0;
	ABag(int max =10);
       // base constructor
	virtual ~ABag();
  // base destructor

						// Insert a new item into the bag -- return false if fails and true if
						// successful
	virtual bool addItem(const E& item) override;

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	virtual bool remove(E& item)override;

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	virtual bool removeTop(E& returnValue) override;

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	virtual bool find(E& returnValue) const override;

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	virtual bool inspectTop(E& item) const override;

	// empties the bag
	virtual void emptyBag() override;

	// use the += operator to add an item to the bag
	virtual bool operator+=(const E& addend)override;

	// get the size of the bag
	virtual int size() const override;

	// get the capacity of the bag
	virtual int bagCapacity() const override;


};

template <typename E>
ABag<E>::ABag(int max)
{
	arr = new E[max];
	position = -1;
	cap = max;
}

template <typename E>
ABag<E>::~ABag()
{
	delete[] arr;
}

// DONE
template <typename E>
inline bool ABag<E>::addItem(const E & item)
{
	if (position == bagCapacity() - 1) //use of bagCapacity to check if bag is full
	{
		return false; 
	}
	else
	{		
		arr[++position] = item; // add 1 to position before its compiled
		return true;
	}
}

//DONE
template <typename E>
inline bool ABag<E>::remove(E& item)
{
	if (position == -1) // check if bag is full
	{
		return false;
	}
	else
	{
		for (int i = position; i >= 0; i--) // loop through each object top to bottom
		{
			if (arr[i] == item) // if the values are equal, then return the item
			{
				item = arr[i];
				position--;
				for (int j = i; j <= position; j++)
				{
					arr[j] = arr[j + 1]; // shift down the objects on top
				}
				return true;
			}
		}
	}
	return false;
}

//DONE
template <typename E>
inline bool ABag<E>::removeTop(E& returnValue)
{
	if (inspectTop(returnValue))
	{
		return false;
	}
	
	position--; //return
	return true;
}

//DONE
template <typename E>
inline bool ABag<E>::find(E& returnValue) const
{
	if (position == -1)
	{
		return false;
	}
	else
	{
		for (int i = position; i >= 0; i--) // loops through objects and returns value
		{
			if (arr[i] == returnValue)
			{
				returnValue = arr[i]; // returns the KVpair found
				return true;
			}
		}
	}
	return false;
}

//DONE
template <typename E>
inline bool ABag<E>::inspectTop(E& item) const
{
	cout << "string" << endl;
	if (position == -1)
	{
		return false;
	}
	item = arr[position];
	return true;
}

//DONE
template <typename E>
inline void ABag<E>::emptyBag()
{
	position = -1; // Moves the position down to -1, in a sense removing the elements
}

//DONE
template <typename E>
inline bool ABag<E>::operator+=(const E& addend)
{
	return addItem(addend); // No need to rewrite addItem, just call it from here
}

//DONE
template <typename E>
inline int ABag<E>::size()const
{
	return position + 1; // returns the actual size
}

//DONE
template <typename E>
inline int ABag<E>::bagCapacity() const
{
	return cap; // returns the capacity
}
#endif

