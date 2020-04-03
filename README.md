# Lidar obstacle detection  

<img src="media/ObstacleDetectionFPS.gif" width="700" height="400" />

## Introduction 

In this project we build lidar obstacle detection process pipline to stream back multiple pcd files and perform filtering, segmentation, clustering, and bounding box detection and we build kd-tree and Euclidean clustring from scratch instead of using built in functions 

## Installation

### Ubuntu 

```bash
$> sudo apt install libpcl-dev
$> cd ~
$> git clone https://github.com/AhmdNassar/lidar-obstacle-detection.git
$> cd SFND_Lidar_Obstacle_Detection
$> mkdir build && cd build
$> cmake ..
$> make
$> ./environment
```

### Windows 

http://www.pointclouds.org/downloads/windows.html

### MAC

#### Install via Homebrew
1. install [homebrew](https://brew.sh/)
2. update homebrew 
	```bash
	$> brew update
	```
3. add  homebrew science [tap](https://docs.brew.sh/Taps) 
	```bash
	$> brew tap brewsci/science
	```
4. view pcl install options
	```bash
	$> brew options pcl
	```
5. install PCL 
	```bash
	$> brew install pcl
