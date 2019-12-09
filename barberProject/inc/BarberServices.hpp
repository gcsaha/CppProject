#ifndef __BARBER_SERVICES_HPP__
#define __BARBER_SERVICES_HPP__
#include "ServiceTypes.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
class BarberServices
{
private:
	int customerId;
	string serviceName;
	int serviceDuration;
public:
	BarberServices(int _customerId);
	~BarberServices(){};
	string getServiceName();
	int getServiceDuration();
	int getCustomerId();
	void generateServiceAttribute();
};

BarberServices::BarberServices(int _customerId)
{
	unsigned char index;
	int ii;
	customerId = _customerId;
	index = static_cast<barberShopServiceType_t>(rand()%32);
	ii = static_cast<int>(valArray[index]);
	serviceDuration = serviceDurationVal[ii];
	serviceName = serviceNameArray[ii];
}
string BarberServices::getServiceName()
{
	return serviceName;
}
int BarberServices::getServiceDuration()
{
	return serviceDuration;
}
int BarberServices::getCustomerId()
{
	return customerId;
}
void BarberServices::generateServiceAttribute()
{
	unsigned char index;
	int ii;
	index = static_cast<barberShopServiceType_t>(rand()%32);
	ii = static_cast<int>(valArray[index]);
	serviceDuration = serviceDurationVal[ii];
	serviceName = serviceNameArray[ii];
}
#endif