#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    // Hàm tạo
    Array(int size) : size(size) {
        data = new int[size];
    }

    // Hàm hủy
    ~Array() {
        delete[] data;
    }

    // Hàm tạo bản sao
    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Hàm toán tử gán
    Array& operator=(const Array& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Hàm nhập dữ liệu từ bàn phím
    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    // Hàm hiển thị dữ liệu ra màn hình
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Hàm gán giá trị cho một phần tử
    void set(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        } else {
            cout << "Chi so khong hop le!" << endl;
        }
    }

    // Hàm lấy giá trị của một phần tử
    int get(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            cout << "Chi so khong hop le!" << endl;
            return -1; // giá trị không hợp lệ
        }
    }
};

int main() {
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;

    Array arr(n);
    arr.input();
    cout << "Mang sau khi nhap: ";
    arr.display();

    int index, value;
    cout << "Nhap chi so va gia tri can gan: ";
    cin >> index >> value;
    arr.set(index, value);

    cout << "Mang sau khi gan gia tri: ";
    arr.display();

    cout << "Nhap chi so can lay gia tri: ";
    cin >> index;
    cout << "Gia tri tai chi so " << index << ": " << arr.get(index) << endl;

    return 0;
}
