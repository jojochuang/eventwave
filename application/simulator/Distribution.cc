#include <iostream>
#include <fstream>
#include "Distribution.h"

using namespace std;

Distribution::Distribution() {
  values = NULL;
  numValues = 0;
}

Distribution::~Distribution() {
  delete [] values;
  numValues = 0;
}

int Distribution::load(istream& in) {
  
  in >> id;
  in >> numValues;
  
  if (!in) {
    return -1;
  }
  
  values = new uint64_t[numValues];
  
  for (int i = 0; i < numValues; i++) {
    double ignore;
    
    in >> ignore;
    in >> values[i];
  }
  return (in ? 0 : -1);
}

int Distribution::getNumValues() const {
  return numValues;
}

int Distribution::getValue(int index) const {
  return values[index];
}

string Distribution::getId() const {
  return id;
}
