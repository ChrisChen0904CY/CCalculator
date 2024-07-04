# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CCalculator_autogen"
  "CMakeFiles\\CCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CCalculator_autogen.dir\\ParseCache.txt"
  )
endif()
