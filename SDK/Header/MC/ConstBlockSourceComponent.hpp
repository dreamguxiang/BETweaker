// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ConstBlockSourceComponent {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONSTBLOCKSOURCECOMPONENT
public:
    ConstBlockSourceComponent() = delete;
#endif

public:
    MCAPI ConstBlockSourceComponent(struct ConstBlockSourceComponent const &);
    MCAPI ConstBlockSourceComponent(class gsl::not_null<class IConstBlockSource const *>);
    MCAPI class IConstBlockSource const & getBlockSource() const;
    MCAPI struct ConstBlockSourceComponent & operator=(struct ConstBlockSourceComponent const &);

protected:

private:

};