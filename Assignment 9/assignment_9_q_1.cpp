#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;

public:
    bool empty() const {
        return elements.empty();
    }

    void push(const T& item) {
        elements.push_back(item);
    }
    
    T pop() {
        if (empty()) {
            cout<<"stack is empty()\n";
            return T(-1);
        }
        T item = elements.back();
        elements.pop_back();
        return item;
    }

    int size() const {
        return elements.size();
    }
};

class Objects {
private:
    int value;

public:
    Objects(int v) : value(v) {}

    int getValue() const {
        return value;
    }
};

int main() {

    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Stack<int> elements: ";
    while (!intStack.empty()) {
        cout << intStack.pop() << " ";
    }
    cout << endl;

    Stack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(6.28);

    cout << "Stack<double> elements: ";
    while (!doubleStack.empty()) {
        cout << doubleStack.pop() << " ";
    }
    cout << endl;

    Stack<Objects> classStack;
    
    classStack.push(Objects(5));
    classStack.push(Objects(10));

    cout << "Stack<Objects> elements:" << endl;
    while (!classStack.empty()) {
        Objects sc = classStack.pop();
        cout << "Value: " << sc.getValue() << endl;
    }

    return 0;
}
