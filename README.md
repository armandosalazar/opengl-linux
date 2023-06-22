*install dependences*

`sudo pacman -S glfw-x11`

*use glfw3*

`gcc main.c -o main -lglfw`

*use opengl*

`gcc main.c -o main -lgldw -lGL`

*run mac*
`gcc main.c -o main -lglfw -framework OpenGL -Wno-deprecated-declarations; ./main`

