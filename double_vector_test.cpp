#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("Vector Magnitude Calculation") {
    vector<double> v1{1, 0, 0};
    double_vector dv1(v1, 0);
    CHECK(magnitude(dv1) == doctest::Approx(1.0).epsilon(0.01));

    vector<double> v2{3, 4, 0};
    double_vector dv2(v2, 1);
    CHECK(magnitude(dv2) == doctest::Approx(5.0).epsilon(0.01));
}

TEST_CASE("Cosine Distance Calculation") {
    vector<double> v1{1, 0, 0};
    double_vector dv1(v1, 0);

    vector<double> v2{0, 1, 0};
    double_vector dv2(v2, 1);

    vector<double> v3{1, 1, 0};
    double_vector dv3(v3, 2);

    CHECK(cosine_distance(dv1, dv2) == doctest::Approx(1.0).epsilon(0.01)); // Orthogonal vectors
    CHECK(cosine_distance(dv1, dv3) == doctest::Approx(0.292893).epsilon(0.01)); // 45-degree angle
}