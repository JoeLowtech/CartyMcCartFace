/*
    Class for Communication between the MCU and another device
 */
#ifndef COMMUNICATION_INTERFACE_H
#define COMMUNICATION_INTERFACE_H

#include "mbed.h"
#include "logger.h"
#include "Codec.h"

 class CommunicationInterface{
    private:
        NetworkInterface *net;
        nsapi_size_or_error_t status;
        SocketAddress local, clientAddress;
        TCPSocket listener;
        TCPSocket* client = NULL;

        static constexpr uint8_t BUFFERSIZE = 255;
        uint8_t receiveBuffer[BUFFERSIZE];
        nsapi_size_or_error_t receivedBytes;

    public:
        Codec codec;

        CommunicationInterface();

        nsapi_size_or_error_t start();
        void send();
        nsapi_size_or_error_t recv();
        driveMessage* decode(){
                   codec.decode_msg(receiveBuffer, receivedBytes);
            return codec.get_decoded_message();
        }
        nsapi_size_or_error_t get_status(){
            return status;
        }
        const char* get_client_ip(){
            return clientAddress.get_ip_address();
        }
 };


 #endif