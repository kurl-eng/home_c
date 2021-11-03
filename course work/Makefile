APPNAME = sensor

SRCS += main.c
SRCS += help.c
SRCS += temp_functions.c
CFLAGS += -O0 -g

all:
	gcc $(SRCS) -o $(APPNAME) $(CFLAGS)

clean:
	rm -f $(APPNAME)

debug:
	gcc -o $(APPNAME) $(SRCS) -DDEBUG

install:
	cp $(APPNAME) /usr/bin

uninstall:
	rm -f /usr/bin/$(APPNAME)