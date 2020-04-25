## Snake Game in C++

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

This is the final project of the [Udacity](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). As the name of this repository indicates, one of the famous games is implemented here by using C++ and it is named SNAKE!. For running this project you have to ensure for installing some dependencies as below. So let's try to build this project first.

## Installing dependencies
* cmake >= 3.7
    * All OSes: click here for installation instructions
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
    * Linux: make is installed by default on most Linux distros
* SDL2 >= 2.0
    * All installation instructions can be found here
    * Note that for Linux, an apt or apt-get installation is preferred to building from source.
* gcc/g++ >= 5.4
    * Linux: gcc / g++ is installed by default on most Linux distros

Now it is time to clone this repository and build it.
1. Clone the repository: `git clone https://github.com/PooyaAlamirpour/SnakeGame.git`
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`

### Snake
If you run this project successfully, you should see a simple menu at the beginning of the starting of this project. This menu has three items. One is used for entering into a new game, another is for seeing the best score of the match and the final item is for closing the game. When the user starts a game, his name is asked. After the match is finished, his name and his score will be store on a file that is named `file_name_score`. When the user is playing the game, his score and the total distance that the snake goes are shown in the title of the window. In this project, I have defined a function that has some reference arguments. So it means, the reference in the function declaration is used. I have defined some classes which have setter and getter methods. Also, these classes have some related access modifiers and members. Mainly, This project is implemented based on Object-Oriented Programming techniques. 
In this project, you can see that we can get data from the user and we can store some data into a file. If the file does not exist, it will be created automatically.
