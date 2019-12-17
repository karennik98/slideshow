#ifndef COMMAND_TYPE_ENUMS_H
#define COMMAND_TYPE_ENUMS_H

#include "utility.h"

enum class CommandType : uint32_t {
    add_rect = hash_function("add_rect"),
    unknown_type = hash_function("unknown_type"),
};


#endif // COMMAND_TYPE_ENUMS_H
