#include <pybind11/pybind11.h>
#include <stdio.h>

int add(int a, int b)
{
    printf("---add int.\n");
    return (a + b);
}

double add(double a, double b)
{
    printf("---add dobule.\n");
    return (a + b);
}

PYBIND11_MODULE(mycalc, m)
{
    m.doc() = "pybind11 add plugin";
    m.def("add", (int (*)(int, int)) &add, "A function which adds two integers");
    m.def("add", (double (*)(double, double)) &add, "A function which adds two doubles");
}
