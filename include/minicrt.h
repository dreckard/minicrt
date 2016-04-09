/*
 * MINICRT.H
 *
 * Header file for minicrt based applications.  Function prototypes and
 * appropriate #defines to default to their use and define Unicode-
 * conditional functions.
 *
 * Copyright (c) 2014 Malcolm J. Smith
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HAVE_MINICRT_FILE

#undef FILE

typedef struct _minicrt_file {
    HANDLE hFile;
} minicrt_file, *pminicrt_file;

#define FILE minicrt_file
#define HAVE_MINICRT_FILE 1
#endif

void *     mini_memcpy(void * dest, void * src, unsigned int len);
int        mini_memcmp(const void * buf1, const void * buf2, unsigned int len);
void *     mini_memmove(void * dest, void * src, unsigned int len);
void *     mini_memset(void * dest, char c, unsigned int len);

void       mini_srand(unsigned int seed);
int        mini_rand();

void       mini_searchenvex_s(const char * filename, const char * env, char * buffer, unsigned int len, int * component);
void       mini_wsearchenvex_s(const wchar_t * filename, const wchar_t * env, wchar_t * buffer, unsigned int len, int * component);
void       mini_searchenv_s(const char * filename, const char * env, char * buffer, unsigned int len);
void       mini_wsearchenv_s(const wchar_t * filename, const wchar_t * env, wchar_t * buffer, unsigned int len);
void       mini_searchenv(const char * filename, const char * env, char * buffer);
void       mini_wsearchenv(const wchar_t * filename, const wchar_t * env, wchar_t * buffer);

FILE *     mini_fopen(char * filename, char * mode);
FILE *     mini_wfopen(wchar_t * filename, wchar_t * mode);

char *     mini_fgets(char * string, int n, FILE * fp);
wchar_t *  mini_fgetws(wchar_t * string, int n, FILE * fp);

int        mini_fclose(FILE * fp);

int        mini_atoi(char * str);
int        mini_wtoi(wchar_t * str);

char *     mini_strncat(char * dest, const char * src, unsigned int len);
wchar_t *  mini_wcsncat(wchar_t * dest, const wchar_t * src, unsigned int len);

char *     mini_strcat_s(char * dest, unsigned int len, const char * src);
wchar_t *  mini_wcscat_s(wchar_t * dest, unsigned int len, const wchar_t * src);

char *     mini_strchr(const char * str, char ch);
wchar_t *  mini_wcschr(const wchar_t * str, wchar_t ch);

char *     mini_strstr(const char * str, char * search);
wchar_t *  mini_wcsstr(const wchar_t * str, wchar_t * search);

char *     mini_strrchr(const char * str, char ch);
wchar_t *  mini_wcsrchr(const wchar_t * str, wchar_t ch);

char *     mini_strupr(char * str);
wchar_t *  mini_wcsupr(wchar_t * str);

char *     mini_strlwr(char * str);
wchar_t *  mini_wcslwr(wchar_t * str);

int        mini_strspn(char * str, char * chars);
int        mini_wcsspn(wchar_t * str, wchar_t * chars);

int        mini_strcspn(char * str, char * chars);
int        mini_wcscspn(wchar_t * str, wchar_t * chars);

char *     mini_strtok_s(char * str, char * match, char ** context);
wchar_t *  mini_wcstok_s(wchar_t * str, wchar_t * match, wchar_t ** context);

char *     mini_strtok(char * str, char * match);
wchar_t *  mini_wcstok(wchar_t * str, wchar_t * match);

int        mini_vsprintf_s(char * szDest, unsigned int len, const char * szFmt, va_list marker);
int        mini_vswprintf_s(wchar_t * szDest, unsigned int len, const wchar_t * szFmt, va_list marker);

int        mini_vsprintf_size(const char * szFmt, va_list marker);
int        mini_vswprintf_size(const wchar_t * szFmt, va_list marker);

int        mini_sprintf_s(char * szDest, unsigned int len, const char * szFmt, ...);
int        mini_swprintf_s(wchar_t * szDest, unsigned int len, const wchar_t * szFmt, ...);

int        mini_sprintf(char * szDest, const char * szFmt, ...);
int        mini_swprintf(wchar_t * szDest, const wchar_t * szFmt, ...);

int        mini_fprintf(FILE * fp, const char * szFmt, ...);
int        mini_fwprintf(FILE * fp, const wchar_t * szFmt, ...);

int        mini_printf(const char * szFmt, ...);
int        mini_wprintf(const wchar_t * szFmt, ...);

//
//  Map tchar versions to the correct place
//

#ifdef UNICODE
#define    mini_tsearchenv      mini_wsearchenv
#define    mini_tsearchenv_s    mini_wsearchenv_s
#define    mini_tsearchenvex_s  mini_wsearchenvex_s
#define    mini_ftopen          mini_wfopen
#define    mini_ftgets          mini_fgetws
#define    mini_ttoi            mini_wtoi
#define    mini_tcsncat         mini_wcsncat
#define    mini_tcscat_s        mini_wcscat_s
#define    mini_tcschr          mini_wcschr
#define    mini_tcsrchr         mini_wcsrchr
#define    mini_tcsstr          mini_wcsstr
#define    mini_tcsupr          mini_wcsupr
#define    mini_tcslwr          mini_wcslwr
#define    mini_tcsspn          mini_wcsspn
#define    mini_tcscspn         mini_wcscspn
#define    mini_tcstok_s        mini_wcstok_s
#define    mini_tcstok          mini_wcstok
#define    mini_vstprintf_s     mini_vswprintf_s
#define    mini_vstprintf_size  mini_vswprintf_size
#define    mini_stprintf_s      mini_swprintf_s
#define    mini_stprintf        mini_swprintf
#define    mini_ftprintf        mini_fwprintf
#define    mini_tprintf         mini_wprintf
#else
#define    mini_tsearchenv      mini_searchenv
#define    mini_tsearchenv_s    mini_searchenv_s
#define    mini_tsearchenvex_s  mini_searchenvex_s
#define    mini_ftopen          mini_fopen
#define    mini_ftgets          mini_fgets
#define    mini_ttoi            mini_atoi
#define    mini_tcsncat         mini_strncat
#define    mini_tcscat_s        mini_strcat_s
#define    mini_tcschr          mini_strchr
#define    mini_tcsrchr         mini_strrchr
#define    mini_tcsstr          mini_strstr
#define    mini_tcsupr          mini_strupr
#define    mini_tcslwr          mini_strlwr
#define    mini_tcsspn          mini_strspn
#define    mini_tcscspn         mini_strcspn
#define    mini_tcstok_s        mini_strtok_s
#define    mini_tcstok          mini_strtok
#define    mini_vstprintf_s     mini_vsprintf_s
#define    mini_vstprintf_size  mini_vsprintf_size
#define    mini_stprintf_s      mini_sprintf_s
#define    mini_stprintf        mini_sprintf
#define    mini_ftprintf        mini_fprintf
#define    mini_tprintf         mini_printf
#endif

#ifndef MINICRT_BUILD

//
//  Have apps use them by default
//

#undef  _tsearchenv
#define _tsearchenv  mini_tsearchenv

#undef  searchenv
#define searchenv  mini_searchenv

#undef  _wsearchenv
#define _wsearchenv mini_wsearchenv

#undef  _tsearchenv_s
#define _tsearchenv_s  mini_tsearchenv_s

#undef  searchenv_s
#define searchenv_s  mini_searchenv_s

#undef  _wsearchenv_s
#define _wsearchenv_s mini_wsearchenv_s

#undef  _tsearchenvex_s
#define _tsearchenvex_s  mini_tsearchenvex_s

#undef  searchenvex_s
#define searchenvex_s  mini_searchenvex_s

#undef  _wsearchenvex_s
#define _wsearchenvex_s mini_wsearchenvex_s

#undef  ftopen
#define ftopen   mini_ftopen

#undef  fopen
#define fopen    mini_fopen

#undef  _wfopen
#define _wfopen  mini_wfopen

#undef  ftgets
#define ftgets   mini_ftgets

#undef  fgets
#define fgets    mini_fgets

#undef  fgetws
#define fgetws   mini_fgetws

#undef  fclose
#define fclose   mini_fclose

#undef  _ttoi
#define _ttoi    mini_ttoi

#undef  atoi
#define atoi     mini_atoi

#undef  wtoi
#define wtoi     mini_wtoi

#undef  _tcschr
#define _tcschr  mini_tcschr

#undef  strchr
#define strchr   mini_strchr

#undef  wcschr
#define wcschr   mini_wcschr

#undef  _tcsrchr
#define _tcsrchr mini_tcsrchr

#undef  strrchr
#define strrchr  mini_strrchr

#undef  wcsrchr
#define wcsrchr  mini_wcsrchr

#undef  _tcsstr
#define _tcsstr  mini_tcsstr

#undef  strstr
#define strstr   mini_strstr

#undef  wcsstr
#define wcsstr   mini_wcsstr

#undef  _tcsncat
#define _tcsncat mini_tcsncat

#undef  strncat
#define strncat  mini_strncat

#undef  wcsncat
#define wcsncat  mini_wcsncat

#undef  _tcscat_s
#define _tcscat_s mini_tcscat_s

#undef  strcat_s
#define strcat_s  mini_strcat_s

#undef  wcscat_s
#define wcscat_s  mini_wcscat_s

#undef  _tcscat
#define _tcscat(a,b) mini_tcscat_s(a, -1, b)

#undef  strcat
#define strcat(a,b)  mini_strcat_s(a, -1, b)

#undef  wcscat
#define wcscat(a,b)  mini_wcscat_s(a, -1, b)

#undef  _tcsupr
#define _tcsupr   mini_tcsupr

#undef  _strupr
#define _strupr   mini_strupr

#undef  _wcsupr
#define _wcsupr   mini_wcsupr

#undef  _tcslwr
#define _tcslwr   mini_tcslwr

#undef  _strlwr
#define _strlwr   mini_strlwr

#undef  _wcslwr
#define _wcslwr   mini_wcslwr

#undef  strspn
#define strspn    mini_strspn

#undef  wcsspn
#define wcsspn    mini_wcsspn

#undef  _tcsspn
#define _tcsspn   mini_tcsspn

#undef  strcspn
#define strcspn   mini_strcspn

#undef  wcscspn
#define wcscspn   mini_wcscspn

#undef  _tcscspn
#define _tcscspn  mini_tcscspn

#undef  _tcstok_s
#define _tcstok_s mini_tcstok_s

#undef  strtok_s
#define strtok_s  mini_strtok_s

#undef  wcstok_s
#define wcstok_s  mini_wcstok_s

#undef  _tcstok
#define _tcstok   mini_tcstok

#undef  strtok
#define strtok    mini_strtok

#undef  wcstok
#define wcstok    mini_wcstok

#undef  _memcpy
#define _memcpy   mini_memcpy

#undef  memcpy
#define memcpy    mini_memcpy

#undef  _memmove
#define _memmove  mini_memmove

#undef  memmove
#define memmove   mini_memmove

#undef  memset
#define memset    mini_memset

#undef  memcmp
#define memcmp    mini_memcmp

#undef  rand
#define rand      mini_rand

#undef  srand
#define srand     mini_srand

#undef  _stprintf_s
#define _stprintf_s  mini_stprintf_s

#undef  sprintf_s
#define sprintf_s    mini_sprintf_s

#undef  swprintf_s
#define swprintf_s   mini_swprintf_s

#undef  _sntprintf
#define _sntprintf   mini_stprintf_s

#undef  _snprintf
#define _snprintf    mini_sprintf_s

#undef  _snwprintf
#define _snwprintf   mini_swprintf_s

#undef  _stprintf
#define _stprintf    mini_stprintf

#undef  sprintf
#define sprintf      mini_sprintf

#undef  swprintf
#define swprintf     mini_swprintf

#undef  _ftprintf
#define _ftprintf    mini_ftprintf

#undef  fprintf
#define fprintf      mini_fprintf

#undef  fwprintf
#define fwprintf     mini_fwprintf

#undef  _tprintf
#define _tprintf     mini_tprintf

#undef  printf
#define printf       mini_printf

#undef  wprintf
#define wprintf      mini_wprintf

#undef  _tcscpy
#define _tcscpy(a,b) mini_stprintf_s(a,-1,_T("%s"),b)

#undef  strcpy
#define strcpy(a,b)  mini_sprintf_s(a,-1,"%s",b)

#undef  wcscpy
#define wcscpy(a,b)  mini_swprintf_s(a,-1,L"%s",b)

#endif // MINICRT_BUILD

//
//  Easy ones, just take them from Win32
//

#undef  _tcsicmp
#define _tcsicmp lstrcmpi

#undef  stricmp
#define stricmp lstrcmpiA

#undef  wcsicmp
#define wcsicmp lstrcmpiW

#undef  _tcscmp
#define _tcscmp lstrcmp

#undef  strcmp
#define strcmp  lstrcmpA

#undef  wcscmp
#define wcscmp  lstrcmpW

#undef  _tcslen
#define _tcslen lstrlen

#undef  strlen
#define strlen  lstrlenA

#undef  wcslen
#define wcslen  lstrlenW

#undef  malloc
#define malloc(x)   HeapAlloc(GetProcessHeap(), 0, x)

#undef  realloc
#define realloc(x,s) HeapReAlloc(GetProcessHeap(), 0, x, s)

#undef  free
#define free(x)     HeapFree(GetProcessHeap(), 0, x)

#undef  exit
#define exit    ExitProcess

#undef stdin
#define stdin  (FILE*)0

#undef stdout
#define stdout (FILE*)1

#undef stderr
#define stderr (FILE*)2

#undef RAND_MAX
#define RAND_MAX 32768

#undef INT_MAX
#define INT_MAX (0x7fffffff)

#undef UINT_MAX
#define UINT_MAX (0xffffffff)

#ifdef __cplusplus
}
#endif

// vim:sw=4:ts=4:et:
