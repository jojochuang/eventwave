#include "CircularBuffer.h"
#include "FileUtil.h"

void CircularBuffer::copy(int fd) {
  if (written < size) {
    FileUtil::write(fd, data, written);
  }
  else {
    FileUtil::write(fd, data + start, size - start);
    FileUtil::write(fd, data, start);
  }
  written = 0;
  start = 0;
} // copy
