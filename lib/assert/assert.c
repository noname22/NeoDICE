
/*
 *  ASSERT.C
 *
 *
 *    (c)Copyright 1992-1997 Obvious Implementations Corp.  Redistribution and
 *    use is allowed under the terms of the DICE-LICENSE FILE,
 *    DICE-LICENSE.TXT.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void
__FailedAssert(file, line)
char *file;
int line;
{
    fprintf(stderr, "Assertion Failed %s line %d\n", file, line);
    abort();
}


