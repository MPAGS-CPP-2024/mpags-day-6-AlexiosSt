# - Build sub-script for the MPAGSCipher library

# - Declare the build of the static MPAGSCipher library
add_library(MPAGSCipher STATIC
  Alphabet.hpp
  CustomExceptions.hpp
  CaesarCipher.hpp
  CaesarCipher.cpp
  Cipher.hpp
  CipherFactory.hpp
  CipherFactory.cpp
  CipherMode.hpp
  CipherType.hpp
  PlayfairCipher.hpp
  PlayfairCipher.cpp
  ProcessCommandLine.hpp
  ProcessCommandLine.cpp
  TransformChar.hpp
  TransformChar.cpp
  VigenereCipher.hpp
  VigenereCipher.cpp
  )

target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
  )
target_compile_features(MPAGSCipher
  PUBLIC cxx_std_17
  )