gcc -I ./moduleA -c ./moduleA/student.c -o ./release/student.o
gcc -I ./moduleA -c ./moduleA/course.c -o ./release/course.o
ar rsv ./release/libstudent.a ./release/student.o
ar rsv ./release/libcourse.a ./release/course.o
gcc main.c -I ./moduleA -L ./release -lstudent -lcourse -o main

