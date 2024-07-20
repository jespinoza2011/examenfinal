#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int digit;
    Node* next;

    Node(int d) : digit(d), next(nullptr) {}
};

class BinaryNumber {
private:
    Node* head;

    void addDigit(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

public:
    BinaryNumber() : head(nullptr) {}

    void inputNumber() {
        string binary;
        cout << "Ingrese un número binario: ";
        cin >> binary;

        for (int i = binary.length() - 1; i >= 0; i--) {
            addDigit(binary[i] - '0');
        }
    }

    void displayNumber() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->digit;
            current = current->next;
        }
        cout << endl;
    }

    BinaryNumber add(BinaryNumber& other) {
        BinaryNumber result;
        Node* thisPtr = this->head;
        Node* otherPtr = other.head;
        int carry = 0;

        while (thisPtr != nullptr || otherPtr != nullptr || carry != 0) {
            int sum = carry;
            if (thisPtr != nullptr) {
                sum += thisPtr->digit;
                thisPtr = thisPtr->next;
            }
            if (otherPtr != nullptr) {
                sum += otherPtr->digit;
                otherPtr = otherPtr->next;
            }

            result.addDigit(sum % 2);
            carry = sum / 2;
        }

        return result;
    }

    ~BinaryNumber() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    BinaryNumber num1, num2;

    cout << "Para el primer número:" << endl;
    num1.inputNumber();

    cout << "Para el segundo número:" << endl;
    num2.inputNumber();

    cout << "Primer número: ";
    num1.displayNumber();

    cout << "Segundo número: ";
    num2.displayNumber();

    BinaryNumber sum = num1.add(num2);
    cout << "Suma: ";
    sum.displayNumber();

    return 0;
}