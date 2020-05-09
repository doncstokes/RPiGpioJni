################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../c_gpio.c \
../rpigpiojni.c 

O_SRCS += \
../c_gpio.o 

OBJS += \
./c_gpio.o \
./rpigpiojni.o 

C_DEPS += \
./c_gpio.d \
./rpigpiojni.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/lib/jvm/java-8-openjdk/include/ -I/usr/lib/jvm/java-8-openjdk-armhf/include/ -I/usr/lib/jvm/java-8-openjdk-armhf/include/linux -I/usr/lib/jvm/java-8-openjdk/include/linux -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


