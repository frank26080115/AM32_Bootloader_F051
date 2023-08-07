This is a fork of the original AM32_Bootloader_F051 project.

I've made changes to improve it's reliability with more tools:

 * UART output uses more stop bits
   * some bit-bang implementations of UART needs a little extra time
 * UART per-byte timeout increased from 250 us to 1000 us
   * some USB interfaces have small buffers and the pause between buffers causes a timeout
 * LED(s) added
 * Version number changed from 10 to 11
