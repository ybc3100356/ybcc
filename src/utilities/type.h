//
// Created by 44190 on 5/25/2021.
//

#ifndef MYCC_TYPE_H
#define MYCC_TYPE_H

#include "utilities.h"
#include "CLexer.h"

using namespace antlrcpp;

enum class BaseType : size_t {
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

    // function
    Function,
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

class CTypeNodeBase {
public:
    virtual BaseType getNodeType() = 0;

    virtual size_t getSize() = 0;

    explicit CTypeNodeBase(BaseType baseType = BaseType::Error, shared_ptr<CTypeNodeBase> childNode = nullptr)
            : childNode(std::move(childNode)), baseType(baseType) {}

protected:
    shared_ptr<CTypeNodeBase> childNode;
    BaseType baseType;
};

using CTypeNodePtr = shared_ptr<CTypeNodeBase>;
using CompoundTypes = vector<CTypeNodePtr>;
using CompoundTypesPtr = shared_ptr<CompoundTypes>;

class CType {
public:

    explicit CType(CTypeNodePtr node = nullptr, bool definedType = false) :
            typeTree(std::move(node)),
            definedType(definedType) {
    }

    bool is_typedef() const { return definedType; }

    CTypeNodePtr getTypeTree() const { return typeTree; }

    size_t getSize() { return typeTree->getSize(); }

protected:
    CTypeNodePtr typeTree;
    bool definedType;
//    QualifierSpecifier qualifier;
//    FunctionSpecifier function;
//    StorageClassSpecifier storageClass;
};


class SimpleTypeNode : public CTypeNodeBase {
public:
    BaseType getNodeType() override { return baseType; }

    size_t getSize() override;

    explicit SimpleTypeNode(BaseType type) : CTypeNodeBase(type) {}
};

using SimpleTypeNodePtr = shared_ptr<SimpleTypeNode>;

class FunctionTypeNode : public CTypeNodeBase {
    vector<CTypeNodePtr> paramList;
public:
    BaseType getNodeType() override {
        return BaseType::Function;
    }

    BaseType getReturnType() {
        return childNode->getNodeType();
    }

    size_t getSize() override { return 0; }

    const vector<CTypeNodePtr> &getParamList() { return paramList; }

    explicit FunctionTypeNode(const CType &returnType)
            : CTypeNodeBase(BaseType::Function, returnType.getTypeTree()) {}

};

using FunctionTypeNodePtr = shared_ptr<FunctionTypeNode>;

//class StructTypeNode : public CTypeNode {
//public:
//    BaseType baseType; // struct or union
//    CompoundTypesPtr childNodes;
//
//    explicit StructTypeNode(const CTypeNodePtr& childNode, BaseType baseType = BaseType::Error)
//            : CTypeNode(*childNode), baseType(baseType), childNodes(nullptr) {}
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
//    explicit PointerTypeNode(const CTypeNodePtr &childNode)
//            : CTypeNode(*childNode) {}
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
//    explicit ArrayTypeNode(const CTypeNodePtr &childNode)
//            : CTypeNode(*childNode) {}
//
//    BaseType getNodeType() override {
//        return BaseType::Array;
//    }
//};
//
//using ArrayTypeNodePtr = shared_ptr<ArrayTypeNode>;


BaseType getBaseType(TypeSpecifiers &specifiers);

const string &getTypeStr(BaseType type);

#endif //MYCC_TYPE_H
