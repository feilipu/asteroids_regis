
# ASTEROIDS

This is a recreation of the classic asteroids video game. Implemented in the C
programming language, using z88dk-libraries ReGIS library to display graphics on the screen.

To compile you need to have z88dk and z88dk-libraries regis installed on your system and the header files available to you. Display is via XTerm compiled with ReGIS enabled.

```sh
    # ZSDCC compile
    zcc +rc2014 -subtype=cpm -v -m --list  --math32 -llib/rc2014/regis --max-allocs-per-node100000 main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 compile
    zcc +rc2014 -subtype=cpm -clib=new -v -m --list -O2 --math32 -llib/rc2014/regis main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 CP/M compile
    zcc +cpm -clib=new -v -m --list -O2 -DAMALLOC --math32 -l../../libsrc/_DEVELOPMENT/lib/sccz80/lib/cpm/regis main.c vector.c player.c asteroids.c renderer.c -o asteroid -create-app

    # SCCZ80 CP/M 8085_AM9511 compile
    zcc +cpm -clib=8085 -v -m --list -O2 -DAMALLOC --am9511 -l../../libsrc/_DEVELOPMENT/lib/sccz80/lib/cpm/regis_8085 main.c vector.c player.c asteroids.c renderer.c  -o asteroid -create-app
```

## Controls
* left arrow to rotate left
* right arrow to rotate right
* up arrow to apply thrust in the direction you are pointing
* space to shoot a bullet
* ESC to exit game

## Images
![animation](https://i.imgur.com/sV164D6.gif)

![game play](http://i.imgur.com/vg8nlAO.png)

