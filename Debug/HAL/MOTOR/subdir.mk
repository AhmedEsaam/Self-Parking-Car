################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/MOTOR/DC_Motor_programe.c 

OBJS += \
./HAL/MOTOR/DC_Motor_programe.o 

C_DEPS += \
./HAL/MOTOR/DC_Motor_programe.d 


# Each subdirectory must supply rules for building sources it contributes
<<<<<<< HEAD
HAL/MOTOR/%.o: ../HAL/MOTOR/%.c HAL/MOTOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
=======
HAL/MOTOR/%.o: ../HAL/MOTOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
>>>>>>> 359433dbf892e7e27816a34f950ec3ce26269be6
	@echo 'Finished building: $<'
	@echo ' '

