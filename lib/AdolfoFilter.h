/* 
 * AdolfoFilter.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2007, Charles Killian, Dejan Kostic, Ryan Braud, James W. Anderson, John Fisher-Ogden, Calvin Hubble, Duy Nguyen, Justin Burke, David Oppenheimer, Amin Vahdat, Adolfo Rodriguez, Sooraj Bhat
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    * Neither the names of Duke University nor The University of
 *      California, San Diego, nor the names of the authors or contributors
 *      may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */
#include "GenericFilter.h"
#include <list>

/**
 * \file AdolfoFilter.h
 * \brief declares the adolfo_filter class
 */

/**
 * \addtogroup Filters
 * @{
 */
 
#ifndef __adolfo_filter
#define __adolfo_filter

/**
 * \brief provides an average bandwidth over a window of time, under an assumption of a fixed-size data packet.
 *
 * One of the problems of the Filters design is that the API for each one is
 * slightly different, and the base class doesn't really encapsulate the
 * functionality very well.  For example the update(double) function from the
 * base class would set the value, but it would get overridden when getValue()
 * is called, which would recompute the value based on the history list.
 *
 * adolfo_filter uses a history list, and each time update() is called, the
 * time is pushed onto the history list.  When checking the value, any times
 * older than the BANDWIDTH_WINDOW are removed.  Then, the size of the list,
 * multiplied by the 'data_packet_size' parameter, and divided by the window
 * time (adjusted for proper units), is used as the value.  The value is in
 * bits per second.
 */
class adolfo_filter:public GenericFilter 
{
 
 public:

  static const int BANDWIDTH_WINDOW_SBITS=2; ///< how long to keep average (seconds) in log of 2: 2^2 = 4 seconds
  static const uint64_t BANDWIDTH_WINDOW= (1<<BANDWIDTH_WINDOW_SBITS) * 1000*1000; ///< how long to keep average in micro-seconds

  adolfo_filter	();
  ~adolfo_filter	( );
  void  update (); ///< Should be called each time a data packet is received.  Assumed to all be the same size.
  void  clear (); ///< resets the value to 0
  double getValue(); ///< computes and returns the latest bandwidth window estimate
 protected:
  void check (); ///< removes old values from the history and sets value.
  std::list < uint64_t > history; 
  int data_packet_size;
};
/** @} */
#endif //__adolfo_filter
