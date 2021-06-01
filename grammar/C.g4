grammar C;

// expression
primaryExpression
    :   identifier
    |   constant
    |   StringLiteral+
    |   '(' expression ')'
    ;

identifier: Identifier;

constant
    :   IntegerConstant
//    |   FloatingConstant
//    |   EnumerationConstant
//    |   CharacterConstant
    ;

postfixExpression
    :
    primaryExpression
    (
//    '[' expression ']'
//    |
    '(' argumentExpressionList? ')'
//    |
//    postfixOperator
    )*
    ;

//postfixOperator
//    :   '++'
//    |   '--'
//    ;
//
argumentExpressionList
    :   assignmentExpression (',' assignmentExpression)*
    ;

unaryExpression
    :
    prefixOperator*
    (
    postfixExpression
    |   unaryOperator unaryExpression
    )
    ;

prefixOperator
    :   '++'
    |   '--'
    |   'sizeof'
    ;

unaryOperator
    :   '&' | '*' | '+' | '-' | '~' | '!'
    ;

castExpression
    :   unaryExpression
    ;

multiplicativeExpression
    :   castExpression (multiplicativeOperator castExpression)*
    ;

multiplicativeOperator
    :   '*'
    |   '/'
    |   '%'
    ;

additiveExpression
    :   multiplicativeExpression (additiveOperator multiplicativeExpression)*
    ;

additiveOperator
    :   '+'
    |   '-'
    ;

shiftExpression
    :   additiveExpression (shiftOperator additiveExpression)*
    ;

shiftOperator
    :   '<<'
    |   '>>'
    ;

relationalExpression
    :   shiftExpression (relationalOperator shiftExpression)*
    ;

relationalOperator
    :   '<'
    |   '>'
    |   '<='
    |   '>='
    ;

equalityExpression
    :   relationalExpression (equalityOperator relationalExpression)*
    ;

equalityOperator
    :   '=='
    |   '!='
    ;

andExpression
    :   equalityExpression (andOperator equalityExpression)*
    ;

andOperator : '&';

exclusiveOrExpression
    :   andExpression (exclusiveOrOperator andExpression)*
    ;

exclusiveOrOperator : '^';

inclusiveOrExpression
    :   exclusiveOrExpression (inclusiveOrOperator exclusiveOrExpression)*
    ;
inclusiveOrOperator : '|';

logicalAndExpression
    :   inclusiveOrExpression (logicalAndOperator inclusiveOrExpression)*
    ;
logicalAndOperator : '&&';

logicalOrExpression
    :   logicalAndExpression (logicalOrOperator logicalAndExpression)*
    ;
logicalOrOperator : '||';

conditionalExpression
    :   logicalOrExpression ('?' expression ':' conditionalExpression)?
    ;

assignmentExpression
    :   conditionalExpression
    |   unaryExpression assignmentOperator assignmentExpression
    ;

assignmentOperator
    :   '=' | '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|='
    ;

expression
    :   assignmentExpression (',' assignmentExpression)*
    ;

constantExpression
    :   conditionalExpression
    ;

// declaration
declaration
    :   declarationSpecifiers initDeclaratorList? ';'
    ;

declarationSpecifiers
    :   typedefSpecifier? declarationSpecifierList
    ;

declarationSpecifierList
    :   declarationSpecifier+
    ;

declarationSpecifier
    :   typeSpecifier
    ;

initDeclaratorList
    :   initDeclarator (',' initDeclarator)*
    ;

initDeclarator
    :   declarator ('=' initializer)?
    ;

typedefSpecifier
    :   'typedef'
    ;

// TODO: add userdefine-type
typeSpecifier
    :   simpleTypeSpecifier
    ;

simpleTypeSpecifier
    :   'void'
    |   'char'
    |   'short'
    |   'int'
    |   'long'
    |   'float'
    |   'double'
    |   'signed'
    |   'unsigned'
    |   '_Bool'
    ;

// TODO: pointer
declarator
    :
//    pointer?
    directDeclarator
    ;

// TODO:
//  function declaration
//  array declatation
directDeclarator
    :   identifier
    ;

parameterTypeList
    :   parameterList //(',' '...')?
    ;

parameterList
    :   parameterDeclaration (',' parameterDeclaration)*
    ;

parameterDeclaration
    :   declarationSpecifiers declarator
    ;

initializer
    :   assignmentExpression
//    |   '{' initializerList ','? '}'
    ;

//initializerList
//    :   designation? initializer (',' designation? initializer)*
//    ;

designation
    :   designatorList '='
    ;

designatorList
    :   designator+
    ;

designator
    :   '[' constantExpression ']'
    |   '.' identifier
    ;

