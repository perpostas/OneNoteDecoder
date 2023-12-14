#include <gtest/gtest.h>

class Counter {
    private:
        int counter_;

    public:
        // Creates a counter that starts at 0.
        Counter() : counter_(0) {}

        // Returns the current counter value, and increments it.
        int Increment() { return ++counter_; };

        // Returns the current counter value, and decrements it.
        int Decrement() { return --counter_; };
};

namespace {

    Counter c;

    TEST(Counter, 1) {
        EXPECT_EQ(c.Increment(), 1);
    }

    TEST(Counter, 2) {
        EXPECT_EQ(c.Increment(), 2);
    }
}