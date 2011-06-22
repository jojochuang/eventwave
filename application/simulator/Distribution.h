#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

class Distribution {
protected:
  uint64_t* values;
  int numValues;
  std::string id;
  
public:
  Distribution();
  virtual ~Distribution();
  
  int load(std::istream& in);
  int getNumValues() const;
  int getValue(int index) const;
  std::string getId() const;
};

#endif // DISTRIBUTION_H
