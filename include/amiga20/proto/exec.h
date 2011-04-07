#ifndef  PROTO_EXEC_H
#define  PROTO_EXEC_H

#include <exec/types.h>
#include <clib/exec_protos.h>
#if defined(_USEOLDEXEC_) || !defined(__USE_SYSBASE)
#include <pragmas/exec_pragmas.h>
#else
extern struct ExecBase *SysBase;
#include <pragmas/exec_sysbase_pragmas.h>
#endif

/*------ Common support library functions ---------*/
#include <clib/alib_protos.h>
#endif
