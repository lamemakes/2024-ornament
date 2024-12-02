# ✨ Blinky Tree ✨

**A super simple holiday ornament that whimsically blinks some LEDs**

## How's it work?

This utilizes [charlieplexing](https://en.wikipedia.org/wiki/Charlieplexing) & an ATTiny85 to control 12 LEDs. When it isn't flashing it's LEDs due to a button trigger, the ATTiny is in a state of [deep sleep ](https://onlinedocs.microchip.com/oxy/GUID-317042D4-BCCE-4065-BB05-AC4312DBC2C4-en-US-2/GUID-0EC704BC-648F-4BF6-90AE-0FAF9C596013.html) and thus using very little power, which is why it can be powered with a CR2032.

## Pics

*Schematic*
![pics/tree]

*PCB*
![pics/tree_ornament-pcb.svg]