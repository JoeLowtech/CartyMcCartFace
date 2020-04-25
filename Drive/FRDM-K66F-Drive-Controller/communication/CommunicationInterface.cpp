#include "CommunicationInterface.h"

CommunicationInterface::CommunicationInterface(): codec(receiveBuffer,BUFFERSIZE)
{
    net = NetworkInterface::get_default_instance();
}

nsapi_size_or_error_t CommunicationInterface::start(){
    
    status = net->connect();
    if (status != 0){
       ERROR("No Connection established: %d\n",status);
    }
    else{
        INFO("nsapi-Code: %d IP address : %s, Port: %d\n",
            net->get_ip_address(&local), local.get_ip_address(), local.get_port());
        
        local.set_port(9999);

        status = listener.open(net);
        if (status != 0){
            ERROR("TCP Server Error: %d\n", status);
        }
        else{
            if ((status = listener.bind(local))){
                ERROR("TCP Server Error: Binding failed %d\n",status);    
            }
            else{
                if((status = listener.listen())){
                    ERROR("TCP Server Error: Listen failed %d\n",status);
                }
                else{
                    INFO("Start listening...\n");
                    client = listener.accept();
                    INFO("Client connected!\n");
                    client->getpeername(&clientAddress);
                    DEBUG("Client IP : %s\n",get_client_ip());
                }
            }
        
        }           
    }
    return status;
}

nsapi_size_or_error_t CommunicationInterface::recv(){
    
    if((receivedBytes = client->recv(receiveBuffer, BUFFERSIZE))){
        decodedMessage = driveMessage_init_zero;
        
        if(!codec.decode_msg(&decodedMessage)){
            ERROR("Received message not decoded\n");
        }
    }
    return receivedBytes;
}
