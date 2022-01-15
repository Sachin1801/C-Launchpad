#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Car
{
public:
    string car_name;
    int x;
    int y;
    Car()
    {
    }
    Car(string name, int x, int y)
    {
        car_name = name;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        //this returns the square of the distance of car from the origin
        return x * x + y * y;
    }
};

bool compare(Car A, Car B)
{
    int da = A.dist();
    int db = B.dist();
    if (da == db)
    {
        return A.car_name < B.car_name; // Sorting based on the name of the car if the total distance is same of any 2 cars
    }
    return da < db; // else it is sorted on the basis of the distance from the origin
}

int main()
{
    int n;
    cin >> n;
    vector<Car> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        string name;
        cin >> name >> x >> y;
        Car temp(name, x, y);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);

    //For each loop
    for (auto c : v)
    {
        cout << "Name " << c.car_name << " Distance " << c.dist() << " Location " << c.x << "," << c.y << endl;
    }
    return 0;
}