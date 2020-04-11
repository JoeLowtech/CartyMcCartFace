#include "CommunicationInterface.h"

CommunicationInterface::CommunicationInterface(
        const char* remoteAddress, const uint16_t remotePort):
        remote(remoteAddress,remotePort)
{
    net = NetworkInterface::get_default_instance();
}

nsapi_size_or_error_t CommunicationInterface::connect(){
    
    status = net->connect();
    if (status != 0){
       INFO("No Connection established: %d\n",status);
    }
    else{
        INFO("Network-Connection: %d",status);
        INFO("nsapi-Code: %d IP address : %s\n",
            net->get_ip_address(&local), local.get_ip_address());
        
        status = socket.open(net);
        if (status != 0){
            INFO("TCP Socket Error: %d\n", status);
        }
        else{
            status = socket.connect(remote);
        }           
    }
    return status;
}