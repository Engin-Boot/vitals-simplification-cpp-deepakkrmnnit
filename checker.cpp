#include <assert.h>
const int bpmlimits[]={70,150};
const int spo2limits[]={90};
const int respRatelimits[]={30,95};
bool bpmIsOk(fload bpm)
{
       return (bpm>bpmlimits[0] && bpm<bpmlimits[1]);  
}
bool spo2IsOk(fload spo2)
{
       return (spo2<spo2limits[0]);  
}
bool respRateIsOk(fload respRate)
{
       return (bpm>respRatelimits[0] && respRate<bpmlimits[1]);  
}


bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (bpmIsOk(bpm) && spo2IsOk(spo2) && respRateIsOk(respRate));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
