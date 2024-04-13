#include <iostream>
#include <fstream>
#include <cstring> //for strcmp
using namespace std;

class Employee
{
    char name[150];
    int tax_Number;
    double salary;

public:
    Employee()
    {
        tax_Number = 0;
        salary = 0.0;
    }

    void setName(const char* empName)
    {
        strncpy(name, empName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null-termination
    }

    const char* getName() const
    {
        return name;
    }

    void getData()
    {
        cout << "Enter employee name: ";
        cin.getline(name, 150);
        if (strcmp(name, "fin") == 0)
            return;
        cout << "Enter the tax number: ";
        cin >> tax_Number;
        cout << "Enter the salary of the employee: ";
        cin >> salary;
        cin.ignore();
    }

    void displayData()
    {
        cout << "Employee name is: " << name << endl;
        cout << "Tax Number is: " << tax_Number << endl;
        cout << "Salary of the employee is " << salary << endl;
    }

    void writeDataToFile(ofstream& outFile)
    {
        outFile.write(reinterpret_cast<char*>(this), sizeof(Employee));
    }
};

void writeEmployeeData(Employee* e1, int numEmployees)
{
    // Writes data of employees into a binary file
    ofstream outFile("test.bin", ios::binary);
    if (!outFile)
    {
        cout << "Error occurred while opening the file." << endl;
        return;
    }

    for (int i = 0; i < numEmployees; i++)
    {
        e1[i].writeDataToFile(outFile);
    }
    outFile.close();
}

int main()
{
    Employee e1[5]; // Array of 50 employees

    // For Reading data of employees
    int numEmployees = 0;
    while (numEmployees < 50)
    {
        e1[numEmployees].getData();
        if (strcmp(e1[numEmployees].getName(), "fin") == 0) // Check termination condition
            break;
        numEmployees++;
    }

    // Write the employee data to a binary file
    writeEmployeeData(e1, numEmployees);

    // Display employee data
    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Employee " << i + 1 << ":" << endl;
        e1[i].displayData();
        cout << endl;
    }

    return 0;
}

