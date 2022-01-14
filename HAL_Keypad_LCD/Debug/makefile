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
KEY_PAD.lss \

FLASH_IMAGE += \
KEY_PAD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KEY_PAD.elf secondary-outputs

# Tool invocations
KEY_PAD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KEY_PAD.map -mmcu=atmega32 -o "KEY_PAD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KEY_PAD.lss: KEY_PAD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KEY_PAD.elf  >"KEY_PAD.lss"
	@echo 'Finished building: $@'
	@echo ' '

KEY_PAD.hex: KEY_PAD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KEY_PAD.elf  "KEY_PAD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KEY_PAD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KEY_PAD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KEY_PAD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
