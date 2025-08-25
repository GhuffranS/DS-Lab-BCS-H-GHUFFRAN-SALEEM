#include <iostream>
using namespace std;

class ShallowBox {
private:
    int* value;

public:
    ShallowBox(int val) {
        value = new int(val);
    }

    ~ShallowBox() {
        delete value;
    }

    void setValue(int val) {
        *value = val;
    }

    void display() {
        cout << "Value: " << *value << " | Address: " << value << endl;
    }
};

class DeepBox {
private:
    int* value;

public:
    DeepBox(int val) {
        value = new int(val);
    }

    ~DeepBox() {
        delete value;
    }

    DeepBox(const DeepBox& other) {
        value = new int(*other.value);
    }

    DeepBox& operator=(const DeepBox& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }

    void setValue(int val) {
        *value = val;
    }

    void display() {
        cout << "Value: " << *value << " | Address: " << value << endl;
    }
};

int main() {
    cout << "Shallow Copy Demonstration" << endl;
    ShallowBox shallow_box1(10);
    cout << "Original Box:" << endl;
    shallow_box1.display();

    ShallowBox shallow_box2 = shallow_box1;
    cout << "Copied Box (using default copy):" << endl;
    shallow_box2.display();

    shallow_box1.setValue(20);
    cout << "Original Box after changing its value:" << endl;
    shallow_box1.display();
    cout << "Copied Box (note it also changed):" << endl;
    shallow_box2.display();

    cout << "\nDeep Copy" << endl;
    DeepBox deep_box1(100);
    cout << "Original Box:" << endl;
    deep_box1.display();

    DeepBox deep_box2 = deep_box1;
    cout << "Copied Box using copy constructor:" << endl;
    deep_box2.display();

    deep_box1.setValue(200);
    cout << "Original Box after changing its value:" << endl;
    deep_box1.display();
    cout << "Copied Box:" << endl;
    deep_box2.display();

    cout << "\nDeep Copy Assignment Operator" << endl;
    DeepBox deep_box3(500);
    cout << "Third Box before assignment:" << endl;
    deep_box3.display();

    deep_box3 = deep_box1;
    cout << "Third Box after assignment from deep_box1:" << endl;
    deep_box3.display();
    cout << "Original Box deep_box1:" << endl;
    deep_box1.display();

    return 0;
}
