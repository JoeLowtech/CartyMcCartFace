/*
    Class for Communication between the MCU and another device
 */
#ifndef COMMUNICATION_INTERFACE_H
#define COMMUNICATION_INTERFACE_H

#include "mbed.h"
#include "logger.h"

 class CommunicationInterface{
    private:
        NetworkInterface *net;
        nsapi_size_or_error_t status;
        SocketAddress local, clientAddress;
        TCPSocket listener;
        TCPSocket* client = NULL;

        static constexpr uint8_t BUFFERSIZE = 255;
        uint8_t receiveBuffer[BUFFERSIZE];
        uint8_t receivedBytes = 0;

    public:
        CommunicationInterface();
        
        nsapi_size_or_error_t start();
        void send();
        nsapi_size_or_error_t recv();
        nsapi_size_or_error_t get_status(){
            return status;
        }
        const char* get_client_ip(){
            return clientAddress.get_ip_address();
        }
 };
 #endif