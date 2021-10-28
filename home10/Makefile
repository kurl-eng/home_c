APPNAME = sensor

SRCS += main.c
SRCS += menu.c
SRCS += structs.c
SRCS += fileops.c

all: 
	gcc $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)
	
install:
	cp $(APPNAME) /home/${user}/$(APPNAME)

uninstall:
	rm -f /home/${user}/$(APPNAME)