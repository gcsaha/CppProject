#include<iostream>
#include"AlarmClockService.hpp"
void startAlarmThread(AlarmClockService *a5,int timeInSecond)
{
  a5->startAlarm(timeInSecond);
}

int main()
{
  AlarmClockService a1(5);
  AlarmClockService a2(15);
  AlarmClockService a3(25);

  std::thread th1(startAlarmThread,&a1,10); 
  std::thread th2(startAlarmThread,&a2,15); 
  std::thread th3(startAlarmThread,&a3,20); 

  std::this_thread::sleep_for(std::chrono::seconds(2));
  a1.restartAlarm();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  a1.stopAlarm();
  th1.join();
  th2.join();
  th3.join();
  return 0;
}
