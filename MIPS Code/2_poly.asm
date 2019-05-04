## poly.asm
##
## evaluate  5x^2 - 12x + 97
##
## $t0 base register, address of x
## $t1 x
## $t2 value of the polynomial
## $t3 temporary
.data
  x:      .word   17           # The base register points here.
  poly:   .word   0


.text
.globl  main

main:
  la    $t0 x          # Init base register
  lw    $t1 0($t0)     # Load x
  ori   $t2 $0 97

  ori   $t3 $0 12      #  evaluate second term
  mult  $t1 $t3        #  12x
  mflo  $t3            #  assume 32 bit result
  subu  $t2 $t2 $t3    #  accumulator = -12x +97

                       #  evaluate third term
  mult  $t1 $t1        #  x^2
  mflo  $t1            #  assume 32 bit result
  ori   $t3 $0 5       #  5
  mult  $t1 $t3        #  5x^2
  mflo  $t3            #
  addu  $t2 $t2 $t3    #  accumulator = 5x^2-12x+97

  sw    $t2 4($t0)     # poly is immediately after x

  ori $v0 $0 10
  syscall

## End of file
