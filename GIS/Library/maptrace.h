/***** MAPTRACE.H ************** Belenkov O.V.   ****** 12/08/10 ***
****** MAPTRACE.H ************** Dishlenko S.G.  ****** 23/07/99 ***
****** MAPTRACE.H ************** Kruzhkova E.A.  ****** 02/04/09 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2010              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*        ТРАССИРОВКА ВЫПОЛНЕНИЯ ПРОГРАММ ДЛЯ ПОИСКА ОШИБОК         *
*                                                                  *
*******************************************************************/

#ifndef MAPTRACE_H
#define MAPTRACE_H

#include "mapversn.h"


//#define MAPTRACER TRUE
//#define TRACE_MEM TRUE
//#define TRACE_MAP TRUE

#ifndef MAPTRACER
  #define MAPTRACER FALSE   // Если трассировка нужна -
                            //  поставить TRUE
#endif

#ifndef LINUXAPI                                // 02/04/09

 #ifdef WINCE
  #define LOGFILENAME ".\\maptrace.log"
 #else
  #define LOGFILENAME "c:\\maptrace.log"
 #endif
#else
 #ifdef LINUXSERVER
  #define LOGFILENAME "/export/home/maptrace.log"
 #else
  #define LOGFILENAME "/maptrace.log"
 #endif
#endif

#if MAPTRACER != FALSE

  #include <stdio.h>


#ifndef LINUXAPI   // 23.07.99

//*******************************************************************
//  Пример вызова трассировки :
//   Tracer("0x%04X|message = 0x%04X BEGIN.\n", hwnd, uMsg);
//*******************************************************************

  #define Tracer2(str, num, mes) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            if (hFile) { fprintf( hFile, str, num, mes); fclose( hFile );} }

  #define Tracer1(str, mes) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            if (hFile) { fprintf( hFile, str, mes); fclose( hFile );} }

  #define Tracer(message) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            if (hFile) { fprintf( hFile, message); fclose( hFile );} }

//*******************************************************************
//  Пример вызова трассировки :
//   TraceCode("0x%04X|message = 0x%04X BEGIN.\n", hwnd, uMsg);
//*******************************************************************

  #define TraceCode(str, nwin, nmes) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            fprintf( hFile, str, nwin, nmes);\
            fclose( hFile );}
  #define TraceMessage(message) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            fprintf( hFile, message);\
            fclose( hFile );}

  #define TraceMessage1(message, v1) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            fprintf( hFile, message, v1);\
            fclose( hFile );}

  #define TraceMessage2(message, v1, v2) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            fprintf( hFile, message, v1, v2);\
            fclose( hFile );}

#else  // 02/04/09


  #define TracerSun(message) \
          { FILE* HFile = fopen( LOGFILENAME, "a+" );\
            fprintf( HFile, message);\
            fclose( HFile );}

  #define Tracer2(str, num, mes) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            fprintf( hFile, str, num, mes);\
            fclose( hFile );}

  #define Tracer1(str, mes) \
          { FILE* hFile = fopen( LOGFILENAME, "a+" );\
            fprintf( hFile, str, mes);\
            fclose( hFile );}

  #define Tracer(message) \
          { FILE* HFile = fopen( LOGFILENAME, "a+" );\
            fprintf( HFile, message);\
            fclose( HFile );}

  #ifdef OC2000                 //19/11/01
    #define TraceCode(str, nwin, nmes) \
            { printf(str, nwin, nmes); }
    #define TraceMessage(message) \
            { printf(message); }
  #else
    #define TraceCode(str, nwin, nmes) \
            { FILE* hFile = fopen( LOGFILENAME, "a+" );\
              fprintf( hFile, str, nwin, nmes);\
              fclose( hFile );}
    #define TraceMessage(message) \
            { FILE* hFile = fopen( LOGFILENAME, "a+" );\
              fprintf( hFile, message);\
              fclose( hFile );}
    #define TraceMessage2(message, v1, v2) \
            { FILE* hFile = fopen( LOGFILENAME, "a+" );\
              fprintf( hFile, message, v1, v2);\
              fclose( hFile );}
  #endif  //OC2000

#endif

#else
  #define Tracer2(str, num, mes)
  #define Tracer1(str, mes)
  #define Tracer(message)

  #define TraceCode(str, nwin, nmes)
  #define TraceMessage(message)
  #define TraceMessage1(message, v1)
  #define TraceMessage2(message, v1, v2)

  // 06/06/08
  #define TracerSun(message)

#endif


#ifdef GISWEB

  #define GisTraceCode(str, v1, v2) TraceMessage2(str, v1, v2)
  #define GisTraceMessage(message)  TraceMessage(message)
  #define TracerSun(message)

#else
#ifndef LINUXAPI
 #if MAPTRACER != FALSE

  #include <stdio.h>

  #define GisTraceCode(str, nwin, nmes) \
          { FILE* hFile = fopen(LOGFILENAME, "a+" );\
            fprintf( hFile, str, nwin, nmes);\
            fclose( hFile );}
  #define GisTraceMessage(message) \
          { FILE* hFile = fopen(LOGFILENAME, "a+" );\
            fprintf( hFile, message);\
            fclose( hFile );}
 #else
   #define GisTraceCode(str, nwin, nmes)
   #define GisTraceMessage(message) 
 #endif
#else
  #define GisTraceCode(str, nwin, nmes)
  #define GisTraceMessage(message) 
#endif

#endif    // GISWEB

#endif
