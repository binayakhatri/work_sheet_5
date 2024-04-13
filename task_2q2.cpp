#include <iostream>
#include <fstream>

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

    // Read data from a file
    void readDataFromFile(ifstream& inFile)
    {
        inFile.read(reinterpret_cast<char*>(this), sizeof(Employee));
    }

    // Write data to a file
    void writeDataToFile(ofstream& outFile)
    {
        outFile.write(reinterpret_cast<char*>(this), sizeof(Employee));
    }

    // Check if the salary is greater than a given amount
    bool salaryGreat(double money) const
    {
        return salary > money;
    }

    // Get the salary
    double getSalary() const
    {
        return salary;
    }
};

int main()
{
    // Open the input file to read employee data
    ifstream inFile("test.bin", ios::binary);
    if (!inFile)
    {
        cout << "Error occurred while opening the file." << endl;
        return 1;
    }

    // Open the output file to write employee data
    ofstream outFile("data.bin", ios::binary);
    if (!outFile)
    {
        cout << "Error occurred while opening the file." << endl;
        return 1;
    }

    double amount;
    cout << "Enter the salary amount: ";
    cin >> amount;

    // Read employee data from test.bin and write to data.bin
    Employee e1;
    double wholeSalary = 0.0;
    int count = 0;
    while (inFile.read(reinterpret_cast<char*>(&e1), sizeof(Employee)))
    {
        if (e1.salaryGreat(amount))
        {
            e1.writeDataToFile(outFile);
            wholeSalary += e1.getSalary();
            count++;
        }
    }

    // Close the files
    inFile.close();
    outFile.close();

    // Calculate and display the average salary of employees
    double salaryOfEmployees = (count > 0) ? wholeSalary / count : 0.0;
    cout << "Average salary of the employees with a salary greater than " << amount << ": " << salaryOfEmployees << endl;
    return 0;
}
