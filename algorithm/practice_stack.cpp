#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// ===== ArrayStack Implementation =====
template <typename T>
class ArrayStack {
private:
    T data[MAX_SIZE];
    int topIndex;

public:
    ArrayStack() : topIndex(-1) {}

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == MAX_SIZE - 1;
    }

    void push(T value) {
        if (!isFull()) data[++topIndex] = value;
    }

    void pop() {
        if (!isEmpty()) topIndex--;
    }

    T top() {
        if (!isEmpty()) return data[topIndex];
        return '\0';
    }
};

// ===== Helper Functions =====
bool isOpening(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isClosing(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// ===== Linter Function =====
void checkBrackets(const string &line) {
    ArrayStack<char> stack;
    ArrayStack<int> positions; // To track positions of opens

    for (int i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (isOpening(c)) {
            stack.push(c);
            positions.push(i + 1); // 1-based index
        }
        else if (isClosing(c)) {
            if (stack.isEmpty()) {
                cout << "ERROR pos=" << i + 1 << " reason=extra-closing" << endl;
                return;
            }

            char open = stack.top();
            if (!isMatching(open, c)) {
                cout << "ERROR pos=" << i + 1 << " reason=mismatch" << endl;
                return;
            }

            stack.pop();
            positions.pop();
        }
    }

    if (!stack.isEmpty()) {
        cout << "ERROR pos=" << positions.top() << " reason=unclosed" << endl;
    } else {
        cout << "OK" << endl;
    }
}

// ===== Main =====
int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    checkBrackets(input);
    return 0;
}
