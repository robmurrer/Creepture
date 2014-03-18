# Install script for directory: /Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D" TYPE FILE FILES "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Box2D.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision" TYPE FILE FILES
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/b2BroadPhase.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/b2Collision.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/b2Distance.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/b2DynamicTree.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/b2TimeOfImpact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision/Shapes" TYPE FILE FILES
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/Shapes/b2CircleShape.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/Shapes/b2EdgeShape.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/Shapes/b2ChainShape.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/Shapes/b2PolygonShape.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Collision/Shapes/b2Shape.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Common" TYPE FILE FILES
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2BlockAllocator.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2Draw.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2GrowableStack.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2Math.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2Settings.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2StackAllocator.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Common/b2Timer.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics" TYPE FILE FILES
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2Body.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2ContactManager.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2Fixture.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2Island.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2TimeStep.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2World.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/b2WorldCallbacks.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Contacts" TYPE FILE FILES
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2CircleContact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2Contact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2ContactSolver.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Contacts/b2PolygonContact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Joints" TYPE FILE FILES
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2DistanceJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2FrictionJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2GearJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2Joint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2MotorJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2MouseJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2PrismaticJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2PulleyJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2RevoluteJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2RopeJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2WeldJoint.h"
    "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Dynamics/Joints/b2WheelJoint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Rope" TYPE FILE FILES "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Rope/b2Rope.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Build/Box2D/libBox2D.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
    EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBox2D.a")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake")
    FILE(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake"
         "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Build/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
    IF(EXPORT_FILE_CHANGED)
      FILE(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets-*.cmake")
      IF(OLD_CONFIG_FILES)
        MESSAGE(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        FILE(REMOVE ${OLD_CONFIG_FILES})
      ENDIF(OLD_CONFIG_FILES)
    ENDIF(EXPORT_FILE_CHANGED)
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Build/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Build/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-noconfig.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/Users/rob/Desktop/evolutionary computation/creepture/lzy/Box2D/Box2DConfig.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

