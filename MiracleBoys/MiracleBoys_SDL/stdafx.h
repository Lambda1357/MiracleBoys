// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

//C
#include <stdio.h>
#include <tchar.h>

//C++
#include <iostream>
#include <vector>
#include <map>
#include <functional>

#include "D:\\SDL\\SDL2-2.0.7\\include\\sdl.h"
#include "D:\\SDL\\SDL2-2.0.7\\include\\sdl_main.h"

//Framework
//싱글톤 및 템플릿 함수들
#include "Singletone.h"
#include "myFunction.h"
#include "EventHandler.h"

//계층 구조로 설계된 게임오브젝트. 상속 계층에 맞게 포함
#include "GameObject.h"

#include "RenderableObject.h"

#include "SplittableObject.h"
#include "Button.h"

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.