PLUGIN_NAME = ThreeBlockz

CCACHE = ccache
HAS_CCACHE := $(shell command -v ccache 2> /dev/null)

ifndef HAS_CCACHE
    CCACHE =
endif

CXX = $(CCACHE) g++

CXXFLAGS_BASE = -std=c++11 -g -fPIC -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -pthread
CXXFLAGS_COVERAGE = -fprofile-arcs -ftest-coverage
CXXFLAGS = $(CXXFLAGS_BASE) $(CXXFLAGS_COVERAGE)

CB_CFLAGS = `pkg-config --cflags codeblocks`
CB_LIBS = `pkg-config --libs codeblocks`

WX_CFLAGS = `wx-config --cflags --version=2.8`
WX_LIBS = `wx-config --libs --version=2.8`

SRC_DIR = src
SRCS = $(filter-out $(SRC_DIR)/$(PLUGIN_NAME).cpp, $(wildcard $(SRC_DIR)/*.cpp))

TEST_DIR = test

SRC_INCLUDE = include
#DEPEND_INCLUDE = -I/usr/include/codeblocks -I/usr/include/codeblocks/tinyxml -I/usr/include/codeblocks/scripting/include -I/usr/include/codeblocks/scripting/bindings -I/usr/include/codeblocks/scripting/sqplus -I/usr/include/codeblocks/wxscintilla/include -I/usr/lib64/wx/include/gtk2-unicode-release-2.8 -I/usr/include/wx-2.8 -I/usr/include/gmock
TEST_INCLUDE = test
INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

DOCS_DIR = docs

MEMCHECK_DIR = memcheck

MEMCHECK_TEST_RESULTS = test.xml

CPPCHECK_DIR = cppcheck

CPPCHECK_RESULTS = results.xml

PROGRAM = plugin
PROGRAM_TEST = testPlugin

PROGRAM_SHARED_LIB = $(PLUGIN_NAME).so

PROGRAM_PLUGIN_PACKAGE = $(PLUGIN_NAME).cbplugin

nocoverage:
	$(eval CXXFLAGS = $(CXXFLAGS_BASE))

.PHONY: all
all: $(PROGRAM) $(PROGRAM_TEST) memcheck-test coverage docs style

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CB_CFLAGS) $(WX_CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o obj .objs *.gcov *.gcda *.gcno $(COVERAGE_RESULTS) lib$(PROGRAM_SHARED_LIB) $(PROGRAM_SHARED_LIB)

.PHONY: clean-all
clean-all: clean
	rm -rf $(PROGRAM) $(PROGRAM_TEST) $(DOCS_DIR) $(MEMCHECK_DIR) $(COVERAGE_DIR) $(CPPCHECK_DIR) $(PROGRAM_PLUGIN_PACKAGE)

$(PROGRAM):
	$(CXX) $(CXXFLAGS) $(CB_CFLAGS) $(WX_CFLAGS) -o $(PROGRAM_SHARED_LIB) -I $(SRC_INCLUDE) $(SRC_DIR)/*.cpp -shared $(CB_LIBS) $(WX_LIBS) -lpthread
	rm -f $(PROGRAM_PLUGIN_PACKAGE)
	rm -f $(PLUGIN_NAME).zip
	zip -j9 $(PLUGIN_NAME).zip manifest.xml
	zip -j9 $(PROGRAM_PLUGIN_PACKAGE) $(PROGRAM_SHARED_LIB) $(PLUGIN_NAME).zip
	rm -f $(PLUGIN_NAME).zip

$(PROGRAM_TEST):
	$(CXX) $(CXXFLAGS) $(CB_CFLAGS) $(WX_CFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) $(TEST_DIR)/*.cpp $(SRCS) $(CB_LIBS) $(WX_LIBS) -lgtest -lpthread

test: $(PROGRAM_TEST)
	./$(PROGRAM_TEST)

memcheck-test: $(PROGRAM_TEST)
	mkdir -p $(MEMCHECK_DIR)
	valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=$(MEMCHECK_DIR)/$(MEMCHECK_TEST_RESULTS) ./$(PROGRAM_TEST)

coverage: test
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --no-external --directory . --output-file $(COVERAGE_RESULTS)
	# Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	# Remove all of the generated files from gcov
	rm -f *.gc*
	mv $(COVERAGE_RESULTS) $(COVERAGE_DIR)/$(COVERAGE_RESULTS)

style: ${SRC_DIR}
	mkdir -p $(CPPCHECK_DIR)
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${TEST_DIR} ${INCLUDE} --suppress=missingInclude &> $(CPPCHECK_DIR)/$(CPPCHECK_RESULTS)

static: style

docs:
	doxygen
