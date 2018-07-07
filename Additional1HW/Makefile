TARGET =main
DEPS =factorization
DEPS:=$(addsuffix .o, $(DEPS))

CC=gcc
CFLAGS =-O2

.PHONY: all clean  

all:	$(TARGET)

$(TARGET):$(DEPS)
	$(CC) $(CFLAGS) $(addsuffix .c,$(TARGET)) $(DEPS) -o $@ -lm

%.o: %.c		
	$(CC) $(CFLAGS) -c $< 	 
clean:
	@echo Tidying things up...
	rm -f $(TARGET)
	-rm -f $(DEPS)
	-rm -f *.o $(TARGET)


