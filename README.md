# 42-CPP03 [![Project Status: WIP – Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip) [![Developed on Platform MacOS](https://badgen.net/badge/Platform/macOS/grey?icon=default)](#) [![jjane-ta 42 Graded points](https://badgen.net/badge/Grade/100/green?icon=default)](#)


## Ex00

ClapTrap class: 
- Attributes : name, health, energy and damage.
- Public fuctions : 
  - attack :
    - Only when has energy and health.
    - Decrease one energy each time.
    - No attack him self.
    - Check if the target exist.
    - **Target its AUTOMATICLY notified when take damage.**
  - takeDamage :
    - Is not possible take more damage than health.
  - beRepaired :
    - Only when has energy.
    - Decrease one energy each time.
    - Is not possible take more health than max_health. 
    
- Out of Subject : The next and prev attributes are implemented to store all instances of this Class that are created and thus make it possible to find the target by name.

## Ex01
ScavTrap class: This clas is derived of ClapTrap base class.
  - Printed in RED.
  - The constructors call the base class's constructors before updating the class values and printing their own messages.
  - The functions attack and takeDamage call the function of the base clas.
  - The function beRepaired override base class function.
  - New var _isGuard is setted true when ScavTrap::guarGate member function is called.
 
 ClapTrap class: Updated
  - Printed in WHITE
  - Now default destructor is virtual.
  - Now default constructor and some private vars are protected.
  - Now beRepaired function is virtual.
  
## Ex02
  FrapTrap class: This is a derived class of ClapTrap, this class is almost identical to the ScavTrap.
  - Printed in PURPLE
  - Some static values of the class are changed.
  - New var FragTrap::highFivesGuys() member function is implemented.
  
## Ex03
DiamondTrap Class: Multiple inheritance
  - Printed in GREEN
  - The super class Claptrap subobject of the DiamondTrap is created once, and only once.
  - This class has its own variable name.
  - Inheritance:
    - ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
    - Hit points (FragTrap)
    - Energy points (ScavTrap)
    - Attack damage (FragTrap)
    - attack() (Scavtrap)
  
  
  
  
