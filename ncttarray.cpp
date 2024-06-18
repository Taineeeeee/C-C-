#include <iostream>
#include <algorithm> 
#include <stdexcept> e

class Array {
private:
    int *arr;
    int size;

public:
   
    Array(int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

   
    ~Array() {
        delete[] arr;
    }

   
    Array(const Array& other) : size(other.size) {
        arr = new int[size];
        std::copy(other.arr, other.arr + size, arr);
    }

  
    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        size = other.size;
        arr = new int[size];
        std::copy(other.arr, other.arr + size, arr);
        return *this;
    }

   
    int getSize() const {
        return size;
    }

   
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

   
    friend std::istream& operator>>(std::istream& in, Array& a) {
        for (int i = 0; i < a.size; ++i) {
            in >> a.arr[i];
        }
        return in;
    }

   r
    friend std::ostream& operator<<(std::ostream& out, const Array& a) {
        for (int i = 0; i < a.size; ++i) {
            out << a.arr[i] << " ";
        }
        return out;
    }

    
    int operator()() const {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        int max_val = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        return max_val;
    }

  
    Array operator+(const Array& other) const {
        if (size != other.size) {
            throw std::runtime_error("Arrays must have the same size");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

 
    Array operator-(const Array& other) const {
        if (size != other.size) {
            throw std::runtime_error("Arrays must have the same size");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] - other.arr[i];
        }
        return result;
    }

    
    Array operator*(const Array& other) const {
        if (size != other.size) {
            throw std::runtime_error("Arrays must have the same size");
        }
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] * other.arr[i];
        }
        return result;
    }

    
    Array operator+(int value) const {
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + value;
        }
        return result;
    }

    
    Array operator-(int value) const {
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] - value;
        }
        return result;
    }

    
    Array operator*(int value) const {
        Array result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] * value;
        }
        return result;
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    Array a(size), b(size);
    std::cout << "Enter elements for array a: ";
    std::cin >> a;
    std::cout << "Enter elements for array b: ";
    std::cin >> b;

    std::cout << "Array a: " << a << std::endl;
    std::cout << "Array b: " << b << std::endl;

    Array c = a + b;
    std::cout << "a + b: " << c << std::endl;

    c = a - b;
    std::cout << "a - b: " << c << std::endl;

    c = a * b;
    std::cout << "a * b: " << c << std::endl;

    c = a + 10;
    std::cout << "a + 10: " << c << std::endl;

    c = a - 10;
    std::cout << "a - 10: " << c << std::endl;

    c = a * 10;
    std::cout << "a * 10: " << c << std::endl;

    std::cout << "Max value in array a: " << a() << std::endl;
    std::cout << "Max value in array b: " << b() << std::endl;

    return 0;
}
