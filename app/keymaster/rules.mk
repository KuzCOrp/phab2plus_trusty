LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

KEYMASTER_ROOT := $(ANDROIDMAKEROOT)/system/keymaster

MODULE_SRCS += \
	$(KEYMASTER_ROOT)/android_keymaster.cpp \
	$(KEYMASTER_ROOT)/android_keymaster_messages.cpp \
	$(KEYMASTER_ROOT)/android_keymaster_utils.cpp \
	$(KEYMASTER_ROOT)/auth_encrypted_key_blob.cpp \
	$(KEYMASTER_ROOT)/asymmetric_key.cpp \
	$(KEYMASTER_ROOT)/asymmetric_key_factory.cpp \
	$(KEYMASTER_ROOT)/authorization_set.cpp \
	$(KEYMASTER_ROOT)/ec_key.cpp \
	$(KEYMASTER_ROOT)/ec_key_factory.cpp \
	$(KEYMASTER_ROOT)/ecdsa_operation.cpp \
	$(KEYMASTER_ROOT)/key.cpp \
	$(KEYMASTER_ROOT)/keymaster_enforcement.cpp \
	$(KEYMASTER_ROOT)/logger.cpp \
	$(KEYMASTER_ROOT)/ocb.c \
	$(KEYMASTER_ROOT)/ocb_utils.cpp \
	$(KEYMASTER_ROOT)/openssl_err.cpp \
	$(KEYMASTER_ROOT)/openssl_utils.cpp \
	$(KEYMASTER_ROOT)/operation.cpp \
	$(KEYMASTER_ROOT)/operation_table.cpp \
	$(KEYMASTER_ROOT)/rsa_key.cpp \
	$(KEYMASTER_ROOT)/rsa_key_factory.cpp \
	$(KEYMASTER_ROOT)/rsa_operation.cpp \
	$(KEYMASTER_ROOT)/serializable.cpp \
	$(LOCAL_DIR)/trusty_keymaster_context.cpp \
	$(LOCAL_DIR)/trusty_keymaster_enforcement.cpp \
	$(LOCAL_DIR)/manifest.c

MODULE_INCLUDES := \
	$(KEYMASTER_ROOT)/include \
	$(KEYMASTER_ROOT) \
	$(KEYMASTER_ROOT)/../../hardware/libhardware/include \
	$(LOCAL_DIR)

MODULE_CPPFLAGS := -std=c++11
MODULE_CPPFLAGS += -fno-short-enums

IPC := ipc

MODULE_DEPS += \
	app/trusty \
	lib/libc-trusty \
	lib/libstdc++-trusty \
	lib/rng \
	lib/hwkey

include $(LOCAL_DIR)/$(IPC)/rules.mk

include make/module.mk
