//
// Created by 44190 on 5/25/2021.
//

#include "type.h"

static const map<multiset<TypeSpecifier>, BaseType> TypeMap = {
        // void
        {{TypeSpecifier::Void},                                                                     BaseType::Void},

        // signed char
        {{TypeSpecifier::Char,},                                                                    BaseType::SChar},
        {{TypeSpecifier::Signed,   TypeSpecifier::Char,},                                           BaseType::SChar},

        // unsigned char
        {{TypeSpecifier::Unsigned, TypeSpecifier::Char,},                                           BaseType::UChar},

        // signed short
        {{TypeSpecifier::Short,},                                                                   BaseType::SShort},
        {{TypeSpecifier::Signed,   TypeSpecifier::Short,},                                          BaseType::SShort},
        {{TypeSpecifier::Short,    TypeSpecifier::Int,},                                            BaseType::SShort},
        {{TypeSpecifier::Signed,   TypeSpecifier::Short, TypeSpecifier::Int,},                      BaseType::SShort},

        // unsigned short
        {{TypeSpecifier::Unsigned, TypeSpecifier::Short,},                                          BaseType::UShort},
        {{TypeSpecifier::Unsigned, TypeSpecifier::Short, TypeSpecifier::Int,},                      BaseType::UShort},

        // signed int
        {{TypeSpecifier::Int,},                                                                     BaseType::SInt},
        {{TypeSpecifier::Signed,},                                                                  BaseType::SInt},
        {{TypeSpecifier::Int,      TypeSpecifier::Signed,},                                         BaseType::SInt},

        // unsigned int
        {{TypeSpecifier::Unsigned,},                                                                BaseType::UInt},
        {{TypeSpecifier::Unsigned, TypeSpecifier::Int,},                                            BaseType::UInt},

        // signed long
        {{TypeSpecifier::Long,},                                                                    BaseType::SLong},
        {{TypeSpecifier::Signed,   TypeSpecifier::Long,},                                           BaseType::SLong},
        {{TypeSpecifier::Long,     TypeSpecifier::Int,},                                            BaseType::SLong},
        {{TypeSpecifier::Signed,   TypeSpecifier::Long,  TypeSpecifier::Int,},                      BaseType::SLong},

        // unsigned long
        {{TypeSpecifier::Unsigned, TypeSpecifier::Long,},                                           BaseType::ULong},
        {{TypeSpecifier::Unsigned, TypeSpecifier::Long,  TypeSpecifier::Int,},                      BaseType::ULong},

        // signed long long
        {{TypeSpecifier::Long,     TypeSpecifier::Long,},                                           BaseType::SLongLong},
        {{TypeSpecifier::Signed,   TypeSpecifier::Long,  TypeSpecifier::Long,},                     BaseType::SLongLong},
        {{TypeSpecifier::Long,     TypeSpecifier::Long,  TypeSpecifier::Int,},                      BaseType::SLongLong},
        {{TypeSpecifier::Signed,   TypeSpecifier::Long,  TypeSpecifier::Long, TypeSpecifier::Int,}, BaseType::SLongLong},

        // unsigned long long
        {{TypeSpecifier::Unsigned, TypeSpecifier::Long,  TypeSpecifier::Long,},                     BaseType::ULongLong},
        {{TypeSpecifier::Unsigned, TypeSpecifier::Long,  TypeSpecifier::Long, TypeSpecifier::Int,}, BaseType::ULongLong},

        // float
        {{TypeSpecifier::Float,},                                                                   BaseType::Float},

        // double
        {{TypeSpecifier::Double,},                                                                  BaseType::Double},
        {{TypeSpecifier::Long,     TypeSpecifier::Double,},                                         BaseType::Double},

        // bool
        {{TypeSpecifier::Bool,},                                                                    BaseType::Bool},
};

BaseType getBaseType(TypeSpecifiers &specifiers) {
    multiset<TypeSpecifier> m;
    for (auto specifier:specifiers) {
        m.insert(specifier);
    }
    auto result = TypeMap.find(m);
    if (result != TypeMap.end())
        return result->second;
    else
        return BaseType::Error;
}

static const string TypeStrings[] = {
        [(size_t) BaseType::Error] = "Error",
        [(size_t) BaseType::Void] = "Void",
        [(size_t) BaseType::SChar] = "SChar",
        [(size_t) BaseType::UChar] = "UChar",
        [(size_t) BaseType::SShort] = "SShort",
        [(size_t) BaseType::UShort] = "UShort",
        [(size_t) BaseType::SInt] = "SInt",
        [(size_t) BaseType::UInt] = "UInt",
        [(size_t) BaseType::SLong] = "SLong",
        [(size_t) BaseType::ULong] = "ULong",
        [(size_t) BaseType::SLongLong] = "SLongLong",
        [(size_t) BaseType::ULongLong] = "ULongLong",
        [(size_t) BaseType::Float] = "Float",
        [(size_t) BaseType::Double] = "Double",
        [(size_t) BaseType::LongDouble] = "LongDouble",
        [(size_t) BaseType::Bool] = "Bool",
        [(size_t) BaseType::Struct] = "Struct",
        [(size_t) BaseType::Union] = "Union",
        [(size_t) BaseType::Enum] = "Enum",
        [(size_t) BaseType::Pointer] = "Pointer",
        [(size_t) BaseType::Array] = "Array",
        [(size_t) BaseType::Function] = "Function",
};

const string &getTypeStr(BaseType type) {
    return TypeStrings[(size_t) type];
}
