#include <iostream>
#include <random>
using namespace std;

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
    return 0;
}
