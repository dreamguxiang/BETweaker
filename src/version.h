/**
 * @file version.h
 * @note DO NOT remove this file unless you know what you are doing!
 *       DO NOT modify code outside the designated area!
 */

#pragma once

#define PLUGIN_VERSION_DEV 0
#define PLUGIN_VERSION_BETA 1
#define PLUGIN_VERSION_RELEASE 2


// ***************************************************************************************
// ***************************************************************************************
// ***************************************************************************************

// Please FILL UP the content in this area before developing your plugin, and DO NOT modify any code
// outside this area.

static_assert(false, "Please modify your plugin information below and delete this line!");

// The basic descriptions of your plugin
// Note that the the plugin name CAN ONLY CONTAIN Enlish alphabet, digit, dash(-) and
// underscore(_). 
#define PLUGIN_NAME "HelloWorldPrinter"
// Describe what your plugin does
// We recommend you start the introduction with a third-person singular verb.
#define PLUGIN_INTRODUCTION "Prints \"Hello, World!\" in the console."
#define PLUGIN_AUTHOR "Me"

// The version of your plugin. If you do not know how to set it, please refer
// to https://semver.org/ .
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 1
#define PLUGIN_VERSION_REVISION 0
#define PLUGIN_VERSION_BUILD 0
#define PLUGIN_VERSION_ACTIONS 0

// The stage of your plugin, which can be PLUGIN_VERSION_DEV, PLUGIN_VERSION_BETA
// and PLUGIN_VERSION_RELEASE
#define PLUGIN_VERSION_STATUS PLUGIN_VERSION_DEV

// The target protocol version of your plugin. If you do not know how to set it,
// please start the latest version of LiteLoaderBDS and get the protocol version.
// If you are confident about the version compatibility of your plugin, you can
// just comment this line (NOT RECOMMENDED).
#define TARGET_BDS_PROTOCOL_VERSION 582

// ***************************************************************************************
// ***************************************************************************************
// ***************************************************************************************


// File version information, which is used in Resource.rc
#define __TO_VERSION_STRING(ver) #ver
#define TO_VERSION_STRING(ver) __TO_VERSION_STRING(ver)

#if PLUGIN_VERSION_STATUS == PLUGIN_VERSION_BETA

#define PLUGIN_FILE_VERSION_FLAG VS_FF_DEBUG
#define PLUGIN_LLVERSION_STATUS ll::Version::Beta
#define PLUGIN_FILE_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION.PLUGIN_VERSION_ACTIONS BETA)

#elif PLUGIN_VERSION_STATUS == PLUGIN_VERSION_DEV

#define PLUGIN_FILE_VERSION_FLAG VS_FF_DEBUG
#define PLUGIN_LLVERSION_STATUS ll::Version::Dev
#define PLUGIN_FILE_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION.PLUGIN_VERSION_ACTIONS DEV)

#else

#define PLUGIN_FILE_VERSION_FLAG 0x0L
#define PLUGIN_LLVERSION_STATUS ll::Version::Release
#define PLUGIN_FILE_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION.PLUGIN_VERSION_ACTIONS)

#endif

#define FILE_VERSION_BLOCK_HEADER 0x04004B0L
#define FILE_VERSION_COMPANY_NAME PLUGIN_AUTHOR
#define FILE_VERSION_LEGAL_COPYRIGHT "Copyright (C) 2022"
#define FILE_VERSION_FILE_DESCRIPTION PLUGIN_INTRODUCTION
#define FILE_VERSION_FILE_VERSION_STRING PLUGIN_FILE_VERSION_STRING
#define FILE_VERSION_INTERNAL_NAME PLUGIN_NAME
#define FILE_VERSION_ORIGINAL_FILENAME PLUGIN_NAME ".dll"
#define FILE_VERSION_PRODUCT_NAME FILE_VERSION_INTERNAL_NAME
#define FILE_VERSION_PRODUCT_VERSION_STRING PLUGIN_FILE_VERSION_STRING
#define FILE_VERSION_FILE_VERSION PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_REVISION, PLUGIN_VERSION_BUILD
#define FILE_VERSION_PRODUCT_VERSION FILE_VERSION_FILE_VERSION
