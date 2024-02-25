
/*

Author: Austin Stephens

Date: 04/13/2022

FileName: modifiedAdressBookVec.cpp

Purpous: Module 02 Assignemnt, Prebuilt Classes

Input: Menu Selection Based on Input

Output: Either menu item or concepts of entering in adress information
Exceptiuons: 
 
    
    Rules:

Modify the Vector address book program you created in the previous module by creating a Person Class, 
an Employer Class and a Personal Info Class. 

Use the Employer and PersonalInfo classes as member variables of a Person class. 

Modify the Vector class to hold People objects instead of Record objects. 

Modify the menu interface and input algorithms to accept data for the Employer and 
Personal Info classes via functions in the Person class. 

Modify the Output to print all the information in each Person object, associated Employer object, 
and associated Personal Info object. 

*/


//librarys
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;


//-----------------------------------------------------------------------------------------------


class Employer
{
    private:
        char *Company;
    public:
        Employer()
        {
           Company = new char[20];
        }
    void getCompany();
    void setCompany();
};

class PersonalInfo
{

    private:
        
        long *PhoneNumber;
        int *Age, *PersonNumber;
    public:
        PersonalInfo()
        {
            PhoneNumber = new long;
            Age = new int;
            PersonNumber = new int;
        }

    void ShowPerson();
    void datafeed();

};

class Person
{
    private:
        char *FirstName,*LastName;
    public: 
        Person()
        {
        FirstName = new char[20];
        LastName = new char[20];
        }   
    
    void GetPerson();
    void SetPerson();
};



//-----------------------------------------------------------------------------------------------------------

void printLines()
{
    cout << "-------------------------" << endl;
}


void Person::GetPerson()
{
    cout << "   First Name: " << FirstName << endl;
    cout << "    Last Name: " << LastName << endl;
}

void Person::SetPerson()
{
    cin.ignore();
    cout << "Enter First Name: " << endl;
    cin.getline(FirstName, 20);
    cout << "Enter Last Name; " << endl;
    cin.getline(LastName, 20);
}

void Employer::getCompany()
{
    cout << "      Company: " << endl;
}

void Employer::setCompany()
{
    cin.ignore();
    cout << "Please Enter Company Name: " << endl;
    cin.getline(Company, 20);
}


void PersonalInfo::ShowPerson()
{
    printLines();
    cout << "          Age: " << *Age << endl;
    cout << " Phone Number: " << *PhoneNumber << endl;
    cout << "Record-Number: " << *PersonNumber << endl;
    printLines();
}

void PersonalInfo::datafeed()
{
    cout << "Enter Age: " << endl;
    cin >> *Age;
    cout << "Enter Phone Number: " << endl;
    cin >> *PhoneNumber;
    cout << "Enter Record Number: " << endl;
    cin >> *PersonNumber;
}




//---------------------------------------------------------------------------------------------------------------


//main
int main()
{
    PersonalInfo *B[20]; 
    Employer *E[20]; Person *P[20];
    int Choice, i=0, j;
    array<string , 1> line;
   
    //vector
    vector<int> numbers;
    line[1] = {"-------------------------"};


    //Vector added
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    
    while (1)
    {
        printLines();
        //vector implemented
        cout << numbers[0] << ". Input information into an record" << endl;
        cout << numbers[1] << ". Display all information in all records" << endl;
        cout << numbers[2] << ". Exit the program" << endl;
        printLines();
        cin >> Choice;


        switch (Choice)
        {
            //new Person creation
        case 1:
            B[i] = new PersonalInfo;
            E[i] = new Employer;
            P[i] = new Person;
            B[i]-> datafeed();
            E[i]-> setCompany();
            P[i]-> SetPerson();
            i++;
            break;

        case 2:
            //loop to repeat functions, wont show if no records have been created
            cin.ignore();
            for (int j = 0; j < i; j++)
            {
                B[j]-> ShowPerson();
                E[j]->getCompany();
                P[j]->GetPerson();
            }
            break;

            
            
            //exit
        case 3:
            exit(0);
        default:

        //exception handling *Added in week2*
            try
            {
                if (Choice != '1' || '2' || '3')
                {
                    throw 99;
                }
                
            }
            catch(int x)
            {
                cout << "\n Invalid Choice Entered: ERROR: " << x << endl;
                cout << line[1] << endl;
            }
            
        }
    }
    return 0;
}