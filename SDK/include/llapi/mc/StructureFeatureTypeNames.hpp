// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

namespace StructureFeatureTypeNames {

#define AFTER_EXTRA

#undef AFTER_EXTRA
    MCAPI class std::basic_string_view<char, struct std::char_traits<char>> getFeatureName(enum StructureFeatureType);
    MCAPI enum StructureFeatureType getFeatureType(std::string const &);
    MCAPI class std::map<std::string, enum StructureFeatureType, struct std::less<std::string>, class std::allocator<struct std::pair<std::string const, enum StructureFeatureType>>> const & getFeatureTypeAliasesMap();

};