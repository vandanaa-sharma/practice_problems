#pragma once

namespace project {

	template <typename T> 
	class vector
	{
	private:

		int size = 20;
		T* array = nullptr;
		int currentSize = 0;

	public:
		vector()
		{
			array = new T[size];
		}

		void push_back(T i) {

			if (currentSize == size - 1) {
				T* newArray = new T[currentSize * 2];
				for (int i = 0; i < currentSize; i++) {
					newArray[i] = array[i];
				}
				delete[] array;
				array = newArray;
			}

			array[currentSize] = i;
			currentSize++;
		}

		void empty() {
			delete[] array;
			array = new T[size];
		}

		int operator[](T i){
			return array[i];
		}

		virtual ~vector() {
			delete[] array;
		}
	};
}

