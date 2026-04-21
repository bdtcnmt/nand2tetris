#pragma once

#include <array>
#include "gates.hpp"

namespace logic {

using Bus16 = std::array<Bit, 16>;

Bus16 not16(Bus16 in);
Bus16 and16(Bus16 a, Bus16 b);
Bus16 or16(Bus16 a, Bus16 b);
Bus16 mux16(Bus16 a, Bus16 b, Bit sel);

} // namespace logic