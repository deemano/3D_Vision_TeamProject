# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "ARi_v04_autogen"
  "CMakeFiles\\ARi_v04_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ARi_v04_autogen.dir\\ParseCache.txt"
  )
endif()
