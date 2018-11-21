#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := esp32-tdd-boilerplate

# Create file Makefile.local in the project root and
# define IDF_PATH := /path/to/ESP32/SDK/folder
include Makefile.local

include $(IDF_PATH)/make/project.mk
