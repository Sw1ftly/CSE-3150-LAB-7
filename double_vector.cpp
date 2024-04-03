#include "double_vector.h"

double square(const double & d) {
    return d * d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double result = 0.0;
    for (size_t i = 0; i < one.elements.size(); ++i) {
        result += one.elements[i] * two.elements[i];
    }
    return result;
}

double magnitude(const double_vector & my_vector) {
    double sum = 0.0;
    for (double elem : my_vector.elements) {
        sum += square(elem);
    }
    return sqrt(sum);
}

double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot = dot_product(one, two);
    double magOne = magnitude(one);
    double magTwo = magnitude(two);
    return 1.0 - (dot / (magOne * magTwo));
}