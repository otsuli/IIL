#include <cstdint>
#include "lexer/tokens.hpp"
enum class TokenType;

using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;

using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;

using f64 = double;
using f32 = float;

typedef const u16 ConstU16;

typedef const std::variant<std::string, int> ConstTokenValue;
typedef const TokenType ConstTokenType;
typedef const u16 ConstU16;
