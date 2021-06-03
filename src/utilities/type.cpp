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

static const size_t TypeSize[] = {
        [(size_t) BaseType::Error] = 0,
        [(size_t) BaseType::Void] = 0,
        [(size_t) BaseType::SChar] = 1,
        [(size_t) BaseType::UChar] = 1,
        [(size_t) BaseType::SShort] = 2,
        [(size_t) BaseType::UShort] = 2,
        [(size_t) BaseType::SInt] = 4,
        [(size_t) BaseType::UInt] = 4,
        [(size_t) BaseType::SLong] = 4,
        [(size_t) BaseType::ULong] = 4,
        [(size_t) BaseType::SLongLong] = 8,
        [(size_t) BaseType::ULongLong] = 8,
        [(size_t) BaseType::Float] = 4,
        [(size_t) BaseType::Double] = 8,
        [(size_t) BaseType::LongDouble] = 8,
        [(size_t) BaseType::Bool] = 1,
        [(size_t) BaseType::Struct] = 0,
        [(size_t) BaseType::Union] = 0,
        [(size_t) BaseType::Enum] = 0,
        [(size_t) BaseType::Pointer] = 4,
        [(size_t) BaseType::Array] = 0,
        [(size_t) BaseType::Function] = 0,
};

const string &getTypeStr(BaseType type) {
    return TypeStrings[(size_t) type];
}

size_t SimpleTypeNode::getSize() {
    return TypeSize[(size_t) nodeType];
}

PointerTypePtr getPointerType(CTypeBasePtr pointTo) {
    return make_shared<PointerTypeNode>(PointerTypeNode(std::move(pointTo)));
}

ArrayTypePtr getArrayType(CTypeBasePtr baseType, size_t size) {
    return make_shared<ArrayTypeNode>(ArrayTypeNode(std::move(baseType), size));
}

bool CTypeNodeBase::typeCheck(const CTypeBasePtr &srcType) {
    // wrong: getNodeType() == BaseType::Array && srcType->getNodeType() == BaseType::Pointer
    if (nodeType == BaseType::Pointer && srcType->nodeType == BaseType::Pointer) {
        return childNode->typeCheck(srcType->childNode);
    } else if (nodeType == BaseType::Array && srcType->nodeType == BaseType::Array) {
        if (dynamic_cast<ArrayTypeNode *>(this)->getSingleSize() ==
            dynamic_pointer_cast<ArrayTypeNode>(srcType)->getSingleSize())
            return childNode->typeCheck(srcType->childNode);
    } else if (nodeType == BaseType::Pointer && srcType->nodeType == BaseType::Array) {
        return childNode->nodeType != BaseType::Pointer; // need to do this by cast
    } else if (nodeType == BaseType::Error && srcType->nodeType == BaseType::Error) {
        return false;
    } else if (nodeType == srcType->nodeType) {
        return true;
    }
    return false;
}
