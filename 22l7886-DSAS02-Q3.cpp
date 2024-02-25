// AZFAR NAYYAN.
// 22L-7886. BSE-3C.
// DATA STRUCTURES ASSIGNMENT NO 02.
// STACKS.

// QUESTION NUMBER 03(THREE).

#include<iostream>

using namespace std;

template<class T>
class UndoStack               
{
	T* data;
	int Top_Index;
	int currentFilledSize;
	int maxSize;

public:
	UndoStack()                             // DEFAULT 100 SIZED UNDOSTACK CONSTRUCTOR.
	{
		maxSize = 100;
		data = new T[maxSize];
		Top_Index = -1;
		currentFilledSize = 0;
	}
	UndoStack(int size)                   //PARAMETERIZED CONSTRUCTOR IF SIZE IS CHANGED.
	{
		maxSize = size;
		data = new T[maxSize];
		Top_Index = -1;
		currentFilledSize = 0;
	}
	bool isEmpty()            //O(1)           //RETURN TRUE IF EMPTY STACK.
	{
		if (currentFilledSize == 0) return true;
		else return false;
	}
	void push(T const& element)    //O(1)       //PUSHES ELEMENT AT THE TOP OF STACK.
	{
		Top_Index = (Top_Index + 1) % maxSize;  //CIRCULAR INCREMENT.
		data[Top_Index] = element;
		if (!(currentFilledSize == maxSize)) currentFilledSize++;
	}
	T pop()        //O(1)                  //POP'S THE TOP ELEMENT.
	{
		if (isEmpty())
		{
			cout << "THE STACK IS EMPTY !!! NOTHING TO POP!." << endl;
			return NULL;
		}
		T element = data[Top_Index];
		data[Top_Index] = NULL;
		Top_Index = (Top_Index - 1 + maxSize) % maxSize;   //CIRCULAR DECREMENT.
		currentFilledSize--;
		return element;
	}
	void top(T& element)    //O(1)          //RETURNS TOP ELEMENT.
	{
		if (isEmpty())
		{
			cout << "STACK IS EMPTY!. NOTHING TO RETURN!." << endl;
			return;
		}
		element = data[Top_Index];
	}
	void print()       //O(currentFilledSize)  PRINTS STACK.
	{
		if (isEmpty())
		{
			cout << "STACK IS EMPTY!. NOTHING TO PRINT!." << endl;
			return;
		}
		cout << "THE UNDO STACK CONTENTS ARE: [ ";
		int printIndex = Top_Index;
		for (int i = 0; i < currentFilledSize; i++)
		{
			cout << data[printIndex];
			if (i != currentFilledSize - 1) cout << "-";
			printIndex = (printIndex - 1 + maxSize) % maxSize;
		}
		cout << " ]" << endl;
	}
	void undo()    //O(1)    //UNDO STACKS   
	{
		if (isEmpty())
		{
			cout << "THE STACK IS EMPTY !!! CAN'T UNDO!." << endl;
			return;
		}
		data[Top_Index] = NULL;
		Top_Index = (Top_Index - 1 + maxSize) % maxSize;   //CIRCULAR DECREMENT.
		currentFilledSize--;
	}
	~UndoStack() //DESTRUCTOR.
	{
		delete[] data;
		data = nullptr;
	}
};


int main()
{	


	cout << "SHORT EXAMPLE: " << endl;

	UndoStack<int> example(5);      //5 SIZED STACK EXAMPLE.

	example.push(1);
	example.push(2);
	example.push(3);
	example.push(4);
	example.push(5);

	example.print();

	example.undo();

	example.print();

	example.push(5);
	example.push(6);
	example.push(7);

	example.print();

	example.undo();
	example.print();
	example.undo();
	example.print();
	example.undo();
	example.print();

	int popped = example.pop();
	cout << "POPPED ELEMENT: " << popped << endl;
	example.print();

	example.top(popped);
	cout << "TOP ELEMENT: " << popped << endl << endl;

	cout << "100 SIZED !" << endl;

	UndoStack<int> undoStack;    //100 SIZED. DEFAULT.

	for (int i = 0; i < 100; i++) undoStack.push(i + 1);

	undoStack.print();

	undoStack.push(101);
	undoStack.push(102);

	cout << "FORGOT LAST TWO ELEMENTS: " << endl;
	undoStack.print();

	undoStack.undo();
	undoStack.undo();
	undoStack.undo();

	cout << "AFTER UNDO THREE TIMES: " << endl;
	undoStack.print();

	int pop = undoStack.pop();
	cout << "POPPED: " << pop << endl;

	undoStack.print();

	system("pause>0");
	return 0;

	//q3
}