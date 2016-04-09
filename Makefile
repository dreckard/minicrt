

all: minicrt.lib

clean:
	if exist *.obj erase *.obj
	if exist *.lib erase *.lib
	if exist *.pdb erase *.pdb
	if exist *~ erase *~
	if exist *.manifest erase *.manifest


DEBUG=0

OBJS=env.obj      \
     envw.obj     \
     file.obj     \
     filew.obj    \
     mem.obj      \
     printf.obj   \
     printfw.obj  \
     printfsz.obj \
     rand.obj     \
     string.obj   \
     stringw.obj  \
     ep_cons.obj  \
     ep_consw.obj \
     ep_dll.obj   \
     ep_gui.obj   \
     ep_guiw.obj  \

LIB=link.exe -lib
LIB_NOLOGO=-nologo

CFLAGS=-nologo -W3 -MT
LDFLAGS=

!IF $(DEBUG)==1
CFLAGS_DEBUG=-Zi -Od
!ELSE
CFLAGS_DEBUG=-O1syi -Gy -Gs9999
!ENDIF

#
# Probe for more esoteric aspects of compiler behavior.
# Apparently pragma doesn't cut it for -GS-, and this is
# the most critical one for Minicrt.  MP is a perf
# optimization that only exists on newer compilers, so
# skip the probe on old ones.
#

!IF [$(CC) -GS- 2>&1 | find "unknown" >NUL]>0
CFLAGS_GS=-GS-
!IF [$(CC) -? 2>&1 | find "/MP" >NUL]==0
CFLAGS_MP=-MP
!ENDIF
!ENDIF

#
# Really old compiler support, when link.exe was
# link32.exe and didn't support -nologo
#

!IF [$(LIB) 2>&1 | find "Microsoft" >NUL]>0
!IF [link32.exe 2>&1 | find "Microsoft" >NUL]==0
LIB=link32.exe -lib
LIB_NOLOGO=
!ENDIF
!ENDIF

!IF [$(CC) -GF 2>&1 | find "unknown" >NUL]>0
CFLAGS_GF=-GF
!ELSE
CFLAGS_GF=-Gf
!ENDIF


CFLAGS=$(CFLAGS) $(CFLAGS_DEBUG) $(CFLAGS_GS) $(CFLAGS_MP) $(CFLAGS_GF)


minicrt.lib: $(OBJS)
	@$(LIB) $(LIB_NOLOGO) $(LDFLAGS) $(OBJS) /out:minicrt.lib


!IFDEF _NMAKE_VER
.c.obj::
!ELSE
.c.obj:
!ENDIF
	@$(CC) $(CFLAGS) -c $<

