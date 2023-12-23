# Holonomic-Art-Bot
Allocated theme for E-yantra Robotics Competition 2022-2023

Cities, by nature, are constantly under development. In the future, the process of achieving the ever-demanding upgrades in the infrastructure of a city will be automated. The impact of such automation can lead to lesser construction time, little to no manual labour and lower execution costs. With more time, energy and finance to spare, this automation will be empowered by technology and imagination of the mind, and leave room for artistic expression.

Humans have an inherent need to make sense of the world around them, understand it and then create something new out of it. For a more inclusive city, this is even more true. Demarcations on the road, signage on billboards and bus stops, and well-landscaped gardens provide order to the chaos and create an environment where the inhabitants can connect to their primal need to belong.

Keeping the above scenario in mind, eYRC 2022-23 present the theme HolA Bot (HB)! HolA Bot is short for Holonomic Art Bot. As the full name suggests, this theme will have two major components to it: Holonomic Drive Bot and Art!

In this theme, the teams will build a HolA Bot for deployment in an arena which is an abstraction of different settings in a Smart City. To enable the robot to do more complex art, the teams will explore an exciting type of mobile locomotion, known as Holonomic Drive. Unlike the usual, more popular differential drive robots, the holonomic drive robots can control all the three degrees of freedom possible on a plane (translation along the x, y-axis and rotation along the z-axis). This gives the robot the ability to make art that would otherwise not be possible with the usual two-wheeled differential drive robot.

**The Differential Drive Robot (Non-holonomic system) has non-holonomic constraints that prevent direct control of translation in one axis
Project Description: A holonomic robot was built using Omniwheels, which is controlled by an ESP32. A pen that can move up and down is mounted on the bot. The bot recieves velocity commands from the laptop through the WIFI to reach the desired position. The current position is obtained using a overhead camera that detects the Aruco marker mounted on the bot. This is communicated to the laptop, which containes the series of desired positions to draw the image or mathematical position. The Desired position and current position is compared to calculate the required velocity of the chassis. Which is then converted to wheel velocities and published to the bot through the WIFI.

This project was done as part of the Eyantra Robotics Competition conducted by IIT Bombay.

The codes needed for the final Implementation:
The softwere is made of 3 python files running on ROS and and an Arduino code running on ESP32. Basic description of the code is done below.

Arduino Code:

ESP32_code_1esp.ino

Recieves velocity of motors as string through the WIFI. Actuates the motors using it.

Python files:

aruco_final.py

Setting up the overhead camera. Cropping the arena from the frame using the 4 aruco markers in the corners. This cropped frame is scaled to 500x500 pixels. The aruco marker on the bot is detected and its coordinates is calculated based on the corners of the aruco markers. This coordinates is the current position of the bot, which is published to connection_final.py.

connection_final.py:

The current position is recieved.The image or mathematical function is converted to set of coordinates. These are the desired coordinates. The differnce of desired and current position is calculated. This is converted to body frame and applied to a PD Controller. This is the desired chassis velocity, which is converted to wheel velocity using inverse kinematics. This velocity is published to connection_final.py

connection_final.py:

A websocket is initiated in the WIFI. The recieved velocity is sent to the esp32 board mounted on the bot through WIFI which is connected as Socket client.
