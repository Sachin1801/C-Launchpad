
template <typename T>
class Vector
{
    int cs; //Current size
    int ms; // Maximum size
    T *arr;

public:
    Vector()
    {
        cs = 0;
        ms = 0;
        arr = new T[ms];
    }
    void push_back(T d)
    {
        if (cs == ms)
        {
            T *oldarr = arr;
            arr = new T[2 * ms];
            ms = ms * 2;
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldarr[i];
            }
            //clear the old memory , i.e the temporary old array that we have made
            delete[] oldarr;
        }
        arr[cs] = d;
        cs++;
    }
    void pop_back()
    {
        cs--;
    }
    T front() const
    {
        return arr[0];
    }
    T end() const
    {
        return arr[cs];
    }
    bool empty() const
    {
        return cs == 0;
    }
    int capacity() const
    {
        return ms;
    }
    T at(const int i)
    {
        return arr[i];
    }
    int size()
    {
        return cs;
    }

    //Operator overloading
    T operator[](const int i)
    {
        return arr[i];
    }
};