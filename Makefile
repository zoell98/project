MAKE=make
ifeq ($(choose),1)
myapp:
	make all -C moduleA && gcc main.c -I ./moduleA -L ./release -lstudent -lcourse -o main
else
myapp:
	make all -C moduleB && gcc main.c -I ./moduleB -L ./release -lstudent_i -lcourse_i -o main

endif
