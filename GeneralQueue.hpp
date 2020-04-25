#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;
	public:
		//Default constructor
		Queue() {
			_size = 0;
			_data = nullptr;
		}

		//Copy constructor
		Queue(const Queue &q) {
			if(q.size() == 0) {
				_size = 0;
				_data = nullptr;
			}
			else{
				int q_size = q.size();
				List *q_data_copy = new List[q_size];
				int i;
				for(i=0; i<q_size; i++) {
					*(q_data_copy+i) = *(q._data+i);
				}

				if(q_size == 1){
					_data = new List(*q_data_copy);
				}
				else{
					_data = new List[q_size];
					for(i=0; i<q_size; i++) {
						*(_data+i) = *(q_data_copy+i);
					}
				}
				_size = q_size;
				delete [] q_data_copy;
			}
		}

		//Getters
		size_t size() const {
			return _size;
		}

		Q front() const {
			return *(_data+size()-1);
		}

		Q back() const {
			return *_data;
		}

		//Push to queue
		void enqueue(Q value) {
			if(_data == nullptr) {
				_data = new List(data);
				_size++;
			}
			else{
				int data_size = size();
				List *data_copy = new List[data_size]; 
				int i;
				for(i=0; i<data_size; i++) {
					*(data-copy+i) = *(_data+i);
				}

				delete [] _data;
				_data = new List [data_size+1]; 

				*(_data) = data;
				for(i=0; i<data_size; i++) {
					*(_data+i+1) = *(data_copy+i); 
				}
				_size++;
				delete[] data_copy;
			}
		}

		//Pop from queue
		void dequeue() {
			if(_data == nullptr) {
				std::cout << "Could not pop empty Queue, Master Yoda" << std::endl;
				return;
			}
			else if(size() == 1) {
				delete _data;
				_data = nullptr;
				_size = 0;
			}
			else{
				int data_size = size();
				List *data_copy = new List[data_size-1];
				int i;
				for(i=0; i<data_size-1; i++) {
					*(data_copy+i) = *(_data+i);
				}

				delete [] _data;
				_data = new List[data_size-1];

				for(i=0; i<data_size-1; i++) {
					*(_data+i) = *(data-copy+i);
				}
				delete [] data_copy;
				_size--;
			}
		}


		void print() {
			for(int i=0; i<size(); i++) {
				std::cout << *(_data+i) << " ";
			}
			std::cout << std::endl;
		}

		bool search(Q value) {
			for(int i=0; i<size(); i++) {
				if(*(_data+i) == value) {
					return true;
				}
			}
			return false;
		}


		bool empty() {
			return _data == nullptr;
		}

		Queue<Q> operator=(const Queue<Q> q) {
			if(q.size() == 0) {
				return *this;
			}
			if(q.size() == 1) {
				List data_copy = *q.values;
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
				int data_size = q.size();
				List *data_copy = new List[data_size];
				for(int i=0; i<data_size; i++) {
					*(data_copy+i) = *(q._data+i);
				}
				
				if(size() < 2) {
					delete _data;
				}
				else{
					delete [] _data;
				}
				_data = new List [data_size];

				for(int i=0; i<data_size; i++) {
					*(_data+i) = *(data_copy+i);
				}
				_size = data_size;
				delete [] data_copy;
			}
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};

template <class U>
std::ostream &operator <<(std::ostream &out, const Queue<U> &q) {
	for(int i=0l i<q.size(); i++) {
		out << *(q._data+i) << " ";
	}
	return out;
}

template <class U>
bool operator==(const Queue<U> &left_queue, const Queue<U> &right_queue) {
	if(left_queue.size() != right_queue.size()) {
		return false;
	}
	for(int i=0; i<left_queue.size(); i++) {
		if(*(left_queue._data+i) != *(right_queue._data+i)) {
			return false;
		}
	}
	return true;
}

template <class U>
bool operator!=(const Queue<U> &left_queue, const Queue<U> &right_queue) {
	return !=(left_queue==right_queue);
}
