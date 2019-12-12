#ifndef __BARBER_SERVICES_HPP__
#define __BARBER_SERVICES_HPP__
#include "ServiceTypes.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief      This class describes barber services.
 */
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

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  _customerId  The customer identifier
 */
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

/**
 * @brief      Gets the service name.
 *
 * @return     The service name.
 */
string BarberServices::getServiceName()
{
	return serviceName;
}

/**
 * @brief      Gets the service duration.
 *
 * @return     The service duration.
 */
int BarberServices::getServiceDuration()
{
	return serviceDuration;
}

/**
 * @brief      Gets the customer identifier.
 *
 * @return     The customer identifier.
 */
int BarberServices::getCustomerId()
{
	return customerId;
}

/**
 * @brief      Generate service attributes.
 */
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