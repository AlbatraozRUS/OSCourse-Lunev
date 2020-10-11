#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>

#pragma once

struct MsgBuf{
    long mtype;    
};

#define PRINTERROR(errorString)\
        {fprintf(stderr, "ATTENTION!\nError occured: ");\
         fprintf(stderr, errorString);\
         exit(EXIT_FAILURE);}


#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define DBG if(1)
#else
    #define DBG if(0)
#endif

void Send_Message(const key_t msgkey, const size_t numProcess);
void ReceiveMessage(const key_t msgkey, const size_t id);
size_t ScanNum(const int argc, char** argv);