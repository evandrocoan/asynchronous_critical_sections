# EPOS Machine Mediators Makefile

include	../../makedefs

# https://www.gnu.org/software/make/manual/html_node/Testing-Flags.html#Testing-Flags
ifneq (,$(findstring -i clean,$(MAKE)))
SUBDIRS := $(shell find * -maxdepth 0 -type d)
else
SUBDIRS := common $(MACH)
endif

all:
	${MAKE} all_multithread -j$(NPROCS)

all_multithread: $(SUBDIRS)

$(SUBDIRS):	FORCE
		(cd $@ && $(MAKE))

clean:
		make MAKE:="${MAKE} $(MAKECLEAN)" $(SUBDIRS)

FORCE:
