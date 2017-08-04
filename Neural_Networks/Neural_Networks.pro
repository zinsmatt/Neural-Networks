TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    neuron.cpp \
    layer.cpp \
    inputlayer.cpp \
    outputlayer.cpp \
    hiddenlayer.cpp \
    neuralnet.cpp

HEADERS += \
    neuron.h \
    layer.h \
    inputlayer.h \
    outputlayer.h \
    hiddenlayer.h \
    neuralnet.h
