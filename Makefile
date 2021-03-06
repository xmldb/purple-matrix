#!/usr/bin/make -f

CC=gcc
LIBS=purple json-glib-1.0 glib-2.0

PKG_CONFIG=pkg-config
CFLAGS+=$(shell $(PKG_CONFIG) --cflags $(LIBS))
CFLAGS+=-fPIC -DPIC
LDLIBS+=$(shell $(PKG_CONFIG) --libs $(LIBS))
LDLIBS+=-lhttp_parser

PLUGIN_DIR_PURPLE	=  $(shell $(PKG_CONFIG) --variable=plugindir purple)
DATA_ROOT_DIR_PURPLE	=  $(shell $(PKG_CONFIG) --variable=datarootdir purple)

TARGET=libmatrix.so

include Makefile.common
