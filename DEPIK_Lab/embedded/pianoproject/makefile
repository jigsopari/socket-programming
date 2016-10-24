
CC = cc 
LD = ld
NM = nm
OC = objcopy

symbols: start.o root.o
	$(LD) -N -Ttext 0x100000 -e _start -nostdlib -o ram.out start.o          root.o
	$(OC) -O binary ram.out ram.bin
	$(NM) ram.out > symbols
	cp ram.bin /tftpboot/durga_pianofile		
start.o: start.S
	$(CC) -g -c start.S

root.o: root.c
	$(CC)  -g -c root.c
	
clean : 
	rm *.o
	rm *.out
	rm *.bin
	rm symbols
