#include<iostream>
#include <assert.h>
const int bpmlimits[]={70,150};
const int spo2limits[]={90};
const int respRatelimits[]={30,95};
bool bpmIsOk(float bpm)
{
       return (bpm>bpmlimits[0] && bpm<bpmlimits[1]);  
}
bool spo2IsOk(float spo2)
{
       return (spo2>spo2limits[0]);  
}
bool respRateIsOk(float respRate)
{
       return (respRate>respRatelimits[0] && respRate<bpmlimits[1]);  
}

bool bpmOk(float value, int lower, int upper)
{
       return ((value>=lower)&& (value<=upper));
}
bool spo2Ok(float value, int lower)
{
       return (value>=lower);
}
bool respRateOk(float value, int lower, int upper)
{
       return ((value>=lower)&& (value<=upper));
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (bpmIsOk(bpm) && spo2IsOk(spo2) && respRateIsOk(respRate));
}

int main() {
  assert(bpmOk(4, 3, 7) == true);
  assert(bpmOk(70, 10, 20) == false);
  assert(bpmOk(5, 10, 20) == false);
  assert(spo2Ok(100,95) == true);
  assert(spo2Ok(20,10) == false);
  assert(spo2Ok(120,100) == false);
  assert(respRateOk(40, 30, 70) == true);
  assert(respRateOk(7, 1, 2) == false);
  assert(respRateOk(50, 100, 120) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
