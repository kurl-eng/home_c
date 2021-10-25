APPNAME = sensor

SRCS += main.c
SRCS += help.c
SRCS += menu.c
SRCS += structs.c
SRCS += fileops.c

all: 
	gcc $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)
install:
	cp $(APPNAME) /home/${usr}
uninstall:
	rm -f /home/${usr}