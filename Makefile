all:	driver_database
CXX	=	g++
CFLAGS	=	-Wall	-g

driver_database:	main.o	Address.o	Date.o	Driver.o	DriverDatabase.o	DriverHashTable.o	DriverList.o	OldestLicenseTracker.o	RecentLicenseTracker.o	Ticket.o
	$(CXX)	$(CFLAGS)	-o	driver_database	main.o	Address.o	Date.o	Driver.o	DriverDatabase.o	DriverHashTable.o	DriverList.o	OldestLicenseTracker.o	RecentLicenseTracker.o	Ticket.o

Address.o:	Address.cpp	Address.h
	$(CXX)	$(CFLAGS)	-c	Address.cpp
Date.o:	Date.cpp	Date.h
	$(CXX)	$(CFLAGS)	-c	Date.cpp
Driver.o:	Driver.cpp	Driver.h
	$(CXX)	$(CFLAGS)	-c	Driver.cpp
DriverDatabase.o:	DriverDatabase.cpp	DriverDatabase.h
	$(CXX)	$(CFLAGS)	-c	DriverDatabase.cpp
DriverHashTable.o:	DriverHashTable.cpp	DriverHashTable.h
	$(CXX)	$(CFLAGS)	-c	DriverHashTable.cpp
DriverList.o:	DriverList.cpp	DriverList.h
	$(CXX)	$(CFLAGS)	-c	DriverList.cpp
OldestLicenseTracker.o:	OldestLicenseTracker.cpp	OldestLicenseTracker.h
	$(CXX)	$(CFLAGS)	-c	OldestLicenseTracker.cpp
RecentLicenseTracker.o:	RecentLicenseTracker.cpp	RecentLicenseTracker.h
	$(CXX)	$(CFLAGS)	-c	RecentLicenseTracker.cpp
Ticket.o:	Ticket.cpp	Ticket.h
	$(CXX)	$(CFLAGS)	-c	Ticket.cpp
main.o:	main.cpp
	$(CXX)	$(CFLAGS)	-c	main.cpp

clean:
	rm	*.o	driver_database