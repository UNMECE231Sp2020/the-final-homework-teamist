#include <iostream>
#include "GeneralList.hpp"

template <class T>
class Stack {
	private:
		List<T> _data;
		size_t _size;
		
	public:
		//Default constructor
		Stack() {
			_size = 0;
			_data = nullptr;
		}
	

		//Default copy constructor
		Stack(const Stack &stack) {
			if(stack.size() == 0) {
				_size = 0;
				_data = nullptr;
			}
			else {
				int stack_size = stack.size();
				List *stack_data_copy = new List[stack_size];
				int i;
				for(i=0; i<stack_size; i++) {
					*(stack_data_copy+i) = *(stack._data+i);
				}

				if(stack_size == 1) {
					_data = new List(*stack_data_copy);
				}
				else {
					_data = new List[stack_size];
					for(i=0; i<stack_size; i++) {
						*(_data+i) = *(stack_data_copy+i);
					}
				}
				_size = stack_size;
				delete [] stack_data_copy;
			}
		}


		//Getters
		T top() const {
			return *_data+size()-1;
		}

size_t size() const {
			return _size;
}

		//Adding data to the https://github.com/UNMECE231Sp2020/the-final-homework-teamist.gitdata structure
		void push(T value) {
			if(_data == nullptr) {
				_data = new List(value);
				_size++;
			}
			else{
				int data_size = size();
			       	List *data_copy = new List[data_size];
				int i;
				for(i=0; i<data_size; i++) {
					*(data_copy+i) = *(_data+i);
				}

				delete [] _data;
				_data = new List [data_size+1];

				for(i=0; i<data_size; i++) {
					*(_data+i) = *(data_copy+i);
				}
				*(_data+i) = value; 
				_size++; 
				delete [] data_copy;
			}
		}

		//Removing data from the data structure
		void pop() {
			if(_data == nullptr) {
				std::cout << "Could not pop empty Stack, Master Jedi" << std:endl;
				return;

			}
			else if(size() == 1) {
				delete _data;
				_data = nullptr; 
				_size = 0;
			}
			else{
				List.pop_back();
			}
		}


		bool search(T value) {
			//return _data.search(value);
			for(int i=0; i<size(); i++) {
				if(*(_data+i) == data) {
					return true;
				}
			}
			return false; 
		}


		bool empty() const {
			return (_data == nullptr) && (_size == 0);
		}

		void print() {
			for(int i=0; i<size(); i++) {
				std::cout << *(_data+i) << " ";
			}
			std::cout << std::endl;
		}

		//This overloaded operator is empty, please implement
		Stack<T> operator=(const Stack<T> &stack) {
			if(stack.size() == 0) {
				return *this;
			}
			if(stack.size() == 1) {
				List data_copy = *stack._data;
				if(size() < 2) {
					delete _data;
				}
				else{
					delete [] _data;
				}
				_data = new List(data_copy);
				_size = 1;
			}
			else {
				int data_size = stack.size();
				List *data_copy = new List[data_size];
				for(int i=0; i<data_size; i++) {
					*(data_copy+i) = *(stack._data+i);
				}

				if(size() < 2) {
					delete _data;
				}
				else{
					delete [] _data;
				}
				_data = new List[data_size];

				for(int i=0; i<data_size; i++) {
					*(_data+i) = *(data_copy+i);
				}
				_size = data_size;
				delte [] data_copy;
			}

		}

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};

template <class S>
std::ostream &operator<<(std::ostream &out, const Stack<S> &stack( {
	for(int i=0; i<stack.size(); i++) {
		out << *(stack._data+i) << " ";
	}
	return out;
}

template <class S>
bool operator==(const Stack<S> *left_side, const Stack<S> &right_side) {
	if(left_side.size() != right_side.size()) {
		return false;
	}
	for(int i=0; i<left_side.size(); i++) {
		if(*(left_side._data+i) != *(right_side._data+i)) {
			return false;
		}
	}
	return true;
}

template <class S>
bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side){
	return !(left_side==right_side);
}














