#include<iostream>

using namespace std;

template <typename T,typename U>

class Pair
{
    T x;
    U y;

    public:

    void setX(T x)
    {
        this->x=x;
    }

    T getX()
    {
        return x;
    }

    void setY(U y)
    {
        this->y=y;
    }

    U getY()
    {
        return y;
    }
};

int main()
{
    Pair<int,double> p1;
    p1.setX(10);
    p1.setY(20.2);

    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<double,char> p2;
    p2.setX(10.1);
    p2.setY('a');

    cout<<p2.getX()<<" "<<p2.getY();
}