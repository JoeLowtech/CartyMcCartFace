#include "CommunicationInterface.h"

CommunicationInterface::CommunicationInterface(): codec()
{
    net = NetworkInterface::get_default_instance();
}

nsapi_size_or_error_t CommunicationInterface::start(){
    
    status = net->connect();
    if (status != 0){
       ERROR("No Connection established: %d",status);
    }
    else{
        INFO("nsapi-Code: %d IP address : %s, Port: %d",
            net->get_ip_address(&local), local.get_ip_address(), local.get_port());
        
        local.set_port(9999);


        status = listener.open(net);
        if (status != 0){
            ERROR("TCP Server Error: %d", status);
        }
        else{
            if ((status = listener.bind(local))){
                ERROR("TCP Server Error: Binding failed %d",status);    
            }
            else{
                if((status = listener.listen())){
                    ERROR("TCP Server Error: Listen failed %d",status);
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
    }
    return receivedBytes;
}


