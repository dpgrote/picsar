//####### Test module for rng_wrapper ####################################

//Define Module name
 #define BOOST_TEST_MODULE "RNG wrapper"

//Will automatically define a main for this test
 #define BOOST_TEST_DYN_LINK

#include <cstdint>
 #include <random>

//Include Boost unit tests library
#include <boost/test/unit_test.hpp>

//Units choice. Not relevant here, but avoids compile-time warning
#define PXRMP_USE_SI_UNITS
#include "rng_wrapper.hpp"

using namespace picsar::multi_physics;

// ------------- Tests --------------

//***Constructors

//Test STL rng_wrapper constructors test (double precision)
BOOST_AUTO_TEST_CASE( rng_stl_wrapper_constructors_double )
{
    int64_t seed = 2391892344079;
    std::mt19937_64 rng{2391892344079};

    stl_rng_wrapper<double> wrp1{seed};
    stl_rng_wrapper<double> wrp2(move(rng));

    BOOST_CHECK_EQUAL( wrp1.unf(0.0,1.0), wrp2.unf(0.0,1.0));
}

//Test STL rng_wrapper constructors test (single precision)
BOOST_AUTO_TEST_CASE( rng_stl_wrapper_constructors_single )
{
    int64_t seed = 2391892344079;
    std::mt19937_64 rng{2391892344079};

    stl_rng_wrapper<float> wrp1{seed};
    stl_rng_wrapper<float> wrp2(move(rng));

    BOOST_CHECK_EQUAL( wrp1.unf(0.0f,1.0f), wrp2.unf(0.0f,1.0f));
}

//***Uniform distribution

//Test STL rng_wrapper unf (double precision)
BOOST_AUTO_TEST_CASE( rng_stl_wrapper_unf_double )
{
    int64_t seed = 2391892344079;
    stl_rng_wrapper<double> wrp{seed};
    size_t how_many = 10000;
    double a = -7.0;
    double b = 11.1;

    for (size_t d = 0; d <= how_many; ++d){
        double qq = wrp.unf(a,b);
        BOOST_TEST( qq >= a);
        BOOST_TEST( qq < b);
    }
}

//Test STL rng_wrapper unf (single precision)
BOOST_AUTO_TEST_CASE( rng_stl_wrapper_unf_single )
{
    int64_t seed = 2391892344079;
    stl_rng_wrapper<float> wrp{seed};
    size_t how_many = 10000;
    float a = -7.0f;
    float b = 11.1f;

    for (size_t d = 0; d <= how_many; ++d){
        float qq = wrp.unf(a,b);
        BOOST_TEST( qq >= a);
        BOOST_TEST( qq < b);
    }
}

//Test STL rng_wrapper exp (double precision)
BOOST_AUTO_TEST_CASE( rng_stl_wrapper_exp_double )
{
    int64_t seed = 2391892344079;
    stl_rng_wrapper<double> wrp{seed};
    size_t how_many = 10000;
    double l = 1.0f;

    for (size_t d = 0; d <= how_many; ++d){
        double qq = wrp.exp(l);
        BOOST_TEST( qq >= 0.0);
    }
}

//Test STL rng_wrapper exp (single precision)
BOOST_AUTO_TEST_CASE( rng_stl_wrapper_exp_single )
{
    int64_t seed = 2391892344079;
    stl_rng_wrapper<float> wrp{seed};
    size_t how_many = 10000;
    float l = 1.0f;

    for (size_t d = 0; d <= how_many; ++d){
        double qq = wrp.exp(l);
        BOOST_TEST( qq >= 0.0f);
    }
}


//***Exponential distribution
