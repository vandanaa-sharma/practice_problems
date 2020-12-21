#pragma once
template<typename T>
class SmartPointer
{
private:
	T* ptr = nullptr;
public:

	explicit SmartPointer(T* iPtr) {
		ptr = iPtr;
	}

	// Copy constructor
	SmartPointer(const SmartPointer &iPtr) {
		delete[] ptr;
		ptr = iPtr;
	}

	// Assignment operator
	void operator=(T* iPtr) {
		delete[] ptr;
		ptr = iPtr;
	}

	// Deference operator
	T& operator*() {
		return *ptr;
	}

	// Arrow operator
	void operator->() {
		return ptr;
	}

	virtual ~SmartPointer() {
		delete[] ptr;
	}
};

