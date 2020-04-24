#include "Codec.h"


Codec::Codec(uint8_t* buffer, uint8_t buffersize){
    input = pb_istream_from_buffer(buffer, buffersize);
}


bool Codec::decode_msg(driveMessage *message){
    return pb_decode(&input, driveMessage_fields, message);  
}    