# MyApp
RCV App for EGEN310

# Set up
- Pull this code onto your laptop and your Arduino Nano 33 BLE
- On your Arduino Nano: Upload file Test2, which is the arduino code, and you should see the LED on board go from blinking to solid on

- On your laptop: connect your phone to Android Studio and enable it to run on it
- Open the app on your phone, use the BLE scanner to connect to your arduino, and you are good to go!

# Notes about the files
- In the java/com.example.ardroid file, as well as in res/layout, and res/menu, all contain files that I wrote. All the files in those
folders part written by me and part generated by AndroidStudio, which is what I wrote this app one, when you add buttons, and move things
around.
- The changes from prototype 1 to 2 were made mostly with button layout, I wanted larger buttons for movement control so it was easier for my large thumbs on the screen. Also I added the drop down menu for BLE scanning so it would be easier to find our device.
- A lot of this was written without any access to the phone I was going to use for the app itself, the arduino board, and the car. Therefore, much of it is untested and is the best I could do under the circumstances, while still probably having large gaping holes where I just wouldn't know to look.
