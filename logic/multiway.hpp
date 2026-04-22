#pragma once

#include <array>
#include "buses.hpp"

namespace logic {

using Bits2 = std::array<Bit, 2>;
using Bits3 = std::array<Bit, 3>;
using Bits8 = std::array<Bit, 8>;

struct DMux4WayResult {
    Bit a;
    Bit b;
    Bit c;
    Bit d;
};

struct DMux8WayResult {
    Bit a;
    Bit b;
    Bit c;
    Bit d;
    Bit e;
    Bit f;
    Bit g;
    Bit h;
};

Bit or8way(Bits8 in);

Bus16 mux4way16(Bus16 a, Bus16 b, Bus16 c, Bus16 d, Bits2 sel);
Bus16 mux8way16(
    Bus16 a, Bus16 b, Bus16 c, Bus16 d, 
    Bus16 e, Bus16 f, Bus16 g, Bus16 h, 
    Bits3 sel
);

DMux4WayResult dmux4way(Bit in, Bits2 sel);
DMux8WayResult dmux8way(Bit in, Bits3 sel);

} // namespace logic