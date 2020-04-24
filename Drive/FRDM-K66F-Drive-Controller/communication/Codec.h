/* 
    Class for endcoding and decoding messages
 */
#ifndef CODEC_H
#define CODEC_H

#include "pb.h"
#include "messages.pb.h"
#include "pb_decode.h"


 class Codec{
    private:
        pb_istream_t input;
        // void encode_msg();
        
    public:
        Codec(uint8_t* inputBuffer, uint8_t buffersize);

        bool decode_msg(driveMessage *message);
        // driveMessage* get_message();   
 };
 #endif