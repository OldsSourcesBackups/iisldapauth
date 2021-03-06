/*++

	IIS LDAP Authentication Module
	Copyright 2006 Inflection Technology, LLC
	For more information, visit http://www.inflectiontech.com.

	Released under LGPL terms.

	Some portions Copyright Salvador Salanova Fortmann.
	Some portions Copyright Microsoft Corporation.

	File Name:	cache.h

	Abstract:
    This module implements a simple user cache.  The cached users are kept
    in an LRU sorted list.  If there will be a large number of simultaneous
    users, then a sorted array would be more appropriate.

	Modification History:

	2006-12-11 ramr
	File created.
--*/

#ifndef _IISLDAPAUTHCACHE_H_
#define _IISLDAPAUTHCACHE_H_

#include <windows.h>
#include <httpfilt.h>
#include "ldapauth_global.h"

/*
	CONSTANTS

    MAX_CACHED_USERS: The maximum number of users we will cache.  Change 
	this number if a large amount of simultaneous users are expected. If 
	the cache fills up, new users will not be cached.

	MAX_CACHE_TIME: Time limit until the cache entry is considered invalid.
*/

#define DEFAULT_CACHE_USERS     500
#define DEFAULT_CACHE_TIME		1800		/* 30 minutes */
#define MAX_CACHE_USERS			5000
#define MAX_CACHE_TIME			604800		/* 1 week */
#define HUNDRED_NS_FRACTION 	10000000

/*
    Cached user structure
*/

typedef struct SUSER_CACHE
{
    CHAR	m_achLDAPUser[SF_MAX_USERNAME];		/* External username and password */
    CHAR	m_achLDAPPassword[SF_MAX_PASSWORD];
    CHAR	m_achNTUser[SF_MAX_USERNAME];		/* Mapped NT account and password */
    CHAR	m_achNTPassword[SF_MAX_PASSWORD];
	UINT64	m_lliTimestamp;						/* Cache entry timestamp */
} SUSER_CACHE, *PUSER_CACHE;

BOOL
Cache_Initialize(
    const UINT32 kuliCacheSize,
	const UINT32 kuliCacheTime
    );

BOOL
Cache_GetUser(
    CHAR * pszLDAPUser,
	BOOL * pfFound,
    CHAR * pszLDAPPassword,
    CHAR * pszNTUser,
    CHAR * pszNTPassword
    );

BOOL
Cache_AddUser(
    CHAR * pszUserName,
    CHAR * pszLDAPPassword,
    CHAR * pszNTUser,
    CHAR * pszNTPassword
    );

VOID
Cache_Terminate(
    VOID
    );

UINT64
GetSystemTime100ns( VOID );

#endif _IISLDAPAUTHCACHE_H_