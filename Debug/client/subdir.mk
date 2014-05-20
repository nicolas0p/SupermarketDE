################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../client/Client.cpp \
../client/SearchLessItems.cpp \
../client/SearchSmallQueue.cpp \
../client/makeRandomClient.cpp 

OBJS += \
./client/Client.o \
./client/SearchLessItems.o \
./client/SearchSmallQueue.o \
./client/makeRandomClient.o 

CPP_DEPS += \
./client/Client.d \
./client/SearchLessItems.d \
./client/SearchSmallQueue.d \
./client/makeRandomClient.d 


# Each subdirectory must supply rules for building sources it contributes
client/%.o: ../client/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


