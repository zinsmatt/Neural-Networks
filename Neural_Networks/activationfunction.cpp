#include "activationfunction.h"
#include <iostream>
#include <limits>

using namespace std;

double ActivationFunction::operator ()(double value) const
{
    switch(type)
    {
    case STEP:
        if(x<0)
            return 0.0 ;
        else
            return 1.0;
    case LINEAR:
        return coef*x;
    case SIGMOID:
        return 1.0 / (1.0 + exp(-coef * x));
    case HYPERTAN:
        return (1.0-exp(-coef*x))/(1.0+exp(-coef*x));;
    default:
        cerr << "ActivationFunction::operator()(double): invalid type of function" << endl;
        return 0.0;
    }
}


double ActivationFunction::derivative(double value) const
{
    switch(type)
    {
    case STEP:
        if(x==0)
            return numeric_limits<double>::max();
        else
            return 0.0;
    case LINEAR:
        return coef;
    case SIGMOID:
        return *this(x)*(1.0-*this(x));
    case HYPERTAN:
        return 1.0-pow(*this(x),2.0);;
    default:
        cerr << "ActivationFunction::operator()(double): invalid type of function" << endl;
        return 0.0;
    }
}
