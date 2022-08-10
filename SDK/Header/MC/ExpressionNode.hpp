// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ExpressionNode {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_EXPRESSIONNODE
#endif
    MCAPI ExpressionNode(class ExpressionNode &&);
    MCAPI ExpressionNode(struct MolangScriptArg &, enum ExpressionOp);
    MCAPI ExpressionNode(class ExpressionNode const &);
    MCAPI ExpressionNode(std::string const &, class SemVersion const &, class gsl::span<class HashedString const, -1>);
    MCAPI ExpressionNode(std::string const &, enum MolangVersion, class gsl::span<class HashedString const, -1>);
    MCAPI ExpressionNode(class Json::Value const &, class SemVersion const &, class gsl::span<class HashedString const, -1>);
    MCAPI ExpressionNode(class Json::Value const &, enum MolangVersion, class gsl::span<class HashedString const, -1>);
    MCAPI ExpressionNode(float);
    MCAPI ExpressionNode();
    MCAPI void clear();
    MCAPI float evalAsFloat(class RenderParams &) const;
    MCAPI struct MolangScriptArg const & evalGeneric(class RenderParams &) const;
    MCAPI std::string const & getExpressionString();
    MCAPI std::string const getExpressionString() const;
    MCAPI enum MolangVersion const getMolangVersion() const;
    MCAPI unsigned __int64 getTreeHash(bool) const;
    MCAPI bool getTreeString(std::string &, bool) const;
    MCAPI bool hasMadd() const;
    MCAPI bool isInitialized() const;
    MCAPI bool isValid() const;
    MCAPI enum MolangCompileResult link() const;
    MCAPI void moveConstantChildToValueIfFloatOrHashType(int);
    MCAPI class ExpressionNode & operator=(class ExpressionNode const &);
    MCAPI class ExpressionNode & operator=(float);
    MCAPI bool operator==(class ExpressionNode const &) const;
    MCAPI bool parse(std::string const &, enum MolangVersion, class gsl::span<class HashedString const, -1>);
    MCAPI ~ExpressionNode();
    MCAPI static void bindType();
    MCAPI static void buildExpressionOpTable();
    MCAPI static float fast_atof_positiveOnly(char const *&);
    MCAPI static class Experiments & getExperiments();
    MCAPI static char const * getOpFriendlyName(enum ExpressionOp);
    MCAPI static class std::recursive_mutex & getQueryFunctionMutex();
    MCAPI static std::vector<struct std::pair<std::string, enum ExpressionOp>> mAliasOpTokens;
    MCAPI static std::vector<std::string> mExpressionOpTokens;
    MCAPI static class std::function<struct MolangScriptArg const & (class RenderParams &, std::vector<class ExpressionNode> const &)> const * queryFunctionAccessorFromString(std::string const &, enum MolangVersion, enum MolangQueryFunctionReturnType &, bool);
    MCAPI static struct MolangQueryFunction & registerQueryFunction(std::string const &, class std::function<struct MolangScriptArg const & (class RenderParams &, std::vector<class ExpressionNode> const &)>, std::string const &, enum MolangQueryFunctionReturnType, class HashedString, unsigned __int64, unsigned __int64, class std::initializer_list<int> const &);
    MCAPI static void setExperiments(class Experiments const &);
    MCAPI static void unregisterQueryFunction(std::string const &, class HashedString);

//private:
    MCAPI bool _buildTree(struct ExpressionOpBitField const &, enum MolangVersion);
    MCAPI bool _checkAllOperationsAreValid() const;
    MCAPI bool _optimize(enum MolangVersion);
    MCAPI bool _processBinaryExpressions(class std::function<bool (enum ExpressionOp)>);
    MCAPI bool _processTernaryAndConditionalExpressions();
    MCAPI bool _readNextToken(char const *&, class gsl::span<class HashedString const, -1> const &, enum MolangVersion);
    MCAPI void _setExpressionStringWithoutRelink(std::string const &);
    MCAPI bool _tokenize(char const *, struct ExpressionOpBitField &, class gsl::span<class HashedString const, -1> const &, enum MolangVersion);
    MCAPI bool _validate(enum MolangVersion, bool, int) const;
    MCAPI bool _validateChildrenAreNumerical(enum MolangVersion) const;
    MCAPI bool findClosingOp(unsigned __int64 &, enum ExpressionOp) const;
    MCAPI bool optimizeFunctionCallParams();
    MCAPI bool processArrays();
    MCAPI bool processBinaryExpression(enum ExpressionOp);
    MCAPI bool processMathFuncs();
    MCAPI bool processMemberAccessors();
    MCAPI bool processNegativesAndLogicalNots();
    MCAPI bool processQueriesAndFunctions();
    MCAPI bool processSections();
    MCAPI bool processSemicolons();
    MCAPI bool processUnaryExpression(enum ExpressionOp);
    MCAPI static enum MolangCompileResult _buildProgram(struct MolangProgramBuildState &, class ExpressionNode const *);
    MCAPI static struct MolangScriptArg * _getOrCreateReferencedMemberVariableScriptArg(struct MolangEvalParams &, class ExpressionNode const &);
    MCAPI static bool _getQueryFunctionAccessor(struct MolangScriptArg &, std::string const &, enum MolangVersion, enum MolangQueryFunctionReturnType, class HashedString const &);
    MCAPI static struct MolangScriptArg const * _getScriptArgFromMemberAccessedVariable(struct MolangEvalParams &, class ExpressionNode const &);
    MCAPI static bool _initializeMolangQueries();
    MCAPI static void _writeScriptArgToMemberAccessedVariable(struct MolangEvalParams &, class ExpressionNode const &, struct MolangScriptArg const &);
    MCAPI static void _writeScriptArgToMolangVariable(class MolangVariableMap &, enum MolangVariableIndex, struct MolangScriptArg const &);


private:
    MCAPI static class std::function<struct MolangScriptArg const & (class RenderParams &, std::vector<class ExpressionNode> const &)> _defaultUnknownQueryFunction;
    MCAPI static class ExperimentStorage mExperiments;
    MCAPI static bool mMolangInitialized;
    MCAPI static class std::unordered_multimap<class HashedString, struct MolangQueryFunction, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, struct MolangQueryFunction>>> mQueryFunctionAccessors;
    MCAPI static class std::unordered_map<class HashedString, class std::unordered_set<class HashedString, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<class HashedString>>, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class std::unordered_set<class HashedString, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<class HashedString>>>>> mQuerySets;


};