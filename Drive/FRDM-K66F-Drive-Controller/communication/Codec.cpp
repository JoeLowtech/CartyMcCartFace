#include "Codec.h"


Codec::Codec(){
}

bool Codec::decode_msg(uint8_t* messageBuffer,uint8_t messageSize){
    input = pb_istream_from_buffer(messageBuffer, messageSize);
    decodedMessage = driveMessage_init_zero;
    bool error_message = false;

    if(!(error_message = pb_decode_ex(&input,
                                       driveMessage_fields,
                                       &decodedMessage,
                                       PB_DECODE_DELIMITED))){
            ERROR("Received message not decoded: %s", PB_GET_ERROR(&input));
    }
    return error_message;
}    