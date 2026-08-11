#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;
template <class T>

class clsMyStackArr {

protected:
	clsDynamicArray <T> _MyList;

public:

	void push(T Item) {
		_MyList.InsertAtBeginning(Item);
	}

	void pop() {
		_MyList.DeleteFirstItem();
	}

    void Print() {
		_MyList.PrintList();
	}

	int Size() {
		return _MyList.Size();
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T Top() {
		return (IsEmpty()) ? (T()) : (_MyList.GetItem(0));
	}

    void Reverse() {
        _MyList.Reverse();
    }

    void InsertAtFront(T Value) {
        _MyList.InsertAtBeginning(Value);
    }

    void Clear() {
        _MyList.Clear();
    }
};

