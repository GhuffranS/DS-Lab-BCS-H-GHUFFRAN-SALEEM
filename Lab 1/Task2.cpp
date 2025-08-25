#include <iostream>
using namespace std;

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

class Exam {
private:
    char* studentName;
    char* examDate;
    double score;

public:
    Exam(const char* name, const char* date, double s) {
        int nameLength = stringLength(name);
        studentName = new char[nameLength + 1];
        stringCopy(studentName, name);

        int dateLength = stringLength(date);
        examDate = new char[dateLength + 1];
        stringCopy(examDate, date);

        score = s;
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    void setScore(double s) {
        score = s;
    }

    void displayDetails() {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam exam1("Babar Azam", "20-05-25", 95.5);
    cout << "Original Exam Details:" << endl;
    exam1.displayDetails();

    Exam exam2 = exam1;
    cout << "\nShallow Copy Exam Details:" << endl;
    exam2.displayDetails();

    exam1.setScore(88.0);
    cout << "\nAfter modifying the score of the original exam:" << endl;
    cout << "Exam 1:" << endl;
    exam1.displayDetails();
    cout << "Exam 2 (Note the score is not changed):" << endl;
    exam2.displayDetails();
    
    return 0;
}

