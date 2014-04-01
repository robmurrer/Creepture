/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#include "../Framework/Test.h"
#include "../Framework/Render.h"

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include "freeglut/freeglut.h"
#endif

//#include "basic.h"
//#include "single.h"
//#include "single-demo.h"
//#include "multiple.h"
#include "plugged.h"
#include "cpgtest.h"

TestEntry g_testEntries[] =
{
        //{"Single-demo", SingleDemo::Create},   
        //{"Single", Single::Create},   
        //{"Multiple", Multiple::Create},   
        //{"Basic", Basic::Create},   
        //{"Plugged", Plugged::Create},   
        {"CPGTest", CPGTest::Create},   
        {NULL, NULL}
};
