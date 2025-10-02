// test_vector_iterator.cpp
// #define CATCH_CONFIG_MAIN // must be in one
#include "catch2/catch.hpp"
#include <algorithm>  //for std::max
#include "vector.hpp"
#include "matrix.hpp"

TEST_CASE("non-const iterator dereference") {
    dsa::Vector<int> v; bool ok{true};
    for (int i{1}; i<=5; i++) 
        v.push_back(i);
    auto it = v.begin();
    ok = ok && (*it == 1);
    *it = 10;
    ok = ok && (v[0] == 10);
    
    REQUIRE(ok);
}
TEST_CASE("non-const forward iterating"){
    // create vector for test cases
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) 
        v.push_back(i);
    dsa::Vector<int>::iterator i = v.begin();
    REQUIRE(*i == 0);
    ++i;
    REQUIRE(*i == 1);
    ++i;
    REQUIRE(*i == 2);
    ++i;
    REQUIRE(*i == 3);
    ++i;
    REQUIRE(*i == 4);
}
TEST_CASE("non-const backward iterating"){
    // create vector for test cases
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) 
        v.push_back(i);
    dsa::Vector<int>::iterator i = v.end();
    --i;
    REQUIRE(*i == 4);
    --i;
    REQUIRE(*i == 3);
    --i;
    REQUIRE(*i == 2);
    --i;
    REQUIRE(*i == 1);
    --i;
    REQUIRE(*i == 0);
}
TEST_CASE("non-const equal and not equal iterator"){
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) 
        v.push_back(i);
    dsa::Vector<int>::iterator i1 = v.begin();
    dsa::Vector<int>::iterator i2 = v.end();
    --i2;
    REQUIRE(i1!=i2);
    ++i1;
    --i2;
    REQUIRE(i1!=i2);
    ++i1;
    --i2;
    REQUIRE(i1==i2);
}
TEST_CASE("non-const -> operator"){
        struct Point {
            int x, y;
        };
        dsa::Vector<Point> points;
        points.push_back({1, 2});
        points.push_back({3, 4});

        dsa::Vector<Point>::iterator i = points.begin();
        REQUIRE(i->x == 1);
        REQUIRE(i->y == 2);

        ++i;
        REQUIRE(i->x == 3);
        REQUIRE(i->y == 4);

        REQUIRE(points.at(1).x == 3);
        i->x = 12;
        REQUIRE(points.at(1).x == 12);
}
TEST_CASE("const iterator dereference") {
    dsa::Vector<int> v; bool ok{true};
    for (int i{1}; i<=5; i++) 
        v.push_back(i);
    const dsa::Vector<int> vc = v;
    dsa::Vector<int>::const_iterator it = vc.begin();
    REQUIRE(*it == 1);
}
TEST_CASE("const forward iterating"){
    // create vector for test cases
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) 
        v.push_back(i);
    const dsa::Vector<int> vc = v;
    dsa::Vector<int>::const_iterator i = vc.begin();
    REQUIRE(*i == 0);
    ++i;
    REQUIRE(*i == 1);
    ++i;
    REQUIRE(*i == 2);
    ++i;
    REQUIRE(*i == 3);
    ++i;
    REQUIRE(*i == 4);
}
TEST_CASE("const backward iterating"){
    // create vector for test cases
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) 
        v.push_back(i);
    const dsa::Vector<int> vc = v;
    dsa::Vector<int>::const_iterator i = vc.end();
    --i;
    REQUIRE(*i == 4);
    --i;
    REQUIRE(*i == 3);
    --i;
    REQUIRE(*i == 2);
    --i;
    REQUIRE(*i == 1);
    --i;
    REQUIRE(*i == 0);
}
TEST_CASE("const equal and not equal iterator"){
    dsa::Vector<int> v;
    for (int i{0}; i < 5; ++i) 
        v.push_back(i);
    const dsa::Vector<int> vc = v;
    dsa::Vector<int>::const_iterator i1 = vc.begin();
    dsa::Vector<int>::const_iterator i2 = vc.end();
    --i2;
    REQUIRE(i1!=i2);
    ++i1;
    --i2;
    REQUIRE(i1!=i2);
    ++i1;
    --i2;
    REQUIRE(i1==i2);
}
TEST_CASE("const -> operator"){
        struct Point {
            int x, y;
        };
        dsa::Vector<Point> points;
        points.push_back({1, 2});
        points.push_back({3, 4});

        const dsa::Vector<Point> const_points = points;

        dsa::Vector<Point>::const_iterator i = const_points.begin();
        REQUIRE(i->x == 1);
        REQUIRE(i->y == 2);

        ++i;
        REQUIRE(i->x == 3);
        REQUIRE(i->y == 4);

        REQUIRE(points.at(1).x == 3);
}