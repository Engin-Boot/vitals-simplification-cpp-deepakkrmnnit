#include<iostream>
#include <assert.h>
const int bpmlimits[]={70,150};
const int spo2limits[]={90};
const int respRatelimits[]={30,95};
class alert
{
      public:
      	virtual void SendAlert(char* vitalName, char* message)=0;
	
};
class AlertInSms:public alert
{
       public:
         void SendAlert(char* vitalName, char* message) override
         {
                std::cout<<vitalName<<" "<<message<<std::endl;
                std::cout<<"sms sent"<<std::endl;
         }
};
class AlertInSound:public alert
{
       public:
         void SendAlert(char* vitalName,char* message) override
         {
                std::cout<<vitalName<<" "<<message<<std::endl;
                std::cout<<"Alertsound"<<std::endl;
         }
};
bool bpmIsOk(float bpm,int lower,int upper)
{
       if(bpm>lower && bpm<upper)
       {
              return true;
       }
       AlertInSms a;
       AlertInSound b;
	    a.SendAlert("bpm","is not ok");
	    b.SendAlert("bpm","is not ok");
       return false;
}
bool spo2IsOk(float spo2,int lower)
{
       if(spo2>lower)
       {
              return true;
       }
       AlertInSms a;
       AlertInSound b;
	   a.SendAlert("spo2","is not ok");
	   b.SendAlert("spo2","is not ok");
       return false;
}
bool respRateIsOk(float respRate,int lower, int upper)
{
       if(respRate>lower && respRate<upper)
       {
              return true;
       }
       AlertInSms a;
      AlertInSound b;
	   a.SendAlert("resprate","is not ok");
	   b.SendAlert("resprate","is not ok");
       return false;
}


bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (bpmIsOk(bpm,bpmlimits[0],bpmlimits[1]) && spo2IsOk(spo2,spo2limits[0]) && respRateIsOk(respRate,respRatelimits[0],respRatelimits[1]));
}

int main() {
  assert(bpmIsOk(4, 3, 7) == true);
  assert(bpmIsOk(70, 10, 20) == false);
  assert(bpmIsOk(5, 10, 20) == false);
  assert(spo2IsOk(100,95) == true);
  assert(spo2IsOk(5,10) == false);
  assert(spo2IsOk(120,100) == true);
  assert(respRateIsOk(40, 30, 70) == true);
  assert(respRateIsOk(7, 1, 2) == false);
  assert(respRateIsOk(50, 100, 120) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
