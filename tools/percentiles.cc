#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "../lib/StatisticalFilter.h"

using namespace std;

int main() {

  double increment = 0.01;

  char* incStr = getenv("PERCENTILE_INCREMENT");
  if(incStr != NULL) {
    //     cerr << "GETENV: " << incStr << endl;
    sscanf(incStr, "%lf", &increment);
  }

  double val;
  StatisticalFilter fil;
  while(!cin.eof()) {
    cin >> val;
    fil.update(val);
  }

  int values = fil.getCount();
  if (increment * values < 1.0) {
    increment = 1.0 / (values-1);
  }
  
  cout << setprecision(16);
  cout << 0.0 << " " << fil.percentileToValue(0.0) << endl;
  for(double iter = increment; iter < 1.0; iter += increment) {
    cout << iter << " " << fil.percentileToValue(iter) << endl;
  }
  cout << 1.0 << " " << fil.percentileToValue(1.0) << endl;
  return 0;
}
