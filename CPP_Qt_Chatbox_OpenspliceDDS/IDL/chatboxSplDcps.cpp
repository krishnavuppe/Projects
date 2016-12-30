#include "chatboxSplDcps.h"
#include "ccpp_chatbox.h"
#include "dds_type_aliases.h"

const char *
__chatbox_message__name(void)
{
    return (const char*)"chatbox::message";
}

const char *
__chatbox_message__keys(void)
{
    return (const char*)"uid";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__chatbox_message__copyIn(
    c_base base,
    struct ::chatbox::message *from,
    struct _chatbox_message *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    to->uid = (c_ulong)from->uid;
#ifdef OSPL_BOUNDS_CHECK
    if(from->uname){
        to->uname = c_stringNew(base, from->uname);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'chatbox::message.uname' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->uname = c_stringNew(base, from->uname);
#endif
    to->msgid = (c_ulong)from->msgid;
#ifdef OSPL_BOUNDS_CHECK
    if(from->msg){
        to->msg = c_stringNew(base, from->msg);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'chatbox::message.msg' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->msg = c_stringNew(base, from->msg);
#endif
    return result;
}

void
__chatbox_message__copyOut(
    void *_from,
    void *_to)
{
    struct _chatbox_message *from = (struct _chatbox_message *)_from;
    struct ::chatbox::message *to = (struct ::chatbox::message *)_to;
    to->uid = (::DDS::ULong)from->uid;
    to->uname = DDS::string_dup(from->uname ? from->uname : "");
    to->msgid = (::DDS::ULong)from->msgid;
    to->msg = DDS::string_dup(from->msg ? from->msg : "");
}

