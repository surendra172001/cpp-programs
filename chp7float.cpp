#include<iostream>
using namespace std;

class FLOAT
{
    float y;
public:
    FLOAT(){}
    FLOAT(float x):y(x){}
    friend FLOAT operator +(FLOAT,FLOAT);
    friend FLOAT operator -(FLOAT,FLOAT);
    friend FLOAT operator /(FLOAT,FLOAT);
    friend FLOAT operator *(FLOAT,FLOAT);
    void putdata()
    {
        cout<<"y : "<<y<<endl;
    }
};

FLOAT operator +(FLOAT x,FLOAT z)
{
    FLOAT t;
    t.y=(x.y)+z.y;
    return t;
}

FLOAT operator -(FLOAT x,FLOAT z)
{
    FLOAT t;
    t.y=x.y-z.y;
    return t;
}

FLOAT operator /(FLOAT x,FLOAT z)
{
    FLOAT t;
    t.y=x.y/z.y;
    return t;
}

FLOAT operator *(FLOAT x,FLOAT z)
{
    FLOAT t;
    t.y=x.y*z.y;
    return t;
}




int main()
{
    FLOAT a(10),b(15),c,d,e,f;
    c=a+b;
    d=a-b;
    e=a/b;
    f=a*b;
    a.putdata();
    b.putdata();
    c.putdata();
    d.putdata();
    e.putdata();
    f.putdata();
    return 0;
}