#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <stdint.h>
#include <string.h>
#include "massert.h"

class CircularBuffer {
private:
  char* data;
  uint64_t size;
  uint64_t start;
  uint64_t written;

public:
  CircularBuffer(uint64_t sz) : size(sz), start(0), written(0) {
    data = new char[size];
  }

  virtual ~CircularBuffer() {
    delete[] data;
  }

  void write(const char* buf, uint32_t len) {
    if (len > size) {
      memcpy(data, buf + len - size, size);
      start = 0;
    }
    ASSERT(start < size);
    uint64_t rem = size - start;
    if (len < rem) {
      memcpy(data + start, buf, len);
      start += len;
    }
    else {
      memcpy(data + start, buf, rem);
      memcpy(data, buf + rem, len - rem);
      start = len - rem;
    }
    ASSERT(start < size);
    written += len;
  } // write

  void copy(int fd);

};

#endif // _CIRCULAR_BUFFER_H
