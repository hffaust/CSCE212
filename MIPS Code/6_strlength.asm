.data
    str: .asciiz "Hello, World!"

.text
.globl main

## Entry point.
#
main:
    la $a0 str
    jal strlength

    or  $a0 $0 $v0
    ori $v0 $0 1
    syscall

    or  $a0 $0 10
    ori $v0 $0 11
    syscall

    ori $v0 $0 10
    syscall

## A function to find the length of a string
# @param $a0 The first address of the (c-style) string.
# @return The number of bytes in the string.
strlength:
    # assume str address is given to me in $a0
    or $t0 $0 $0 # count reg
    or $t1 $0 $0 # the current byte
    or $t2 $0 $a0 # The string address

    strlength_befloop:
        lb  $t1 0($t2)
        beq $t1 $0 strlength_aftloop

        addi $t0 $t0 1 # count++

        addi $t2 $t2 1 # increment the byte index

        j strlength_befloop

    strlength_aftloop:
    ori $v0 $t0 0
    j $ra
