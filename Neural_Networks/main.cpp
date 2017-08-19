#include <iostream>
#include <random>
using namespace std;

class Fnc
{
public:
    ~Fnc() { cout << "destructor : "; print(); }
    int x;
    Fnc() { cout << "default constructor" << endl; }
    Fnc(int i) : x(i) { cout << "constructor with int" << endl; }
    void print() { cout << "Fnc adr : " << (void*)this << endl; }
};

class Object
{
public:
    Fnc& f;
    Fnc* ptf;
public:
    Object(Fnc& _f, Fnc* _pt) : f(_f), ptf(_pt) {}
    void print() {
        cout << f.x << endl; cout << ptf->x << endl;
        f.print();
        ptf->print();
        }
};


Object function()
{

    Object o(std::move(Fnc({32})),&Fnc({22}));
    o.print();


    o.print();



    return o;
}



int main(int argc, char *argv[])
{



    cout << "Hello World!" << endl;

    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(0,1);
    for(int i=0;i<8;i++)
    {
        cout << distribution(generator) << endl;
    }


    Object out = function();
    out.print();
    out.print();
    cout << "----------------\n";
    cout << out.f.x << endl;
    cout << out.ptf->x << endl;
    cout << "-------------\n";
    return 0;
}
