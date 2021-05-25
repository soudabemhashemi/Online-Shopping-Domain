all: a.out
a.out: goods.o car.o tv.o mobile.o user.o seller.o buyer.o store.o readfile.o exception.o offer.o admin.o packet.o validation.o sale.o md5.o main.o
	g++ goods.o car.o tv.o mobile.o user.o seller.o buyer.o store.o readfile.o exception.o offer.o admin.o packet.o validation.o sale.o md5.o main.o -o a.out
sale.o: sale.cpp sale.hpp offer.o
	g++ -std=c++11 -c sale.cpp
goods.o: goods.cpp goods.hpp user.o
	g++ -std=c++11 -c goods.cpp
md5.o: md5.cpp md5.hpp
	g++ -std=c++11 -c md5.cpp
tv.o: tv.cpp tv.hpp goods.o
	g++ -std=c++11 -c tv.cpp
md5.o: md5.cpp md5.hpp
	g++ -std=c++11 -c md5.cpp
car.o: car.cpp car.hpp goods.o
	g++ -std=c++11 -c car.cpp
mobile.o: mobile.cpp mobile.hpp goods.o
	g++ -std=c++11 -c mobile.cpp
user.o: user.cpp user.hpp exception.hpp seller.o admin.o md5.o
	g++ -std=c++11 -c user.cpp
buyer.o: buyer.cpp buyer.hpp packet.o store.o
	g++ -std=c++11 -c buyer.cpp
seller.o: seller.cpp seller.hpp offer.o admin.o sale.o
	g++ -std=c++11 -c seller.cpp
admin.o: admin.cpp admin.hpp offer.o user.o packet.o
	g++ -std=c++11 -c admin.cpp
store.o: store.cpp store.hpp goods.o user.o buyer.o offer.o admin.o sale.o
	g++ -std=c++11 -c store.cpp
validation.o: validation.cpp validation.hpp exception.o user.o admin.o buyer.o seller.o
	g++ -std=c++11 -c validation.cpp
readfile.o: readfile.cpp readfile.hpp store.o admin.o user.o seller.o validation.o
	g++ -std=c++11 -c readfile.cpp
exception.o: exception.cpp exception.hpp
	g++ -std=c++11 -c exception.cpp
offer.o: offer.cpp offer.hpp exception.o
	g++ -std=c++11 -c offer.cpp
packet.o: packet.cpp packet.hpp
	g++ -std=c++11 -c packet.cpp
main.o: main.cpp readfile.o user.o
	g++ -std=c++11 -c main.cpp 
.phony: clean
clean:
	rm *.o
	rm a.out
