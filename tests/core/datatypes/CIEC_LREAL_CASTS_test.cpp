/*******************************************************************************
 * Copyright (c) 2011 - 2012 ACIN, nxtControl, 2018 TU Vienna/ACIN
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Martin Melik Merkumians, Ingo Hegny, Alois Zoitl, Stanislav Meduna - initial API and implementation and/or initial documentation
 *   Martin Melik Merkumians - Adds cast template tests
 *******************************************************************************/
#include <boost/test/unit_test.hpp>
#include "forte_boost_output_support.h"
#include <boost/test/tools/floating_point_comparison.hpp>

#include "../../../src/core/datatypes/forte_real.h"

//BOOLEAN
#include "../../../src/core/datatypes/forte_bool.h"
//BIT-Datatypes
#include "../../../src/core/datatypes/forte_byte.h"
#include "../../../src/core/datatypes/forte_word.h"
#include "../../../src/core/datatypes/forte_dword.h"
//INT-Datatypes
#include "../../../src/core/datatypes/forte_sint.h"
#include "../../../src/core/datatypes/forte_usint.h"
#include "../../../src/core/datatypes/forte_int.h"
#include "../../../src/core/datatypes/forte_uint.h"
#include "../../../src/core/datatypes/forte_dint.h"
#include "../../../src/core/datatypes/forte_udint.h"
//STRING-Datatypes
#include "../../../src/core/datatypes/forte_string.h"
#include "../../../src/core/datatypes/forte_wstring.h"
//TIME
#include "../../../src/core/datatypes/forte_time.h"

//64bit Datatypes
#include "../../../src/core/datatypes/forte_lword.h"
#include "../../../src/core/datatypes/forte_lint.h"
#include "../../../src/core/datatypes/forte_ulint.h"
#include "../../../src/core/datatypes/forte_lreal.h"

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(CIEC_LREAL_casts_function_test)


BOOST_AUTO_TEST_CASE(CASTS_LREAL_to_BOOL)
{
  CIEC_LREAL nTestLReal0;
  CIEC_LREAL nTestLReal1;
  CIEC_LREAL nTestLReal2_2874e6;
  CIEC_LREAL nTestLRealm6_2587em4;
  CIEC_LREAL nTestLReal1_0em37;
  CIEC_LREAL nTestLReal36;

  CIEC_BOOL bTestBool;

//check initial values
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal0) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal36) == 0.0);

  nTestLReal0 = CIEC_LREAL(0.0);
  nTestLReal1 = CIEC_LREAL(1.0);
  nTestLReal2_2874e6 = CIEC_LREAL(2.2874e6);
  nTestLRealm6_2587em4 = CIEC_LREAL(-6.2587e-4);
  nTestLReal1_0em37 = CIEC_LREAL(1.0e-37);
  nTestLReal36 = CIEC_LREAL(36.0);


  BOOST_TEST(0.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal0));
  BOOST_TEST(1.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1));
  BOOST_TEST(2.2874e6 == static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6));
  BOOST_TEST(-6.2587e-4 == static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4));
  BOOST_TEST(1.0e-37 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37));
  BOOST_TEST(36.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal36));

//checks
  CIEC_ANY::specialCast(nTestLReal0, bTestBool);
  BOOST_CHECK_EQUAL(false, bTestBool);
  CIEC_ANY::specialCast(nTestLReal1, bTestBool);
  BOOST_CHECK_EQUAL(true, bTestBool);
  CIEC_ANY::specialCast(nTestLReal2_2874e6, bTestBool);
  BOOST_CHECK_EQUAL(true, bTestBool);
  CIEC_ANY::specialCast(nTestLReal36, bTestBool);
  BOOST_CHECK_EQUAL(true, bTestBool);
  CIEC_ANY::specialCast(nTestLRealm6_2587em4, bTestBool);
  BOOST_CHECK_EQUAL(false, bTestBool);
}

