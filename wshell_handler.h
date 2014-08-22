/*
 *      last modified:  2014/05/01
 *      first wrote:    2014/04/19
 *
 *      wono (a.k.a wonho)
 */
 
#ifndef _wshell_handler_h_
#define _wshell_handler_h_

#include <stdio.h>

#define BASH    "bash "

/*  SHELL_TYPE: type of shell - BASH, ...
 *  SHELL_PATH: path of the shell located   */
#define SCRIPT_OPEN( SHELL_TYPE, SHELL_PATH )\
system (SHELL_TYPE SHELL_PATH)

#endif
