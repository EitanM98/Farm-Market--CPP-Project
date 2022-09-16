cmake_minimum_required(VERSION 3.21)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4 farmMarket.cpp Farm.cpp Farm.h Market.cpp Market.h Animal.cpp Animal.h Cow.cpp Cow.h Sheep.cpp Sheep.h Chicken.cpp Chicken.h Product.cpp Product.h Milk.cpp Milk.h Wool.cpp Wool.h Egg.cpp Egg.h cowFarm.cpp cowFarm.h chickenFarm.cpp chickenFarm.h sheepFarm.cpp sheepFarm.h MarketExceptions.h)
