################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/base_detector.cpp \
../src/fgs.cpp \
../src/gp_regression.cpp \
../src/local_fgs.cpp 

OBJS += \
./src/base_detector.o \
./src/fgs.o \
./src/gp_regression.o \
./src/local_fgs.o 

CPP_DEPS += \
./src/base_detector.d \
./src/fgs.d \
./src/gp_regression.d \
./src/local_fgs.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