statement
//    : Identifier ':' statement                                  #labelStmt
//    |   'case' constantExpression ':' statement                 #caseStmt
//    |   'default' ':' statement                                 #defaultStmt
    :   compoundStatement                                       #block
    |   expression? ';'                                         #expStmt
    |   'if' '(' expression ')' statement ('else' statement)?   #ifStmt
//    |   'switch' '(' expression ')' statement                   #switchStmt
    |   'while' '(' expression ')' statement                    #whileLoop
    |   'do' statement 'while' '(' expression ')' ';'           #doWhile
    |   'for' '(' forCondition ')' statement                    #forLoop
    |   'continue' ';'                                          #continueStmt
    |   'break' ';'                                             #breakStmt
    |   'return' expression? ';'                                #returnStmt
//    |   'goto' Identifier ';'                                   #jumpStmt
    ;

compoundStatement
    :   '{' blockItem* '}'
    ;

blockItem
    :   statement
    |   declaration
    ;

forCondition
	:   (declaration | expression? ';' ) forCondExpression? ';' forFinalExpression?
	;

forFinalExpression:    expression    ;
forCondExpression:    expression    ;


// program file
compilationUnit
    :   translationUnit? EOF
    ;

translationUnit
    :   externalDeclaration+
    ;

externalDeclaration
    :   functionDefinition
    |   declaration
    |   ';' // stray ;
    ;

functionDefinition
    :   declarationSpecifiers? declarator '(' parameterTypeList? ')' compoundStatement
    ;

Auto : 'auto';
Break : 'break';
Case : 'case';
Char : 'char';
Const : 'const';
Continue : 'continue';
Default : 'default';
Do : 'do';
Double : 'double';
Else : 'else';
Enum : 'enum';
Extern : 'extern';
Float : 'float';
For : 'for';
Goto : 'goto';
If : 'if';
Inline : 'inline';
Int : 'int';
Long : 'long';
Register : 'register';
Restrict : 'restrict';
Return : 'return';
Short : 'short';
Signed : 'signed';
Sizeof : 'sizeof';
Static : 'static';
Struct : 'struct';
Switch : 'switch';
Typedef : 'typedef';
Union : 'union';
Unsigned : 'unsigned';
Void : 'void';
Volatile : 'volatile';
While : 'while';

Alignas : '_Alignas';
Alignof : '_Alignof';
Atomic : '_Atomic';
Bool : '_Bool';
Complex : '_Complex';
Generic : '_Generic';
Imaginary : '_Imaginary';
Noreturn : '_Noreturn';
StaticAssert : '_Static_assert';
ThreadLocal : '_Thread_local';

LeftParen : '(';
RightParen : ')';
LeftBracket : '[';
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';

Less : '<';
LessEqual : '<=';
Greater : '>';
GreaterEqual : '>=';
LeftShift : '<<';
RightShift : '>>';

Plus : '+';
PlusPlus : '++';
Minus : '-';
MinusMinus : '--';
Star : '*';
Div : '/';
Mod : '%';

And : '&';
Or : '|';
AndAnd : '&&';
OrOr : '||';
Caret : '^';
Not : '!';
Tilde : '~';

Question : '?';
Colon : ':';
Semi : ';';
Comma : ',';

Assign : '=';
// '*=' | '/=' | '%=' | '+=' | '-=' | '<<=' | '>>=' | '&=' | '^=' | '|='
StarAssign : '*=';
DivAssign : '/=';
ModAssign : '%=';
PlusAssign : '+=';
MinusAssign : '-=';
LeftShiftAssign : '<<=';
RightShiftAssign : '>>=';
AndAssign : '&=';
XorAssign : '^=';
OrAssign : '|=';

Equal : '==';
NotEqual : '!=';

Arrow : '->';
Dot : '.';
Ellipsis : '...';

Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |   Digit
        )*
    ;

fragment
IdentifierNondigit
    :   Nondigit
    |   UniversalCharacterName
    //|   // other implementation-defined characters...
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
Digit
    :   [0-9]
    ;

fragment
UniversalCharacterName
    :   '\\u' HexQuad
    |   '\\U' HexQuad HexQuad
    ;

fragment
HexQuad
    :   HexadecimalDigit HexadecimalDigit HexadecimalDigit HexadecimalDigit
    ;

IntegerConstant
    :   DecimalConstant IntegerSuffix?
    |   OctalConstant IntegerSuffix?
    |   HexadecimalConstant IntegerSuffix?
    |	BinaryConstant
    ;

fragment
BinaryConstant
	:	'0' [bB] [0-1]+
	;

fragment
DecimalConstant
    :   NonzeroDigit Digit*
    ;

