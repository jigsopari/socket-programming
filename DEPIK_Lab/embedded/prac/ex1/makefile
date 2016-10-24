
CC = cc 
LD = ld
NM = nm
OC = objcopy

symbols: start.o root1.o
	$(LD) -N -Ttext 0x300000 -e _start -nostdlib -o ram.out start.o          root1.o
	$(OC) -O binary ram.out ram.bin
	$(NM) ram.out > symbols1
	cp ram.bin /tftpboot/durga_bootfile		
start.o: start.S
	$(CC) -c start.S

root1.o: root1.c
	$(CC) $(CFLAGS) -c root1.c
	
clean : 
	rm *.o
	rm *.out
	rm *.bin
