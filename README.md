# vision_algorithms_for_mobile_robotics

A collection of vision algorithms in the context of mobile robots.

### Dependencies:

sfml 2.4.2  
Eigen 3.3.7

### Install the dependencies as Linux Debian Packages:

`sudo apt-get install libsfml-dev libeigen3-dev libopencv-dev python3-opencv`

### Build the code using cmake:

Execute the following command in the build folder  
`cmake ..`  
`make clean`  
`make`  
You may then run the programm by using:  
`./runApplication`

provisional command:
`docker run --device=/dev/video0:/dev/video0 -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -p 5000:5000 -p 8888:8888 -it --name opencvtest3 vafmr_ex1 /bin/bash`

### Links:

https://www.sfml-dev.org/tutorials/2.5/start-linux.php
