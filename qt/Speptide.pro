QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ../../VisPeptide/src/spc/mparser.cpp \
    ../../VisPeptide/src/spc/ms1ms2.cpp \
    ../../VisPeptide/src/spc/result.cpp \
    ../../VisPeptide/src/spc/scoring.cpp \
    ../../VisPeptide/src/spc/spectra.cpp \
    ../../VisPeptide/src/spc/speptide.cpp \
    ../../VisPeptide/src/ini/dictionary.c \
    ../../VisPeptide/src/ini/iniparser.c

HEADERS += \
    mainwindow.h \
    ../../VisPeptide/src/spc/mparser.h \
    ../../VisPeptide/src/spc/ms1ms2.h \
    ../../VisPeptide/src/spc/result.h \
    ../../VisPeptide/src/spc/scoring.h \
    ../../VisPeptide/src/spc/spectra.h \
    ../../VisPeptide/src/spc/speptide.h \
    ../../VisPeptide/src/ini/dictionary.h \
    ../../VisPeptide/src/ini/iniparser.h
