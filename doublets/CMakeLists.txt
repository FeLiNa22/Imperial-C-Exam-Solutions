cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
project(doublets)

# NOTES TO CLION USERS ----------------
# - To run an *executable*, select the executable from the drop down list of
#   configurations (top right) and click on the Run button (play symbol)
# - To run one of the *make targets* (i.e. "Build All", "run", "run_alt", "tests" and
#   "tests_alt"), select the target from the drop down list of configurations (top
#   right) and click on the Build button (hammer symbol)
# - Should you accidentally delete the whole cmake-build-debug folder, right-click 
#   on CMakeLists.txt and choose "Reload CMake Project"


# Identify precompiled dictionary
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(PRECOMPILED_DICT ${CMAKE_CURRENT_SOURCE_DIR}/lib/dict_alt.o)
set_source_files_properties(
  ${OBJS}
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true
)

# Copy words.txt to cmake-build-debug/
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/words.txt DESTINATION ${CMAKE_BINARY_DIR})

# Set include/ as (guess what) include directory
include_directories(include)

# Define dependencies for executables 
add_executable(doublets main.c doublets.c trie.c)
add_executable(doublets_alt ${PRECOMPILED_DICT} main.c doublets.c)
add_executable(doublets_tests trie.c doublets.c doublets_tests.c)
add_executable(doublets_tests_alt ${PRECOMPILED_DICT} doublets.c doublets_tests.c)
add_executable(dictionary_tests trie.c doublets.c trie_tests.c)

# Link criterion testing library to tests executables
find_library(CRITERION NAMES criterion PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(doublets_tests ${CRITERION})
target_link_libraries(doublets_tests_alt ${CRITERION})
target_link_libraries(dictionary_tests ${CRITERION})

# Add shortcut targets (to invoke with make)
add_custom_target(run 
  COMMAND doublets
  DEPENDS doublets
)

add_custom_target(run_alt 
  COMMAND doublets_alt
  DEPENDS doublets_alt
)

add_custom_target(tests
  COMMAND echo "Dictionary tests =================================================="
  COMMAND dictionary_tests || (exit 0)
  COMMAND echo "Doublets tests ===================================================="
  COMMAND doublets_tests || (exit 0)
  DEPENDS doublets_tests dictionary_tests
)

add_custom_target(tests_alt
  COMMAND echo "Doublets tests ===================================================="
  COMMAND doublets_tests_alt || (exit 0)
  DEPENDS doublets_tests_alt
)

