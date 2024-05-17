#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_ConvertUnits_Angle

# Uninstall dependencies
arduino-cli lib uninstall \
  me_InstallStandardStreams \
  me_UartSpeeds \
  me_BaseTypes
