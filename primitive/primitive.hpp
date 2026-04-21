#pragma once

namespace logic {

using Bit = bool;

// primitive gate: everything is built from this
Bit nand_gate(Bit a, Bit b);

} // namespace logic