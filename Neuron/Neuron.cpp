#include <iostream.h>
#include <math.h>
#include <stdio.h>

#define e 2.7182818284;

class Neuron
{
public:
    int n;
    double *w;
    double (*activation)(double);

    Neuron(int num_of_sinopses, double (*activation)(double))
    {
        n = num_of_sinopses;
        w = new double[n];
        this->activation = activation;
    }

    void set_weight(int i, double value)
    {
        w[i] = value;
    }

    double get_axon(double *x) //x - sinopses
    {
        double h = 0;
        for(int i=0;i<n;i++)
        {
            h += w[i]*x[i];
        }
        return activation(h);
    }

    // конструктор копирования
    Neuron(const Neuron &neur_in)
    {
        n = neur_in.n;
        w = new double[n];
        activation = neur_in.activation;
        for(int i=0;i<n;i++)
            w[i] = neur_in.w[i];
    }

    // конструктор присваивания
    Neuron& Neuron::operator= (const Neuron &neur_in)
    {
        if (&neur_in == this)
            return *this;
        delete w;
        n = neur_in.n;
        w = new double[n];
        activation = neur_in.activation;
        for(int i=0;i<n;i++)
            w[i] = neur_in.w[i];
        return *this;
    }

    // деструктор
    ~Neuron()
    {
        delete w;
    }

};

double normalize_1(double x)
{
    return 1/(1+exp(-x));
}

int main()
{
    int n = 1000;
    Neuron a = Neuron(n,normalize_1);

    double *x;
    x = new double[n];
    for(int i=0;i<n;i++)
        x[i] = i;

    a.set_weight(0,0);
    for(int i=1;i<n;i++)
        a.set_weight(i, 1/(double) i);

    Neuron b = a;
    a = b;
    // проверка присваивания на утечку памяти
    for(int i=0;i<1000;i++)
        a = a;
    b = a;

    cout << a.w[4] << ", " << x[4] << '\n';
    cout << a.get_axon(x) << endl;
    cout << b.w[4] << ", " << x[4] << '\n';
    cout << b.get_axon(x) << endl;

    return 0;
}
