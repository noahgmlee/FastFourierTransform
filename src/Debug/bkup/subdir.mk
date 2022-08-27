################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bkup/discreteFT_bkup.cpp 

OBJS += \
./bkup/discreteFT_bkup.o 

CPP_DEPS += \
./bkup/discreteFT_bkup.d 


# Each subdirectory must supply rules for building sources it contributes
bkup/%.o: ../bkup/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


