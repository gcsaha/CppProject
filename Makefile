SUBDIRS = $(wildcard */.) 

all:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir; \
	done
clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done
memcheck:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir memcheck; \
	done
