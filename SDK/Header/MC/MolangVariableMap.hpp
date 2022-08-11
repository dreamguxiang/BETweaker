// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MolangVariableMap {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOLANGVARIABLEMAP
public:
    MolangVariableMap() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOLANGVARIABLEMAP
#endif
    MCAPI MolangVariableMap(class MolangVariableMap &&);
    MCAPI MolangVariableMap(class MolangVariableMap const &);
    MCAPI class MolangVariableMap & clear();
    MCAPI struct MolangScriptArg const * getConstScriptArgReference(enum MolangVariableIndex const &) const;
    MCAPI struct MolangScriptArg const & getMolangVariable(enum MolangVariableIndex const &, bool &) const;
    MCAPI struct MolangScriptArg const & getMolangVariable(unsigned __int64 const &, bool &) const;
    MCAPI struct MolangScriptArg const & getMolangVariable(unsigned __int64, char const *) const;
    MCAPI struct MolangScriptArg * getNonConstScriptArgReference(enum MolangVariableIndex const &);
    MCAPI struct MolangScriptArg * getOrAddNonConstScriptArgReference(enum MolangVariableIndex const &);
    MCAPI struct MolangScriptArg const & getPublicMolangVariable(enum MolangVariableIndex const &, bool &) const;
    MCAPI std::vector<std::unique_ptr<class MolangVariable>> const & getVariables() const;
    MCAPI class MolangVariableMap & operator=(class MolangVariableMap &&);
    MCAPI class MolangVariableMap & operator=(class MolangVariableMap const &);
    MCAPI void setMolangStructMember(class HashedString const &, class HashedString const &, struct MolangScriptArg const &);
    MCAPI void setMolangVariable(class HashedString const &, struct MolangScriptArg const &);
    MCAPI void setMolangVariable(enum MolangVariableIndex, struct MolangScriptArg const &);
    MCAPI void setMolangVariable(unsigned __int64, char const *, struct MolangScriptArg const &);
    MCAPI void setMolangVariableSettings(struct MolangVariableSettings const &);
    MCAPI ~MolangVariableMap();

//private:
    MCAPI class MolangVariable const * _getMolangVariable(enum MolangVariableIndex) const;
    MCAPI class MolangVariable * _getOrAddMolangVariable(unsigned __int64 const &, char const *, bool);
    MCAPI class MolangVariable * _getOrAddMolangVariable(enum MolangVariableIndex);

private:

};