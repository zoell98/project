all:student.o course.o libstudent.a libcourse.a
student.o: student.c
	gcc -c student.c -o ../release/student.o
course.o: course.c
	gcc -c course.c -o ../release/course.o
libstudent.a: student.o
	ar rsv ../release/libstudent.a ../release/student.o
libcourse.a: course.o
	ar rsv ../release/libcourse.a ../release/course.o

