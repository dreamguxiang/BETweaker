// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

namespace persona {

#define AFTER_EXTRA
// Add Member There
	enum class AnimationExpression {
		Linear = 0x0,
		Blinking = 0x1,
	};
	enum class AnimatedTextureType {
		None = 0x0,
		Face = 0x1,
		Body32x32 = 0x2,
		Body128x128 = 0x3,
	};

    enum PieceType : unsigned int {
        Unknown = 0x0,
        Skeleton = 0x1,
        Body = 0x2,
        Skin = 0x3,
        Bottom = 0x4,
        Feet = 0x5,
        Dress = 0x6,
        Top = 0x7,
        High_Pants = 0x8,
        Hands = 0x9,
        Outerwear = 0xA,
        FacialHair = 0xB,
        Mouth = 0xC,
        Eyes = 0xD,
        Hair = 0xE,
        Hood = 0xF,
        Back = 0x10,
        FaceAccessory = 0x11,
        Head = 0x12,
        Legs = 0x13,
        LeftLeg = 0x14,
        RightLeg = 0x15,
        Arms = 0x16,
        LeftArm = 0x17,
        RightArm = 0x18,
        Capes = 0x19,
        ClassicSkin = 0x1A,
        Emote = 0x1B,
        Unsupported = 0x1C,
        Count = 0x1D,
    };

#undef AFTER_EXTRA
    MCAPI extern std::string const ANIMATED_128X128_NAME;
    MCAPI extern std::string const ANIMATED_128X128_TEXTURE_CONTROLLER_FIRST_PERSON;
    MCAPI extern std::string const ANIMATED_128X128_TEXTURE_CONTROLLER_THIRD_PERSON;
    MCAPI extern class HashedString const ANIMATED_128X128_TEXTURE_FRAMES_VARIABLE;
    MCAPI extern std::string const ANIMATED_32X32_NAME;
    MCAPI extern std::string const ANIMATED_32X32_TEXTURE_CONTROLLER_FIRST_PERSON;
    MCAPI extern std::string const ANIMATED_32X32_TEXTURE_CONTROLLER_THIRD_PERSON;
    MCAPI extern class HashedString const ANIMATED_32X32_TEXTURE_FRAMES_VARIABLE;
    MCAPI extern std::string const ANIMATED_FACE_CONTROLLER_FIRST_PERSON;
    MCAPI extern std::string const ANIMATED_FACE_CONTROLLER_THIRD_PERSON;
    MCAPI extern std::string const ANIMATED_FACE_NAME;
    MCAPI extern class HashedString const ANIMATED_FACE_TEXTURE_FRAMES_VARIABLE;
    MCAPI extern int const INVALID_INDEX;
    MCAPI extern class mce::UUID const NONE_PIECE_ID;
    MCAPI extern std::string const NONE_PIECE_PATH;
    MCAPI extern class mce::UUID const NO_PIECE_SELECTED;
    MCAPI extern class HashedString const USE_BLINKING_ANIMATION_VARIABLE;
    MCAPI enum persona::PieceType pieceTypeFromString(std::string const &);
    MCAPI std::string const & stringFromPieceType(enum persona::PieceType, bool);

};