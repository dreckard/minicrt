
all: libminicrt.a

CFLAGS=-Os -fno-stack-protector -Iinclude
DEBUG=0
VPATH=src

ifeq ($(DEBUG),1)
CFLAGS += -g
endif

clean:
	rm -f *.o *.a *~

OBJS=env.o envw.o file.o filew.o mem.o printf.o printfw.o printfsz.o rand.o string.o stringw.o ep_cons.o ep_consw.o ep_dll.o ep_gui.o ep_guiw.o 

libminicrt.a: $(OBJS)
	ar r libminicrt.a $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
