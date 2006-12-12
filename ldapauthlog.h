/*++

	IIS LDAP Authentication Module
	Copyright 2006 Inflection Technology, LLC
	For more information, visit http://www.inflectiontech.com.

	Released under LGPL terms.

	Some portions Copyright Salvador Salanova Fortmann.
	Some portions Copyright Microsoft Corporation.

	File Name:	ldapauthlog.h

	Abstract:
    This module implements a file logging system.

	Modification History:

	2006-12-12 ramr
	File created.
--*/

#ifndef _IISLDAPAUTHLOG_H_
#define _IISLDAPAUTHLOG_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

/*
	CONSTANTS
*/

#define LDAPLOG_INFORMATIONAL   1
#define LDAPLOG_WARNING			2
#define LDAPLOG_CRITICAL		4
#define LDAPLOG_DEBUG			8

BOOL
Log_Initialize(
    const CHAR * pszLogPath
    );

BOOL
Log_Write(
    CHAR * pszLogLine,
	UINT16 liLevel
    );

BOOL
Log_Flush(
    VOID
    );

VOID
Log_Terminate(
    VOID
    );

#endif