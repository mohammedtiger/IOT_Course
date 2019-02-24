/* mqtt_socket.h
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

/* Implementation by: David Garske
 * Based on specification for MQTT v3.1.1
 * See http://mqtt.org/documentation for additional MQTT documentation.
 */

#ifndef WOLFMQTT_SOCKET_H
#define WOLFMQTT_SOCKET_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "../MQTTLayer/mqtt_types.h"
#ifdef ENABLE_MQTT_TLS
    #if !defined(WOLFSSL_USER_SETTINGS) && !defined(USE_WINDOWS_API)
        #include <wolfssl/options.h>
    #endif
	#include <wolfssl/wolfcrypt/settings.h>
    #include <wolfssl/ssl.h>
    #include <wolfssl/wolfcrypt/types.h>

    #ifndef WOLF_TLS_DHKEY_BITS_MIN /* allow define to be overridden */
        #ifdef WOLFSSL_MAX_STRENGTH
            #define WOLF_TLS_DHKEY_BITS_MIN 2048
        #else
            #define WOLF_TLS_DHKEY_BITS_MIN 1024
        #endif
    #endif
#endif

/* Default Port Numbers */
#define MQTT_DEFAULT_PORT   1883
#define MQTT_SECURE_PORT    8883


struct _MqttClient;

/* Function callbacks */
typedef int (*MqttTlsCb)(struct _MqttClient* client);

typedef int (*MqttNetConnectCb)(const char* host, word16 port, int timeout_ms);



typedef int (*MqttNetWriteCb)(
    const byte* buf, int buf_len, int timeout_ms);
typedef int (*MqttNetReadCb)(
    byte* buf, int buf_len, int timeout_ms);
typedef int (*MqttNetDisconnectCb)();
typedef int (*MqttNetInitCb)(void );
/* Strucutre for Network Security */
#ifdef ENABLE_MQTT_TLS
typedef struct _MqttTls {
    WOLFSSL_CTX         *ctx;
    WOLFSSL             *ssl;
    int                 sockRc;
    int                 timeout_ms;
} MqttTls;
#endif

/* Structure for Network callbacks */
typedef struct _MqttNet {
    void                *context;
    MqttNetConnectCb    connect;
    MqttNetReadCb       read;
    MqttNetWriteCb      write;
    MqttNetDisconnectCb disconnect;
    MqttNetInitCb 		init;
} MqttNet;


/* MQTT SOCKET APPLICATION INTERFACE */
int MqttSocket_Init(struct _MqttClient *client, MqttNet* net);
int MqttSocket_Write(struct _MqttClient *client, const byte* buf, int buf_len,
    int timeout_ms);
int MqttSocket_Read(struct _MqttClient *client, byte* buf, int buf_len,
    int timeout_ms);

int MqttSocket_Connect(struct _MqttClient *client, const char* host,
    word16 port, int timeout_ms, int use_tls, MqttTlsCb cb);
int MqttSocket_Disconnect(struct _MqttClient *client);


#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLFMQTT_SOCKET_H */
