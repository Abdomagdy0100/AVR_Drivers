################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
banking1-4-4-8_HAL.lss \

FLASH_IMAGE += \
banking1-4-4-8_HAL.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: banking1-4-4-8_HAL.elf secondary-outputs

# Tool invocations
banking1-4-4-8_HAL.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,banking1-4-4-8_HAL.map -mmcu=atmega32 -o "banking1-4-4-8_HAL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

banking1-4-4-8_HAL.lss: banking1-4-4-8_HAL.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S banking1-4-4-8_HAL.elf  >"banking1-4-4-8_HAL.lss"
	@echo 'Finished building: $@'
	@echo ' '

banking1-4-4-8_HAL.hex: banking1-4-4-8_HAL.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex banking1-4-4-8_HAL.elf  "banking1-4-4-8_HAL.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: banking1-4-4-8_HAL.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 banking1-4-4-8_HAL.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) banking1-4-4-8_HAL.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
