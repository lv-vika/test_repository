/*Замкнутий двонаправлений зв’язаний список
Працівник :
П.І.Б., освіта, спеціальність, стаж, рік народження
добавлення елемента в кінець списку;
сортування списку за зростанням стажу методом вставки;
пошук працівника за прізвищем та вивід його даних*/

#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string name;
    string education;
    string occupation;
    int experience;
    int birth;
    public:
        Employee(string xName, string xEducation, string xOccupation, int xExperience, int xBirth);
        Employee(Employee* xEmployee);
        string getName();
        string getEducation();
        string getOccupation();
        int getExperience();
        int getBirth();
        void showData();
}; 

Employee::Employee(string xName, string xEducation, string xOccupation, int xExperience, int xBirth){
    name = xName;
    education = xEducation;
    occupation = xOccupation;
    experience = xExperience;
    birth = xBirth;
}

Employee::Employee(Employee* xEmployee) {
    name = xEmployee->name;
    education = xEmployee->education;
    occupation = xEmployee->occupation;
    experience = xEmployee->experience;
    birth = xEmployee->birth;
}

string Employee::getName() {
    return name;
}

string Employee::getEducation() {
    return education;
}

string Employee::getOccupation() {
    return occupation;
}

int Employee::getExperience() {
    return experience;
}

int Employee::getBirth() {
    return birth;
}

void Employee::showData() {
    cout << "Name " << name << endl << "education  " << education << endl << "occupation  " << occupation << endl << "experience " << experience << endl << "birth " << birth << endl;
}

class List {
public:
    Employee* employee;
    List* prev;
    List* next;
        List(Employee *xCurrent);
        void addItem(List* current, Employee* newEmployee);
        void print();

};

List::List(Employee* xEmployee) {
    employee = new Employee(xEmployee);
    prev = NULL;
    next = NULL;
}

void List::addItem(List* current, Employee* xEmployee) {
    List* temp, *p;
    temp = (List*)malloc(sizeof(List));
    p = current->next;
    current->next = temp;
    temp->employee = new Employee(xEmployee);
    temp->next = p;
    temp->prev = current;
    if (p != NULL)
        p->prev = temp;
}

void List::print() {
    List* temp = this;
    do {
        temp->employee->showData();
        temp = temp->next;
    } while (temp != NULL); // условие окончания обхода
}

int main()
{
    Employee* item = new Employee("VIKA", "Employee", "progger", 1, 2003);
    Employee* item_two = new Employee("VIKA1", "Employee1", "progger1", 2, 2005);
    Employee* item_three = new Employee("VIKA2", "Employee2", "progger2", 2, 2005);
    List* list = new List(item);
    list->addItem(list, item_two);
    list->addItem(list, item_three);
    list->print();
}

