// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Matrix {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MATRIX
public:
    class Matrix& operator=(class Matrix const &) = delete;
    Matrix(class Matrix const &) = delete;
    Matrix() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MATRIX
#endif
    MCAPI Matrix(struct glm::qua<float, 0> const &);
    MCAPI void transform3(struct glm::vec<3, float, 0> &, float &) const;

};