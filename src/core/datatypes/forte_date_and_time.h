/*******************************************************************************
 * Copyright (c) 2008, 2023 nxtControl GmbH, ACIN, fortiss GmbH
 *                          Primetals Technologies Austria GmbH
 *                          Martin Erich Jobst
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Stanislav Meduna, Alois Zoitl, Martin Melik Merkumians, Monika Wenger
 *      - initial implementation and rework communication infrastructure
 *    Martin Melik Merkumians - make TForteUInt64 constructor explicit,
 *        removed built-in type operator=, removed operator++
 *    Martin Jobst - add user-defined literal
 *******************************************************************************/
#ifndef _FORTE_DATE_AND_TIME_H_
#define _FORTE_DATE_AND_TIME_H_

#include "forte_any_date.h"
#include <forte_architecture_time.h>

/*!\ingroup COREDTS CIEC_DATE_AND_TIME represents the time data types according to IEC 61131.
 */

class CIEC_DATE_AND_TIME final : public CIEC_ANY_DATE {
    DECLARE_FIRMWARE_DATATYPE(DATE_AND_TIME)
  public:
    [[deprecated("Please use the corresponding numeric_limits template")]]
    constexpr static size_t scmBitLength = 64U;

    CIEC_DATE_AND_TIME() = default;

    CIEC_DATE_AND_TIME(const CIEC_DATE_AND_TIME& paValue) : CIEC_ANY_DATE() {
      setValueSimple(paValue);
    }

    explicit CIEC_DATE_AND_TIME(const TValueType paValue) {
      setTUINT64(paValue);
    }

    ~CIEC_DATE_AND_TIME() override = default;

    CIEC_DATE_AND_TIME& operator = (const CIEC_DATE_AND_TIME &paValue){
      // Simple value assignment - no self assignment check needed
      setValueSimple(paValue);
      return *this;
    }

  /*! \brief Converts CIEC_TIME to unsigned 64 bit integer
   *
   *   Conversion operator for converting CIEC_TIME to unsigned 64 bit integer
   */
    operator TForteUInt64() const {
      return getTUINT64();
    }

    EDataTypeID getDataTypeID() const override {
      return CIEC_ANY::e_DATE_AND_TIME;
    }

  /*! \brief Converts string value to data type value
   *
   *   This command implements a conversion function from IEC 61131
   *   data type (string format) to a C++ conform type.
   *   This function is necessary for communication with a proper engineering system.
   *   \param paValue  Pointer to the given String
   *   \return Can be the following response:
   *   \return number of bytes taken used from the buffer
   *        -1 on on error
   */
    int fromString(const char *paValue) override;
      /*! \brief Converts data type value to string - use local time
       *
       *   This command implements a conversion function from C++ data type
       *   to IEC 61131 conform data type (string format).
       *   This function is necessary for communication with a proper engineering system.
       *   \param paValue Pointer to the provided buffer
       *   \param paBufferSize Size of the provided buffer
       *   \return number of bytes used in the buffer without trailing 0x00
       *           -1 on error
       */
    int toString(char* paValue, size_t paBufferSize) const override;

      /*! \brief Converts data type value to string - use GMT time
       *   \param paValue Pointer to the provided buffer
       *   \param paBufferSize Size of the provided buffer
       *   \return number of bytes used in the buffer without trailing 0x00
       *           -1 on error
       */
    int toGMTString(char* paValue, unsigned int paBufferSize) const;

    /*! \brief calculates buffer size needed for toString conversion
     */
    size_t getToStringBufferSize() const override {
      return sizeof("DT#1970-01-01-00:00:00.000");
    }
};

inline bool operator==(const CIEC_DATE_AND_TIME left, const CIEC_DATE_AND_TIME &right) {
  return static_cast<TForteUInt64>(left) == static_cast<TForteUInt64>(right);
}

inline bool operator!=(const CIEC_DATE_AND_TIME left, const CIEC_DATE_AND_TIME &right) {
  return !(left == right);
}

inline CIEC_DATE_AND_TIME operator ""_DATE_AND_TIME(unsigned long long int paValue) {
  return CIEC_DATE_AND_TIME(static_cast<CIEC_DATE_AND_TIME::TValueType>(paValue));
}

namespace std {
  template <>
  struct numeric_limits<CIEC_DATE_AND_TIME> : public forte::templates::numeric_limits<CIEC_DATE_AND_TIME> {
    static constexpr size_t bitLength = 64U;
  };
}

#endif /*_FORTE_DATE_AND_TIME_H_*/
