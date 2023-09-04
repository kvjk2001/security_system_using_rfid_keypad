# security_system_using_rfid_keypad


#RFID(Radio Frequency Identification and Detection)  for security purposes solves many problems in today's world as hacking is getting more and more popular. It is not that easy to hack RFID as the RFID tag stores the particular information and if a new tag has the same information, it will not be scanned as it won't match the radio frequency of the original tag. Thus, RFID is a very safe and secure mode of locking system. But that does not mean that it does not have any disadvantages. Here the RFID tag will be checked, along with a password associated with the tag, to secure the system. This project is an RFID and keypad-based security system using 8052 microcontroller. RFID is an electronic device which has two parts - one is RFID Reader and other is RFID tag or Card. When the RFID tag is brought close to the RFID reader it reads tag data serially. A motor driver L293D is used for opening gate and a buzzer with a BC547 NPN transistor is used for indications. A 4X4 Keypad is used for entering password. When a person put’s their RFID tag to RFID reader then RFID reads tag’s data and sends it to 8052 microcontroller and then microcontroller compares this data with pre-defined data. If data is matched with predefined data, then microcontroller asks for password and after entering password microcontroller compares password with predefined password. If password matches, gate will open otherwise LCD shows access denied and buzzer starts beeping for some time
