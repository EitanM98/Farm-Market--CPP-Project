CPP_FARM: farmMarket.o Market.o Farm.o cowFarm.o sheepFarm.o chickenFarm.o Animal.o Cow.o Sheep.o Chicken.o Product.o Milk.o Egg.o Wool.o
	g++ farmMarket.o Market.o Farm.o cowFarm.o sheepFarm.o chickenFarm.o Animal.o Cow.o Sheep.o Chicken.o Product.o Milk.o Egg.o Wool.o -o CPP_FARM
farmMarket.o:farmMarket.cpp Market.h cowFarm.h chickenFarm.h sheepFarm.h Farm.h Product.h Animal.h Milk.h Egg.h Wool.h Chicken.h Sheep.h Cow.h MarketExceptions.h
	g++ -c farmMarket.cpp
Market.o:Market.h Market.cpp cowFarm.h chickenFarm.h sheepFarm.h Farm.h Product.h Animal.h Milk.h Egg.h Wool.h Chicken.h Sheep.h Cow.h MarketExceptions.h
	g++ -c Market.cpp
Farm.o: Farm.h Farm.cpp Product.h Animal.h Milk.h Egg.h Wool.h Chicken.h Sheep.h Cow.h
	g++ -c Farm.cpp
cowFarm.o:cowFarm.h cowFarm.cpp Farm.h Product.h Animal.h Milk.h Egg.h Wool.h Chicken.h Sheep.h Cow.h
	g++ -c cowFarm.cpp
sheepFarm.o:sheepFarm.h sheepFarm.cpp Farm.h Product.h Animal.h Milk.h Egg.h Wool.h Chicken.h Sheep.h Cow.h
	g++ -c sheepFarm.cpp
chickenFarm.o:chickenFarm.h chickenFarm.cpp Farm.h Product.h Animal.h Milk.h Egg.h Wool.h Chicken.h Sheep.h Cow.h
	g++ -c chickenFarm.cpp
Animal.o: Product.h Animal.cpp Animal.h
	g++ -c Animal.cpp
Cow.o: Animal.h Cow.cpp Cow.h Product.h
	g++ -c Cow.cpp
Sheep.o:Animal.h Sheep.cpp Sheep.h Product.h
	g++ -c Sheep.cpp
Chicken.o:Animal.h Chicken.cpp Chicken.h Product.h
	g++ -c Chicken.cpp
Product.o: Product.cpp Product.h
	g++ -c Product.cpp
Milk.o:Product.h Milk.h Milk.cpp
	g++ -c Milk.cpp 
Egg.o:Product.h Egg.h Egg.cpp
	g++ -c Egg.cpp 
Wool.o:Product.h Wool.h Wool.cpp
	g++ -c Wool.cpp 
clean: 
	rm -f *.o CPP_FARM
