
#include "../Services_layers/Speical_Timer.h"
#include "../Services_layers/String_Queue.h"
#include "../Services_layers/Special_Uart.h"
#include "../Services_layers/Services_layers.h"
#include "../NWAL/MQTTLayer/mqtt_client_cfg.h"
#include "../NWAL/MQTTLayer/mqtt_client.h"
#include "../HAL/WIFI.h"
#include <avr/delay.h>
#include <avr/io.h>
#include <string.h>
#include "../HAL/F90_Temperature.h"


MqttNet mqtt_Socket;

MqttClient mqtt_user;



//create buffer that carry data to transmit (mqtt data)
unsigned char MQTT_Tx_Array[MSG_BUFFER_SIZE] = {0};

//create buffer that carry data to receive (mqtt data)
unsigned char MQTT_Rx_Array[MSG_RXBUFFER_SIZE] = {0};




int main ()
{

	MqttClientNet_Init(&mqtt_Socket);

	MqttClient_Init(&mqtt_user , &mqtt_Socket , mqttclient_message_cb ,MQTT_Tx_Array,sizeof(MQTT_Tx_Array),MQTT_Rx_Array,sizeof(MQTT_Rx_Array) ,1000);


	while(1)
	{

		while(!WIFI_Rounter_Connect("Embeddedfab" , "Embeddedfab135" , 7000));

		MqttClient_NetDisconnect(&mqtt_user );
		MqttClient_NetConnect(&mqtt_user , "169.55.61.243" , 1883 , 1500 , false , NULL);

		MqttConnect mqtt_information;
		memset(&mqtt_information , 0 , sizeof(mqtt_information));

		mqtt_information.username = "BBFF-WCLtgOtq4oy8Po85nu6vdHMeZCQByP";
		mqtt_information.password = "";
		mqtt_information.keep_alive_sec = DEFAULT_KEEP_ALIVE_SEC;
		mqtt_information.clean_session = DEFAULT_CLEAN_SECETION;
		mqtt_information.client_id = "jhkjashdjkhciuhqwdkbs";
		mqtt_information.enable_lwt = 0;



		int rc = MqttClient_Connect(&mqtt_user ,&mqtt_information);

		if(rc == MQTT_CODE_SUCCESS)
		{


			while(1)
			{

				unsigned char Temp_arr[2][15];
				unsigned char Topic[2][45];
				int Len[2];
				memset(Temp_arr , 0 ,sizeof(Temp_arr));

				int temp = F90_int_Temp_Read();

				memcpy(Topic[ADC_PIN_TEMP] , "/v1.6/devices/Temper/temp" , sizeof("/v1.6/devices/Temper/temp"));
				Len[ADC_PIN_TEMP] = sprintf(Temp_arr[ADC_PIN_TEMP] , "{\"value\":%d}" , temp);

				int LDR = F90_int_LDR_Read();

				memcpy(Topic[ADC_PIN_LDR] , "/v1.6/devices/LDR/LDR" , sizeof("/v1.6/devices/LDR/LDR"));
				Len[ADC_PIN_LDR] = sprintf(Temp_arr[ADC_PIN_LDR] , "{\"value\":%d}" , LDR);


				MqttPublish publish;
				memset(&publish, 0, sizeof(MqttPublish));
				publish.retain = 0;
				publish.qos = 1;
				publish.duplicate = 1;
				publish.topic_name = Topic[ADC_PIN_TEMP];
				publish.packet_id = mqttclient_get_packetid();

				publish.buffer = (byte*)Temp_arr[ADC_PIN_TEMP];
				publish.total_len = (word16)Len[ADC_PIN_TEMP];
				int rc = MqttClient_Publish(&mqtt_user, &publish);

				rc = MqttClient_Publish(&mqtt_user, &publish);





				if(rc != MQTT_CODE_SUCCESS)
					break;


			}
		}
	}


	return 0;
}









//#include "../HAL/WIFI.h"
//
//
//
//typedef void (*Init_t)(void);
//typedef int (*write_arr_t)(unsigned char * , int len);
//typedef int (*read_arr_t)(char *);
//
//
//typedef struct Wifi_ptr
//{
//	Init_t Init;
//	write_arr_t write_arr;
//	read_arr_t read_arr;
//}Wifi_ptr_t;
//
//
//void Net_Init(Wifi_ptr_t *me)
//{
//
//	if(me)
//	{
//		me->Init = WIFI_Init;
//		me->read_arr = WIFI_Receive;
//		me->write_arr = WIFI_Send_Arr;
//	}
//
//}
//
//Wifi_ptr_t wifi;
//
//
//Wifi_ptr_t Ethernet;
//
//
//int main ()
//{
//
//	Net_Init(&wifi);
//
//
//	wifi.Init();
//
//	wifi.write_arr("hello" , 5);
//
//
//	return 0 ;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

//

//	MqttSubscribe subscribe;
//	MqttTopic topics;
//
//	topics.topic_filter = "Hazem";
//	topics.qos = 0;
//
//	memset(&subscribe, 0, sizeof(MqttSubscribe));
//	subscribe.packet_id = mqttclient_get_packetid();
//	subscribe.topic_count = sizeof(topics)/sizeof(MqttTopic);
//	subscribe.topics = &topics;
//
//	mqtt_user.msg.stat = MQTT_MSG_BEGIN;
//	MqttClient_Subscribe(&mqtt_user, &subscribe);
