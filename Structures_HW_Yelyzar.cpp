#include <iostream>
#include <vector>
#include <numeric>

class Student {

private:
    std::string name;
    std::string surname;
    std::string album_number;
    std::vector<float> grades;
    float final_grade = 0.0f;

public:

    Student(std::string n, std::string s, std::string album) {
        name = n;
        surname = s;
        set_album_number(album);
    }

    void set_name(std::string n) {
        name = n;
    }

    void set_surname(std::string s) {
        surname = s;
    }

    bool is_valid_album(const std::string& album) {
        if (album.length() < 5 || album.length() > 6)
            return false;

        for (char c : album) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }

    bool set_album_number(std::string album) {
        if (is_valid_album(album)) {
            album_number = album;
            return true;
        }
        return false;
    }

    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    void calculate_grade() {
        if (!grades.empty())
        {
            final_grade = std::accumulate(grades.begin(), grades.end(), 0.0f) / grades.size();
        }
    }

    bool passed_semester() {
        int count_2s = std::count(grades.begin(), grades.end(), 2.0f);
        return count_2s <= 1;
    }

    void print() {
        std::cout << "Student: " << name << " " << surname << " (Album: " << album_number << ")\n";
        std::cout << "Grades: " <<"\n";

        for (float g : grades) {
            std::cout << g << " " << "\n";
        }
        std::cout << "\nFinal grade: " << final_grade << "\n";
        std::cout << "\nPassed semester: ";
        if (passed_semester()) {
            std::cout << "Yes";
        }
        else {
            std::cout << "No";
        }
        std::cout << "\n";
    }
};

class Complex {

private:
    double real;
    double imag;

public:
    Complex(double r, double i = 0.0) : real(r), imag(i) {}

    void set_real(double r) { 
        real = r; 
    }

    void set_imag(double i) { 
        imag = i; 
    }

    double get_real() { 
        return real; 
    }

    double get_imag() { 
        return imag; 
    }

    Complex add(const Complex& n) {
        return Complex(real + n.real, imag + n.imag);
    }

    Complex add(double number) {
        return Complex(real + number, imag);
    }
    void print() {
        std::cout << real << (imag >= 0 ? "+" : "") << imag << "i\n";
    }
};

int main() {

    Student student("Yelyzar", "Pashchenko", "163650");

    student.add_grade(5.0);
    student.add_grade(4.0);
    student.add_grade(5.0);
    student.add_grade(4.5);
    student.add_grade(3.0);
    student.add_grade(3.0);
    student.add_grade(3.0);
    student.add_grade(5.0);
    student.add_grade(5.0);
    student.add_grade(5.0);

    student.calculate_grade();
    student.print();

    Complex a(1.0, -2.0);
    Complex b(3.14);
    b.set_imag(-5);
    Complex c = a.add(b);
    c.print();

    return 0;
}