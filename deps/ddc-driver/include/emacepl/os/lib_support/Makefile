##############################################################################
# Data Device Corporation
#
# Filename: Makefile - makefile for drivers/acex/src/os/lib_support
#
# Copyright (c) 2011 Data Device Corporation
##############################################################################
# Non-Disclosure Statement
# ------------------------
# This software is the sole property of Data Device Corporation. All
# rights, title, ownership, or other interests in the software remain
# the property of Data Device Corporation. This software may be used
# in accordance with applicable licenses. Any unauthorized use,
# duplication, transmission, distribution, or disclosure is expressly
# forbidden.
#
# This non-disclosure statement may not be removed or modified without
# prior written consent of Data Device Corporation.
##############################################################################
# Module Description:
#
# This file contains the makefile rules for building the DDC ACEX library.
#
##############################################################################

TGT_DIR=$(WIND_BASE)/target

EXTRA_INCLUDE += -I../../..

EXTRA_DEFINE += $(DDC_EXTRA_DEFINE)
ADDED_CFLAGS += $(DDC_ADDED_CFLAGS)
LIB_BASE_NAME = $(DDC_LIB_BASE_NAME)

OBJS = ddc_os_lib_util.o

include $(TGT_DIR)/h/make/rules.library
