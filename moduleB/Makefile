all:student_i.o course_i.o libstudent_i.a libcourse_i.a
student_i.o:student_i.c
	gcc -c student_i.c -o ../release/student_i.o
course_i.o:course_i.c
	gcc -c course_i.c -o ../release/course_i.o
libstudent_i.a:student_i.o
	ar rsv ../release/libstudent_i.a ../release/student_i.o
libcourse_i.a:course_i.o
	ar rsv ../release/libcourse_i.a ../release/course_i.o

