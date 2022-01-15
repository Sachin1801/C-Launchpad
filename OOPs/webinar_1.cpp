#include <iostream>
using namespace std;

class Complex
{

    int real;
    int img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    //Parameterised constructor
    Complex(const int r, const int i)
    {
        real = r;
        img = i;
    }
    //Copy constructor
    //It exists by default
    void setReal(const int r)
    {
        real = r;
    }
    void setImg(const int i)
    {
        img = i;
    }
    int getReal() const
    {
        return real;
    }
    int getImg() const
    {
        return img;
    }
    void Print() const
    {
        if (img > 0)
        {
            cout << real << " + " << img << "i" << endl;
        }
        else
        {
            cout << real << " - " << -img << "i" << endl;
        }
    }
    void add(const Complex &X)
    {
        real += X.real;
        img += X.img;
    }
    //Operator overload
    void operator+(const Complex &X)
    {
        real += X.real;
        img += X.img;
    }
    void operator!()
    {
        img *= -1;
    }
    void operator[](string s)
    {
        //cout << real << " + " << img << s << endl;
        if (s == "real")
        {
            cout << real;
        }
        else
        {
            cout << img;
        }
    }
};

istream &operator>>(istream &is, Complex &c)
{
    int r1, i1;
    cin >> r1 >> i1;
    c.setImg(i1);
    c.setReal(r1);
    return is;
}

ostream &operator<<(ostream &os, Complex &c)
{
    c.Print();
    return os;
}

int main()
{ /*
    Complex c2(5, 3);
    Complex c1;
    c1.setImg(5);
    c1.setReal(8);
    c1.Print();
    c2.Print();
    //c1.add(c2);
    c1 + c2;
    c1.Print();
    c2.Print();
    !c1;
    c1.Print();
    c1["real"];
    cout << endl;
    */
    //<<,>>
    Complex d1, d2;
    cin >> d1 >> d2;
    cout << d1 << d2;
    return 0;
}