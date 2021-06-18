//
// Created by 44190 on 5/25/2021.
//

#ifndef MYCC_TYPE_H
#define MYCC_TYPE_H

#include <utility>

#include "utilities.h"
#include "error.h"
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

    virtual BaseType getBaseType() = 0;

    virtual size_t getSize() = 0;

    virtual CTypeBasePtr typeCast(const CTypeBasePtr &castTo) {
        return static_pointer_cast<CTypeNodeBase>(castTo);
    };

    bool typeCheck(const CTypeBasePtr &srcType);

    CTypeBasePtr getChild() { return childNode; }

    size_t getBaseNodeSize() {
        if (childNode)
            return childNode->getBaseNodeSize();
        else
            return getSize();
    }

    explicit CTypeNodeBase(BaseType baseType = BaseType::Error, CTypeBasePtr childNode = nullptr)
            : childNode(std::move(childNode)), nodeType(baseType) {}

protected:
    CTypeBasePtr childNode;
    BaseType nodeType;
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
    BaseType getNodeType() override { return nodeType; }

    BaseType getBaseType() override { return nodeType; }

    size_t getSize() override;

    explicit SimpleTypeNode(BaseType type) : CTypeNodeBase(type) {}
};

using SimpleTypePtr = shared_ptr<SimpleTypeNode>;

class FunctionTypeNode : public CTypeNodeBase {
    vector<CTypeBasePtr> paramList;
public:
    BaseType getNodeType() override { return BaseType::Function; }

    BaseType getBaseType() override { return childNode->getNodeType(); }

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

    BaseType getBaseType() override { return childNode->getBaseType(); }

    size_t getSize() override { return WORD_BYTES; }

    BaseType getNodeType() override { return BaseType::Pointer; }
};

using PointerTypePtr = shared_ptr<PointerTypeNode>;

class ArrayTypeNode : public CTypeNodeBase {
    size_t size;
public:
    explicit ArrayTypeNode(CTypeBasePtr childNode, size_t size)
            : CTypeNodeBase(BaseType::Array, std::move(childNode)), size(size) {}

    size_t getSize() override { return size * childNode->getSize(); }

    size_t getSingleSize() const { return size; }

    BaseType getNodeType() override { return BaseType::Array; }

    BaseType getBaseType() override { return childNode->getBaseType(); }

};

using ArrayTypePtr = shared_ptr<ArrayTypeNode>;

class NoneTypeNode : public CTypeNodeBase {
public:
    explicit NoneTypeNode()
            : CTypeNodeBase() {}

    BaseType getNodeType() override {
        return BaseType::Error;
    }
};

using NoneTypePtr = shared_ptr<NoneTypeNode>;


ArrayTypePtr getArrayType(CTypeBasePtr baseType, size_t size);

PointerTypePtr getPointerType(CTypeBasePtr pointTo);

bool isSameType(const CTypeBasePtr &first, const CTypeBasePtr &second);
//class StructTypeNode : public CTypeNode {
//public:
//    BaseType nodeType; // struct or union
//    CompoundTypesPtr childNodes;
//
//    explicit StructTypeNode(const CTypeBasePtr& childNode, BaseType nodeType = BaseType::Error)
//            : CTypeNode(*childNode), nodeType(nodeType), childNodes(nullptr) {}
//
//    BaseType getNodeType() override {
//        return nodeType;
//    }
//};
//
//using StructTypeNodePtr = shared_ptr<StructTypeNode>;
//

CTypeBasePtr getRetType(const CTypeBasePtr &first, const CTypeBasePtr &second, size_t op);

BaseType getBaseType(TypeSpecifiers &specifiers);

const string &getTypeStr(BaseType type);

#endif //MYCC_TYPE_H
