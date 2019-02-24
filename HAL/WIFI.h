/*
 * WIFI.h
 *
 *  Created on: 9 Feb 2019
 *      Author: root
 */

#ifndef WIFI_H_
#define WIFI_H_

#include "../NWAL/MQTTLayer/mqtt_types.h"

void WIFI_Init(void);
int WIFI_Rounter_Connect(char *ssid , char *pass , long timeout);
int WIFI_Send_Arr(const byte *arr , int size);
void EF_Number_to_String(unsigned char * u8NumberArray, unsigned char u8NumberArraySize, unsigned char * u8StringArray, unsigned char u8StringArraySize);
int WIFI_Receive(char *arr);
int WIFI_IP_Connect(char *protocol,const char*IP , int port , long timeout);
int WIFI_IP_Send(char *data , int len ,  long timeout);

void WIFI_ATCOMMAND_DELAY(long timeout);
int WIFI_Read_Data(char *arr , int size);
void WIFI_QUEUE_FLUSH();


#endif /* WIFI_H_ */
