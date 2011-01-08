MESSAGE(STATUS "IRRDIR = $ENV{IRRDIR}")

FIND_PATH(IRRLICHT_INCLUDE_DIR NAMES irrlicht.h
   PATHS
   $ENV{IRRDIR}/include
   /usr/local/include/irrlicht
   /usr/include/irrlicht
)

MESSAGE(STATUS "IRRLICHT_INCLUDE_DIR = ${IRRLICHT_INCLUDE_DIR}")

FIND_LIBRARY(IRRLICHT_LIBRARY NAMES libIrrlicht.a Irrlicht
   PATHS
   $ENV{IRRDIR}/lib
   $ENV{IRRDIR}/lib/Linux
   $ENV{IRRDIR}/lib/MacOSX
   $ENV{IRRDIR}/lib/Win32-gcc
   $ENV{IRRDIR}/lib/Win32-visualstudio
   $ENV{IRRDIR}/lib/Win64-visualstudio
   /usr/local/lib
   /usr/lib
)

MESSAGE(STATUS "IRRLICHT_LIBRARY = ${IRRLICHT_LIBRARY}")

# handle the QUIETLY and REQUIRED arguments and set IRRLICHT_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(IRRLICHT DEFAULT_MSG IRRLICHT_LIBRARY IRRLICHT_INCLUDE_DIR)

IF(IRRLICHT_FOUND)
  SET(IRRLICHT_LIBRARIES ${IRRLICHT_LIBRARY})
ELSE(IRRLICHT_FOUND)
  SET(IRRLICHT_LIBRARIES)
ENDIF(IRRLICHT_FOUND)

MARK_AS_ADVANCED(IRRLICHT_LIBRARY IRRLICHT_INCLUDE_DIR) 
