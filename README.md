# Background

Nowadays, the industry is changing its organizational structure. This change is known as Industry 4.0, which is intended to improve the economic sector. Companies will become more intelligent by using diverse techniques. One such technique is “Automatic material handling” which deals with the problem of supplying the right material, at the right place and at the right time in the industries. The advantages are reduced labor cost, increased productivity, improved worker safety, reduced, manufacturing lead time and many more. Here we propose A Smart Automatic material handling technique which has an edge over the conventional methods.

# Problem Definition

Conventional Automatic material handling system in industries makes the use of Conveyors, Cranes, Monorails. The most modern approach makes use of a Unit load carrier called “Automated Guided Vehicle”. Guiding paths are used to guide AGV from source to destination. The guidance paths are created with the energized wire embedded in the floor, painted lines on the floor, with laser, with infrared transmitter-receiver, etc. The problem with the guide path is that it fails in dealing with dynamic changes in the structure of the environment and deployment is also not easy. The guidance path cannot always give the shortest path between two stations. It also fails with obstacles, traffic jams, collision identification.

# Project Development Approach

Each project need to be developed with software model which makes the project with high quality, reliable and cost effective. Our project is developed with the following software model,

•	The prototyping model is a systems development method in which a prototype is built, tested and then reworked as necessary until an acceptable outcome is achieved from which the complete system or product can be developed. This model works best in scenarios where not all of the project requirements are known in detail ahead of time. It is an iterative, trial-and-error process that takes place between the developers and the users.

•	The Prototyping Model is one of the most popularly used Software Development Life Cycle Models (SDLC models).This model is used when the customers do not know the exact project requirements beforehand. In this model, a prototype of the end product is first developed, tested and refined as per customer feedback repeatedly till a final acceptable prototype is achieved which forms the basis for developing the final product.

# System Modules

Here are some modules that we have use in this project:

•	Admin

Admin can edit, Add, Delete the goods location and manages user access.

•	User

User can give tasks to the AGVs and can only use other functionalities.

•	AGV

AGV receive the command from user interface and do action according to that. It pick up and deposit the goods.

•	Wi-Fi

WiFi is used for Indoor navigation purpose.

•	Cloud

Cloud is used to store routine tasks which will be helpful in future reference

# Functional Requirements
		
•	Path	Robot must be able to plan future path using WIFI routers.
		
•	Movements	Robot must be able to move in all directions.
		
•	Obstacles	Robot must be able to take action in order to avoid colliding
	with walls, furniture, or any other materials.
		
•	Capacity	Robot must be able to carry expected weight as per client
	request.
		
•	Assurance of	Robot must be able to acknowledge the client about the status
	Delivery	of delivery of goods.
   
   
# Hardware and Software Requirements

•	Hardware Requirements:

   1.	Edge Device

   2.	Wi-Fi Routers with high range frequency

   3.	Internet Services

   4.	IoT Components

      a.	MPU 6050

      b.	rFC522

   5.	Board computer(Raspberry pi)

   6.	Micro controller (Arduino)

   7.	Power Source

      •	Front end: ReactJS,HTML, CSS, Bootstrap, JavaScript, jQuery, AJAX

      •	Back end: NodeJS,AWS

      •	Database: DynamoDB

      •	IDE: Visual studio code, Notepad++, Arduino IDE

# Login Table

