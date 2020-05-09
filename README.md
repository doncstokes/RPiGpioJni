# RPiGpioJni

This is a Java Native Interface (JNI) wrapper for the C file "c_gpio.c" from the python RPi.GPIO project
by Ben Croston stored at https://sourceforge.net/projects/raspberry-gpio-python . This C file is self contained
and can be easily reused without python to read/write Raspberry Pi GPIO pins. I created this JNI wrapper so that I could access c_gpio.c from Java applications.

Under the top level directory, you will find two projects. The first is an eclipse Java project that creates the jar file
featuring the RPiGpio class as an API for Java applications that wish to access Raspberry Pi GPIO. This project also
generates the C skelton for the C eclipse project. You will find a Main class in this project as an example of API usage
and a test program for the module. The second project is an eclipse C project that creates the shared object library file
that is loaded at runtime by the RPiGpio class.

To integrate this API with your java application, first build the java jar from the eclipse java project.
Second, build the shared object library "librpigpiojni.so" with the eclipse C project. The library file must be placed
in a place where the loader can find it, either one of the system lib directories or a directory included in the
"LD_LIBRARY_PATH" environment variable. Third, build your java application with the API jar from the first step.
In your application, instanitate an instance of RPiGpio, call the "setup" method, call the "setup_gpio" method for each
of your GPIOs, call the "input" and "output" methods to read/write GPIOs. Lastly, call the "cleanup" method before you
terminate.

You will find more documentation in the javadoc of the API classes.

*** USE CAUTION WHEN EXECUTING THIS CODE as you can damage your hardware if done incorrectly. ***

My compliments go out to Ben Croston for creating a wonderfully reusable piece of software in the RPi.GPIO python module.
