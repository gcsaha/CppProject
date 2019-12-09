#ifndef __ALARM_CLOCK_SERVICE_HPP__
#define __ALARM_CLOCK_SERVICE_HPP__

#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
#include<condition_variable>
class AlarmClockService
{
  private:
	std::condition_variable cv;
	std::mutex mtx;
	bool restart;
	int _timeInSecond;
  public:
    AlarmClockService(int timeInSecond);
    ~AlarmClockService(){};
	void restartAlarm(int timeInSecond );
	void stopAlarm();
	void startAlarm(int timeInSecond);
};
AlarmClockService::AlarmClockService(int timeInSecond )
{
	_timeInSecond = timeInSecond;
}
void AlarmClockService::stopAlarm()
{
  std::cout<<"Inside stopAlarm :: we are stoping this alarm"<<std::endl;
  cv.notify_one();
}
void AlarmClockService::restartAlarm(int timeInSecond=0)
{
  std::unique_lock<std::mutex> lck(mtx);
  if(timeInSecond !=0)
  {
    _timeInSecond=timeInSecond;
  }
  std::cout<<"Inside restartAlarm :: we are restarting the timer"<<std::endl;
  restart = true;
  lck.unlock();
  cv.notify_one();
}
void AlarmClockService::startAlarm(int timeInSecond = 0)
{
  restart = false;
  std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
  if(timeInSecond !=0 )
  {
  	_timeInSecond = timeInSecond;
  }
  do{
	lck.lock();
	std::cout<<" Alarm time  :: "<<_timeInSecond <<" "<<std::endl;
	lck.unlock();
	lck.lock();
	cv.wait_for(lck,std::chrono::seconds(_timeInSecond));
	if(restart == false)
	{
	  std::cout<<"Either timed out or asked to stop"<<std::endl;
	  lck.unlock();
	}
	else 
	{
	  restart = false;
	  lck.unlock();
	  lck.lock();
	  std::cout<<" Alarm time  :: "<<_timeInSecond <<" "<<std::endl;
	  cv.wait_for(lck,std::chrono::seconds(_timeInSecond));
	  std::cout<<"After reset :: Either timed out or asked to stop"<<std::endl;
	  lck.unlock();
	}
  }while(restart == true);
}
#endif
