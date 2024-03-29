//#pragma comment(lib, "winmm.lib") // PlaySound 함수 호출 용
//#define BGMPATH "AcidRain.wav" // 배경음악의 경로(파일 이름)

#ifndef __STDIO_H__ //__STDIO_H__라는 매크로가 정의되어있지 않으면
#define __STDIO_H__ //__STDIO_H__를 정의한다

#include <stdio.h> //stdio.h 헤더파일 선언한다 -> 중복선언방지를 위해서

#endif //ifndef 종료      #ifndef~#endif가 하나의 묶음

#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <windows.h>

#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <stdlib.h>

#endif

#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>

#endif

#ifndef __MATH_H__
#define __MATH_H__

#include <math.h>

#endif

#ifndef __CONIO_H__
#define __CONIO_H__

#include <CONIO.h>

#endif

#ifndef _TIME_H__
#define _TIME_H__

#include  <time.h>

#endif

#ifndef _MMSYSTEM_H__
#define _MMSYSTEM_H__

#include  <MMSystem.h>

#endif

#ifndef _DIGHTALV_H__
#define _DIGITALV_H__

#include  <Digitalv.h>

#endif

#ifndef _DIGHTALV_H__
#define _DIGITALV_H__

#include  <Digitalv.h>

#endif

#ifdef _IOSTREAM_H
#define _IOSTREAM_H

#include <iostream>

#endif


