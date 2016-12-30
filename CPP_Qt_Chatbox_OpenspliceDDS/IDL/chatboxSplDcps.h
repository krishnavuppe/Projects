#ifndef CHATBOXSPLTYPES_H
#define CHATBOXSPLTYPES_H

#include "ccpp_chatbox.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __chatbox_chatbox__load (c_base base);

extern c_metaObject __chatbox_message__load (c_base base);
extern const char * __chatbox_message__keys (void);
extern const char * __chatbox_message__name (void);
struct _chatbox_message ;
extern  c_bool __chatbox_message__copyIn(c_base base, struct chatbox::message *from, struct _chatbox_message *to);
extern  void __chatbox_message__copyOut(void *_from, void *_to);
struct _chatbox_message {
    c_ulong uid;
    c_string uname;
    c_ulong msgid;
    c_string msg;
};

#endif
