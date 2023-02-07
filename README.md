# 42-CPP03 [![Project Status: WIP – Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip) <img src="https://badgen.net/badge/Platform/macOS/grey?icon=default" /> <img align=right src="https://badgen.net/badge/Grade/pending/black?icon=default" />


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