fragment
OctalConstant
    :   '0' OctalDigit*
    ;

fragment
HexadecimalConstant
    :   HexadecimalPrefix HexadecimalDigit+
    ;

fragment
HexadecimalPrefix
    :   '0' [xX]
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

fragment
OctalDigit
    :   [0-7]
    ;

fragment
HexadecimalDigit
    :   [0-9a-fA-F]
    ;

fragment
IntegerSuffix
    :   UnsignedSuffix LongSuffix?
    |   UnsignedSuffix LongLongSuffix
    |   LongSuffix UnsignedSuffix?
    |   LongLongSuffix UnsignedSuffix?
    ;

fragment
UnsignedSuffix
    :   [uU]
    ;

fragment
LongSuffix
    :   [lL]
    ;

fragment
LongLongSuffix
    :   'll' | 'LL'
    ;

fragment
FloatingConstant
    :   DecimalFloatingConstant
    |   HexadecimalFloatingConstant
    ;

fragment
DecimalFloatingConstant
    :   FractionalConstant ExponentPart? FloatingSuffix?
    |   DigitSequence ExponentPart FloatingSuffix?
    ;

fragment
HexadecimalFloatingConstant
    :   HexadecimalPrefix (HexadecimalFractionalConstant | HexadecimalDigitSequence) BinaryExponentPart FloatingSuffix?
    ;

fragment
FractionalConstant
    :   DigitSequence? '.' DigitSequence
    |   DigitSequence '.'
    ;

fragment
ExponentPart
    :   [eE] Sign? DigitSequence
    ;

fragment
Sign
    :   [+-]
    ;

DigitSequence
    :   Digit+
    ;

fragment
HexadecimalFractionalConstant
    :   HexadecimalDigitSequence? '.' HexadecimalDigitSequence
    |   HexadecimalDigitSequence '.'
    ;

fragment
BinaryExponentPart
    :   [pP] Sign? DigitSequence
    ;

fragment
HexadecimalDigitSequence
    :   HexadecimalDigit+
    ;

fragment
FloatingSuffix
    :   [flFL]
    ;

fragment
CharacterConstant
    :   '\'' CCharSequence '\''
    |   'L\'' CCharSequence '\''
    |   'u\'' CCharSequence '\''
    |   'U\'' CCharSequence '\''
    ;

fragment
CCharSequence
    :   CChar+
    ;

fragment
CChar
    :   ~['\\\r\n]
    |   EscapeSequence
    ;
fragment
EscapeSequence
    :   SimpleEscapeSequence
    |   OctalEscapeSequence
    |   HexadecimalEscapeSequence
    |   UniversalCharacterName
    ;
fragment
SimpleEscapeSequence
    :   '\\' ['"?abfnrtv\\]
    ;
fragment
OctalEscapeSequence
    :   '\\' OctalDigit OctalDigit? OctalDigit?
    ;
fragment
HexadecimalEscapeSequence
    :   '\\x' HexadecimalDigit+
    ;
StringLiteral
    :   EncodingPrefix? '"' SCharSequence? '"'
    ;
fragment
EncodingPrefix
    :   'u8'
    |   'u'
    |   'U'
    |   'L'
    ;
fragment
SCharSequence
    :   SChar+
    ;
fragment
SChar
    :   ~["\\\r\n]
    |   EscapeSequence
    |   '\\\n'   // Added line
    |   '\\\r\n' // Added line
    ;

ComplexDefine
    :   '#' Whitespace? 'define'  ~[#\r\n]*
        -> skip
    ;

IncludeDirective
    :   '#' Whitespace? 'include' Whitespace? (('"' ~[\r\n]* '"') | ('<' ~[\r\n]* '>' )) Whitespace? Newline
        -> skip
    ;

// ignore the following asm blocks:
/*
    asm
    {
        mfspr x, 286;
    }
 */
AsmBlock
    :   'asm' ~'{'* '{' ~'}'* '}'
	-> skip
    ;

// ignore the lines generated by c preprocessor
// sample line : '#line 1 "/home/dm/files/dk1.h" 1'
LineAfterPreprocessing
    :   '#line' Whitespace* ~[\r\n]*
        -> skip
    ;

LineDirective
    :   '#' Whitespace? DecimalConstant Whitespace? StringLiteral ~[\r\n]*
        -> skip
    ;

PragmaDirective
    :   '#' Whitespace? 'pragma' Whitespace ~[\r\n]*
        -> skip
    ;

Whitespace
    :   [ \t]+
        -> skip
    ;

Newline
    :   (   '\r' '\n'?
        |   '\n'
        )
        -> skip
    ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;