// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
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
//�̱��� �� ���ø� �Լ���
#include "Singletone.h"
#include "myFunction.h"
#include "EventHandler.h"
#include "SceneManager.h"
#include "MusicManager.h"

//���� ������ ����� ���ӿ�����Ʈ. ��� ������ �°� ����
#include "GameObject.h"

#include "RenderableObject.h"

#include "SplittableObject.h"
#include "Button.h"
#include "FloatImage.h"

#include "Character.h"

//�� ����, �������̽� ���Ŀ� ���� ������ ���� �� ����.
#include "IScene.h"
#include "StartScene.h"

//������ ����
#include "Util.h"
#include "BaseWindow.h"
#include "TimeManager.h"
#include "FrameSkip.h"

#include "System.h"

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.