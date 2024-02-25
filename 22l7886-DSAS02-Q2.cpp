// AZFAR NAYYAN.
// 22L-7886. BSE-3C.
// DATA STRUCTURES ASSIGNMENT NO 02.
// STACKS.

// QUESTION NUMBER 02(TWO).

#include<iostream>

using namespace std;

template<class T>
class Stack              //STACK FOR REVERSING IT IN O(1).
{
	T* data;
	int maxSize;
	int currentFilledSize;
	int Top_Index;
	int Bottom_Index;
	bool isReversed;
	int baseSize;

public:
	Stack()   //DEAFULT CONSTRUCOR.
	{
		baseSize = 5;
		maxSize = 5;
		data = new T[maxSize];
		currentFilledSize = 0;
		Top_Index = -1;
		Bottom_Index = 0;
		isReversed = false;
	}
	Stack(int s)     //PARAMETERIZED FOR CUSTOMZED SIZE.
	{
		baseSize = s;
		maxSize = s;
		data = new T[maxSize];
		currentFilledSize = 0;
		Top_Index = -1;
		Bottom_Index = 0;
		isReversed = false;
	}
	bool IsEmpty()
	{
		if (currentFilledSize == 0) return true;
		else return false;
	}
	int circularIncrement(int currentVal)       //CIRCULARY INCREMENTS THE INDEXES IN A ARRAY.
	{
		return (currentVal + 1) % maxSize;
	}
	int circularDecrement(int currentVal)      //CURCULARLY DECREMENTS IN A ARRAY.
	{
		return (currentVal - 1 + maxSize) % maxSize;
	}
	void push(T element)                    //PUSH AT TOP
	{
		if (isReversed == false) Top_Index = circularIncrement(Top_Index);
		else if (isReversed == true) Top_Index = circularDecrement(Top_Index);

		if (currentFilledSize == (maxSize - 1))
		{
			growDouble();
		}

		data[Top_Index] = element;
		if (!(currentFilledSize == maxSize)) currentFilledSize++;
	}
	T pop()     //POP FROM TOP.
	{
		if (IsEmpty())
		{
			cout << "THE STACK IS EMPTY !!! NOTHING TO POP!." << endl;
			return NULL;
		}
		T element = data[Top_Index];
		data[Top_Index] = NULL;
		
		if (isReversed == true) Top_Index = circularIncrement(Top_Index);
		else if (isReversed == false) Top_Index = circularDecrement(Top_Index);

		currentFilledSize--;
		if ((currentFilledSize < (maxSize / 2)) && maxSize != baseSize)
		{
			shrink();
		}
		return element;
	}
	void Top(T& const element)
	{
		if (IsEmpty())
		{
			cout << "STACK IS EMPTY!. NOTHING TO RETURN!." << endl;
			return;
		}
		element = data[Top_Index];
	}
	void print()
	{
		if (IsEmpty())
		{
			cout << "STACK IS EMPTY!. NOTHING TO PRINT!." << endl;
			return;
		}
	
		int printIndex = Top_Index;
		cout << "THE CONTENTS OF STACK ARE: [ ";
		for (int i = 0; i < currentFilledSize; i++)
		{
			cout << data[printIndex];
			if (i != currentFilledSize - 1)cout << "-";

			if (isReversed == false) printIndex = circularDecrement(printIndex);
			else if (isReversed == true) printIndex = circularIncrement(printIndex);
		}
		cout << " ]" << endl;
	}
	void ReverseInBigOhofOne()       //REVERSE IN BIG OH OF ONE JUST REVERSES THE TOP AND BOTTOM INDEXES.
	{
		isReversed = !isReversed;     //BOOL VARAIBLE TO DETEMINE CIRCULAR INCREMENT OR DECREMENT.
		int top = Top_Index;
		Top_Index = Bottom_Index;
		Bottom_Index = top;
	}
	~Stack()                  //DESTRUCTOR.
	{
		delete[] data;
		data = nullptr;
	}
	void growDouble()      //IF SIZE GETS FILLED THE STACK GETS DOUBLED.
	{
		int* currentArray = NULL;
		currentArray = new T[currentFilledSize];

		int temp = Top_Index;
		
		for (int i = 0; i < maxSize; i++)
		{
			currentArray[i] = data[temp];
			Top_Index = i;

			if (isReversed == false) temp = circularDecrement(temp);
			else if (isReversed == true) temp = circularIncrement(temp);
		}
		isReversed = false;
		Bottom_Index = 0;
		currentFilledSize = maxSize - 1;

		int prevSize = maxSize;
		int newSize = maxSize * 2;
		maxSize = newSize;

		delete[] data;
		data = new T[maxSize];

		int j = prevSize - 1;
		for (int i = 0; i < prevSize; i++, j--)
		{
			data[i] = currentArray[j];
		}

		cout << "ARRAY GROWED TO " << maxSize << endl;
	}
	void shrink()
	{
		int* currentArray = NULL;
		currentArray = new T[currentFilledSize];

		int temp = Top_Index;

		for (int i = 0; i < currentFilledSize; i++)
		{
			currentArray[i] = data[temp];
			Top_Index = i;

			if (isReversed == false) temp = circularDecrement(temp);
			else if (isReversed == true) temp = circularIncrement(temp);
		}

		isReversed = false;
		Bottom_Index = 0;

		int prevSize = currentFilledSize;
		int newSize = maxSize / 2;
		maxSize = newSize;

		delete[] data;
		data = new T[maxSize];

		int j = prevSize - 1;
		for (int i = 0; i < prevSize; i++, j--)
		{
			data[i] = currentArray[j];
		}

		cout << "ARRAY SHRINKED TO " << maxSize << ". ";

	}
};



int main()
{

	Stack<int> s1(5);

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	s1.print();

	s1.push(5);

	s1.print();

	s1.push(6);
	s1.push(7);
	s1.push(8);

	s1.print();

	s1.ReverseInBigOhofOne();

	s1.print();

	s1.ReverseInBigOhofOne();

	s1.push(9);

	s1.print();

	s1.push(10);
	s1.push(11);
	s1.push(12);
	s1.push(13);
	s1.push(14);
	s1.push(15);
	s1.push(16);

	s1.print();

	s1.push(17);
	s1.push(18);
	s1.push(19);
	s1.push(20);

	s1.print();

	s1.ReverseInBigOhofOne();

	s1.print();

	int popped_1 = s1.pop();
	int popped_2 = s1.pop();
	int popped_3 = s1.pop();

	cout << endl << "POPPED: " << popped_1 << endl;
	cout << "POPPED: " << popped_2 << endl;
	cout << "POPPED: " << popped_3 << endl;

	s1.print();

	s1.ReverseInBigOhofOne();

	s1.print();

	cout << "POPPING: ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " " << endl;

	s1.print();

	cout << "POPPING: ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " ";
	cout << s1.pop() << " " << endl;

	s1.print();

	s1.ReverseInBigOhofOne();

	s1.print();

	

	system("pause>0");
	return 0;


	//q2 
}