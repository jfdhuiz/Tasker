#ifndef INTERVAL_H
#define INTERVAL_H
#include <cstdint>
namespace util {
struct Interval;

}

struct util::Interval {
    /**
      uint64_t is considered ambiguous in the context of serialization,
      sorry  I ad to change it.
      */
    unsigned long long size;
    unsigned long long frequency;
};

#endif // INTERVAL_H