BOOST_AUTO_TEST_CASE(CASTS_LREAL_to_BITDTs)
{
  CIEC_BYTE nTestByte;
  CIEC_WORD nTestWord;
  CIEC_DWORD nTestDWord;
  CIEC_LWORD nTestLWord;

  CIEC_LREAL nTestLReal0;
  CIEC_LREAL nTestLReal1;
  CIEC_LREAL nTestLReal2_2874e6;
  CIEC_LREAL nTestLRealm6_2587em4;
  CIEC_LREAL nTestLReal1_0em37;
  CIEC_LREAL nTestLReal36;

//check initial values
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal0) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal36) == 0.0);

  nTestLReal0 = CIEC_LREAL(0.0);
  nTestLReal1 = CIEC_LREAL(1.0);
  nTestLReal2_2874e6 = CIEC_LREAL(2.2874e6);
  nTestLRealm6_2587em4 = CIEC_LREAL(-6.2587e-4);
  nTestLReal1_0em37 = CIEC_LREAL(1.0e-37);
  nTestLReal36 = CIEC_LREAL(36.0);

  //the 4byte hex value for 36.0:        0x4042000000000000
  //the 4byte hex value for -6.2587e-4f: 0xbf44822d973cf2fb
  //the 4byte hex value for 1:           0x3ff0000000000000

  BOOST_TEST(0.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal0));
  BOOST_TEST(1.0 ==static_cast<CIEC_LREAL::TValueType>(nTestLReal1));
  BOOST_TEST(2.2874e6 == static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6));
  BOOST_TEST(-6.2587e-4 == static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4));
  BOOST_TEST(1.0e-37 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37));
  BOOST_TEST(36.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal36));

//toByte
  nTestByte.setValue(nTestLReal0);
  CIEC_ANY::specialCast(nTestLReal0, nTestByte);
  BOOST_CHECK_EQUAL(nTestByte, 0U);
  CIEC_ANY::specialCast(nTestLReal1, nTestByte);
  BOOST_CHECK_EQUAL(nTestByte, 0);
  CIEC_ANY::specialCast(nTestLReal36, nTestByte);
  BOOST_CHECK_EQUAL(nTestByte, 0);
  CIEC_ANY::specialCast(nTestLRealm6_2587em4, nTestByte);
  BOOST_CHECK_EQUAL(nTestByte, 0xfb);

//toWord
  CIEC_ANY::specialCast(nTestLReal0, nTestWord);
  BOOST_CHECK_EQUAL(nTestWord, 0U);
  CIEC_ANY::specialCast(nTestLReal1, nTestWord);
  BOOST_CHECK_EQUAL(nTestWord, 0x0);
  CIEC_ANY::specialCast(nTestLReal36, nTestWord);
  BOOST_CHECK_EQUAL(nTestWord, 0x0);
  CIEC_ANY::specialCast(nTestLRealm6_2587em4, nTestWord);
  BOOST_CHECK_EQUAL(nTestWord, 0xf2fb);

//toDWord
  CIEC_ANY::specialCast(nTestLReal0, nTestDWord);
  BOOST_CHECK_EQUAL(nTestDWord, 0UL);
  CIEC_ANY::specialCast(nTestLReal1, nTestDWord);
  BOOST_CHECK_EQUAL(nTestDWord, 0x0);
  CIEC_ANY::specialCast(nTestLReal36, nTestDWord);
  BOOST_CHECK_EQUAL(nTestDWord, 0x0);
  CIEC_ANY::specialCast(nTestLRealm6_2587em4, nTestDWord);
  BOOST_CHECK_EQUAL(nTestDWord, 0x973cf2fb);

//toLWord
  CIEC_ANY::specialCast(nTestLReal0, nTestLWord);
  BOOST_CHECK_EQUAL(nTestLWord, 0ULL);
  CIEC_ANY::specialCast(nTestLReal1, nTestLWord);
  BOOST_CHECK_EQUAL(0x3ff0000000000000ULL, nTestLWord);
  CIEC_ANY::specialCast(nTestLReal36, nTestLWord);
  BOOST_CHECK_EQUAL(0x4042000000000000ULL, nTestLWord);
  CIEC_ANY::specialCast(nTestLRealm6_2587em4, nTestLWord);
  BOOST_CHECK_EQUAL(nTestLWord, 0xbf44822d973cf2fbULL);
}

