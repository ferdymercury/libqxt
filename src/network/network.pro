TARGET           =  QxtNetwork
DEPENDPATH      += .
INCLUDEPATH     += . ../core ../../deploy/include
DEFINES         += BUILD_QXT_NETWORK
CONFIG          += qxtbuild convenience
QT              =  core network
TEMPLATE        = lib

LIBS            += -L../../deploy/libs/ -lQxtCore -lQxtKit
LIBS            += -lssl	


QxtBlowFish.sources 	= QxtBlowFish.cpp
QxtBlowFish.stability 	= +linux-g++ +win32-g++

QxtRPCPeer.sources 	= QxtRPCPeer.cpp
QxtRPCPeer.stability 	= +linux-g++ +win32-g++

Parts=QxtBlowFish QxtRPCPeer
