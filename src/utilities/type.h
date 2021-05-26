//
// Created by 44190 on 5/25/2021.
//

#ifndef MYCC_TYPE_H
#define MYCC_TYPE_H

#include "CLexer.h"
#include <utility>
#include <vector>
#include <memory>
#include <map>

using namespace antlrcpp;
using std::vector;
using std::string;
using std::multiset;
using std::map;
using std::shared_ptr;

enum class BaseType {
    Error = 0,
    Void,
    SChar,
    UChar,
    SShort,
    UShort,
    SInt,
    UInt,
    SLong,
    ULong,
    SLongLong,
    ULongLong,
    Float,
    Double,
    LongDouble,
    Bool,

    // user define
    Struct,
    Union,
    Enum,
    Pointer,
    Array,
};

enum class StorageClassSpecifier : size_t {
    None = 0,
    ExternSpecifier = CLexer::Extern,
    StaticSpecifier = CLexer::Static,
    AutoSpecifier = CLexer::Auto,
    RegisterSpecifier = CLexer::Register,
};

enum class QualifierSpecifier : size_t {
    None = 0,
    ConstSpecifier = CLexer::Const,
    RestrictSpecifier = CLexer::Restrict,
    VolatileSpecifier = CLexer::Volatile,
};

enum class FunctionSpecifier : size_t {
    None = 0,
    InlineSpecifier = CLexer::Inline,
    NoreturnSpecifier = CLexer::Noreturn,
};

enum class TypeSpecifier : size_t {
    // type
    Void = CLexer::Void,
    Char = CLexer::Char,
    Short = CLexer::Short,
    Int = CLexer::Int,
    Long = CLexer::Long,
    Float = CLexer::Float,
    Double = CLexer::Double,
    Signed = CLexer::Signed,
    Unsigned = CLexer::Unsigned,
    Bool = CLexer::Bool,

    // struct or union
    Struct = CLexer::Struct,
    Union = CLexer::Union,

    // enum
    Enum = CLexer::Enum,
};

using TypeSpecifiers = vector<TypeSpecifier>;

class CTypeNode {
public:
    shared_ptr<CTypeNode> node;
//    QualifierSpecifier qualifier;
//    FunctionSpecifier function;
//    StorageClassSpecifier storageClass;

    explicit CTypeNode(shared_ptr<CTypeNode> node) : node(std::move(node)) {
    }

    virtual BaseType getNodeType() = 0;
};

using CTypeNodePtr = shared_ptr<CTypeNode>;
using CompoundTypes = vector<CTypeNodePtr>;
using CompoundTypesPtr = shared_ptr<CompoundTypes>;

class CType {
public:
    CTypeNodePtr node;
    bool definedType;

    explicit CType(CTypeNodePtr node = nullptr, bool definedType = false) :
            node(std::move(node)),
            definedType(definedType) {
    }
};
//
//class StructTypeNode : public CTypeNode {
//public:
//    BaseType baseType; // struct or union
//    CompoundTypesPtr childNodes;
//
//    explicit StructTypeNode(const CTypeNodePtr& node, BaseType baseType = BaseType::Error)
//            : CTypeNode(*node), baseType(baseType), childNodes(nullptr) {}
//
//    BaseType getNodeType() override {
//        return baseType;
//    }
//};
//
//using StructTypeNodePtr = shared_ptr<StructTypeNode>;
//
//class PointerTypeNode : public CTypeNode {
//public:
//    CTypeNodePtr ptrToNode;
//
//    explicit PointerTypeNode(const CTypeNodePtr &node)
//            : CTypeNode(*node) {}
//
//    BaseType getNodeType() override {
//        return BaseType::Pointer;
//    }
//};
//
//using PointerTypeNodePtr = shared_ptr<PointerTypeNode>;
//
//class ArrayTypeNode : public CTypeNode {
//public:
//    CTypeNodePtr arrayBaseNode;
//
//    explicit ArrayTypeNode(const CTypeNodePtr &node)
//            : CTypeNode(*node) {}
//
//    BaseType getNodeType() override {
//        return BaseType::Array;
//    }
//};
//
//using ArrayTypeNodePtr = shared_ptr<ArrayTypeNode>;

class SimpleTypeNode : public CTypeNode {
public:
    BaseType baseType;

    explicit SimpleTypeNode(CTypeNodePtr node, BaseType baseType = BaseType::Error)
            : CTypeNode(std::move(node)), baseType(baseType) {}

    BaseType getNodeType() override {
        return baseType;
    }
};

using SimpleTypeNodePtr = shared_ptr<SimpleTypeNode>;

BaseType getBaseType(TypeSpecifiers &specifiers);

#endif //MYCC_TYPE_H
