CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -g

SOURCES = main.cpp
SOURCES += InputVal.cpp Menu.cpp
SOURCES += Space.cpp Map.cpp
SOURCES += OldGrowth.cpp Successional.cpp
SOURCES += River.cpp Dirt.cpp
SOURCES += Farm.cpp Highway.cpp Building.cpp
SOURCES += Game.cpp Ent.cpp
SOURCES += Item.cpp Boulder.cpp MagicIce.cpp Seeds.cpp
SOURCES += Fire.cpp Water.cpp Heal.cpp

HEADERS = InputVal.hpp Menu.hpp
HEADERS += Colors.hpp Sprites.hpp
HEADERS += Space.hpp Map.hpp
HEADERS += OldGrowth.hpp Successional.hpp
HEADERS += River.hpp Dirt.hpp
HEADERS += Farm.hpp Highway.hpp Building.hpp
HEADERS += Game.hpp Ent.hpp
HEADERS += Item.hpp Boulder.hpp MagicIce.hpp Seeds.hpp
HEADERS += Fire.hpp Water.hpp Heal.hpp

ent: ${SOURCES} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SOURCES} -o ent




