#include "primitive.hpp"

namespace logic {
    
Bit nand_gate(Bit a, Bit b) {
    return !(a && b);
}

} // namespace logic