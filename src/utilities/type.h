//
// Created by 44190 on 5/25/2021.
//

#ifndef MYCC_TYPE_H
#define MYCC_TYPE_H

#include <utility>

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

class CTypeNodeBase;

using CTypeBasePtr = shared_ptr<CTypeNodeBase>;

class CTypeNodeBase {
public:
    virtual BaseType getNodeType() = 0;

    virtual size_t getSize() = 0;

//    virtual CTypeBasePtr typeCast(CTypeBasePtr valueType) = 0;

    bool typeCheck(const CTypeBasePtr &srcType) {
        if (srcType->getNodeType() == BaseType::Pointer && getNodeType() == BaseType::Pointer) {
            return childNode->typeCheck(srcType->childNode);
        } else if (srcType->getNodeType() == getNodeType()) {
            return true;
        }
        return false;
    }

    CTypeBasePtr getChild() { return childNode; }

    explicit CTypeNodeBase(BaseType baseType = BaseType::Error, CTypeBasePtr childNode = nullptr)
            : childNode(std::move(childNode)), baseType(baseType) {}

protected:
    CTypeBasePtr childNode;
    BaseType baseType;
};

class CType {
public:

    explicit CType(CTypeBasePtr node = nullptr, bool definedType = false) :
            typeTree(std::move(node)),
            definedType(definedType) {
    }

    bool isTypedef() const { return definedType; }

    CTypeBasePtr getTypeTree() const { return typeTree; }

    size_t getSize() { return typeTree->getSize(); }

protected:
    CTypeBasePtr typeTree;
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

using SimpleTypePtr = shared_ptr<SimpleTypeNode>;

class FunctionTypeNode : public CTypeNodeBase {
    vector<CTypeBasePtr> paramList;
public:
    BaseType getNodeType() override {
        return BaseType::Function;
    }

    BaseType getReturnType() {
        return childNode->getNodeType();
    }

    size_t getSize() override { return 0; }

    vector<CTypeBasePtr> &getParamList() { return paramList; }

    explicit FunctionTypeNode(const CType &returnType, vector<CTypeBasePtr> paramList)
            : CTypeNodeBase(BaseType::Function, returnType.getTypeTree()),
              paramList(std::move(paramList)) {}
};

using FunctionTypePtr = shared_ptr<FunctionTypeNode>;

class PointerTypeNode : public CTypeNodeBase {
public:
    explicit PointerTypeNode(CTypeBasePtr childNode)
            : CTypeNodeBase(BaseType::Pointer, std::move(childNode)) {}

    size_t getSize() override { return WORD_BYTES; }

    BaseType getNodeType() override {
        return BaseType::Pointer;
    }
};

using PointerTypePtr = shared_ptr<PointerTypeNode>;

PointerTypePtr getPointerType(CTypeBasePtr pointTo);

class NoneType : public CTypeNodeBase {
public:
    explicit NoneType()
            : CTypeNodeBase() {}

    BaseType getNodeType() override {
        return BaseType::Error;
    }
};

using NoneTypePtr = shared_ptr<NoneType>;

//class StructTypeNode : public CTypeNode {
//public:
//    BaseType baseType; // struct or union
//    CompoundTypesPtr childNodes;
//
//    explicit StructTypeNode(const CTypeBasePtr& childNode, BaseType baseType = BaseType::Error)
//            : CTypeNode(*childNode), baseType(baseType), childNodes(nullptr) {}
//
//    BaseType getNodeType() override {
//        return baseType;
//    }
//};
//
//using StructTypeNodePtr = shared_ptr<StructTypeNode>;
//

//
//class ArrayTypeNode : public CTypeNode {
//public:
//    CTypeBasePtr arrayBaseNode;
//
//    explicit ArrayTypeNode(const CTypeBasePtr &childNode)
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
