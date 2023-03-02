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
    Pair<Pair<int,int>,int> p1;
    
    Pair<int,int> p2;

    p2.setX(10);
    p2.setY(20);

    p1.setX(p2);
    p1.setY(30);

    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY();
}