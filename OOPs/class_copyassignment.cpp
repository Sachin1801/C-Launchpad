#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    float price;

public:
    int modelno;
    char *name;

    Car()
    {
        name = NULL;
    }
    Car(float p, int m, char *n)
    {
        price = p;
        modelno = m;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Car(Car &X)
    {
        cout << "Inside copy constructor " << endl;
        price = X.price;
        modelno = X.modelno;
        //This is how we create a deep copy
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
    }

    void operator=(Car &X)
    {
        price = X.price;
        modelno = X.modelno;
        //This is how we create a deep copy
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
    }

    void
    setprice(float p)
    {
        price = p;
    }
    void print()
    {
        cout << " Name " << name << endl;
        cout << " Model No " << modelno << endl;
        cout << " Price of the car is " << price << endl;
    }
};

int main()
{
    Car c(100, 200, "BUDI"); //Calling parametrised constructor
    Car d(c);
    d = c; // Here the copy assignment operator is called and not the copy constructor
    d.name[0] = 'A';
    d.setprice(400); // Calling copy constructor
    c.print();
    d.print();
    return 0;
}