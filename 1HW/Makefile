TARGET = sort_lnx
DEPS = insertion_sort
DEPS:=$(addsuffix .o, $(DEPS))

CC=gcc
CFLAGS =-O2

.PHONY: all clean #Отслеживает появления файла 

all:	$(TARGET)

$(TARGET):$(DEPS)
	$(CC) $(CFLAGS) $(addsuffix .c,$(TARGET)) $(DEPS) -o $<

%.o: %.c		#Любой файл с .о собирается при наличии .с
	$(CC) $(CFLAGS) -c $< 	# @ показывает что надо подставить туда файл .с 
clean:
	@echo Tidying things up...
	rm -f $(TARGET)
	-rm -f $(DEPS)
	-rm -f *.o $(TARGET)

target: dep1 dep2 dep3
