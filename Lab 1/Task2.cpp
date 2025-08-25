#include <iostream>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    double score;

public:
    Exam(const char* name, const char* date, double s) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

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
    Exam exam1("Babar Azam", "20-10-2025", 85.5);
    cout << "Details of exam1:" << endl;
    exam1.displayDetails();

    Exam exam2 = exam1; //shallow copy
    cout << "Details of exam2 :" << endl;
    exam2.displayDetails();

    exam1.setScore(92.0); //shallow copy
    cout << "After modifying exam1's score to 92.0:" << endl;
    cout << "Details of exam1:" << endl;
    exam1.displayDetails();
    cout << "Details of exam2 :" << endl;
    exam2.displayDetails();

    return 0;
}