![login_table](https://user-images.githubusercontent.com/47167762/71502009-9991e380-2893-11ea-983d-bfcade5e3cb3.JPG)

# Register Table

![register_table](https://user-images.githubusercontent.com/47167762/71502042-ccd47280-2893-11ea-87ce-6c95a52e1c78.JPG)

# Location Table

![location_table](https://user-images.githubusercontent.com/47167762/71502047-cd6d0900-2893-11ea-80ce-26bb3e2792fe.JPG)

# External Table

![external_table](https://user-images.githubusercontent.com/47167762/71502045-cd6d0900-2893-11ea-8ef2-6d87b7c8ca8e.JPG)

# Internal Table

![internal_table](https://user-images.githubusercontent.com/47167762/71502046-cd6d0900-2893-11ea-855f-34a340c0f17f.JPG)

# Recharging Table

![recharging_table](https://user-images.githubusercontent.com/47167762/71502041-cc3bdc00-2893-11ea-8ba4-7281715ea2a5.JPG)

# Project Architecture 

![architecture](https://user-images.githubusercontent.com/47167762/71502043-ccd47280-2893-11ea-99fc-6b44802ee373.JPG)

# Implementation

➢	MQTT broker on Edge device

The MQTT protocol provides a lightweight method of carrying out messaging using a publish/subscribe model. This makes it suitable for Internet of Things messaging such as with low power sensors or mobile devices such as phones, embedded computers or microcontrollers. It requires a device to run a broker through wich devices can publish and subscribe for massages


Mosquito broker will run on edge device. The communication between AGVs and Web UI will take place through this edge device. MQTT protocol will be used to commutnicate with AGVs.

![MQTT](https://user-images.githubusercontent.com/47167762/71502233-14a7c980-2895-11ea-9244-aa8a9e9f0610.JPG)


➢	AGV(Automated Guided Vehicle)

The AGV is autnomous mobile robot, consist of onboard computer and other components, that can carry materials from one location to another.


The AGV will receive the Source and detinition from edge device by MQTT protocol. Each AGV will subscribe to the MQTT broker at edge device, as MQTT client to receive delivery details.

![AGV](https://user-images.githubusercontent.com/47167762/71502235-15406000-2895-11ea-9af0-104431dea21f.JPG)

# AGV Prototype

![AGV_prototype](https://user-images.githubusercontent.com/47167762/71502236-15406000-2895-11ea-9cf4-fc2872e1f311.JPG)
![AGV_prototype](https://user-images.githubusercontent.com/47167762/71502237-15406000-2895-11ea-881d-b475a3a7e77f.JPG)
![AGV_prototype](https://user-images.githubusercontent.com/47167762/71502238-15d8f680-2895-11ea-8e0b-751f4f7a46b6.JPG)

➢	Greengrass on AGV board computer

Greengrass is used to ectend cloud capabilities to each AGVs in system. OTA (Over the Air) updates as well as remote treacebelity of system is achieved through cloud support.


The path planning algorithm is deployed on each AGV using Greengrass.

![greengrass](https://user-images.githubusercontent.com/47167762/71502232-14a7c980-2895-11ea-9df4-072a2bd43449.JPG)
![greengrass_1](https://user-images.githubusercontent.com/47167762/71502234-14a7c980-2895-11ea-8c2e-e43a9c294046.JPG)


➢	Path Planning

AGVs Finds the optimum path between source and destination points. Optimum path is the one that minimizes the amount of turning or breackings.


After Path planning driving sequence is derived to guide the AGV in environment.
![path_planning](https://user-images.githubusercontent.com/47167762/71502442-3eadbb80-2896-11ea-81ef-59f1998d8c3f.JPG)

![path_planning](https://user-images.githubusercontent.com/47167762/71502445-3eadbb80-2896-11ea-8dc6-215f23a55a05.JPG)

➢	Flask Web Server on Edge Device

Flask architecture provides a python backend for our UI package.

![flask](https://user-images.githubusercontent.com/47167762/71502446-3eadbb80-2896-11ea-8de4-ff21042ee8dd.JPG)

# Schedule Delivery with DynamoDB

![station_delivery](https://user-images.githubusercontent.com/47167762/71502447-3f465200-2896-11ea-93b9-3b1737a7a525.JPG)

# Conclusion

The trend is clear: more and more companies, large and small are turning to solutions involving Automated Material Handling and Automated Guided Vehicle’s (AGV). The development of new vehicle types and technology break-throughs in field like AI leads to more intelligence in AGV solutions, and is expanding the scope of what an AGV can do. The rapidly growing e-commerce sector and paradigm shift in the automotive industry are other important driving factors.

Automated Guided Vehicle is SMART DECISION-MAKING VEHICLE. It is fully capable to lift and carry loads of significant weight and can move in an effective path without any deviation from its path.

# References 

## AWS Greengrass:

https://docs.aws.amazon.com/greengrass/latest/developerguide/what-is-gg.html

## AWS API Gateway:

https://docs.aws.amazon.com/apigateway/latest/developerguide/welcome.html

## Webpage:

https://developer.mozilla.org/en-US/docs/Web/JavaScript

## ReactJS:

https://reactjs.org/

## Serial Communication:

https://www.sunfounder.com/blog/rpi-ard/
