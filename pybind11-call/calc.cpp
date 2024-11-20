#include <pybind11/pybind11.h>

int add(int a, int b)
{
    return (a + b);
}

double add(double a, double b)
{
    return (a + b);
}

PYBIND11_MODULE(mycalc, m)
{
    m.doc() = "pybind11 add plugin";
    m.def("add", (int (*)(int, int)) &add, "A function which adds two integers");
    m.def("add", (double (*)(double, double)) &add, "A function which adds two doubles");
}
