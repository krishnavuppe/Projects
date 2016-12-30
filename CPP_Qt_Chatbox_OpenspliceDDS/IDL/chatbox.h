//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: chatbox.h
//  Source: chatbox.idl
//  Generated: Mon Dec 26 22:38:08 2016
//  OpenSplice V6.4.140407OSS
//  
//******************************************************************
#ifndef _CHATBOX_H_
#define _CHATBOX_H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"


namespace chatbox
{
   struct message;

   struct message
   {
         DDS::ULong uid;
         DDS::String_mgr uname;
         DDS::ULong msgid;
         DDS::String_mgr msg;
   };

   typedef DDS_DCPSStruct_var < message> message_var;
   typedef DDS_DCPSStruct_out < message> message_out;
}




#endif 