# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Dtrip_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Dtrip_autogen.dir\\ParseCache.txt"
  "Dtrip_autogen"
  )
endif()
