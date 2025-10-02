// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.hpp"
#include <stdexcept>

// test cases from Part 1

TEST_CASE("Empty vector test", "[empty]") {
    dsa::Vector<int> v;
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.size() == 0);
    REQUIRE(v.empty());
}
TEST_CASE("Push back Test","[pushback]") {
    dsa::Vector<int> v;
    v.push_back(10);
    REQUIRE(v.size() == 1);
    REQUIRE(v.capacity() == 1);
    REQUIRE(v.at(0) == 10);
    REQUIRE(!v.empty());

    v.push_back(5);
    REQUIRE(v.size() == 2);
    REQUIRE(v.capacity() == 2);
    REQUIRE(v.at(1) == 5);
    REQUIRE(!v.empty());


    v.push_back(16);
    REQUIRE(v.size() == 3);
    REQUIRE(v.capacity() == 4);
    REQUIRE(v.at(2) == 16);
    REQUIRE(!v.empty());


    REQUIRE(v.front() == 10);
    REQUIRE(v.back() == 16);
}
TEST_CASE("Insert Test","[insert]") {
    dsa::Vector<int> v;
    REQUIRE_THROWS(v.insert(1,10));
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());

    v.insert(0,10);
    REQUIRE(v.size() == 1);
    REQUIRE(v.capacity() == 1);
    REQUIRE(v.at(0) == 10);
    REQUIRE(!v.empty());


    v.insert(0,9); // front
    REQUIRE(v.size() == 2);
    REQUIRE(v.capacity() == 2);
    REQUIRE(v.at(0) == 9);
    REQUIRE(v.at(1) == 10);
    REQUIRE(!v.empty());

    v.insert(1,13); // middle
    REQUIRE(v.size() == 3);
    REQUIRE(v.capacity() == 4);
    REQUIRE(v.at(0) == 9);
    REQUIRE(v.at(1) == 13);
    REQUIRE(v.at(2) == 10);
    REQUIRE(!v.empty());

    v.insert(3,16); // end
    REQUIRE(v.size() == 4);
    REQUIRE(v.capacity() == 4);
    REQUIRE(v.at(0) == 9);
    REQUIRE(v.at(1) == 13);
    REQUIRE(v.at(2) == 10);
    REQUIRE(v.at(3) == 16);
    REQUIRE(!v.empty());

    v.insert(1,42); // resize
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 8);
    REQUIRE(v.at(0) == 9);
    REQUIRE(v.at(1) == 42);
    REQUIRE(v.at(2) == 13);
    REQUIRE(v.at(3) == 10);
    REQUIRE(v.at(4) == 16);
    REQUIRE(!v.empty());

    REQUIRE(v.front() == 9);
    REQUIRE(v.back() == 16);
}
TEST_CASE("Pop back test","[popback]") {
    dsa::Vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.pop_back();
    REQUIRE(!v.empty());
    REQUIRE(v.size()== 5);
    REQUIRE(v.capacity()== 8);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 4);

    v.pop_back();
    REQUIRE(!v.empty());
    REQUIRE(v.size()== 4);
    REQUIRE(v.capacity()== 8);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 3);

    v.pop_back();
    REQUIRE(!v.empty());
    REQUIRE(v.size()== 3);
    REQUIRE(v.capacity()== 8);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 2);

    v.pop_back();
    REQUIRE(!v.empty());
    REQUIRE(v.size()== 2);
    REQUIRE(v.capacity()== 4);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 1);

    v.pop_back();
    REQUIRE(!v.empty());
    REQUIRE(v.size()== 1);
    REQUIRE(v.capacity()== 2);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 0);

    v.pop_back();
    REQUIRE(v.empty());
    REQUIRE(v.size()== 0);
    REQUIRE(v.capacity()== 1);


}
TEST_CASE("Erase test","[erase]") {
    dsa::Vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v.erase(0);
    REQUIRE(!v.empty()); //beginning
    REQUIRE(v.size()== 4);
    REQUIRE(v.capacity()== 8);
    REQUIRE(v.at(0)==1);
    REQUIRE(v.at(1)==2);
    REQUIRE(v.at(2)==3);
    REQUIRE(v.at(3)==4);

    v.erase(2);
    REQUIRE(!v.empty()); // middle
    REQUIRE(v.size() == 3);
    REQUIRE(v.capacity()== 8);
    REQUIRE(v.at(0)==1);
    REQUIRE(v.at(1)==2);
    REQUIRE(v.at(2)==4);

    v.erase(2);
    REQUIRE(!v.empty()); // end
    REQUIRE(v.size() == 2);
    REQUIRE(v.capacity()== 4);
    REQUIRE(v.at(0)==1);
    REQUIRE(v.at(1)==2);

}
TEST_CASE("At test","[at]") {
    dsa::Vector<int> v;
    REQUIRE_THROWS(v.at(0));
    REQUIRE_THROWS(v.at(-5));
    v.push_back(5);
    REQUIRE_THROWS(v.at(1));

    const dsa::Vector<int> f; // constant versions
    REQUIRE_THROWS(f.at(0));
    REQUIRE_THROWS(f.at(-5));
}

TEST_CASE("Constant vector test","[constVect]") {
    dsa::Vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    const dsa::Vector<int> empty;
    REQUIRE(empty.size()==0);
    REQUIRE(empty.capacity()==0);
    REQUIRE(empty.empty());

    const dsa::Vector<int> cv = v;
    REQUIRE(cv.front() == 0);
    REQUIRE(cv.at(1)==1);
    REQUIRE(cv.at(2)==2);
    REQUIRE(cv.at(3)==3);
    REQUIRE(cv.back() == 4);
}
