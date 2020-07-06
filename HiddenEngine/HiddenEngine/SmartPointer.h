#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <class T> 
class SmartPointer {
public:
	//default constructor
	//should always use one of the more advanced constructors though
	SmartPointer() {}
	//creates a smart pointer based off a regular pointer that's been fed in
	SmartPointer(T* p_ptr) {
		m_rawPointer = p_ptr;

		m_counter = new RefCount();
		m_counter->count++;
	}
	//this constructor takes in another smart pointer and increases the references
	//to that smart pointer, thus increasing the RefCount pointer for both
	SmartPointer(const SmartPointer<T>& autre) {
		m_rawPointer = autre.m_rawPointer;
		m_counter = autre.m_counter;
		m_counter->count++;
	}

	~SmartPointer() {
		//we check if we even have anything to do here
		if (m_counter != nullptr) {
			//if we do, we decrement the reference counter
			m_counter->count--;
			//if the reference counter is now 0, aka, nothing is referencing this pointer
			if (m_counter->count == 0) {
				//we delete the pointer and reset it to nullptr
				delete m_rawPointer;
				m_rawPointer = nullptr;
				//and we do the same to the counter, so we can check if there's anything to do here again
				delete m_counter;
				m_counter = nullptr;
			}
		}
	}

	T& operator*() {
		return *m_rawPointer;
	}
	T* operator->() {
		return m_rawPointer;
	}

	SmartPointer<T>& operator=(const SmartPointer<T>& autre) {
		//first, we check if we're already referencing the same pointer
		if (this != other) {
			//if we're not, and our current pointer isn't already nullptr, we delete the current pointer
			if (rawPointer != nullptr) {
				delete this;
			}

			//we then take the values of the other smart pointer and make them our own
			//and then increment the reference counter to indicate an increase in references
			m_rawPointer = autre.m_rawPointer;
			m_counter = autre.m_counter;
			m_counter->count++;
		}

		return *this;
	}

private:
	struct RefCount {
		unsigned int count;
	};

	T* m_rawPointer = nullptr;
	RefCount* m_counter = nullptr;
};

#endif