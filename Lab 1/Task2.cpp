#include <iostream>
#include <string>

class Exam {
private:
    std::string* studentName;
    std::string* examDate;
    int* score;

public:
    // Default constructor
    Exam() {
        studentName = new std::string("N/A");
        examDate = new std::string("N/A");
        score = new int(0);
    }

    // Parameterized constructor
    Exam(const std::string& name, const std::string& date, int s) {
        studentName = new std::string(name);
        examDate = new std::string(date);
        score = new int(s);
    }

    // Destructor
    ~Exam() {
        delete studentName;
        delete examDate;
        delete score;
    }

    // Setters
    void setDetails(const std::string& name, const std::string& date, int s) {
        *studentName = name;
        *examDate = date;
        *score = s;
    }

    // Display method
    void display() {
        std::cout << "Student Name: " << *studentName << std::endl;
        std::cout << "Exam Date: " << *examDate << std::endl;
        std::cout << "Score: " << *score << std::endl;
    }
};

int main() {
    // Create an original Exam object
    Exam originalExam("Ahmad", "2023-10-26", 85);
    std::cout << "Original Exam Details:" << std::endl;
    originalExam.display();
    std::cout << std::endl;

    // Create a shallow copy
    Exam shallowCopy = originalExam;
    std::cout << "Shallow Copy Details (before modification):" << std::endl;
    shallowCopy.display();
    std::cout << std::endl;

    // Modify the shallow copy
    shallowCopy.setDetails("Ali", "2023-11-15", 92);

    // Display both objects to show the issue
    std::cout << "Shallow Copy Details (after modification):" << std::endl;
    shallowCopy.display();
    std::cout << std::endl;

    std::cout << "Original Exam Details (after shallow copy modification):" << std::endl;
    originalExam.display();

    return 0;
}
