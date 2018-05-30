#include <utils.h>
#include <timeDriver.h>

void sleep(unsigned int secs){
  unsigned int s, os, count;
  count = 0;
  s = os = getSec();
  while (count < secs) {
    if (s != os) {
      count ++;
    }
    os = s;
    s = getSec();
  }
}
