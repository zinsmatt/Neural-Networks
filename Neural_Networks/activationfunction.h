#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H

#include <limits>

class ActivationFunction
{
    double coef;    // coefficient that multiplies x (not used for step)
public:

    enum ActivationFunctionENUM{
        STEP, LINEAR, SIGMOID, HYPERTAN
    };

    ActivationFunctionENUM type;

    ActivationFunction(ActivationFunctionENUM _type, double _coef = 1.0) : type(_type), coef(_coef) {}

    double operator()(double value) const;   // compute the output
    double derivative(double value) const;  // compute the derivative
};

/*class Step : public ActivationFunction
{
    double operator ()(double x) const
    {
        if(x<0)
            return 0.0;
        else
            return 1.0;
    }

    double derivative(double value) const
    {
        if(x==0)
            return std::numeric_limits<double>::max();
        else
            return 0.0;
    }
};

class Linear : public ActivationFunction
{
    double coef;    // coefficient that multiplies x

public:
    Linear(double c = 1.0) : coef(c) {}

    void setCoef(double c) { coef = c; }

    double operator ()(double x) const { return coef*x; }

    double derivative(double value) const { return coef; }
};

class Sigmoid : public ActivationFunction
{
    double coef;
public:
    Sigmoid(double c = 1.0) : coef(c) {}

    void setCoef(double c) { coef = c; }

    double operator ()(double x) const { return 1.0 / (1.0 + exp(-coef * x)); }

    double derivative(double value) const { return *this(x)*(1.0-*this(x)); }
};

class HyperTan : public ActivationFunction
{
    double coef;
public:
    HyperTan(double c = 1.0) : coef(c) {}

    void setCoef(double c) { coef = c; }

    double operator ()(double x) const { return (1.0-exp(-coef*x))/(1.0+exp(-coef*x)); }

    double derivative(double value) const { return 1.0-pow(*this(x),2.0); }
};*/

#endif // ACTIVATIONFUNCTION_H
