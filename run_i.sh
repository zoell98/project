gcc -I ./moduleB -c ./moduleB/student_i.c -o ./release/student_i.o
gcc -I ./moduleB -c ./moduleB/course_i.c -o ./release/course_i.o
ar rsv ./release/libstudent_i.a ./release/student_i.o
ar rsv ./release/libcourse_i.a ./release/course_i.o
gcc main.c -I ./moduleA -I ./moduleB -L ./release -lstudent_i -lcourse_i -o main