BOOST_AUTO_TEST_CASE(CASTS_LREAL_to_INTS)
{
  CIEC_USINT nTestUSInt;
  CIEC_INT nTestInt;
  CIEC_UINT nTestUInt;
  CIEC_DINT nTestDInt;
  CIEC_UDINT nTestUDInt;
  CIEC_LINT nTestLInt;
  CIEC_ULINT nTestULInt;

  CIEC_LREAL nTestLReal0;
  CIEC_LREAL nTestLReal1;
  CIEC_LREAL nTestLReal2_2874e6;
  CIEC_LREAL nTestLRealm6_2587em4;
  CIEC_LREAL nTestLReal1_0em37;
  CIEC_LREAL nTestLReal36;

//check initial values
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal0) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal36) == 0.0);

  nTestLReal0 = CIEC_LREAL(0.0);
  nTestLReal1 = CIEC_LREAL(1.0);
  nTestLReal2_2874e6 = CIEC_LREAL(2.2874e6);
  nTestLRealm6_2587em4 = CIEC_LREAL(-6.2587e-4);
  nTestLReal1_0em37 = CIEC_LREAL(1.0e-37);
  nTestLReal36 = CIEC_LREAL(36.0);

  BOOST_TEST(0.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal0));
  BOOST_TEST(1.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1));
  BOOST_TEST(2.2874e6 == static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6));
  BOOST_TEST(-6.2587e-4 == static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4));
  BOOST_TEST(1.0e-37 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37));
  BOOST_TEST(36.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal36));

//toUSINT
  CIEC_ANY::specialCast(nTestLReal0, nTestUSInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_USINT::TValueType>(nTestUSInt), 0U);
  CIEC_ANY::specialCast(nTestLReal1, nTestUSInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_USINT::TValueType>(nTestUSInt), 1U);
  CIEC_ANY::specialCast(nTestLReal36, nTestUSInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_USINT::TValueType>(nTestUSInt), 36U);

//toINT
  CIEC_ANY::specialCast(nTestLReal0, nTestInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_INT::TValueType>(nTestInt), 0);
  CIEC_ANY::specialCast(nTestLReal1, nTestInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_INT::TValueType>(nTestInt), 1);
  CIEC_ANY::specialCast(nTestLReal36, nTestInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_INT::TValueType>(nTestInt), 36);

  // toUINT
  CIEC_ANY::specialCast(nTestLReal0, nTestUInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_UINT::TValueType>(nTestUInt), 0U);
  CIEC_ANY::specialCast(nTestLReal1, nTestUInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_UINT::TValueType>(nTestUInt), 1U);
  CIEC_ANY::specialCast(nTestLReal36, nTestUInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_UINT::TValueType>(nTestUInt), 36U);

  // toDINT
  CIEC_ANY::specialCast(nTestLReal0, nTestDInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_DINT::TValueType>(nTestDInt), 0L);
  CIEC_ANY::specialCast(nTestLReal1, nTestDInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_DINT::TValueType>(nTestDInt), 1L);
  CIEC_ANY::specialCast(nTestLReal36, nTestDInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_DINT::TValueType>(nTestDInt), 36L);

  // toUDINT
  CIEC_ANY::specialCast(nTestLReal0, nTestUDInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_UDINT::TValueType>(nTestUDInt), 0UL);
  CIEC_ANY::specialCast(nTestLReal1, nTestUDInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_UDINT::TValueType>(nTestUDInt), 1UL);
  CIEC_ANY::specialCast(nTestLReal36, nTestUDInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_UDINT::TValueType>(nTestUDInt), 36UL);

  // toLINT
  CIEC_ANY::specialCast(nTestLReal0, nTestLInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_LINT::TValueType>(nTestLInt), 0LL);
  CIEC_ANY::specialCast(nTestLReal1, nTestLInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_LINT::TValueType>(nTestLInt), 1LL);
  CIEC_ANY::specialCast(nTestLReal36, nTestLInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_LINT::TValueType>(nTestLInt), 36LL);

  // toULINT
  CIEC_ANY::specialCast(nTestLReal0, nTestULInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_ULINT::TValueType>(nTestULInt), 0ULL);
  CIEC_ANY::specialCast(nTestLReal1, nTestULInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_ULINT::TValueType>(nTestULInt), 1ULL);
  CIEC_ANY::specialCast(nTestLReal36, nTestULInt);
  BOOST_CHECK_EQUAL(static_cast<CIEC_ULINT::TValueType>(nTestULInt), 36ULL);
}

