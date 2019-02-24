/* mqttexample.h
 *
 * Copyright (C) 2006-2016 wolfSSL Inc.
 *
 * This file is part of wolfMQTT.
 *
 * wolfMQTT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfMQTT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef WOLFMQTT_EXAMPLE_H
#define WOLFMQTT_EXAMPLE_H

#include "mqtt_client.h"
#include "../MQTTSocket/mqttnet.h"

/* Default Configurations */
#define DEFAULT_CMD_TIMEOUT_MS  			3000
#define DEFAULT_CON_TIMEOUT_MS  			5000
#define DEFAULT_KEEP_ALIVE_SEC  			1200
#define DEFAULT_CLEAN_SECETION  			1

/*======================================================================================================
 *
 * 									 Thing Speaks config
 *
 *======================================================================================================
 *  */
#ifdef THINGSPEAK_IP
//mqtt quality of service (0 , 1 , 2)
#define DEFAULT_MQTT_QOS       	 			MQTT_QOS_0
#define SUBSCRIBE_MQTT_QOS       	 		MQTT_QOS_0

//mqtt username its should be unique
#define MQTT_USERNAMR 						"sXswAFtktigerpn"
//mqtt pass from thingspeak site
#define MQTT_PASSWORD						"93OT3R2BS4JY96S1"

//mqtt ID its should be unique
#define DEFAULT_CLIENT_ID       			"sXswAFtkpnFab"

//mqtt publish topics
#define PUBLISH_1_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field1/DGAJEZCGD29CCQ6C"
//#define PUBLISH_2_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field2/DGAJEZCGD29CCQ6C"
//#define PUBLISH_3_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field3/DGAJEZCGD29CCQ6C"
//#define PUBLISH_4_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field4/DGAJEZCGD29CCQ6C"
//#define PUBLISH_5_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field5/DGAJEZCGD29CCQ6C"
//#define PUBLISH_6_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field6/DGAJEZCGD29CCQ6C"
//#define PUBLISH_7_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field7/DGAJEZCGD29CCQ6C"
//#define PUBLISH_8_TOPIC_NAME_TEMP_T    		"channels/537822/publish/fields/field8/DGAJEZCGD29CCQ6C"

#define PUBLISH_1_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field1/T2O1252Y25QG01LB"
//#define PUBLISH_2_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field2/T2O1252Y25QG01LB"
//#define PUBLISH_3_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field3/T2O1252Y25QG01LB"
//#define PUBLISH_4_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field4/T2O1252Y25QG01LB"
//#define PUBLISH_5_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field5/T2O1252Y25QG01LB"
//#define PUBLISH_6_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field6/T2O1252Y25QG01LB"
//#define PUBLISH_7_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field7/T2O1252Y25QG01LB"
//#define PUBLISH_8_TOPIC_NAME_LIGHT_T    	"channels/550293/publish/fields/field8/T2O1252Y25QG01LB"

//mqtt default publish topic
#define DEFAULT_TOPIC_NAME     	 	 		PUBLISH_1_TOPIC_NAME_TEMP_T

//mqtt subscribe topics
#define SUBSCRIBE_1_TOPICS_NAME        		"channels/578852/subscribe/fields/field1/ZUHQQEWR2DPNR7G8"
//#define SUBSCRIBE_2_TOPICS_NAME        		"channels/554578/subscribe/fields/field2/K9GD5I5Y92HQXTJW"
//#define SUBSCRIBE_3_TOPICS_NAME        		"channels/554578/subscribe/fields/field3/K9GD5I5Y92HQXTJW"
//#define SUBSCRIBE_4_TOPICS_NAME        		"channels/554578/subscribe/fields/field4/K9GD5I5Y92HQXTJW"
//#define SUBSCRIBE_5_TOPICS_NAME        		"channels/554578/subscribe/fields/field5/K9GD5I5Y92HQXTJW"
//#define SUBSCRIBE_6_TOPICS_NAME        		"channels/554578/subscribe/fields/field6/K9GD5I5Y92HQXTJW"
//#define SUBSCRIBE_7_TOPICS_NAME        		"channels/554578/subscribe/fields/field7/K9GD5I5Y92HQXTJW"
//#define SUBSCRIBE_8_TOPICS_NAME        		"channels/554578/subscribe/fields/field8/K9GD5I5Y92HQXTJW"

//mqtt default subscribe topic
#define SUBSCRIBE_TOPICS     		 		SUBSCRIBE_1_TOPICS_NAME
#endif
/*======================================================================================================
 *
 * 									 Ubidots config
 *
 *======================================================================================================
 *  */
#ifdef UBIDOTS_IP
//mqtt quality of service (0 , 1 , 2)
#define DEFAULT_MQTT_QOS       	 			MQTT_QOS_1
#define SUBSCRIBE_MQTT_QOS       	 		MQTT_QOS_0

//mqtt Username from ubidots site
#define MQTT_USERNAMR 						"BBFF-UsVSjZvsJOETFPFSoTpjxSymuLZJG8"
#define MQTT_PASSWORD						""

