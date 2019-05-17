#include <bits/stdc++.h>
using namespace std;

// C++11 lest unit testing framework
#include "lest.hpp"

void function(void) {
    
}

// tests
const lest::test tests[] = {
    CASE("description") {
        //const auto meetings = vector<Meeting> {Meeting(1, 3), Meeting(2, 4)};
        //const auto actual = mergeRanges(meetings);
        //const auto expected = vector<Meeting> {Meeting(1, 4)};
        //EXPECT(actual == expected);
    },

    
};

int main(int argc, char** argv) {
    return lest::run(tests, argc, argv);
}