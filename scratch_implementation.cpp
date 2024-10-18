#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack;
    int maxSize;

public:
    Stack(int size) {
        maxSize = size;
    }

    void push(int item) {
        if (isFull()) {
            std::cout << "Stack overflow, cannot add more elements." << std::endl;
            return;
        }
        stack.push_back(item);
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow, no elements to pop." << std::endl;
            return -1;
        }
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    int top() const {
        if (isEmpty()) {
            std::cout << "Stack is empty, no top element." << std::endl;
            return -1;
        }
        return stack.back();
    }

    bool isEmpty() const {
        return stack.empty();
    }

    bool isFull() const {
        return stack.size() == maxSize;
    }

    int size() const {
        return stack.size();
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = stack.size() - 1; i >= 0; --i) {
            std::cout << stack[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    std::cout << "Top element: " << s.top() << std::endl;
    s.display();

    s.pop();
    std::cout << "Top element after pop: " << s.top() << std::endl;

    s.display();

    return 0;
}
