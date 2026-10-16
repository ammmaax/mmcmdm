#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int age;
    int course;

public:
    Student() : name("Unknown"), age(17), course(1) {}

    Student(string name, int age, int course)
    {
        this->name = name;
        this->age = age;
        this->course = course;
    }

    string GetName() const
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    int GetAge() const
    {
        return age;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    int GetCourse() const
    {
        return course;
    }

    void SetCourse(int course)
    {
        this->course = course;
    }

    void Input()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter course: ";
        cin >> course;
    }

    void Output() const
    {
        cout << "Name: " << name
             << "  Age: " << age
             << "  Course: " << course << endl;
    }
};
istream& operator>>(istream& in, Student& obj)
{
    string name;
    int age;
    int course;

    cout << "Enter name: ";
    in >> name;

    cout << "Enter age: ";
    in >> age;

    cout << "Enter course: ";
    in >> course;
    if (in)
    {
        obj.SetName(name);
        obj.SetAge(age);
        obj.SetCourse(course);
    }

    return in;
}
ostream& operator<<(ostream& out, const Student& obj)
{
    out << "Name: " << obj.GetName()
        << "  Age: " << obj.GetAge()
        << "  Course: " << obj.GetCourse();

    return out;
}

Student operator++(Student& obj, int)
{
    Student temp = obj;
    obj.SetCourse(obj.GetCourse() + 1);
    return temp;
}

Student& operator--(Student& obj)
{
    obj.SetCourse(obj.GetCourse() - 1);
    return obj;
}

Student& operator+=(Student& obj, int value)
{
    obj.SetAge(obj.GetAge() + value);
    return obj;
}

Student& operator-=(Student& obj, int value)
{
    obj.SetAge(obj.GetAge() - value);
    return obj;
}

int main()
{
    Student obj1;

    cin >> obj1;
    cout << obj1 << '\n';

    return 0;
}
