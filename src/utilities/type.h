//
// Created by 44190 on 5/25/2021.
//

#ifndef MYCC_TYPE_H
#define MYCC_TYPE_H

#include "CLexer.h"
#include <vector>
#include <memory>
#include <map>

using namespace c_grammar;
using std::vector;
using std::string;
using std::multiset;
using std::map;

enum class BaseType {
    Error = 0,
    Void,
    SChar,
    UChar,
    SShort,
    UShort,
    SInt,
    UInt,
    SLOng,
    ULong,
    SLongLong,
    ULongLong,
    Float,
    Double,
    LongDouble,
    Bool,
    Struct,
    Union,
    Enum,
};

enum class StorageClassSpecifier : size_t {
    None = 0,
    ExternSpecifier = CLexer::Extern,
    StaticSpecifier = CLexer::Static,
    AutoSpecifier = CLexer::Auto,
    RegisterSpecifier = CLexer::Register,
};

enum class QualifierSpecifier : size_t {
    // qualifier
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

class CompoundType {
    BaseType type;
    string name;
};

using CompoundTypes = vector<CompoundType>;
using CompoundTypesPtr = std::shared_ptr<CompoundTypes>;
using TypeSpecifiers = vector<TypeSpecifier>;
//using SpecifiersPtr = std::shared_ptr<Specifiers>;

class CType {
public:
    BaseType baseType;
    bool definedType;
    CompoundTypesPtr compoundTypesPtr;
    StorageClassSpecifier storageClass;
    QualifierSpecifier qualifier;
    FunctionSpecifier function;

    explicit CType(StorageClassSpecifier storageClass) :
            baseType(BaseType::Error),
            definedType(false),
            compoundTypesPtr(nullptr),
            storageClass(storageClass),
            qualifier(QualifierSpecifier::None),
            function(FunctionSpecifier::None) {
    }
};


BaseType getBaseType(TypeSpecifiers &specifiers);

#endif //MYCC_TYPE_H
