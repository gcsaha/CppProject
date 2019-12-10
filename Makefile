SUBDIRS := $(wildcard */.)
PP := alarmClock barberProject

.PHONY: all $(SUBDIRS) 
all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: clean $(PP)
clean: $(PP)
$(PP):
	$(MAKE) -C $@ clean
