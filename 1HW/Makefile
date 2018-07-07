TARGET = sort_lnx
DEPS = insertion_sort
DEPS:=$(addsuffix .o, $(DEPS))

CC=gcc
CFLAGS =-O2

.PHONY: all clean 

all:	$(TARGET)

$(TARGET):$(DEPS)
	$(CC) $(CFLAGS) $(addsuffix .c,$(TARGET)) $(DEPS) -o $@

%.o: %.c		#Любой файл с .о собирается при наличии .с
	$(CC) $(CFLAGS) -c $< 	
clean:
	@echo Tidying things up...
	rm -f $(TARGET)
	-rm -f $(DEPS)
	-rm -f *.o $(TARGET)


