# ULTRASONIC BLINDSTICK WITH GSM AND GPS TRACKING
This is a smart stick that assists blind people by providing five crucial features: Obstacle Detection, Water Sensing, tracking,sending messages and  Smart Decision Making.  




<p align="center">
  <img width="245" alt="image" src="https://github.com/Elbina-Paudel/Ultrasonic-Blindstick-with-GSM-and-GPS-tracking/assets/120787628/267e85a0-ee91-42a9-bd80-02e56e85a66e">

</p>


## Tools & Materials Used
* Arduino Nano
* Ultrasonic sensor(JSN SR04T)
* Water Sensor(hw038)
* Buzzers - 2 pcs
* Battery
* GSM module
* GPS module (NEO 6M)
* Buck Converter



## Working 
<p align="center">
<img width="313" alt="image" src="https://github.com/Elbina-Paudel/Ultrasonic-Blindstick-with-GSM-and-GPS-tracking/assets/120787628/422250c7-044c-425b-8a15-dfec50372121">
  </p>
 

<p align="center">
<img width="449" alt="image" src="https://github.com/Elbina-Paudel/Ultrasonic-Blindstick-with-GSM-and-GPS-tracking/assets/120787628/f6a76ba1-fbbc-4a3c-a31d-9e44b3b7d3b4">
  </p>
  
  <p align="center">
<img width="430" alt="image" src="https://github.com/Elbina-Paudel/Ultrasonic-Blindstick-with-GSM-and-GPS-tracking/assets/120787628/7fa6d401-e6fa-481e-a112-ba6818a5111d">
  </p>







1 System Initialization:

We initialize the components, including the Arduino board, ultrasonic sensor, GSM module, GPS module, and water sensor. After that, pins will be configured for the ultrasonic sensor, GSM communication, GPS communication, and the water sensor.

2 Obstacle Detection:

Object distance is detected from the ultrasonic sensor. The distance is checked along with a predefined threshold, indicating the presence of an obstacle. We use a water sensor to check for the presence of water. If water is detected then a specific alert (buzzing sound) is activated to notify the user.

3 Obstacle Alert:

The buzzer and vibrating motor is Activated if an obstacle is detected for immediate feedback to the user. SMS is sent to notify predefined contacts about the obstacle, including the user's location obtained from GPS.GPS data is included in SMS alerts for tracking purposes. On emergency button activation, the call is sent to the care taker. Timer setting is done to periodically send SMS updates with the current location to predefined contacts. The frequency is adjusted based on user preferences and power considerations.
