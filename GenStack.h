#include <iostream>
using namespace std;

template<class dType>
class GenStack
{
	private:
		int max;
		int top;
		dType *myArray;
		
	public:
		GenStack(int maxSize);
		~GenStack();

		void push(dType data);
		dType pop();
		dType peek();

		int getSize();
		int isEmpty();
		int isFull();
};

template<class dType>
GenStack<dType>:: GenStack(int maxSize){
	if(maxSize <1) cout << "Max size must be a number greater than 0.\n";
	else{
	myArray = new dType(maxSize);
	max = maxSize;
	top = -1;
	}
}

template<class dType>
GenStack<dType>:: ~GenStack(){
	delete []myArray;
	cout<<"object destroyed"<<endl;
}

template<class dType>
void GenStack<dType>:: push(dType data){
	if(top == max-1) cout << "Stack is filled, push() is not possible.\n";
	else myArray[++top] = data;
}

template<class dType>
dType GenStack<dType>:: pop(){
	if(top == -1) cout << "Stack is empty, pop() is not possible.\n";
	else return myArray[top--]; //makes array appear smaller without actually being smaller-- changes where we say the top is
}

template<class dType>
dType GenStack<dType>:: peek(){
	return myArray[top];
}

template<class dType>
int GenStack<dType>:: isFull(){
	return (top == max-1); //if top == max-1, stack has reached max capacity
}

template<class dType>
int GenStack<dType>:: isEmpty(){
	return (top == -1); 
}

template<class dType>
int GenStack<dType>:: getSize(){
	return (top + 1);
}
