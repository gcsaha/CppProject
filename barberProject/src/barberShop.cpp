#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <condition_variable>
#include "BarberServices.hpp"

using namespace std;

mutex queueLock;
queue<BarberServices *> myQueue;
condition_variable cond;
bool threadLife[20];

void barber(int th)
{
	int val = -9999;
	BarberServices *bs;
	while(threadLife[th - 1])
	{
		unique_lock<mutex> lk(queueLock);
		if(myQueue.empty())
		{
			cout<<"Barber "<<th<<" :: I am going to sleep"<<endl;
		    cond.wait(lk); // wait till any customer arrives.
		    cout<<"Barber "<<th<<" Got signal. Received customer"<<endl;
		    lk.unlock();
		}
		else
		{
			bs = myQueue.front();
			val = bs->getServiceDuration();
			myQueue.pop();
			cout<<"Barber "<<th<< " ...giving service to "<<bs->getCustomerId()<<" as "<<bs->getServiceName()<<" to customer for "<<val<<" Sec"<<endl;
			::delete bs;
			lk.unlock();
			this_thread::sleep_for(std::chrono::seconds(val));
		}
	}
	cout<<"Exiting from Barber thread "<<th<<endl;
}


void customerQueueManager()
{
	int customerId=1;
	int barberId = 2;
	int extra_wait_time = 0;
	int i=0;
	int count =0;
	while(count < 3)
	{
		auto numberOfCostomer = 1 + rand()%5;
		unique_lock<mutex> lk(queueLock);
		cout<<"customerQueueManager :: adding "<<numberOfCostomer<<"  customer"<<endl;

		for(auto p=1;p<=numberOfCostomer;p++)
		{
			if(myQueue.size() >= MAX_WAITING_CUSTOMER)
			{   
				cout<<"Current Queue size = "<<myQueue.size()<<endl;
				cout<<"Add more Barber barberId = "<<barberId<<endl;
				threadLife[barberId -1] = true;
				::new thread(barber,barberId);
				extra_wait_time = (rand()%15);
				barberId++;
				break;
			}
			else 
			{
				myQueue.push(::new BarberServices(customerId));
				customerId++;
			}
		}
		i++;
		sadfad
		auto sleepTime = extra_wait_time + 1 + rand()%14;
		extra_wait_time = 0;
		cout<<"I am customerQueueManager going to sleep for : "<<sleepTime<<endl;
		cout<<"cirrent queue size = "<<myQueue.size()<<endl;
		lk.unlock();
		cond.notify_all();
		this_thread::sleep_for(std::chrono::seconds(sleepTime));
		count++;
	}
	cout<<"Exiting from customerQueueManager"<<endl;
}

int main()
{
	srand(time(NULL));
	//thread threads[20];
	threadLife[0]=true;
	for(auto i=1;i<20;i++)
		threadLife[i]=false;
	thread t1(customerQueueManager);
	thread t2(barber,1);
	t1.join();
	for(auto i=0;i<20;i++)
		threadLife[i]=false;
	t2.join();
	return 0;
}
