// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ExpressionOpBitField {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPRESSIONOPBITFIELD
public:
    struct ExpressionOpBitField& operator=(struct ExpressionOpBitField const &) = delete;
    ExpressionOpBitField(struct ExpressionOpBitField const &) = delete;
    ExpressionOpBitField() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_EXPRESSIONOPBITFIELD
#endif
    MCAPI bool areBitsSet(enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp) const;
    MCAPI bool areBitsSet(enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp) const;
    MCAPI bool areBitsSet(enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp) const;
    MCAPI bool areBitsSet(enum ExpressionOp, enum ExpressionOp, enum ExpressionOp, enum ExpressionOp) const;
    MCAPI bool areBitsSet(enum ExpressionOp, enum ExpressionOp, enum ExpressionOp) const;

};