//mqtt username its should be unique
#define DEFAULT_CLIENT_ID       			"sXswAFtkpnEmmFabu"

//mqtt publish topics
#define PUBLISH_1_TOPIC_NAME_TEMP_U     	 "/v1.6/devices/ef/t-1-"
//#define PUBLISH_2_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-2-"
//#define PUBLISH_3_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-3-"
//#define PUBLISH_4_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-4-"
//#define PUBLISH_5_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-5-"
//#define PUBLISH_6_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-6-"
//#define PUBLISH_7_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-7-"
//#define PUBLISH_8_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-8-"
//#define PUBLISH_9_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-9-"
//#define PUBLISH_10_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-10-"
//#define PUBLISH_11_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-11-"
//#define PUBLISH_12_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-12-"
//#define PUBLISH_13_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-13-"
//#define PUBLISH_14_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-14-"
//#define PUBLISH_15_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-15-"
#define PUBLISH_16_TOPIC_NAME_TEMP_U    	"/v1.6/devices/ef/t-16-"

#define PUBLISH_1_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-1-"
//#define PUBLISH_2_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-2-"
//#define PUBLISH_3_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-3-"
//#define PUBLISH_4_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-4-"
//#define PUBLISH_5_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-5-"
//#define PUBLISH_6_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-6-"
//#define PUBLISH_7_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-7-"
//#define PUBLISH_8_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-8-"
//#define PUBLISH_9_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-9-"
//#define PUBLISH_10_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-10-"
//#define PUBLISH_11_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-11-"
//#define PUBLISH_12_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-12-"
//#define PUBLISH_13_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-13-"
//#define PUBLISH_14_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-14-"
//#define PUBLISH_15_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-15-"
//#define PUBLISH_16_TOPIC_NAME_LIGHT_U    	"/v1.6/devices/ef/l-16-"

#define PUBLISH_1_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-1-"
//#define PUBLISH_2_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-2-"
//#define PUBLISH_3_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-3-"
//#define PUBLISH_4_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-4-"
//#define PUBLISH_5_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-5-"
//#define PUBLISH_6_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-6-"
//#define PUBLISH_7_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-7-"
//#define PUBLISH_8_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-8-"
//#define PUBLISH_9_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-9-"
//#define PUBLISH_10_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-10-"
//#define PUBLISH_11_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-11-"
//#define PUBLISH_12_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-12-"
//#define PUBLISH_13_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-13-"
//#define PUBLISH_14_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-14-"
//#define PUBLISH_15_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-15-"
//#define PUBLISH_16_TOPIC_NAME_POTEN_U    	"/v1.6/devices/ef/p-16-"


//mqtt default publish topic
#define DEFAULT_TOPIC_NAME     	 	 		PUBLISH_16_TOPIC_NAME_TEMP_U

//mqtt subscribe topics
#define SUBSCRIBE_1_TOPICS_NAME        "/v1.6/devices/sub_embedeedfab2018/embeddedfab2018"

//mqtt default subscribe topic
#define SUBSCRIBE_TOPICS     		 		SUBSCRIBE_1_TOPICS_NAME
#endif
/*======================================================================================================
 *
 * 									 EmbeddedFab config
 *
 *======================================================================================================
 *  */
#ifdef EMBEDDEDFAB_IP
//mqtt quality of service (0 , 1 , 2)
#define DEFAULT_MQTT_QOS       	 				MQTT_QOS_1
#define SUBSCRIBE_MQTT_QOS       	 			MQTT_QOS_0

//mqtt Username from ubidots site
#define MQTT_USERNAMR 						""
#define MQTT_PASSWORD						""

//mqtt username its should be unique
#define DEFAULT_CLIENT_ID       			"MQTT_1"

//mqtt publish topics
#define PUBLISH_1_TOPIC_NAME_TEMP_E     	 "Node"



//mqtt default publish topic
#define DEFAULT_TOPIC_NAME     	 	 		PUBLISH_1_TOPIC_NAME_TEMP_E

//mqtt subscribe topics
#define SUBSCRIBE_1_TOPICS_NAME        		"Gate"

//mqtt default subscribe topic
#define SUBSCRIBE_TOPICS     		 		SUBSCRIBE_1_TOPICS_NAME
#endif
/*======================================================================================================
 *
 * 									 MQTT config
 *
 *======================================================================================================
 *  */


#define PUBLISH_MESSAGE     	 			"Embedded"
#define SUBSCRIBE_TOPICS_EX     	 		4


#define PRINT_BUFFER_SIZE       			5
#define MSG_BUFFER_SIZE	        			80
#define MAX_PACKET_ID           			((1 << 16) - 1)

#define MQTT_RECEIVE_FRAME_SERVER 			false

#if MQTT_RECEIVE_FRAME_SERVER
#define MSG_RXBUFFER_SIZE	        		80
#else
#define MSG_RXBUFFER_SIZE	        		80


#endif

#endif /* WOLFMQTT_EXAMPLE_H */