BOOST_AUTO_TEST_CASE(CASTS_LREAL_to_REAL)
{
  CIEC_LREAL nTestLReal0;
  CIEC_LREAL nTestLReal1;
  CIEC_LREAL nTestLReal2_2874e6;
  CIEC_LREAL nTestLRealm6_2587em4;
  CIEC_LREAL nTestLReal1_0em37;
  CIEC_LREAL nTestLReal36;

//check initial values
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal0) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37) == 0.0);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nTestLReal36) == 0.0);

  nTestLReal0 = CIEC_LREAL(0.0);
  nTestLReal1 = CIEC_LREAL(1.0);
  nTestLReal2_2874e6 = CIEC_LREAL(2.2874e6);
  nTestLRealm6_2587em4 = CIEC_LREAL(-6.2587e-4);
  nTestLReal1_0em37 = CIEC_LREAL(1.0e-37);
  nTestLReal36 = CIEC_LREAL(36.0);

  BOOST_TEST(0.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal0));
  BOOST_TEST(1.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1));
  BOOST_TEST(2.2874e6 == static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6));
  BOOST_TEST(-6.2587e-4 == static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4));
  BOOST_TEST(1.0e-37 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37));
  BOOST_TEST(36.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal36));



  CIEC_REAL nTestReal;

//toLREAL
  BOOST_TEST(1.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1));
  BOOST_TEST(2.2874e6 == static_cast<CIEC_LREAL::TValueType>(nTestLReal2_2874e6));
  BOOST_TEST(-6.2587e-4 == static_cast<CIEC_LREAL::TValueType>(nTestLRealm6_2587em4));
  BOOST_TEST(1.0e-37 == static_cast<CIEC_LREAL::TValueType>(nTestLReal1_0em37));
  BOOST_TEST(36.0 == static_cast<CIEC_LREAL::TValueType>(nTestLReal36));

  CIEC_ANY::specialCast(nTestLReal0, nTestReal);
  BOOST_CHECK_EQUAL(0.0f, nTestReal);
  CIEC_ANY::specialCast(nTestLReal1, nTestReal);
  BOOST_CHECK_EQUAL(1.0f, nTestReal);
  CIEC_ANY::specialCast(nTestLReal2_2874e6, nTestReal);
  BOOST_CHECK_EQUAL(2.2874e6f, nTestReal);
  CIEC_ANY::specialCast(nTestLRealm6_2587em4, nTestReal);
  BOOST_CHECK_EQUAL(-6.2587e-4f, nTestReal);
  CIEC_ANY::specialCast(nTestLReal1_0em37, nTestReal);
  BOOST_CHECK_EQUAL(1.0e-37f, nTestReal);
  CIEC_ANY::specialCast(nTestLReal36, nTestReal);
  BOOST_CHECK_EQUAL(36.0f, nTestReal);
}

BOOST_AUTO_TEST_CASE(LREAL_Castable_test)
{
  bool bUp, bDown;

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_BOOL, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_SINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_INT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_DINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_LINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_USINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_UINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_UDINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_ULINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_BYTE, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_WORD, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_DWORD, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_LWORD, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_DATE, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_TIME_OF_DAY, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_DATE_AND_TIME, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_TIME, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_REAL, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_LREAL, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_STRING, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_LREAL, CIEC_ANY::e_WSTRING, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
}

BOOST_AUTO_TEST_CASE(Explict_cast_operator_to_LREAL)
{
  CIEC_USINT nUsint(2);
  CIEC_UINT nUint(3);
  CIEC_UDINT nUdint(4);
  CIEC_ULINT nUlint(5);
  CIEC_SINT nSint(6);
  CIEC_INT nInt(7);
  CIEC_DINT nDint(8);
  CIEC_LINT nLint(9);
  CIEC_REAL nReal(10);
  CIEC_LREAL nLreal(11);
  CIEC_LWORD nLword(0x4026000000000000);

  CIEC_LREAL nResult(0);

  nResult = CIEC_ANY::cast<CIEC_LREAL>(nUsint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 2);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nUint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 3);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nUdint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 4);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nUlint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 5);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nSint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 6);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nInt);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 7);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nDint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 8);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nLint);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 9);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nReal);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 10);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nLreal);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 11);
  nResult = CIEC_ANY::cast<CIEC_LREAL>(nLword);
  BOOST_TEST(static_cast<CIEC_LREAL::TValueType>(nResult) == 11);
}

BOOST_AUTO_TEST_CASE(REAL_TO_LREAL_cast_constructor)
{
  CIEC_REAL realValue(36.0f);
  CIEC_LREAL lrealValue(realValue);

  BOOST_TEST(36.0 == static_cast<CIEC_LREAL::TValueType>(lrealValue));
}

BOOST_AUTO_TEST_SUITE_END()
