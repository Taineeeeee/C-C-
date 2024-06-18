#include <iostream>

class Complex {
private:
    int real;
    int imag;

public:
    /
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    
    int getReal() const { return real; }
    int getImag() const { return imag; }

   
    void setReal(int r) { real = r; }
    void setImag(int i) { imag = i; }

   
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex& operator+=(const Complex &other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex& operator-=(const Complex &other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    Complex& operator*=(const Complex &other) {
        int newReal = real * other.real - imag * other.imag;
        int newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
        return *this;
    }

    bool operator==(const Complex &other) const {
        return (real == other.real && imag == other.imag);
    }

    bool operator!=(const Complex &other) const {
        return !(*this == other);
    }

    bool operator>(const Complex &other) const {
        return (real*real + imag*imag) > (other.real*real + other.imag*imag);
    }

    bool operator<(const Complex &other) const {
        return (real*real + imag*imag) < (other.real*real + other.imag*imag);
    }

    // Friend functions for input and output
    friend std::ostream& operator<<(std::ostream &out, const Complex &c);
    friend std::istream& operator>>(std::istream &in, Complex &c);
};

std::ostream& operator<<(std::ostream &out, const Complex &c) {
    out << c.real;
    if (c.imag >= 0) {
        out << " + " << c.imag << "i";
    } else {
        out << " - " << -c.imag << "i";
    }
    return out;
}

std::istream& operator>>(std::istream &in, Complex &c) {
    std::cout << "Enter real part: ";
    in >> c.real;
    std::cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex a(3, 4), b(1, 2), c;
    std::cout << "Complex number a: " << a << std::endl;
    std::cout << "Complex number b: " << b << std::endl;

    c = a + b;
    std::cout << "a + b: " << c << std::endl;

    c = a - b;
    std::cout << "a - b: " << c << std::endl;

    c = a * b;
    std::cout << "a * b: " << c << std::endl;

    a += b;
    std::cout << "a += b: " << a << std::endl;

    a -= b;
    std::cout << "a -= b: " << a << std::endl;

    a *= b;
    std::cout << "a *= b: " << a << std::endl;

    bool areEqual = (a == b);
    std::cout << "a == b: " << (areEqual ? "true" : "false") << std::endl;

    bool notEqual = (a != b);
    std::cout << "a != b: " << (notEqual ? "true" : "false") << std::endl;

    bool isGreater = (a > b);
    std::cout << "a > b: " << (isGreater ? "true" : "false") << std::endl;

    bool isLess = (a < b);
    std::cout << "a < b: " << (isLess ? "true" : "false") << std::endl;

    std::cout << "Enter a complex number ( a + bi ):" << std::endl;
    std::cin >> c;
    std::cout << "You entered: " << c << std::endl;

    return 0;
}
