// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

//Windows
#include <Windows.h>

//C
#include <stdio.h>
#include <tchar.h>
#include <time.h>

//C++
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>

#include "D:\\SDL\\SDL2-2.0.7\\include\\sdl.h"
#include "D:\\SDL\\SDL2-2.0.7\\include\\sdl_main.h"

//Framework
//싱글톤 및 템플릿 함수들
#include "Singletone.h"
#include "myFunction.h"
#include "EventHandler.h"
#include "SceneManager.h"
#include "MusicManager.h"

//계층 구조로 설계된 게임오브젝트. 상속 계층에 맞게 포함
#include "GameObject.h"

#include "RenderableObject.h"

#include "SplittableObject.h"
#include "Button.h"
#include "FloatImage.h"

#include "Character.h"

//씬 구조, 인터페이스 형식에 맞춰 다형성 가질 수 있음.
#include "IScene.h"
#include "StartScene.h"

//대진쌤 구조
#include "Util.h"
#include "BaseWindow.h"
#include "TimeManager.h"
#include "FrameSkip.h"

#include "System.h"

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.