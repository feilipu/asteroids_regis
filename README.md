
# ASTEROIDS

This is a recreation of the classic asteroids video game.

Implemented in the C programming language, using ReGIS to display graphics on the screen.

To compile you need to have z88dk installed on your system and the header files available to you.

Display is via [XTerm compiled with ReGIS enabled](https://github.com/feilipu/ReGIS?tab=readme-ov-file#preparing-xterm-to-support-regis).

For convenience CP/M is chosen as the target platform, but other targets are possible.

```sh
    # ZSDCC compile
    zcc +rc2014 -subtype=cpm -v -m --list --math32 --max-allocs-per-node100000 main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 compile
    zcc +rc2014 -subtype=cpm -clib=new -v -m --list -O2 --math32 main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 CP/M math32 compile
    zcc +cpm -v -m --list -O2 -DAMALLOC --math32 -lfastmath main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 CP/M math16 compile
    zcc +cpm -v -m --list -O2 -DAMALLOC --math16 --math32 -lfastmath main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 CP/M am9511 compile
    zcc +cpm -v -m --list -O2 -DAMALLOC --am9511 -lfastmath main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app
    
    # SCCZ80 CP/M z180 math16 compile
    zcc +cpm -clib=z180 -v -m --list -O2 -DAMALLOC --math16 --math32 -lfastmath main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 CP/M 8085 am9511 compile
    zcc +cpm -clib=8085 -v -m --list -O2 -DAMALLOC --am9511 -lfastmath main.c vector.c player.c asteroids.c renderer.c  -o asteroid -create-app
```

## Screen

Using XTerm compiled with ReGIS support, and picocom to provide a serial interface.

```sh
xterm +u8 -geometry 132x50 -ti 340 -tn 340 -title "Asteroids" -e picocom -b 115200 -p 2 -f h /dev/ttyUSB0 --send-cmd "sx -vv"
```

## Controls
* "A" or "a" to rotate left
* "D" or "d" to rotate right
* "W" or "w" to apply thrust in the direction you are pointing
* "S" or "s" to shoot a bullet
* ESC to exit game

## Images
![animation](https://i.imgur.com/sV164D6.gif)

![game play](http://i.imgur.com/vg8nlAO.png)

