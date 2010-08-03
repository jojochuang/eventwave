//*********************************************************************
//* C_Base64 - a simple base64 encoder and decoder.
//*
//*     Copyright (c) 1999, Bob Withers - bwit@pobox.com
//*
//* This code may be freely used for any purpose, either personal
//* or commercial, provided the authors copyright notice remains
//* intact.
//
//* Reformated by James W. Anderson.  Added declarations to use
//* enhanced version.
//*********************************************************************

#ifndef BASE64_H
#define BASE64_H

/**
 * \file Base64.h
 * \brief code to compute Base64 of strings.  Not originally written for Mace.
 *
 * Copyright notice:
 * \verbatim
 * C_Base64 - a simple base64 encoder and decoder.
 * 
 *   Copyright (c) 1999, Bob Withers - bwit@pobox.com
 * 
 * This code may be freely used for any purpose, either personal
 * or commercial, provided the authors copyright notice remains
 * intact.
 * 
 * Reformated by James W. Anderson.  Added declarations to use
 * enhanced version.
 * \endverbatim
 */

#include <string>

/// class to encode and decode strings using Base64
class Base64 {
public:
  static std::string encode(const std::string& data); ///< returns the Base64 version of \c data as a string.
  static std::string decode(const std::string& data); ///< returns the decoded version of Base64 encoded \c data as a string.

  static bool isPrintable(const std::string& s); ///< Tests a string \c s to see if all the characters are printable (whether to call encode())).

  static const std::string Base64Table;

private:
  static const std::string::size_type DecodeTable[];
  static const char fillchar;
  static const std::string::size_type np;
};

#endif // BASE64_H
