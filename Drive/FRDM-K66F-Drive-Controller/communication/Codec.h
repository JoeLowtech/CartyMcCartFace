/* 
    Class for endcoding and decoding messages
 */
#ifndef CODEC_H
#define CODEC_H

#include "pb.h"
#include "messages.pb.h"
#include "pb_decode.h"
#include "logger.h"


 class Codec{
    private:
        driveMessage decodedMessage;
        pb_istream_t input;

    public:
        Codec();
        bool decode_msg(uint8_t* messageBuffer,uint8_t messageSize);
        driveMessage* get_decoded_message(){
            return &decodedMessage;
        };

 };
 #endif