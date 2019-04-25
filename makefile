
stu1459_mysh:stu1459_mysh.o match.o lls.o lecho.o lcat.o lmkdir.o lrm.o lcd.o lpwd.o lwc.o
	gcc stu1459_mysh.o match.o lls.o lecho.o lcat.o lmkdir.o lrm.o lcd.o lpwd.o lwc.o -o stu1459_mysh 
 
main.o:main.c	
	gcc -c stu1459_mysh.c -o stu1459_mysh.o
match.o:match.c
	gcc -c match.c -o match.o
lls.o:lls.c
	gcc -c lls.c -o lls.o
lecho.o:lecho.c	
	gcc -c lecho.c -o lecho.o
lcat.o:lcat.c
	gcc -c lcat.c -o lcat.o
lmkdir.o:lmkdir.c
	gcc -c lmkdir.c -o lmkdir.o
lrm.o:lrm.c
	gcc -c lrm.c -o lrm.o
lcd.o:lcd.c
	gcc -c lcd.c -o lcd.o
lpwd.o:lpwd.c
	gcc -c lpwd.c -o lpwd.o
lwc.o:lwc.c
	gcc -c lwc.c -o lwc.o

clean:
	rm -f *.o stu1459_mysh 
